/***************************************/
/*  GetSimpleTuple_data.cxx            */
/*                                     */
/*  Andrés Bórquez                     */
/*                                     */
/***************************************/

// September 2021

#include "GetSimpleTuple_data.hxx"

int main(int argc, char **argv) {

  gDataKind = "data";

  parseCommandLine(argc, argv);
  printOptions();

  SetNumberingScheme("PDG");

  // assign options
  TString gInputFile = "clas_" + gRunNumber + "_*.pass2.root";                  // *: all rn files, node dir
  TString gOutputFile = "pruned" + gTargetOption + "_" + gRunNumber + ".root";  // node dir
  TString outTitle = "Data of particles";

  /*** DATA STRUCTURES ***/

  // output
  rec_t rec;

  /*** INPUT ***/

  // init ClasTool
  TClasTool *input = new TClasTool();
  input->InitDSTReader("ROOTDSTR");

  input->Add(gInputFile);

  // define TIdentificatorV2
  TIdentificatorV2 *t = new TIdentificatorV2(input);
  Int_t nEvents = (Int_t)input->GetEntries();

  /*** OUTPUT ***/

  // define output file
  TFile *rootFile = new TFile(gOutputFile, "RECREATE", outTitle);

  // define output ntuples
  TTree *tElectrons = new TTree("ntuple_e", "All electrons");
  SetElectronBranches_REC(tElectrons, rec);

  TTree *tParticles = new TTree("ntuple_data", "Stable particles");
  SetParticleBranches_REC(tParticles, rec);

  /*** START ***/

  // jumps to first readable event (mandatory)
  input->Next();

  // loop around events
  for (Int_t i = 0; i < nEvents; i++) {
    if (input->GetNRows("EVNT") > 0) {   // prevent seg-fault
      if (t->GetCategorization(0, gDataKind, gTargetOption) == "electron") {
        AssignElectronVar_REC(t, rec, i);
        tElectrons->Fill();
        // loop in detected particles
        for (Int_t p = 1; p < input->GetNRows("EVNT"); p++) {
          // rest of particles
          if (t->GetCategorization(p, gDataKind, gTargetOption) == "gamma" || t->GetCategorization(p, gDataKind, gTargetOption) == "pi+" ||
              t->GetCategorization(p, gDataKind, gTargetOption) == "pi-") {
            AssignParticleVar_REC(t, rec, p, i);
            tParticles->Fill();
          }
        }  // end of loop in rest of particles
      }    // end of electron condition
    }      // end of smth-in-EVNT-bank condition

    // next event!
    input->Next();
  }  // end of loop in events

  // write and close output file
  rootFile->Write();
  rootFile->Close();
  std::cout << "File " << gOutputFile << " has been created!" << std::endl;

  return 0;
}
