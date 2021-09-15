/***************************************/
/*  GetSimpleTuple_sim.cxx             */
/*                                     */
/*  Andrés Bórquez                     */
/*                                     */
/***************************************/

// September 2021

#include "GetSimpleTuple_sim.hxx"

int main(int argc, char **argv) {

  gDataKind = "sim";

  parseCommandLine(argc, argv);
  printOptions();

  // assign options
  TString gInputFile = "recsis" + gTargetOption + "_" + gRunNumber + ".root";   // current dir
  TString gOutputFile = "pruned" + gTargetOption + "_" + gRunNumber + ".root";  // current dir
  TString outTitle = "Simulation of particles";

  /*** DATA STRUCTURES ***/

  // output
  rec_t rec;
  gen_t gen;

  /*** INPUT ***/

  // init ClasTool
  TClasTool *input = new TClasTool();
  input->InitDSTReader("ROOTDSTR");

  input->Add(gInputFile);

  // define TIdentificatorV2
  TIdentificatorV2 *t = new TIdentificatorV2(input);
  Int_t nEvents = (Int_t)input->GetEntries();

#ifdef DEBUG
  nEvents = nEvents / 10;
#endif

  /*** OUTPUT ***/

  // define output file
  TFile *rootFile = new TFile(gOutputFile, "RECREATE", outTitle);

  // define output ntuples
  TTree *tElectrons = new TTree("ntuple_e", "All electrons");
  SetElectronBranches_REC(tElectrons, rec);
  SetElectronBranches_GEN(tElectrons, gen);

  TTree *tParticles = new TTree("ntuple_sim", "Stable particles");
  SetParticleBranches_REC(tParticles, rec);
  SetParticleBranches_GEN(tParticles, gen);

  /*** VECTORS ***/

  // define sorting vectors
  RVec<Int_t> gsim_row;
  RVec<Int_t> simrec_row;

  /*** START ***/

  // jumps to first readable event (mandatory)
  input->Next();

  // loop around events
  for (Int_t i = 0; i < nEvents; i++) {  // nEvents

    /*** STEP 1: FIND PARTICLES ***/

    if (input->GetNRows("GSIM") > 0) {  // prevent seg-fault

      // first, check numbering scheme
      if (t->Id(0, 1) == 11) {
        SetNumberingScheme("PDG");
      } else if (t->Id(0, 1) == 3) {
        SetNumberingScheme("GEANT");
      }

      if (t->Id(0, 1) == gElectronID) {
        for (Int_t q = 1; q < input->GetNRows("GSIM"); q++) {
          if (t->Id(q, 1) == gPiPlusID || t->Id(q, 1) == gPiMinusID || t->Id(q, 1) == gGammaID || t->Id(q, 1) == gElectronID ||
              t->Id(q, 1) == gPositronID || t->Id(q, 1) == gProtonID || t->Id(q, 1) == gNeutronID || t->Id(q, 1) == gKaonPlusID ||
              t->Id(q, 1) == gKaonMinusID || t->Id(q, 1) == gKaonZeroLongID || t->Id(q, 1) == gKaonZeroShortID ||
              t->Id(q, 1) == gKaonZeroID) {
            gsim_row.push_back(q);
          }
        }  // end of loop in gsim-particles

        if (input->GetNRows("EVNT") > 0) {  // prevent seg-fault
          if (t->GetCategorization(0, gDataKind, gTargetOption) == "electron") {
            for (Int_t p = 1; p < input->GetNRows("EVNT"); p++) {
              if (t->GetCategorization(p, gDataKind, gTargetOption) == "pi+" ||
                  t->GetCategorization(p, gDataKind, gTargetOption) == "pi-" ||
                  t->GetCategorization(p, gDataKind, gTargetOption) == "gamma") {
                simrec_row.push_back(p);
              }
            }  // end of loop in simrec-particles
          }    // end of electron-in-simrec condition
        }      // end of smth-in-EVNT-bank

      }  // end of electron-in-gsim condition
    }    // end of smth-in-GSIM-bank

    /*** STEP 2: PRELIMINARY SORT ***/

    gsim_row = SortByMomentum(t, gsim_row, 1);
    simrec_row = SortByMomentum(t, simrec_row, 0);

    /*** STEP 3: ANGULAR MATCHING ***/

    AngularMatching(t, simrec_row, gsim_row, gDataKind, gTargetOption);

    /*** STEP 4: FILL ***/

    // (1) electron ntuple
    if (input->GetNRows("GSIM") > 0) {  // prevent seg-fault
      // the event id never gets null'd
      rec.evnt = i;
      if (t->Id(0, 1) == gElectronID) {
        AssignElectronVar_GEN(t, gen, i);
        if (input->GetNRows("EVNT") > 0) {  // prevent seg-fault
          if (t->GetCategorization(0, gDataKind, gTargetOption) != "electron") {
            NullElectronVar_REC(rec);
          } else {
            AssignElectronVar_REC(t, rec, i);
          }
        }  // end of smth-in-EVNT-bank condition
        tElectrons->Fill();
      }  // end of electorn-in-GSIM condition
    }    // end of smth-in-GSIM-bank condition

    // (2) particles ntuple
    for (Int_t index = 0; index < (Int_t)simrec_row.size(); index++) {  // simrec_row.size() == gsim_row.size()
      // gsim
      if (gsim_row[index] == -1) {
        NullParticleVar_GEN(gen);
      } else {
        AssignParticleVar_GEN(t, gen, gsim_row[index], i);
      }
      // simrec
      if (simrec_row[index] == -1) {
        NullParticleVar_REC(rec);
      } else {
        AssignParticleVar_REC(t, rec, simrec_row[index], i);
      }
      // fill!
      tParticles->Fill();
    }

    // reset memory
    gsim_row.clear();
    simrec_row.clear();

    // next event
    input->Next();
  }  // end of loop in events

  // write and close output file
  rootFile->Write();
  rootFile->Close();

  std::cout << "File " << gOutputFile << " has been created!" << std::endl;

  return 0;
}
