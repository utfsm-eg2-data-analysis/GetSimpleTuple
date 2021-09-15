#ifndef TREEOPS_HXX
#define TREEOPS_HXX

#include "GSTtree.h"
#include "Headers.hxx"

#include "TIdentificatorV2.h"

#include "Constants.hxx"
#include "Math.hxx"
#include "PDG.hxx"

#ifndef UX_HXX
#include "UX.hxx"
#endif

void SetElectronBranches_REC(TTree* tree, rec_t& rec) {
  // electron (26)
  tree->Branch("Q2", &rec.Q2);
  tree->Branch("W", &rec.W);
  tree->Branch("Nu", &rec.Nu);
  tree->Branch("Xb", &rec.Xb);
  tree->Branch("Yb", &rec.Yb);
  tree->Branch("Px", &rec.Pex);
  tree->Branch("Py", &rec.Pey);
  tree->Branch("Pz", &rec.Pez);
  tree->Branch("P", &rec.Pe);
  tree->Branch("Ein", &rec.Eine);
  tree->Branch("Eout", &rec.Eoute);
  tree->Branch("Etot", &rec.Etote);
  tree->Branch("XEC", &rec.XECe);
  tree->Branch("YEC", &rec.YECe);
  tree->Branch("ZEC", &rec.ZECe);
  tree->Branch("vxe", &rec.vxe);
  tree->Branch("vye", &rec.vye);
  tree->Branch("vze", &rec.vze);
  tree->Branch("vxec", &rec.vxec);
  tree->Branch("vyec", &rec.vyec);
  tree->Branch("vzec", &rec.vzec);
  tree->Branch("TargType", &rec.TargType);
  tree->Branch("Sector", &rec.SectorEl);
  tree->Branch("PhiLab", &rec.PhiLabEl);
  tree->Branch("ThetaLab", &rec.ThetaLabEl);
  tree->Branch("Betta", &rec.BettaEl);
  // evnt (1)
  tree->Branch("evnt", &rec.evnt);
}

void SetParticleBranches_REC(TTree* tree, rec_t& rec) {
  // electron (26)
  tree->Branch("Q2", &rec.Q2);
  tree->Branch("W", &rec.W);
  tree->Branch("Nu", &rec.Nu);
  tree->Branch("Xb", &rec.Xb);
  tree->Branch("Yb", &rec.Yb);
  tree->Branch("Pex", &rec.Pex);
  tree->Branch("Pey", &rec.Pey);
  tree->Branch("Pez", &rec.Pez);
  tree->Branch("Pe", &rec.Pe);
  tree->Branch("Eine", &rec.Eine);
  tree->Branch("Eoute", &rec.Eoute);
  tree->Branch("Etote", &rec.Etote);
  tree->Branch("XECe", &rec.XECe);
  tree->Branch("YECe", &rec.YECe);
  tree->Branch("ZECe", &rec.ZECe);
  tree->Branch("vxe", &rec.vxe);
  tree->Branch("vye", &rec.vye);
  tree->Branch("vze", &rec.vze);
  tree->Branch("vxec", &rec.vxec);
  tree->Branch("vyec", &rec.vyec);
  tree->Branch("vzec", &rec.vzec);
  tree->Branch("TargType", &rec.TargType);
  tree->Branch("SectorEl", &rec.SectorEl);
  tree->Branch("PhiLabEl", &rec.PhiLabEl);
  tree->Branch("ThetaLabEl", &rec.ThetaLabEl);
  tree->Branch("BettaEl", &rec.BettaEl);
  // particle (29)
  tree->Branch("Eh", &rec.Eh);
  tree->Branch("Zh", &rec.Zh);
  tree->Branch("ThetaPQ", &rec.ThetaPQ);
  tree->Branch("Pt2", &rec.Pt2);
  tree->Branch("Pl2", &rec.Pl2);
  tree->Branch("PhiPQ", &rec.PhiPQ);
  tree->Branch("Mx2", &rec.Mx2);
  tree->Branch("T", &rec.T);
  tree->Branch("PhiLab", &rec.PhiLab);
  tree->Branch("ThetaLab", &rec.ThetaLab);
  tree->Branch("vxh", &rec.vxh);
  tree->Branch("vyh", &rec.vyh);
  tree->Branch("vzh", &rec.vzh);
  tree->Branch("Sector", &rec.Sector);
  tree->Branch("Px", &rec.Px);
  tree->Branch("Py", &rec.Py);
  tree->Branch("Pz", &rec.Pz);
  tree->Branch("P", &rec.P);
  tree->Branch("Betta", &rec.Betta);
  tree->Branch("Mass2", &rec.Mass2);
  tree->Branch("Etot", &rec.Etot);
  tree->Branch("Ein", &rec.Ein);
  tree->Branch("Eout", &rec.Eout);
  tree->Branch("XEC", &rec.XEC);
  tree->Branch("YEC", &rec.YEC);
  tree->Branch("ZEC", &rec.ZEC);
  tree->Branch("pid", &rec.pid);
  tree->Branch("T4", &rec.T4);
  tree->Branch("deltaZ", &rec.deltaZ);
  // event (1)
  tree->Branch("evnt", &rec.evnt);
}

