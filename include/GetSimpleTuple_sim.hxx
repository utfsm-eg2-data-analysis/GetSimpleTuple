#ifndef UX_HXX
#include "UX.hxx"
#endif

#ifndef TREEOPS_HXX
#include "TreeOps.hxx"
#endif

#ifndef VECOPS_HXX
#include "VecOps.hxx"
#endif

std::vector<int> SortByMomentum(TIdentificatorV2* t, std::vector<int> vector_row, Int_t kind) {
  // Returns a new "vector_row2" where particle indices are sorted by their respective momentum (from lower to higher)
  // first, fill the momentum vector
  std::vector<double> momentum;
  for (Int_t m = 0; m < (Int_t)vector_row.size(); m++) {
    momentum.push_back(t->Momentum(vector_row[m], kind));
  }
  // Argsort() creates an indices-vector with the indices sorted by the input-vector values
  std::vector<int> indices = Argsort(momentum);
  // Take(input-vector, indices-vector) creates a sorted-vector by moving all input-vector indices to match the order assigned by the
  // indices-vector
  std::vector<int> vector_row2 = Take(vector_row, indices);
  return vector_row2;
}

void AngularMatching(TIdentificatorV2* t, std::vector<int>& simrec_row, std::vector<int>& gsim_row, TString dataKind, TString targetOption) {
  // Matches the "simrec_row" vector with the "gsim_row" vector under angular matching
  // if particles don't match, the counterpart is filled with null

  // worst from electron (CLAS paper @ P = 0.75 GeV):
  //       fDeltaThetaLab = 0.33, fDeltaPhiLab = 0.96
  // arbitrary values:
  //       fDeltaThetaLab = 0.5, fDeltaPhiLab = 2.0
  // measured values: (worst from pi+ with 0 < P < 0.35 GeV)
  //       fDeltaThetaLab = 0.78, fDeltaPhiLab = 1.41
  // worst from electron (CLAS paper @ P = 0.1 GeV):
  const Double_t fDeltaThetaLab = 2.40;  // Delta_Theta = 3*sigma_Theta
  const Double_t fDeltaPhiLab = 5.43;    // Delta_Phi = 3*sigma_Phi

  // define output vectors - initially empty
  std::vector<int> simrec_new;
  std::vector<int> gsim_new;

  // declare PhiLab and ThetaLab
  Double_t simrec_phi;
  Double_t simrec_theta;
  Double_t gsim_phi;
  Double_t gsim_theta;

  // define vector sizes - loop length
  Int_t M = (Int_t)gsim_row.size();
  Int_t N = (Int_t)simrec_row.size();

  // m, n are the vectors' indices
  for (Int_t m = 0; m < M; m++) {
    for (Int_t n = 0; n < N; n++) {

      // gsim angles don't need correction
      gsim_phi = PhiLab(t->Px(gsim_row[m], 1), t->Py(gsim_row[m], 1), t->Pz(gsim_row[m], 1));
      gsim_theta = ThetaLab(t->Px(gsim_row[m], 1), t->Py(gsim_row[m], 1), t->Pz(gsim_row[m], 1));

      // for reconstructed photons
      TLorentzVector* fGamma = t->GetCorrPhotonMomentum(simrec_row[n]);
      TString fParticleName = t->GetCategorization(simrec_row[n], dataKind, targetOption);
      Double_t fPx = (fParticleName == "gamma") * fGamma->Px() + (fParticleName != "gamma") * t->Px(simrec_row[n], 0);
      Double_t fPy = (fParticleName == "gamma") * fGamma->Py() + (fParticleName != "gamma") * t->Py(simrec_row[n], 0);
      Double_t fPz = (fParticleName == "gamma") * fGamma->Pz() + (fParticleName != "gamma") * t->Pz(simrec_row[n], 0);

      simrec_phi = PhiLab(fPx, fPy, fPz);
      simrec_theta = ThetaLab(fPx, fPy, fPz);

      /*** MATCHING CONDITION ***/

      Bool_t fAngularMatching = TMath::Abs(simrec_phi - gsim_phi) < fDeltaPhiLab && TMath::Abs(simrec_theta - gsim_theta) < fDeltaThetaLab;
      if (fAngularMatching && std::find(gsim_new.begin(), gsim_new.end(), gsim_row[m]) == gsim_new.end() &&
          std::find(simrec_new.begin(), simrec_new.end(), simrec_row[n]) == simrec_new.end()) {
        // std::find function returns an iterator to the first element in the range ["begin","end"[ that compares equal to "row"
        // if no such element is found, the function returns "end", this is done to prevent particles that already matched
        gsim_new.push_back(gsim_row[m]);      // add gsim_row to gsim_new
        simrec_new.push_back(simrec_row[n]);  // add simrec_row to simrec_new
      }

    }  // end of simrec loop
  }    // end of gsim loop

  /*** FILL REMAINING ***/

  for (Int_t m = 0; m < M; m++) {
    // if it's not in gsim_new
    if (std::find(gsim_new.begin(), gsim_new.end(), gsim_row[m]) == gsim_new.end()) {
      gsim_new.push_back(gsim_row[m]);  // add gsim_row to gsim_new
      simrec_new.push_back(-1);         // add null simrec
    }
  }

  for (Int_t n = 0; n < N; n++) {
    // if it's not in simrec_new
    if (std::find(simrec_new.begin(), simrec_new.end(), simrec_row[n]) == simrec_new.end()) {
      simrec_new.push_back(simrec_row[n]);  // add simrec_row to simrec_new
      gsim_new.push_back(-1);               // add null gsim
    }
  }

  // assign results
  gsim_row = gsim_new;
  simrec_row = simrec_new;
}
