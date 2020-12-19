#include "TIdentificatorV2.h"
#include "GSTtree.h"

#include "Headers.hxx"
#include "Constants.hxx"
#include "Math.hxx"
#include "PDG.hxx"

#ifndef TREEOPS_HXX
#define TREEOPS_HXX

void SetElectronBranches_REC(TTree* tree, rec_e& re) {
  // electron (46)
  tree->Branch("Q2", &re.Q2);
  tree->Branch("W", &re.W);
  tree->Branch("Nu", &re.Nu);
  tree->Branch("Xb", &re.Xb);
  tree->Branch("Yb", &re.Yb);
  tree->Branch("vxe", &re.vxe);
  tree->Branch("vye", &re.vye);
  tree->Branch("vze", &re.vze);
  tree->Branch("Sector", &re.Sector);
  tree->Branch("TargType", &re.TargType);
  tree->Branch("Px", &re.Px);
  tree->Branch("Py", &re.Py);
  tree->Branch("Pz", &re.Pz);
  tree->Branch("P", &re.P);
  tree->Branch("Betta", &re.Betta);
  tree->Branch("Etot", &re.Etot);
  tree->Branch("Ein", &re.Ein);
  tree->Branch("Eout", &re.Eout);
  tree->Branch("vxec", &re.vxec);
  tree->Branch("vyec", &re.vyec);
  tree->Branch("vzec", &re.vzec);
  tree->Branch("XEC", &re.XEC);
  tree->Branch("YEC", &re.YEC);
  tree->Branch("ZEC", &re.ZEC);
  tree->Branch("PhiLab", &re.PhiLab);
  tree->Branch("ThetaLab", &re.ThetaLab);
  tree->Branch("StatDC", &re.StatDC);
  tree->Branch("DCStatus", &re.DCStatus);
  tree->Branch("StatEC", &re.StatEC);
  tree->Branch("ECStatus", &re.ECStatus);
  tree->Branch("TimeEC", &re.TimeEC);
  tree->Branch("PathEC", &re.PathEC);
  tree->Branch("Chi2EC", &re.Chi2EC);
  tree->Branch("StatSC", &re.StatSC);
  tree->Branch("SCStatus", &re.SCStatus);
  tree->Branch("TimeSC", &re.TimeSC);
  tree->Branch("PathSC", &re.PathSC);
  tree->Branch("StatCC", &re.StatCC);
  tree->Branch("CCStatus", &re.CCStatus);
  tree->Branch("Nphe", &re.Nphe);
  tree->Branch("Chi2CC", &re.Chi2CC);
  tree->Branch("Status", &re.Status);
  tree->Branch("NRowsDC", &re.NRowsDC);
  tree->Branch("NRowsEC", &re.NRowsEC);
  tree->Branch("NRowsSC", &re.NRowsSC);
  tree->Branch("NRowsCC", &re.NRowsCC);
  // event (1)
  tree->Branch("evnt", &re.evnt);
}

