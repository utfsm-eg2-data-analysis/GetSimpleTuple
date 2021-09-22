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

void SetElectronBranches_REC(TTree* tree, elec_t& elec) {
  // electron (26)
  tree->Branch("Q2", &elec.Q2);
  tree->Branch("W", &elec.W);
  tree->Branch("Nu", &elec.Nu);
  tree->Branch("Xb", &elec.Xb);
  tree->Branch("Yb", &elec.Yb);
  tree->Branch("Px", &elec.Px);
  tree->Branch("Py", &elec.Py);
  tree->Branch("Pz", &elec.Pz);
  tree->Branch("P", &elec.P);
  tree->Branch("Ein", &elec.Ein);
  tree->Branch("Eout", &elec.Eout);
  tree->Branch("Etot", &elec.Etot);
  tree->Branch("XEC", &elec.XEC);
  tree->Branch("YEC", &elec.YEC);
  tree->Branch("ZEC", &elec.ZEC);
  tree->Branch("vxe", &elec.vx);
  tree->Branch("vye", &elec.vy);
  tree->Branch("vze", &elec.vz);
  tree->Branch("vxec", &elec.vxc);
  tree->Branch("vyec", &elec.vyc);
  tree->Branch("vzec", &elec.vzc);
  tree->Branch("TargType", &elec.TargType);
  tree->Branch("Sector", &elec.Sector);
  tree->Branch("PhiLab", &elec.PhiLab);
  tree->Branch("ThetaLab", &elec.ThetaLab);
  tree->Branch("Betta", &elec.Betta);
  // evnt (1)
  tree->Branch("evnt", &elec.evnt);
}

void SetParticleBranches_REC(TTree* tree, elec_t& elec, part_t& part) {
  // electron (26)
  tree->Branch("Q2", &elec.Q2);
  tree->Branch("W", &elec.W);
  tree->Branch("Nu", &elec.Nu);
  tree->Branch("Xb", &elec.Xb);
  tree->Branch("Yb", &elec.Yb);
  tree->Branch("Pex", &elec.Px);
  tree->Branch("Pey", &elec.Py);
  tree->Branch("Pez", &elec.Pz);
  tree->Branch("Pe", &elec.P);
  tree->Branch("Eine", &elec.Ein);
  tree->Branch("Eoute", &elec.Eout);
  tree->Branch("Etote", &elec.Etot);
  tree->Branch("XECe", &elec.XEC);
  tree->Branch("YECe", &elec.YEC);
  tree->Branch("ZECe", &elec.ZEC);
  tree->Branch("vxe", &elec.vx);
  tree->Branch("vye", &elec.vy);
  tree->Branch("vze", &elec.vz);
  tree->Branch("vxec", &elec.vxc);
  tree->Branch("vyec", &elec.vyc);
  tree->Branch("vzec", &elec.vzc);
  tree->Branch("TargType", &elec.TargType);
  tree->Branch("SectorEl", &elec.Sector);
  tree->Branch("PhiLabEl", &elec.PhiLab);
  tree->Branch("ThetaLabEl", &elec.ThetaLab);
  tree->Branch("BettaEl", &elec.Betta);
  // event (1)
  tree->Branch("evnt", &elec.evnt);
  // particle (29)
  tree->Branch("Eh", &part.Eh);
  tree->Branch("Zh", &part.Zh);
  tree->Branch("ThetaPQ", &part.ThetaPQ);
  tree->Branch("Pt2", &part.Pt2);
  tree->Branch("Pl2", &part.Pl2);
  tree->Branch("PhiPQ", &part.PhiPQ);
  tree->Branch("Mx2", &part.Mx2);
  tree->Branch("T", &part.T);
  tree->Branch("PhiLab", &part.PhiLab);
  tree->Branch("ThetaLab", &part.ThetaLab);
  tree->Branch("vxh", &part.vx);
  tree->Branch("vyh", &part.vy);
  tree->Branch("vzh", &part.vz);
  tree->Branch("Sector", &part.Sector);
  tree->Branch("Px", &part.Px);
  tree->Branch("Py", &part.Py);
  tree->Branch("Pz", &part.Pz);
  tree->Branch("P", &part.P);
  tree->Branch("Betta", &part.Betta);
  tree->Branch("Mass2", &part.Mass2);
  tree->Branch("Etot", &part.Etot);
  tree->Branch("Ein", &part.Ein);
  tree->Branch("Eout", &part.Eout);
  tree->Branch("XEC", &part.XEC);
  tree->Branch("YEC", &part.YEC);
  tree->Branch("ZEC", &part.ZEC);
  tree->Branch("pid", &part.pid);
  tree->Branch("T4", &part.T4);
  tree->Branch("deltaZ", &part.deltaZ);
}