void AssignElectronVar_REC(TIdentificatorV2* t, rec_t& rec, Int_t evnt) {
  // electron (26)
  rec.Q2 = t->Q2();
  rec.W = t->W();
  rec.Nu = t->Nu();
  rec.Xb = t->Xb();
  rec.Yb = t->Yb();
  rec.Pex = t->Px(0);
  rec.Pey = t->Py(0);
  rec.Pez = t->Pz(0);
  rec.Pe = t->Momentum(0);
  rec.Eine = t->Ein(0);
  rec.Eoute = t->Eout(0);
  rec.Etote = t->Etot(0);
  rec.XECe = t->XEC(0);
  rec.YECe = t->YEC(0);
  rec.ZECe = t->ZEC(0);
  rec.vxe = t->X(0);
  rec.vye = t->Y(0);
  rec.vze = t->Z(0);
  TVector3* fVert = t->GetCorrectedVert();
  rec.vxec = fVert->X();
  rec.vyec = fVert->Y();
  rec.vzec = fVert->Z();
  rec.TargType = t->TargType(gDataKind, gTargetOption);
  rec.SectorEl = t->Sector(0);
  rec.PhiLabEl = t->PhiLab(0);
  rec.ThetaLabEl = t->ThetaLab(0);
  rec.BettaEl = t->Betta(0);
  // evnt (1)
  rec.evnt = evnt;
}