void SetParticleBranches_REC(TTree* tree, rec_p& rp) {
  // electron (46)
  tree->Branch("Q2", &rp.Q2);
  tree->Branch("W", &rp.W);
  tree->Branch("Nu", &rp.Nu);
  tree->Branch("Xb", &rp.Xb);
  tree->Branch("Yb", &rp.Yb);
  tree->Branch("vxe", &rp.vxe);
  tree->Branch("vye", &rp.vye);
  tree->Branch("vze", &rp.vze);
  tree->Branch("SectorEl", &rp.SectorEl);
  tree->Branch("TargType", &rp.TargType);
  tree->Branch("Pex", &rp.Pex);
  tree->Branch("Pey", &rp.Pey);
  tree->Branch("Pez", &rp.Pez);
  tree->Branch("Pe", &rp.Pe);
  tree->Branch("BettaEl", &rp.BettaEl);
  tree->Branch("Etote", &rp.Etote);
  tree->Branch("Eine", &rp.Eine);
  tree->Branch("Eoute", &rp.Eoute);
  tree->Branch("vxec", &rp.vxec);
  tree->Branch("vyec", &rp.vyec);
  tree->Branch("vzec", &rp.vzec);
  tree->Branch("XECe", &rp.XECe);
  tree->Branch("YECe", &rp.YECe);
  tree->Branch("ZECe", &rp.ZECe);
  tree->Branch("PhiLabEl", &rp.PhiLabEl);
  tree->Branch("ThetaLabEl", &rp.ThetaLabEl);
  tree->Branch("StatDCEl", &rp.StatDCEl);
  tree->Branch("DCStatusEl", &rp.DCStatusEl);
  tree->Branch("StatECEl", &rp.StatECEl);
  tree->Branch("ECStatusEl", &rp.ECStatusEl);
  tree->Branch("TimeECEl", &rp.TimeECEl);
  tree->Branch("PathECEl", &rp.PathECEl);
  tree->Branch("Chi2ECEl", &rp.Chi2ECEl);
  tree->Branch("StatSCEl", &rp.StatSCEl);
  tree->Branch("SCStatusEl", &rp.SCStatusEl);
  tree->Branch("TimeSCEl", &rp.TimeSCEl);
  tree->Branch("PathSCEl", &rp.PathSCEl);
  tree->Branch("StatCCEl", &rp.StatCCEl);
  tree->Branch("CCStatusEl", &rp.CCStatusEl);
  tree->Branch("NpheEl", &rp.NpheEl);
  tree->Branch("Chi2CCEl", &rp.Chi2CCEl);
  tree->Branch("StatusEl", &rp.StatusEl);
  tree->Branch("NRowsDCEl", &rp.NRowsDCEl);
  tree->Branch("NRowsECEl", &rp.NRowsECEl);
  tree->Branch("NRowsSCEl", &rp.NRowsSCEl);
  tree->Branch("NRowsCCEl", &rp.NRowsCCEl);
  // particle (49)
  tree->Branch("Eh", &rp.Eh);
  tree->Branch("Zh", &rp.Zh);
  tree->Branch("ThetaPQ", &rp.ThetaPQ);
  tree->Branch("Pt2", &rp.Pt2);
  tree->Branch("Pl2", &rp.Pl2);
  tree->Branch("PhiPQ", &rp.PhiPQ);
  tree->Branch("Mx2", &rp.Mx2);
  tree->Branch("T", &rp.T);
  tree->Branch("PhiLab", &rp.PhiLab);
  tree->Branch("ThetaLab", &rp.ThetaLab);
  tree->Branch("vxh", &rp.vxh);
  tree->Branch("vyh", &rp.vyh);
  tree->Branch("vzh", &rp.vzh);
  tree->Branch("Sector", &rp.Sector);
  tree->Branch("Px", &rp.Px);
  tree->Branch("Py", &rp.Py);
  tree->Branch("Pz", &rp.Pz);
  tree->Branch("P", &rp.P);
  tree->Branch("Betta", &rp.Betta);
  tree->Branch("Mass2", &rp.Mass2);
  tree->Branch("Etot", &rp.Etot);
  tree->Branch("Ein", &rp.Ein);
  tree->Branch("Eout", &rp.Eout);
  tree->Branch("XEC", &rp.XEC);
  tree->Branch("YEC", &rp.YEC);
  tree->Branch("ZEC", &rp.ZEC);
  tree->Branch("pid", &rp.pid);
  tree->Branch("T4", &rp.T4);
  tree->Branch("deltaZ", &rp.deltaZ);
  tree->Branch("StatDC", &rp.StatDC);
  tree->Branch("DCStatus", &rp.DCStatus);
  tree->Branch("StatEC", &rp.StatEC);
  tree->Branch("ECStatus", &rp.ECStatus);
  tree->Branch("TimeEC", &rp.TimeEC);
  tree->Branch("PathEC", &rp.PathEC);
  tree->Branch("Chi2EC", &rp.Chi2EC);
  tree->Branch("StatSC", &rp.StatSC);
  tree->Branch("SCStatus", &rp.SCStatus);
  tree->Branch("TimeSC", &rp.TimeSC);
  tree->Branch("PathSC", &rp.PathSC);
  tree->Branch("StatCC", &rp.StatCC);
  tree->Branch("CCStatus", &rp.CCStatus);
  tree->Branch("Nphe", &rp.Nphe);
  tree->Branch("Chi2CC", &rp.Chi2CC);
  tree->Branch("Status", &rp.Status);
  tree->Branch("NRowsDC", &rp.NRowsDC);
  tree->Branch("NRowsEC", &rp.NRowsEC);
  tree->Branch("NRowsSC", &rp.NRowsSC);
  tree->Branch("NRowsCC", &rp.NRowsCC);
  // event (1)
  tree->Branch("evnt", &rp.evnt);
}