void WriteElectronVar_REC(TIdentificatorV2* t, elec_t& elec, Int_t evnt) {
  // electron (26)
  elec.Q2 = t->Q2();
  elec.W = t->W();
  elec.Nu = t->Nu();
  elec.Xb = t->Xb();
  elec.Yb = t->Yb();
  elec.Px = t->Px(0);
  elec.Py = t->Py(0);
  elec.Pz = t->Pz(0);
  elec.P = t->Momentum(0);
  elec.Ein = t->Ein(0);
  elec.Eout = t->Eout(0);
  elec.Etot = t->Etot(0);
  elec.XEC = t->XEC(0);
  elec.YEC = t->YEC(0);
  elec.ZEC = t->ZEC(0);
  elec.vx = t->X(0);
  elec.vy = t->Y(0);
  elec.vz = t->Z(0);
  TVector3* fVert = t->GetCorrectedVert();
  elec.vxc = fVert->X();
  elec.vyc = fVert->Y();
  elec.vzc = fVert->Z();
  elec.TargType = t->TargType(gDataKind, gTargetOption);
  elec.Sector = t->Sector(0);
  elec.PhiLab = t->PhiLab(0);
  elec.ThetaLab = t->ThetaLab(0);
  elec.Betta = t->Betta(0);
  // evnt (1)
  elec.evnt = evnt;
}

void WriteParticleVar_REC(TIdentificatorV2* t, elec_t& elec, part_t& part, Int_t row, Int_t evnt) {
  // electron (26)
  elec.Q2 = t->Q2();
  elec.W = t->W();
  elec.Nu = t->Nu();
  elec.Xb = t->Xb();
  elec.Yb = t->Yb();
  elec.Px = t->Px(0);
  elec.Py = t->Py(0);
  elec.Pz = t->Pz(0);
  elec.P = t->Momentum(0);
  elec.Ein = t->Ein(0);
  elec.Eout = t->Eout(0);
  elec.Etot = t->Etot(0);
  elec.XEC = t->XEC(0);
  elec.YEC = t->YEC(0);
  elec.ZEC = t->ZEC(0);
  elec.vx = t->X(0);
  elec.vy = t->Y(0);
  elec.vz = t->Z(0);
  TVector3* fVert = t->GetCorrectedVert();
  elec.vxc = fVert->X();
  elec.vyc = fVert->Y();
  elec.vzc = fVert->Z();
  elec.TargType = t->TargType(gDataKind, gTargetOption);
  elec.Sector = t->Sector(0);
  elec.PhiLab = t->PhiLab(0);
  elec.ThetaLab = t->ThetaLab(0);
  elec.Betta = t->Betta(0);
  // evnt (1)
  elec.evnt = evnt;
  // particle (29)
  part.pid = particleID(t->GetCategorization(row, gDataKind, gTargetOption));
  part.vx = t->X(row);
  part.vy = t->Y(row);
  part.vz = t->Z(row);
  part.Sector = t->Sector(row);
  part.deltaZ = t->Z(row) - fVert->Z();
  part.XEC = t->XEC(row);
  part.YEC = t->YEC(row);
  part.ZEC = t->ZEC(row);
  part.Etot = t->Etot(row);
  part.Ein = t->Ein(row);
  part.Eout = t->Eout(row);
  // let's define some auxiliary Double_t
  Double_t fMass = particleMass(part.pid);
  TLorentzVector* fGamma = t->GetCorrPhotonMomentum(row);
  Double_t fPx = (part.pid == 22) * fGamma->Px() + (part.pid != 22) * t->Px(row);
  Double_t fPy = (part.pid == 22) * fGamma->Py() + (part.pid != 22) * t->Py(row);
  Double_t fPz = (part.pid == 22) * fGamma->Pz() + (part.pid != 22) * t->Pz(row);
  Double_t fP = TMath::Sqrt(fPx * fPx + fPy * fPy + fPz * fPz);
  Double_t fE = (part.pid == 22) * fGamma->E() + (part.pid != 22) * TMath::Sqrt(fMass * fMass + fP * fP);
  Double_t fZ = fE / t->Nu();
  // continue...
  part.Px = fPx;
  part.Py = fPy;
  part.Pz = fPz;
  part.P = fP;
  part.PhiLab = PhiLab(fPx, fPy, fPz);
  part.ThetaLab = ThetaLab(fPx, fPy, fPz);
  part.Eh = fE;
  part.Zh = fZ;
  part.ThetaPQ = ThetaPQ(t->Px(0), t->Py(0), t->Pz(0), fPx, fPy, fPz);
  part.PhiPQ = PhiPQ(t->Px(0), t->Py(0), t->Pz(0), fPx, fPy, fPz);
  Double_t fCosThetaPQ = (fPz * (kEbeam - t->Pz(0)) - fPx * t->Px(0) - fPy * t->Py(0)) / (TMath::Sqrt(t->Nu() * t->Nu() + t->Q2()) * fP);
  Double_t fPt2 = fP * fP * (1 - fCosThetaPQ * fCosThetaPQ);
  Double_t fPl2 = fP * fP * fCosThetaPQ * fCosThetaPQ;
  part.Pt2 = fPt2;
  part.Pl2 = fPl2;
  part.Mx2 = t->W() * t->W() + fMass * fMass - 2 * fZ * t->Nu() * t->Nu() + 2 * TMath::Sqrt(fPl2 * (t->Nu() * t->Nu() + t->Q2())) -
             2 * kMassProton * fZ * t->Nu();
  part.T = fMass * fMass - 2 * fZ * t->Nu() * t->Nu() + 2 * TMath::Sqrt(fPl2 * (t->Nu() * t->Nu() + t->Q2())) - t->Q2();
  part.Betta = t->Betta(row);  // BettaMeasured
  part.Mass2 = fP * fP * (TMath::Power(t->Betta(row), -2) - 1);
  part.T4 = t->PathSC(0) / 30. - t->TimeSC(0) + t->TimeSC(row) - (t->PathSC(row) / 30.) * TMath::Sqrt(TMath::Power(fMass / fP, 2) + 1);
}