void AssignParticleVar_REC(TIdentificatorV2* t, rec_t& rec, Int_t row, Int_t evnt) {
  // electron (26)
  rec.Q2 = t->Q2();
  rec.W = t->W();
  rec.Nu = t->Nu();
  rec.Xb = t->Xb();
  rec.Yb = t->Yb();
  rec.Pex = t->Px(0);
  rec.Pey = t->Py(0);
  rec.Pez = t->Pz(0);
  rec.Pe = t->Momentum(0);
  rec.Eine = t->Ein(0);
  rec.Eoute = t->Eout(0);
  rec.Etote = t->Etot(0);
  rec.XECe = t->XEC(0);
  rec.YECe = t->YEC(0);
  rec.ZECe = t->ZEC(0);
  rec.vxe = t->X(0);
  rec.vye = t->Y(0);
  rec.vze = t->Z(0);
  TVector3* fVert = t->GetCorrectedVert();
  rec.vxec = fVert->X();
  rec.vyec = fVert->Y();
  rec.vzec = fVert->Z();
  rec.TargType = t->TargType(gDataKind, gTargetOption);
  rec.SectorEl = t->Sector(0);
  rec.PhiLabEl = t->PhiLab(0);
  rec.ThetaLabEl = t->ThetaLab(0);
  rec.BettaEl = t->Betta(0);
  // particle (29)
  rec.pid = particleID(t->GetCategorization(row, gDataKind, gTargetOption));
  rec.vxh = t->X(row);
  rec.vyh = t->Y(row);
  rec.vzh = t->Z(row);
  rec.Sector = t->Sector(row);
  rec.deltaZ = t->Z(row) - fVert->Z();
  rec.XEC = t->XEC(row);
  rec.YEC = t->YEC(row);
  rec.ZEC = t->ZEC(row);
  rec.Etot = t->Etot(row);
  rec.Ein = t->Ein(row);
  rec.Eout = t->Eout(row);
  // let's define some auxiliary Double_t
  Double_t fMass = particleMass(rec.pid);
  TLorentzVector* fGamma = t->GetCorrPhotonMomentum(row);
  Double_t fPx = (rec.pid == 22) * fGamma->Px() + (rec.pid != 22) * t->Px(row);
  Double_t fPy = (rec.pid == 22) * fGamma->Py() + (rec.pid != 22) * t->Py(row);
  Double_t fPz = (rec.pid == 22) * fGamma->Pz() + (rec.pid != 22) * t->Pz(row);
  Double_t fP = TMath::Sqrt(fPx * fPx + fPy * fPy + fPz * fPz);
  Double_t fE = (rec.pid == 22) * fGamma->E() + (rec.pid != 22) * TMath::Sqrt(fMass * fMass + fP * fP);
  Double_t fZ = fE / t->Nu();
  // continue...
  rec.Px = fPx;
  rec.Py = fPy;
  rec.Pz = fPz;
  rec.P = fP;
  rec.PhiLab = PhiLab(fPx, fPy, fPz);
  rec.ThetaLab = ThetaLab(fPx, fPy, fPz);
  rec.Eh = fE;
  rec.Zh = fZ;
  rec.ThetaPQ = ThetaPQ(t->Px(0), t->Py(0), t->Pz(0), fPx, fPy, fPz);
  rec.PhiPQ = PhiPQ(t->Px(0), t->Py(0), t->Pz(0), fPx, fPy, fPz);
  Double_t fCosThetaPQ = (fPz * (kEbeam - t->Pz(0)) - fPx * t->Px(0) - fPy * t->Py(0)) / (TMath::Sqrt(t->Nu() * t->Nu() + t->Q2()) * fP);
  Double_t fPt2 = fP * fP * (1 - fCosThetaPQ * fCosThetaPQ);
  Double_t fPl2 = fP * fP * fCosThetaPQ * fCosThetaPQ;
  rec.Pt2 = fPt2;
  rec.Pl2 = fPl2;
  rec.Mx2 = t->W() * t->W() + fMass * fMass - 2 * fZ * t->Nu() * t->Nu() + 2 * TMath::Sqrt(fPl2 * (t->Nu() * t->Nu() + t->Q2())) -
            2 * kMassProton * fZ * t->Nu();
  rec.T = fMass * fMass - 2 * fZ * t->Nu() * t->Nu() + 2 * TMath::Sqrt(fPl2 * (t->Nu() * t->Nu() + t->Q2())) - t->Q2();
  rec.Betta = t->Betta(row);  // BettaMeasured
  rec.Mass2 = fP * fP * (TMath::Power(t->Betta(row), -2) - 1);
  rec.T4 = t->PathSC(0) / 30. - t->TimeSC(0) + t->TimeSC(row) - (t->PathSC(row) / 30.) * TMath::Sqrt(TMath::Power(fMass / fP, 2) + 1);
  // evnt (1)
  rec.evnt = evnt;
}

void SetElectronBranches_GEN(TTree* tree, gen_t& gen) {
  // electron (17)
  tree->Branch("mc_Q2", &gen.mc_Q2);
  tree->Branch("mc_W", &gen.mc_W);
  tree->Branch("mc_Nu", &gen.mc_Nu);
  tree->Branch("mc_Xb", &gen.mc_Xb);
  tree->Branch("mc_Yb", &gen.mc_Yb);
  tree->Branch("mc_Px", &gen.mc_Pex);
  tree->Branch("mc_Py", &gen.mc_Pey);
  tree->Branch("mc_Pz", &gen.mc_Pez);
  tree->Branch("mc_P", &gen.mc_Pe);
  tree->Branch("mc_vxe", &gen.mc_vxe);
  tree->Branch("mc_vye", &gen.mc_vye);
  tree->Branch("mc_vze", &gen.mc_vze);
  tree->Branch("mc_TargType", &gen.mc_TargType);
  tree->Branch("mc_Sector", &gen.mc_SectorEl);
  tree->Branch("mc_PhiLab", &gen.mc_PhiLabEl);
  tree->Branch("mc_ThetaLab", &gen.mc_ThetaLabEl);
  tree->Branch("mc_Betta", &gen.mc_BettaEl);
}