void SetElectronBranches_GEN(TTree* tree, gen_e& ge) {
  // gsim (17)
  tree->Branch("mc_Q2", &ge.mc_Q2);
  tree->Branch("mc_W", &ge.mc_W);
  tree->Branch("mc_Nu", &ge.mc_Nu);
  tree->Branch("mc_Xb", &ge.mc_Xb);
  tree->Branch("mc_Yb", &ge.mc_Yb);
  tree->Branch("mc_vxe", &ge.mc_vxe);
  tree->Branch("mc_vye", &ge.mc_vye);
  tree->Branch("mc_vze", &ge.mc_vze);
  tree->Branch("mc_Sector", &ge.mc_Sector);
  tree->Branch("mc_TargType", &ge.mc_TargType);
  tree->Branch("mc_Px", &ge.mc_Px);
  tree->Branch("mc_Py", &ge.mc_Py);
  tree->Branch("mc_Pz", &ge.mc_Pz);
  tree->Branch("mc_P", &ge.mc_P);
  tree->Branch("mc_Betta", &ge.mc_Betta);
  tree->Branch("mc_ThetaLab", &ge.mc_ThetaLab);
  tree->Branch("mc_PhiLab", &ge.mc_PhiLab);
}

void SetParticleBranches_GEN(TTree* tree, gen_p& gp) {
  // gsim electron (17)
  tree->Branch("mc_Q2", &gp.mc_Q2);
  tree->Branch("mc_W", &gp.mc_W);
  tree->Branch("mc_Nu", &gp.mc_Nu);
  tree->Branch("mc_Xb", &gp.mc_Xb);
  tree->Branch("mc_Yb", &gp.mc_Yb);
  tree->Branch("mc_vxe", &gp.mc_vxe);
  tree->Branch("mc_vye", &gp.mc_vye);
  tree->Branch("mc_vze", &gp.mc_vze);
  tree->Branch("mc_SectorEl", &gp.mc_SectorEl);
  tree->Branch("mc_TargType", &gp.mc_TargType);
  tree->Branch("mc_Pex", &gp.mc_Pex);
  tree->Branch("mc_Pey", &gp.mc_Pey);
  tree->Branch("mc_Pez", &gp.mc_Pez);
  tree->Branch("mc_Pe", &gp.mc_Pe);
  tree->Branch("mc_BettaEl", &gp.mc_BettaEl);
  tree->Branch("mc_ThetaLabEl", &gp.mc_ThetaLabEl);
  tree->Branch("mc_PhiLabEl", &gp.mc_PhiLabEl);
  // gsim particle (22)
  tree->Branch("mc_Eh", &gp.mc_Eh);
  tree->Branch("mc_Zh", &gp.mc_Zh);
  tree->Branch("mc_ThetaPQ", &gp.mc_ThetaPQ);
  tree->Branch("mc_Pt2", &gp.mc_Pt2);
  tree->Branch("mc_Pl2", &gp.mc_Pl2);
  tree->Branch("mc_PhiPQ", &gp.mc_PhiPQ);
  tree->Branch("mc_Mx2", &gp.mc_Mx2);
  tree->Branch("mc_T", &gp.mc_T);
  tree->Branch("mc_ThetaLab", &gp.mc_ThetaLab);
  tree->Branch("mc_PhiLab", &gp.mc_PhiLab);
  tree->Branch("mc_vxh", &gp.mc_vxh);
  tree->Branch("mc_vyh", &gp.mc_vyh);
  tree->Branch("mc_vzh", &gp.mc_vzh);
  tree->Branch("mc_Sector", &gp.mc_Sector);
  tree->Branch("mc_Px", &gp.mc_Px);
  tree->Branch("mc_Py", &gp.mc_Py);
  tree->Branch("mc_Pz", &gp.mc_Pz);
  tree->Branch("mc_P", &gp.mc_P);
  tree->Branch("mc_Betta", &gp.mc_Betta);
  tree->Branch("mc_Mass2", &gp.mc_Mass2);
  tree->Branch("mc_pid", &gp.mc_pid);
  tree->Branch("mc_deltaZ", &gp.mc_deltaZ);
}

