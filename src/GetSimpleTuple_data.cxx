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
  rec_p rec;

  /*** INPUT ***/

  // init ClasTool
  TClasTool *input = new TClasTool();
  input->InitDSTReader("ROOTDSTR");

  input->Add(gInputFile);

  // define TIdentificatorV2
  TIdentificatorV2 *t = new TIdentificatorV2(input);
  Int_t nEvents = input->GetEntries();

  /*** OUTPUT ***/

  // define output file
  TFile *rootFile = new TFile(gOutputFile, "RECREATE", outTitle, 505);

  // define output ntuple
  TTree *tParticles = new TTree("ntuple_data", "Stable particles");
  SetOutputBranches_REC(tParticles, rec);

  /*** START ***/

  // jumps to first readable event (mandatory)
  input->Next();

  // loop around events
  for (Int_t i = 0; i < nEvents; i++) {  // nEvents or 2000
    FindNFillParticles(tParticles, t, input, i, rec);
    // next event!
    input->Next();
  }  // end of loop in events

  // write and close output file
  rootFile->Write();
  rootFile->Close();
  std::cout << "File " << gOutputFile << " has been created!" << std::endl;

  return 0;
}