void SetElectronBranches_GEN(TTree* tree, elec_t& elec) {
  // electron (17 vars)
  tree->Branch("mc_Q2", &elec.Q2);
  tree->Branch("mc_W", &elec.W);
  tree->Branch("mc_Nu", &elec.Nu);
  tree->Branch("mc_Xb", &elec.Xb);
  tree->Branch("mc_Yb", &elec.Yb);
  tree->Branch("mc_Px", &elec.Px);
  tree->Branch("mc_Py", &elec.Py);
  tree->Branch("mc_Pz", &elec.Pz);
  tree->Branch("mc_P", &elec.P);
  tree->Branch("mc_vxe", &elec.vx);
  tree->Branch("mc_vye", &elec.vy);
  tree->Branch("mc_vze", &elec.vz);
  tree->Branch("mc_TargType", &elec.TargType);
  tree->Branch("mc_Sector", &elec.Sector);
  tree->Branch("mc_PhiLab", &elec.PhiLab);
  tree->Branch("mc_ThetaLab", &elec.ThetaLab);
  tree->Branch("mc_Betta", &elec.Betta);
}

void SetParticleBranches_GEN(TTree* tree, elec_t& elec, part_t& part) {
  // gsim electron (17)
  tree->Branch("mc_Q2", &elec.Q2);
  tree->Branch("mc_W", &elec.W);
  tree->Branch("mc_Nu", &elec.Nu);
  tree->Branch("mc_Xb", &elec.Xb);
  tree->Branch("mc_Yb", &elec.Yb);
  tree->Branch("mc_Pex", &elec.Px);
  tree->Branch("mc_Pey", &elec.Py);
  tree->Branch("mc_Pez", &elec.Pz);
  tree->Branch("mc_Pe", &elec.P);
  tree->Branch("mc_vxe", &elec.vx);
  tree->Branch("mc_vye", &elec.vy);
  tree->Branch("mc_vze", &elec.vz);
  tree->Branch("mc_TargType", &elec.TargType);
  tree->Branch("mc_SectorEl", &elec.Sector);
  tree->Branch("mc_PhiLabEl", &elec.PhiLab);
  tree->Branch("mc_ThetaLabEl", &elec.ThetaLab);
  tree->Branch("mc_BettaEl", &elec.Betta);
  // gsim particle (23)
  tree->Branch("mc_Eh", &part.Eh);
  tree->Branch("mc_Zh", &part.Zh);
  tree->Branch("mc_ThetaPQ", &part.ThetaPQ);
  tree->Branch("mc_Pt2", &part.Pt2);
  tree->Branch("mc_Pl2", &part.Pl2);
  tree->Branch("mc_PhiPQ", &part.PhiPQ);
  tree->Branch("mc_Mx2", &part.Mx2);
  tree->Branch("mc_T", &part.T);
  tree->Branch("mc_ThetaLab", &part.ThetaLab);
  tree->Branch("mc_PhiLab", &part.PhiLab);
  tree->Branch("mc_vxh", &part.vx);
  tree->Branch("mc_vyh", &part.vy);
  tree->Branch("mc_vzh", &part.vz);
  tree->Branch("mc_Sector", &part.Sector);
  tree->Branch("mc_Px", &part.Px);
  tree->Branch("mc_Py", &part.Py);
  tree->Branch("mc_Pz", &part.Pz);
  tree->Branch("mc_P", &part.P);
  tree->Branch("mc_Betta", &part.Betta);
  tree->Branch("mc_Mass2", &part.Mass2);
  tree->Branch("mc_deltaZ", &part.deltaZ);
  tree->Branch("mc_pid", &part.pid);
  tree->Branch("mc_ParentID", &part.ParentID);
}