void AssignElectronVar_REC(TIdentificatorV2* t, rec_e& re, Int_t evnt, TString dataKind, TString targetOption) {
  // electron (46)
  re.Q2 = t->Q2();
  re.W = t->W();
  re.Nu = t->Nu();
  re.Xb = t->Xb();
  re.Yb = t->Yb();
  re.vxe = t->X(0);
  re.vye = t->Y(0);
  re.vze = t->Z(0);
  re.Sector = t->Sector(0);
  re.Px = t->Px(0);
  re.Py = t->Py(0);
  re.Pz = t->Pz(0);
  re.P = t->Momentum(0);
  re.Betta = t->Betta(0);
  re.Etot = t->Etot(0);
  re.Ein = t->Ein(0);
  re.Eout = t->Eout(0);
  TVector3* fVert = t->GetCorrectedVert();
  re.vxec = fVert->X();
  re.vyec = fVert->Y();
  re.vzec = fVert->Z();
  re.TargType = t->TargTypeSM(dataKind, targetOption, 0);
  re.XEC = t->XEC(0);
  re.YEC = t->YEC(0);
  re.ZEC = t->ZEC(0);
  re.PhiLab = t->PhiLab(0);
  re.ThetaLab = t->ThetaLab(0);
  re.StatDC = t->StatDC(0);
  re.DCStatus = t->DCStatus(0);
  re.StatEC = t->StatEC(0);
  re.ECStatus = t->ECStatus(0);
  re.TimeEC = t->TimeEC(0);
  re.PathEC = t->PathEC(0);
  re.Chi2EC = t->Chi2EC(0);
  re.StatSC = t->StatSC(0);
  re.SCStatus = t->SCStatus(0);
  re.TimeSC = t->TimeSC(0);
  re.PathSC = t->PathSC(0);
  re.StatCC = t->StatCC(0);
  re.CCStatus = t->CCStatus(0);
  re.Nphe = t->Nphe(0);
  re.Chi2CC = t->Chi2CC(0);
  re.Status = t->Status(0);
  re.NRowsDC = t->NRowsDC();
  re.NRowsEC = t->NRowsEC();
  re.NRowsSC = t->NRowsSC();
  re.NRowsCC = t->NRowsCC();
  // evnt (1)
  re.evnt = evnt;
}