void SetParticleBranches_GEN(TTree* tree, gen_t& gen) {
  // gsim electron (17)
  tree->Branch("mc_Q2", &gen.mc_Q2);
  tree->Branch("mc_W", &gen.mc_W);
  tree->Branch("mc_Nu", &gen.mc_Nu);
  tree->Branch("mc_Xb", &gen.mc_Xb);
  tree->Branch("mc_Yb", &gen.mc_Yb);
  tree->Branch("mc_Pex", &gen.mc_Pex);
  tree->Branch("mc_Pey", &gen.mc_Pey);
  tree->Branch("mc_Pez", &gen.mc_Pez);
  tree->Branch("mc_Pe", &gen.mc_Pe);
  tree->Branch("mc_vxe", &gen.mc_vxe);
  tree->Branch("mc_vye", &gen.mc_vye);
  tree->Branch("mc_vze", &gen.mc_vze);
  tree->Branch("mc_TargType", &gen.mc_TargType);
  tree->Branch("mc_SectorEl", &gen.mc_SectorEl);
  tree->Branch("mc_PhiLabEl", &gen.mc_PhiLabEl);
  tree->Branch("mc_ThetaLabEl", &gen.mc_ThetaLabEl);
  tree->Branch("mc_BettaEl", &gen.mc_BettaEl);
  // gsim particle (23)
  tree->Branch("mc_Eh", &gen.mc_Eh);
  tree->Branch("mc_Zh", &gen.mc_Zh);
  tree->Branch("mc_ThetaPQ", &gen.mc_ThetaPQ);
  tree->Branch("mc_Pt2", &gen.mc_Pt2);
  tree->Branch("mc_Pl2", &gen.mc_Pl2);
  tree->Branch("mc_PhiPQ", &gen.mc_PhiPQ);
  tree->Branch("mc_Mx2", &gen.mc_Mx2);
  tree->Branch("mc_T", &gen.mc_T);
  tree->Branch("mc_ThetaLab", &gen.mc_ThetaLab);
  tree->Branch("mc_PhiLab", &gen.mc_PhiLab);
  tree->Branch("mc_vxh", &gen.mc_vxh);
  tree->Branch("mc_vyh", &gen.mc_vyh);
  tree->Branch("mc_vzh", &gen.mc_vzh);
  tree->Branch("mc_Sector", &gen.mc_Sector);
  tree->Branch("mc_Px", &gen.mc_Px);
  tree->Branch("mc_Py", &gen.mc_Py);
  tree->Branch("mc_Pz", &gen.mc_Pz);
  tree->Branch("mc_P", &gen.mc_P);
  tree->Branch("mc_Betta", &gen.mc_Betta);
  tree->Branch("mc_Mass2", &gen.mc_Mass2);
  tree->Branch("mc_pid", &gen.mc_pid);
  tree->Branch("mc_deltaZ", &gen.mc_deltaZ);
  tree->Branch("mc_ParentID", &gen.mc_ParentID);
}

void NullElectronVar_REC(rec_t& rec) {
  // (26 variables)
  rec.Q2 = INVLD;
  rec.W = INVLD;
  rec.Nu = INVLD;
  rec.Xb = INVLD;
  rec.Yb = INVLD;
  rec.Pex = INVLD;
  rec.Pey = INVLD;
  rec.Pez = INVLD;
  rec.Pe = INVLD;
  rec.Eine = INVLD;
  rec.Eoute = INVLD;
  rec.Etote = INVLD;
  rec.XECe = INVLD;
  rec.YECe = INVLD;
  rec.ZECe = INVLD;
  rec.vxe = INVLD;
  rec.vye = INVLD;
  rec.vze = INVLD;
  rec.vxec = INVLD;
  rec.vyec = INVLD;
  rec.vzec = INVLD;
  rec.TargType = INVLD;
  rec.SectorEl = INVLD;
  rec.PhiLabEl = INVLD;
  rec.ThetaLabEl = INVLD;
  rec.BettaEl = INVLD;
}

