#include "TreeOps.hxx"

#ifndef UI_HXX
#include "UI.hxx"
#endif

void FindNFillParticles(TTree* tParticles, TIdentificatorV2* t, TClasTool* input, Int_t i, rec_p& rec) {
  if (input->GetNRows("EVNT") > 0) {  // prevent seg-fault
    if (t->GetCategorization(0, gDataKind, gTargetOption) == "electron") {
      AssignElectronVar_REC(t, rec, i);  // (TIdentificator, rec_p, evnt)
      // loop in detected particles
      Int_t fNpart = 0;
      for (Int_t p = 1; p < input->GetNRows("EVNT"); p++) {
        // rest of particles
        if (t->GetCategorization(p, gDataKind, gTargetOption) == "gamma" || t->GetCategorization(p, gDataKind, gTargetOption) == "pi+" ||
            t->GetCategorization(p, gDataKind, gTargetOption) == "pi-") {
          AssignParticleVar_REC(t, rec, p);  // (TIdentificator, rec_p, row)
          fNpart++;
        }
      }  // end of loop in rest of particles
      tParticles->Fill();
      ClearParticleVar_REC(rec);
    }  // end of electron condition
  }    // end of smth-in-EVNT-bank condition
}