void AssignParticleVar_REC(TIdentificatorV2* t, rec_p& rp, Int_t row, Int_t evnt, TString dataKind, TString targetOption) {
  // electron (46)
  rp.Q2 = t->Q2();
  rp.W = t->W();
  rp.Nu = t->Nu();
  rp.Xb = t->Xb();
  rp.Yb = t->Yb();
  rp.vxe = t->X(0);
  rp.vye = t->Y(0);
  rp.vze = t->Z(0);
  rp.SectorEl = t->Sector(0);
  rp.Pex = t->Px(0);
  rp.Pey = t->Py(0);
  rp.Pez = t->Pz(0);
  rp.Pe = t->Momentum(0);
  rp.BettaEl = t->Betta(0);
  rp.Etote = t->Etot(0);
  rp.Eine = t->Ein(0);
  rp.Eoute = t->Eout(0);
  TVector3* fVert = t->GetCorrectedVert();
  rp.vxec = fVert->X();
  rp.vyec = fVert->Y();
  rp.vzec = fVert->Z();
  rp.TargType = t->TargTypeSM(dataKind, targetOption, 0);
  rp.XECe = t->XEC(0);
  rp.YECe = t->YEC(0);
  rp.ZECe = t->ZEC(0);
  rp.PhiLabEl = t->PhiLab(0);
  rp.ThetaLabEl = t->ThetaLab(0);
  rp.StatDCEl = t->StatDC(0);
  rp.DCStatusEl = t->DCStatus(0);
  rp.StatECEl = t->StatEC(0);
  rp.ECStatusEl = t->ECStatus(0);
  rp.TimeECEl = t->TimeEC(0);
  rp.PathECEl = t->PathEC(0);
  rp.Chi2ECEl = t->Chi2EC(0);
  rp.StatSCEl = t->StatSC(0);
  rp.SCStatusEl = t->SCStatus(0);
  rp.TimeSCEl = t->TimeSC(0);
  rp.PathSCEl = t->PathSC(0);
  rp.StatCCEl = t->StatCC(0);
  rp.CCStatusEl = t->CCStatus(0);
  rp.NpheEl = t->Nphe(0);
  rp.Chi2CCEl = t->Chi2CC(0);
  rp.StatusEl = t->Status(0);
  rp.NRowsDCEl = t->NRowsDC();
  rp.NRowsECEl = t->NRowsEC();
  rp.NRowsSCEl = t->NRowsSC();
  rp.NRowsCCEl = t->NRowsCC();
  // particle (49)
  rp.pid = particleID(t->GetCategorization(row, dataKind, targetOption));
  rp.vxh = t->X(row);
  rp.vyh = t->Y(row);
  rp.vzh = t->Z(row);
  rp.Sector = t->Sector(row);
  rp.deltaZ = t->Z(row) - fVert->Z();
  rp.XEC = t->XEC(row);
  rp.YEC = t->YEC(row);
  rp.ZEC = t->ZEC(row);
  rp.Etot = t->Etot(row);
  rp.Ein = t->Ein(row);
  rp.Eout = t->Eout(row);
  // let's define some auxiliary Double_t
  Double_t fMass = particleMass(rp.pid);
  TLorentzVector* fGamma = t->GetCorrPhotonMomentum(row);
  Double_t fPx = (rp.pid == 22) * fGamma->Px() + (rp.pid != 22) * t->Px(row);
  Double_t fPy = (rp.pid == 22) * fGamma->Py() + (rp.pid != 22) * t->Py(row);
  Double_t fPz = (rp.pid == 22) * fGamma->Pz() + (rp.pid != 22) * t->Pz(row);
  Double_t fP = TMath::Sqrt(fPx * fPx + fPy * fPy + fPz * fPz);
  Double_t fE = (rp.pid == 22) * fGamma->E() + (rp.pid != 22) * TMath::Sqrt(fMass * fMass + fP * fP);
  Double_t fZ = fE / t->Nu();
  // continue...
  rp.Px = fPx;
  rp.Py = fPy;
  rp.Pz = fPz;
  rp.P = fP;
  rp.PhiLab = PhiLab(fPx, fPy, fPz);
  rp.ThetaLab = ThetaLab(fPx, fPy, fPz);
  rp.Eh = fE;
  rp.Zh = fZ;
  rp.ThetaPQ = ThetaPQ(t->Px(0), t->Py(0), t->Pz(0), fPx, fPy, fPz);
  rp.PhiPQ = PhiPQ(t->Px(0), t->Py(0), t->Pz(0), fPx, fPy, fPz);
  Double_t fCosThetaPQ = (fPz * (kEbeam - t->Pz(0)) - fPx * t->Px(0) - fPy * t->Py(0)) / (TMath::Sqrt(t->Nu() * t->Nu() + t->Q2()) * fP);
  Double_t fPt2 = fP * fP * (1 - fCosThetaPQ * fCosThetaPQ);
  Double_t fPl2 = fP * fP * fCosThetaPQ * fCosThetaPQ;
  rp.Pt2 = fPt2;
  rp.Pl2 = fPl2;
  rp.Mx2 = t->W() * t->W() + fMass * fMass - 2 * fZ * t->Nu() * t->Nu() + 2 * TMath::Sqrt(fPl2 * (t->Nu() * t->Nu() + t->Q2())) - 2 * kMassProton * fZ * t->Nu();
  rp.T = fMass * fMass - 2 * fZ * t->Nu() * t->Nu() + 2 * TMath::Sqrt(fPl2 * (t->Nu() * t->Nu() + t->Q2())) - t->Q2();
  rp.Betta = t->Betta(row);  // BettaMeasured
  rp.Mass2 = fP * fP * (TMath::Power(t->Betta(row), -2) - 1);
  rp.T4 = t->PathSC(0) / 30. - t->TimeSC(0) + t->TimeSC(row) - (t->PathSC(row) / 30.) * TMath::Sqrt(TMath::Power(fMass / fP, 2) + 1);
  // status
  rp.StatDC = t->StatDC(row);
  rp.DCStatus = t->DCStatus(row);
  rp.StatEC = t->StatEC(row);
  rp.ECStatus = t->ECStatus(row);
  rp.TimeEC = t->TimeEC(row);
  rp.PathEC = t->PathEC(row);
  rp.Chi2EC = t->Chi2EC(row);
  rp.StatSC = t->StatSC(row);
  rp.SCStatus = t->SCStatus(row);
  rp.TimeSC = t->TimeSC(row);
  rp.PathSC = t->PathSC(row);
  rp.StatCC = t->StatCC(row);
  rp.CCStatus = t->CCStatus(row);
  rp.Nphe = t->Nphe(row);
  rp.Chi2CC = t->Chi2CC(row);
  rp.Status = t->Status(row);
  rp.NRowsDC = t->NRowsDC();
  rp.NRowsEC = t->NRowsEC();
  rp.NRowsSC = t->NRowsSC();
  rp.NRowsCC = t->NRowsCC();
  // evnt (1)
  rp.evnt = evnt;
}