void NullParticleVar_REC(rec_t& rec) {
  // electron (26)
  rec.Q2 = INVLD;
  rec.W = INVLD;
  rec.Nu = INVLD;
  rec.Xb = INVLD;
  rec.Yb = INVLD;
  rec.Pex = INVLD;
  rec.Pey = INVLD;
  rec.Pez = INVLD;
  rec.Pe = INVLD;
  rec.Eine = INVLD;
  rec.Eoute = INVLD;
  rec.Etote = INVLD;
  rec.XECe = INVLD;
  rec.YECe = INVLD;
  rec.ZECe = INVLD;
  rec.vxe = INVLD;
  rec.vye = INVLD;
  rec.vze = INVLD;
  rec.vxec = INVLD;
  rec.vyec = INVLD;
  rec.vzec = INVLD;
  rec.TargType = INVLD;
  rec.SectorEl = INVLD;
  rec.PhiLabEl = INVLD;
  rec.ThetaLabEl = INVLD;
  rec.BettaEl = INVLD;
  // particle (29)
  rec.pid = INVLD;
  rec.Eh = INVLD;
  rec.Zh = INVLD;
  rec.ThetaPQ = INVLD;
  rec.PhiPQ = INVLD;
  rec.Pt2 = INVLD;
  rec.Pl2 = INVLD;
  rec.Mx2 = INVLD;
  rec.T = INVLD;
  rec.ThetaLab = INVLD;
  rec.PhiLab = INVLD;
  rec.T4 = INVLD;
  rec.vxh = INVLD;
  rec.vyh = INVLD;
  rec.vzh = INVLD;
  rec.Sector = INVLD;
  rec.Px = INVLD;
  rec.Py = INVLD;
  rec.Pz = INVLD;
  rec.P = INVLD;
  rec.Betta = INVLD;
  rec.Mass2 = INVLD;
  rec.Etot = INVLD;
  rec.Ein = INVLD;
  rec.Eout = INVLD;
  rec.XEC = INVLD;
  rec.YEC = INVLD;
  rec.ZEC = INVLD;
  rec.deltaZ = INVLD;
}

void NullElectronVar_GEN(gen_t& gen) {
  // electron (17 variables)
  gen.mc_Q2 = INVLD;
  gen.mc_W = INVLD;
  gen.mc_Nu = INVLD;
  gen.mc_Xb = INVLD;
  gen.mc_Yb = INVLD;
  gen.mc_Pex = INVLD;
  gen.mc_Pey = INVLD;
  gen.mc_Pez = INVLD;
  gen.mc_Pe = INVLD;
  gen.mc_vxe = INVLD;
  gen.mc_vye = INVLD;
  gen.mc_vze = INVLD;
  gen.mc_TargType = INVLD;
  gen.mc_SectorEl = INVLD;
  gen.mc_PhiLabEl = INVLD;
  gen.mc_ThetaLabEl = INVLD;
  gen.mc_BettaEl = INVLD;
}

void NullParticleVar_GEN(gen_t& gen) {
  // electron (17 variables)
  gen.mc_Q2 = INVLD;
  gen.mc_W = INVLD;
  gen.mc_Nu = INVLD;
  gen.mc_Xb = INVLD;
  gen.mc_Yb = INVLD;
  gen.mc_Pex = INVLD;
  gen.mc_Pey = INVLD;
  gen.mc_Pez = INVLD;
  gen.mc_Pe = INVLD;
  gen.mc_vxe = INVLD;
  gen.mc_vye = INVLD;
  gen.mc_vze = INVLD;
  gen.mc_TargType = INVLD;
  gen.mc_SectorEl = INVLD;
  gen.mc_PhiLabEl = INVLD;
  gen.mc_ThetaLabEl = INVLD;
  gen.mc_BettaEl = INVLD;
  // particle (23 variables)
  gen.mc_Eh = INVLD;
  gen.mc_Zh = INVLD;
  gen.mc_ThetaPQ = INVLD;
  gen.mc_Pt2 = INVLD;
  gen.mc_Pl2 = INVLD;
  gen.mc_PhiPQ = INVLD;
  gen.mc_ThetaLab = INVLD;
  gen.mc_PhiLab = INVLD;
  gen.mc_Mx2 = INVLD;
  gen.mc_T = INVLD;
  gen.mc_vxh = INVLD;
  gen.mc_vyh = INVLD;
  gen.mc_vzh = INVLD;
  gen.mc_Sector = INVLD;
  gen.mc_Px = INVLD;
  gen.mc_Py = INVLD;
  gen.mc_Pz = INVLD;
  gen.mc_P = INVLD;
  gen.mc_Betta = INVLD;
  gen.mc_Mass2 = INVLD;
  gen.mc_deltaZ = INVLD;
  gen.mc_pid = INVLD;
  gen.mc_ParentID = INVLD;
}

