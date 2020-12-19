/***************************************/
/*  GetSimpleTuple_data.cxx            */
/*                                     */
/*  Andrés Bórquez                     */
/*                                     */
/***************************************/

// December 2020
// Independent of Analyser

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
  rec_e re;
  rec_p rp;

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

  TTree *tParticles = new TTree("ntuple_data", "Stable particles");
  SetParticleBranches_REC(tParticles, rp);

  /*** START ***/

  // jumps to first readable event (mandatory)
  input->Next();

  // loop around events
  for (Int_t i = 0; i < nEvents; i++) {  // nEvents or 2000
    FindNFillParticles(tElectrons, tParticles, t, input, i, re, rp);
    // next event!
    input->Next();
  }  // end of loop in events

  // write and close output file
  rootFile->Write();
  rootFile->Close();
  std::cout << "File " << gOutputFile << " has been created!" << std::endl;

  return 0;
}