void AssignElectronVar_GEN(TIdentificatorV2* t, gen_e& ge, Int_t evnt, TString dataKind, TString targetOption) {
  // gsim (17)
  ge.mc_Q2 = t->Q2(1);
  ge.mc_W = t->W(1);
  ge.mc_Nu = t->Nu(1);
  ge.mc_Xb = t->Xb(1);
  ge.mc_Yb = t->Yb(1);
  ge.mc_vxe = t->X(0, 1);
  ge.mc_vye = t->Y(0, 1);
  ge.mc_vze = t->Z(0, 1);
  ge.mc_Sector = t->Sector(0, 1);
  ge.mc_Px = t->Px(0, 1);
  ge.mc_Py = t->Py(0, 1);
  ge.mc_Pz = t->Pz(0, 1);
  ge.mc_P = t->Momentum(0, 1);
  ge.mc_Betta = t->Betta(0, 1);
  ge.mc_ThetaLab = t->ThetaLab(0, 1);
  ge.mc_PhiLab = t->PhiLab(0, 1);
  ge.mc_TargType = t->TargTypeSM(dataKind, targetOption, 1);
}

void AssignParticleVar_GEN(TIdentificatorV2* t, gen_p& gp, Int_t row, Int_t evnt, TString dataKind, TString targetOption) {
  // gsim electron (17)
  gp.mc_Q2 = t->Q2(1);
  gp.mc_W = t->W(1);
  gp.mc_Nu = t->Nu(1);
  gp.mc_Xb = t->Xb(1);
  gp.mc_Yb = t->Yb(1);
  gp.mc_vxe = t->X(0, 1);
  gp.mc_vye = t->Y(0, 1);
  gp.mc_vze = t->Z(0, 1);
  gp.mc_SectorEl = t->Sector(0, 1);
  gp.mc_Pex = t->Px(0, 1);
  gp.mc_Pey = t->Py(0, 1);
  gp.mc_Pez = t->Pz(0, 1);
  gp.mc_Pe = t->Momentum(0, 1);
  gp.mc_BettaEl = t->Betta(0, 1);
  gp.mc_ThetaLabEl = t->ThetaLab(0, 1);
  gp.mc_PhiLabEl = t->PhiLab(0, 1);
  gp.mc_TargType = t->TargTypeSM(dataKind, targetOption, 1);
  // gsim particle (22)
  gp.mc_pid = ToPDG(t->Id(row, 1));  // from GEANT to PDG
  gp.mc_ThetaPQ = t->ThetaPQ(row, 1);
  gp.mc_PhiPQ = t->PhiPQ(row, 1);
  gp.mc_Pt2 = t->Pt2(row, 1);
  gp.mc_Pl2 = t->Pl2(row, 1);
  Double_t fMass = particleMass(gp.mc_pid);
  Double_t fE = t->Zh(row, 1, fMass) * t->Nu(1);
  gp.mc_Zh = t->Zh(row, 1, fMass);
  gp.mc_Eh = fE;
  gp.mc_Mx2 = t->Mx2(row, 1, fMass);
  gp.mc_T = t->T(row, 1, fMass);
  gp.mc_ThetaLab = t->ThetaLab(row, 1);
  gp.mc_PhiLab = t->PhiLab(row, 1);
  gp.mc_vxh = t->X(row, 1);
  gp.mc_vyh = t->Y(row, 1);
  gp.mc_vzh = t->Z(row, 1);
  gp.mc_Sector = t->Sector(row, 1);
  gp.mc_Px = t->Px(row, 1);
  gp.mc_Py = t->Py(row, 1);
  gp.mc_Pz = t->Pz(row, 1);
  gp.mc_P = t->Momentum(row, 1);
  gp.mc_Betta = t->Betta(row, 1);
  gp.mc_Mass2 = t->Mass2(row, 1);
  gp.mc_deltaZ = t->Z(row, 1) - t->Z(0, 1);
}