void AssignElectronVar_GEN(TIdentificatorV2* t, gen_t& gen, Int_t evnt) {
  // electron (17 variables)
  gen.mc_Q2 = t->Q2(1);
  gen.mc_W = t->W(1);
  gen.mc_Nu = t->Nu(1);
  gen.mc_Xb = t->Xb(1);
  gen.mc_Yb = t->Yb(1);
  gen.mc_Pex = t->Px(0, 1);
  gen.mc_Pey = t->Py(0, 1);
  gen.mc_Pez = t->Pz(0, 1);
  gen.mc_Pe = t->Momentum(0, 1);
  gen.mc_vxe = t->X(0, 1);
  gen.mc_vye = t->Y(0, 1);
  gen.mc_vze = t->Z(0, 1);
  gen.mc_TargType = t->TargType(gDataKind, gTargetOption);
  gen.mc_SectorEl = t->Sector(0, 1);
  gen.mc_PhiLabEl = t->PhiLab(0, 1);
  gen.mc_ThetaLabEl = t->ThetaLab(0, 1);
  gen.mc_BettaEl = t->Betta(0, 1);
}

void AssignParticleVar_GEN(TIdentificatorV2* t, gen_t& gen, Int_t row, Int_t evnt) {
  // electron (17 variables)
  gen.mc_Q2 = t->Q2(1);
  gen.mc_W = t->W(1);
  gen.mc_Nu = t->Nu(1);
  gen.mc_Xb = t->Xb(1);
  gen.mc_Yb = t->Yb(1);
  gen.mc_Pex = t->Px(0, 1);
  gen.mc_Pey = t->Py(0, 1);
  gen.mc_Pez = t->Pz(0, 1);
  gen.mc_Pe = t->Momentum(0, 1);
  gen.mc_vxe = t->X(0, 1);
  gen.mc_vye = t->Y(0, 1);
  gen.mc_vze = t->Z(0, 1);
  gen.mc_TargType = t->TargType(gDataKind, gTargetOption);
  gen.mc_SectorEl = t->Sector(0, 1);
  gen.mc_PhiLabEl = t->PhiLab(0, 1);
  gen.mc_ThetaLabEl = t->ThetaLab(0, 1);
  gen.mc_BettaEl = t->Betta(0, 1);
  // particle (23 variables)
  gen.mc_pid = ToPDG(t->Id(row, 1));  // from GEANT to PDG
  gen.mc_ThetaPQ = t->ThetaPQ(row, 1);
  gen.mc_PhiPQ = t->PhiPQ(row, 1);
  gen.mc_Pt2 = t->Pt2(row, 1);
  gen.mc_Pl2 = t->Pl2(row, 1);
  Double_t fMass = particleMass(gen.mc_pid);
  Double_t fE = t->Zh(row, 1, fMass) * t->Nu(1);
  gen.mc_Zh = t->Zh(row, 1, fMass);
  gen.mc_Eh = fE;
  gen.mc_Mx2 = t->Mx2(row, 1, fMass);
  gen.mc_T = t->T(row, 1, fMass);
  gen.mc_ThetaLab = t->ThetaLab(row, 1);
  gen.mc_PhiLab = t->PhiLab(row, 1);
  gen.mc_vxh = t->X(row, 1);
  gen.mc_vyh = t->Y(row, 1);
  gen.mc_vzh = t->Z(row, 1);
  gen.mc_Sector = t->Sector(row, 1);
  gen.mc_Px = t->Px(row, 1);
  gen.mc_Py = t->Py(row, 1);
  gen.mc_Pz = t->Pz(row, 1);
  gen.mc_P = t->Momentum(row, 1);
  gen.mc_Betta = t->Betta(row, 1);
  gen.mc_Mass2 = t->Mass2(row, 1);
  gen.mc_deltaZ = t->Z(row, 1) - t->Z(0, 1);
  gen.mc_ParentID = t->Status(row, 1);
}

#endif