void NullElectronVar_REC(elec_t& elec) {
  // (26 variables)
  elec.Q2 = INVLD;
  elec.W = INVLD;
  elec.Nu = INVLD;
  elec.Xb = INVLD;
  elec.Yb = INVLD;
  elec.Px = INVLD;
  elec.Py = INVLD;
  elec.Pz = INVLD;
  elec.P = INVLD;
  elec.Ein = INVLD;
  elec.Eout = INVLD;
  elec.Etot = INVLD;
  elec.XEC = INVLD;
  elec.YEC = INVLD;
  elec.ZEC = INVLD;
  elec.vx = INVLD;
  elec.vy = INVLD;
  elec.vz = INVLD;
  elec.vxc = INVLD;
  elec.vyc = INVLD;
  elec.vzc = INVLD;
  elec.TargType = INVLD;
  elec.Sector = INVLD;
  elec.PhiLab = INVLD;
  elec.ThetaLab = INVLD;
  elec.Betta = INVLD;
}

void NullParticleVar_REC(elec_t& elec, part_t& part) {
  // electron (26)
  elec.Q2 = INVLD;
  elec.W = INVLD;
  elec.Nu = INVLD;
  elec.Xb = INVLD;
  elec.Yb = INVLD;
  elec.Px = INVLD;
  elec.Py = INVLD;
  elec.Pz = INVLD;
  elec.P = INVLD;
  elec.Ein = INVLD;
  elec.Eout = INVLD;
  elec.Etot = INVLD;
  elec.XEC = INVLD;
  elec.YEC = INVLD;
  elec.ZEC = INVLD;
  elec.vx = INVLD;
  elec.vy = INVLD;
  elec.vz = INVLD;
  elec.vxc = INVLD;
  elec.vyc = INVLD;
  elec.vzc = INVLD;
  elec.TargType = INVLD;
  elec.Sector = INVLD;
  elec.PhiLab = INVLD;
  elec.ThetaLab = INVLD;
  elec.Betta = INVLD;
  // particle (29)
  part.Eh = INVLD;
  part.Zh = INVLD;
  part.ThetaPQ = INVLD;
  part.PhiPQ = INVLD;
  part.Pt2 = INVLD;
  part.Pl2 = INVLD;
  part.Mx2 = INVLD;
  part.T = INVLD;
  part.ThetaLab = INVLD;
  part.PhiLab = INVLD;
  part.T4 = INVLD;
  part.vx = INVLD;
  part.vy = INVLD;
  part.vz = INVLD;
  part.Sector = INVLD;
  part.Px = INVLD;
  part.Py = INVLD;
  part.Pz = INVLD;
  part.P = INVLD;
  part.Betta = INVLD;
  part.Mass2 = INVLD;
  part.Etot = INVLD;
  part.Ein = INVLD;
  part.Eout = INVLD;
  part.XEC = INVLD;
  part.YEC = INVLD;
  part.ZEC = INVLD;
  part.deltaZ = INVLD;
  part.pid = INVLD;
}

void NullElectronVar_GEN(elec_t& elec) {
  // electron (17 variables)
  elec.Q2 = INVLD;
  elec.W = INVLD;
  elec.Nu = INVLD;
  elec.Xb = INVLD;
  elec.Yb = INVLD;
  elec.Px = INVLD;
  elec.Py = INVLD;
  elec.Pz = INVLD;
  elec.P = INVLD;
  elec.vx = INVLD;
  elec.vy = INVLD;
  elec.vz = INVLD;
  elec.TargType = INVLD;
  elec.Sector = INVLD;
  elec.PhiLab = INVLD;
  elec.ThetaLab = INVLD;
  elec.Betta = INVLD;
}