void NullElectronVar_REC(rec_e& re) {
  // (46 variables)
  re.Q2 = INVLD;
  re.W = INVLD;
  re.Nu = INVLD;
  re.Xb = INVLD;
  re.Yb = INVLD;
  re.vxe = INVLD;
  re.vye = INVLD;
  re.vze = INVLD;
  re.Sector = INVLD;
  re.Px = INVLD;
  re.Py = INVLD;
  re.Pz = INVLD;
  re.P = INVLD;
  re.Betta = INVLD;
  re.Etot = INVLD;
  re.Ein = INVLD;
  re.Eout = INVLD;
  re.vxec = INVLD;
  re.vyec = INVLD;
  re.vzec = INVLD;
  re.TargType = INVLD;
  re.XEC = INVLD;
  re.YEC = INVLD;
  re.ZEC = INVLD;
  re.ThetaLab = INVLD;
  re.PhiLab = INVLD;
  re.StatDC = INVLD;
  re.DCStatus = INVLD;
  re.StatEC = INVLD;
  re.ECStatus = INVLD;
  re.TimeEC = INVLD;
  re.PathEC = INVLD;
  re.Chi2EC = INVLD;
  re.StatSC = INVLD;
  re.SCStatus = INVLD;
  re.TimeSC = INVLD;
  re.PathSC = INVLD;
  re.StatCC = INVLD;
  re.CCStatus = INVLD;
  re.Nphe = INVLD;
  re.Chi2CC = INVLD;
  re.Status = INVLD;
  re.NRowsDC = INVLD;
  re.NRowsEC = INVLD;
  re.NRowsSC = INVLD;
  re.NRowsCC = INVLD;
}

void NullParticleVar_REC(rec_p& rp) {
  // electron (46)
  rp.Q2 = INVLD;
  rp.W = INVLD;
  rp.Nu = INVLD;
  rp.Xb = INVLD;
  rp.Yb = INVLD;
  rp.vxe = INVLD;
  rp.vye = INVLD;
  rp.vze = INVLD;
  rp.SectorEl = INVLD;
  rp.Pex = INVLD;
  rp.Pey = INVLD;
  rp.Pez = INVLD;
  rp.Pe = INVLD;
  rp.BettaEl = INVLD;
  rp.Etote = INVLD;
  rp.Eine = INVLD;
  rp.Eoute = INVLD;
  rp.vxec = INVLD;
  rp.vyec = INVLD;
  rp.vzec = INVLD;
  rp.TargType = INVLD;
  rp.XECe = INVLD;
  rp.YECe = INVLD;
  rp.ZECe = INVLD;
  rp.ThetaLabEl = INVLD;
  rp.PhiLabEl = INVLD;
  rp.StatDCEl = INVLD;
  rp.DCStatusEl = INVLD;
  rp.StatECEl = INVLD;
  rp.ECStatusEl = INVLD;
  rp.TimeECEl = INVLD;
  rp.PathECEl = INVLD;
  rp.Chi2ECEl = INVLD;
  rp.StatSCEl = INVLD;
  rp.SCStatusEl = INVLD;
  rp.TimeSCEl = INVLD;
  rp.PathSCEl = INVLD;
  rp.StatCCEl = INVLD;
  rp.CCStatusEl = INVLD;
  rp.NpheEl = INVLD;
  rp.Chi2CCEl = INVLD;
  rp.StatusEl = INVLD;
  rp.NRowsDCEl = INVLD;
  rp.NRowsECEl = INVLD;
  rp.NRowsSCEl = INVLD;
  rp.NRowsCCEl = INVLD;
  // particle (49)
  rp.pid = INVLD;
  rp.Eh = INVLD;
  rp.Zh = INVLD;
  rp.ThetaPQ = INVLD;
  rp.PhiPQ = INVLD;
  rp.Pt2 = INVLD;
  rp.Pl2 = INVLD;
  rp.Mx2 = INVLD;
  rp.T = INVLD;
  rp.ThetaLab = INVLD;
  rp.PhiLab = INVLD;
  rp.T4 = INVLD;
  rp.vxh = INVLD;
  rp.vyh = INVLD;
  rp.vzh = INVLD;
  rp.Sector = INVLD;
  rp.Px = INVLD;
  rp.Py = INVLD;
  rp.Pz = INVLD;
  rp.P = INVLD;
  rp.Betta = INVLD;
  rp.Mass2 = INVLD;
  rp.Etot = INVLD;
  rp.Ein = INVLD;
  rp.Eout = INVLD;
  rp.XEC = INVLD;
  rp.YEC = INVLD;
  rp.ZEC = INVLD;
  rp.deltaZ = INVLD;
  rp.StatDC = INVLD;
  rp.DCStatus = INVLD;
  rp.StatEC = INVLD;
  rp.ECStatus = INVLD;
  rp.TimeEC = INVLD;
  rp.PathEC = INVLD;
  rp.Chi2EC = INVLD;
  rp.StatSC = INVLD;
  rp.SCStatus = INVLD;
  rp.TimeSC = INVLD;
  rp.PathSC = INVLD;
  rp.StatCC = INVLD;
  rp.CCStatus = INVLD;
  rp.Nphe = INVLD;
  rp.Chi2CC = INVLD;
  rp.Status = INVLD;
  rp.NRowsDC = INVLD;
  rp.NRowsEC = INVLD;
  rp.NRowsSC = INVLD;
  rp.NRowsCC = INVLD;
}

