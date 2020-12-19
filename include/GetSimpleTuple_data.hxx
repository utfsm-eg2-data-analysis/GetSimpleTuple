#include "UI.hxx"
#include "TreeOps.hxx"

void FindNFillParticles(TTree* tElectrons, TTree* tParticles, TIdentificatorV2* t, TClasTool* input, Int_t i, rec_e& re, rec_p& rp) {
  if (input->GetNRows("EVNT") > 0) {  // prevent seg-fault
    if (t->GetCategorization(0, gDataKind, gTargetOption) == "electron") {
      AssignElectronVar_REC(t, re, i, gDataKind, gTargetOption);  // (TIdentificator, rec_e, evnt, gDataKind, gTargetOption)
      tElectrons->Fill();
      // loop in detected particles
      for (Int_t p = 1; p < input->GetNRows("EVNT"); p++) {
        // rest of particles
        if (t->GetCategorization(p, gDataKind, gTargetOption) == "gamma" || t->GetCategorization(p, gDataKind, gTargetOption) == "pi+" ||
            t->GetCategorization(p, gDataKind, gTargetOption) == "pi-") {
          AssignParticleVar_REC(t, rp, p, i, gDataKind, gTargetOption);  // (TIdentificator, rec_p, row, evnt, gDataKind, gTargetOption)
          tParticles->Fill();
        }
      }  // end of loop in rest of particles
    }    // end of electron condition
  }      // end of smth-in-EVNT-bank condition
}
