/***************************************/
/*  GetSimpleTuple_sim.cxx             */
/*                                     */
/*  Andrés Bórquez                     */
/*                                     */
/***************************************/

// December 2020
// Independent of Analyser

#include "GetSimpleTuple_sim.hxx"

int main(int argc, char **argv) {

  gDataKind = "sim";

  parseCommandLine(argc, argv);
  printOptions();

  // assign options
  TString gInputFile = "recsis" + gTargetOption + "_" + gRunNumber + ".root";   // node dir
  TString gOutputFile = "pruned" + gTargetOption + "_" + gRunNumber + ".root";  // node dir
  TString outTitle = "Simulation of particles";

  /*** DATA STRUCTURES ***/

  // output
  rec_e re;
  rec_p rp;
  gen_e ge;
  gen_p gp;

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
  SetElectronBranches_REC(tElectrons, re);
  SetElectronBranches_GEN(tElectrons, ge);

  TTree *tParticles = new TTree("ntuple_sim", "Stable particles");
  SetParticleBranches_REC(tParticles, rp);
  SetParticleBranches_GEN(tParticles, gp);

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

    FindParticles(input, t, gsim_row, simrec_row);

    /*** STEP 2: PRELIMINARY SORT ***/

    gsim_row = SortByMomentum(t, gsim_row, 1);
    simrec_row = SortByMomentum(t, simrec_row, 0);

    /*** STEP 3: ANGULAR MATCHING ***/

    AngularMatching(t, simrec_row, gsim_row);

    /*** STEP 4: FILL ***/

    FillElectrons(tElectrons, input, t, i, ge, re);
    FillParticles(tParticles, gsim_row, simrec_row, t, i, gp, rp);

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