void NullElectronVar_GEN(gen_e& ge) {
  // (17 variables)
  ge.mc_Q2 = INVLD;
  ge.mc_W = INVLD;
  ge.mc_Nu = INVLD;
  ge.mc_Xb = INVLD;
  ge.mc_Yb = INVLD;
  ge.mc_vxe = INVLD;
  ge.mc_vye = INVLD;
  ge.mc_vze = INVLD;
  ge.mc_Sector = INVLD;
  ge.mc_TargType = INVLD;
  ge.mc_Px = INVLD;
  ge.mc_Py = INVLD;
  ge.mc_Pz = INVLD;
  ge.mc_P = INVLD;
  ge.mc_Betta = INVLD;
  ge.mc_ThetaLab = INVLD;
  ge.mc_PhiLab = INVLD;
}

void NullParticleVar_GEN(gen_p& gp) {
  // gsim electron (17)
  gp.mc_Q2 = INVLD;
  gp.mc_W = INVLD;
  gp.mc_Nu = INVLD;
  gp.mc_Xb = INVLD;
  gp.mc_Yb = INVLD;
  gp.mc_vxe = INVLD;
  gp.mc_vye = INVLD;
  gp.mc_vze = INVLD;
  gp.mc_SectorEl = INVLD;
  gp.mc_TargType = INVLD;
  gp.mc_Pex = INVLD;
  gp.mc_Pey = INVLD;
  gp.mc_Pez = INVLD;
  gp.mc_Pe = INVLD;
  gp.mc_BettaEl = INVLD;
  gp.mc_ThetaLabEl = INVLD;
  gp.mc_PhiLabEl = INVLD;
  // gsim particle (22)
  gp.mc_Eh = INVLD;
  gp.mc_Zh = INVLD;
  gp.mc_ThetaPQ = INVLD;
  gp.mc_Pt2 = INVLD;
  gp.mc_Pl2 = INVLD;
  gp.mc_PhiPQ = INVLD;
  gp.mc_ThetaLab = INVLD;
  gp.mc_PhiLab = INVLD;
  gp.mc_Mx2 = INVLD;
  gp.mc_T = INVLD;
  gp.mc_vxh = INVLD;
  gp.mc_vyh = INVLD;
  gp.mc_vzh = INVLD;
  gp.mc_Sector = INVLD;
  gp.mc_Px = INVLD;
  gp.mc_Py = INVLD;
  gp.mc_Pz = INVLD;
  gp.mc_P = INVLD;
  gp.mc_Betta = INVLD;
  gp.mc_Mass2 = INVLD;
  gp.mc_deltaZ = INVLD;
  gp.mc_pid = INVLD;
}

#endif