void NullParticleVar_GEN(elec_t& elec, part_t& part) {
  // electron (17 variables)
  elec.Q2 = INVLD;
  elec.W = INVLD;
  elec.Nu = INVLD;
  elec.Xb = INVLD;
  elec.Yb = INVLD;
  elec.Px = INVLD;
  elec.Py = INVLD;
  elec.Pz = INVLD;
  elec.P = INVLD;
  elec.vx = INVLD;
  elec.vy = INVLD;
  elec.vz = INVLD;
  elec.TargType = INVLD;
  elec.Sector = INVLD;
  elec.PhiLab = INVLD;
  elec.ThetaLab = INVLD;
  elec.Betta = INVLD;
  // particle (23 variables)
  part.Eh = INVLD;
  part.Zh = INVLD;
  part.ThetaPQ = INVLD;
  part.Pt2 = INVLD;
  part.Pl2 = INVLD;
  part.PhiPQ = INVLD;
  part.ThetaLab = INVLD;
  part.PhiLab = INVLD;
  part.Mx2 = INVLD;
  part.T = INVLD;
  part.vx = INVLD;
  part.vy = INVLD;
  part.vz = INVLD;
  part.Sector = INVLD;
  part.Px = INVLD;
  part.Py = INVLD;
  part.Pz = INVLD;
  part.P = INVLD;
  part.Betta = INVLD;
  part.Mass2 = INVLD;
  part.deltaZ = INVLD;
  part.pid = INVLD;
  part.ParentID = INVLD;
}

void WriteElectronVar_GEN(TIdentificatorV2* t, elec_t& elec) {
  // electron (17 variables)
  elec.Q2 = t->Q2(1);
  elec.W = t->W(1);
  elec.Nu = t->Nu(1);
  elec.Xb = t->Xb(1);
  elec.Yb = t->Yb(1);
  elec.Px = t->Px(0, 1);
  elec.Py = t->Py(0, 1);
  elec.Pz = t->Pz(0, 1);
  elec.P = t->Momentum(0, 1);
  elec.vx = t->X(0, 1);
  elec.vy = t->Y(0, 1);
  elec.vz = t->Z(0, 1);
  elec.TargType = t->TargType(gDataKind, gTargetOption);
  elec.Sector = t->Sector(0, 1);
  elec.PhiLab = t->PhiLab(0, 1);
  elec.ThetaLab = t->ThetaLab(0, 1);
  elec.Betta = t->Betta(0, 1);
}

void WriteParticleVar_GEN(TIdentificatorV2* t, elec_t& elec, part_t& part, Int_t row) {
  // electron (17 variables)
  elec.Q2 = t->Q2(1);
  elec.W = t->W(1);
  elec.Nu = t->Nu(1);
  elec.Xb = t->Xb(1);
  elec.Yb = t->Yb(1);
  elec.Px = t->Px(0, 1);
  elec.Py = t->Py(0, 1);
  elec.Pz = t->Pz(0, 1);
  elec.P = t->Momentum(0, 1);
  elec.vx = t->X(0, 1);
  elec.vy = t->Y(0, 1);
  elec.vz = t->Z(0, 1);
  elec.TargType = t->TargType(gDataKind, gTargetOption);
  elec.Sector = t->Sector(0, 1);
  elec.PhiLab = t->PhiLab(0, 1);
  elec.ThetaLab = t->ThetaLab(0, 1);
  elec.Betta = t->Betta(0, 1);
  // particle (23 variables)
  part.pid = ToPDG(t->Id(row, 1));  // from GEANT to PDG
  part.ThetaPQ = t->ThetaPQ(row, 1);
  part.PhiPQ = t->PhiPQ(row, 1);
  part.Pt2 = t->Pt2(row, 1);
  part.Pl2 = t->Pl2(row, 1);
  Double_t fMass = particleMass(part.pid);
  Double_t fE = t->Zh(row, 1, fMass) * t->Nu(1);
  part.Zh = t->Zh(row, 1, fMass);
  part.Eh = fE;
  part.Mx2 = t->Mx2(row, 1, fMass);
  part.T = t->T(row, 1, fMass);
  part.ThetaLab = t->ThetaLab(row, 1);
  part.PhiLab = t->PhiLab(row, 1);
  part.vx = t->X(row, 1);
  part.vy = t->Y(row, 1);
  part.vz = t->Z(row, 1);
  part.Sector = t->Sector(row, 1);
  part.Px = t->Px(row, 1);
  part.Py = t->Py(row, 1);
  part.Pz = t->Pz(row, 1);
  part.P = t->Momentum(row, 1);
  part.Betta = t->Betta(row, 1);
  part.Mass2 = t->Mass2(row, 1);
  part.deltaZ = t->Z(row, 1) - t->Z(0, 1);
  part.ParentID = t->Status(row, 1);
}

#endif
