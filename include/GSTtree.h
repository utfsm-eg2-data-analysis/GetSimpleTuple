#ifndef __GSTTREE__H
#define __GSTTREE__H

/*
   NAMING CONVENTIONS

   data_e : electron variables for data
   data_p : particle variables for data

   sim_e   : electron variables for simulations
   sim_p   : particle variables for simulations
*/

struct data_e {
  // (47 variables)
  // electron (46)
  Double_t Q2, W, Nu, Xb, Yb;
  Double_t vxe, vye, vze;
  Double_t Sector;
  Double_t Px, Py, Pz, P;
  Double_t Betta, Etot, Ein, Eout;
  Double_t vxec, vyec, vzec;
  Double_t TargType;
  Double_t XEC, YEC, ZEC;
  Double_t ThetaLab, PhiLab;
  Double_t StatDC, DCStatus, StatEC, ECStatus, TimeEC, PathEC, Chi2EC, StatSC, SCStatus, TimeSC, PathSC, StatCC, CCStatus, Nphe, Chi2CC, Status;
  Double_t NRowsDC, NRowsEC, NRowsSC, NRowsCC;
  // evnt (1)
  Double_t evnt;
};

struct data_p {
  // (96 variables)
  // electron (46)
  Double_t Q2, W, Nu, Xb, Yb;
  Double_t vxe, vye, vze;
  Double_t SectorEl;
  Double_t Pex, Pey, Pez, Pe;
  Double_t BettaEl, Etote, Eine, Eoute;
  Double_t vxec, vyec, vzec;
  Double_t TargType;
  Double_t XECe, YECe, ZECe;
  Double_t ThetaLabEl, PhiLabEl;
  Double_t StatDCEl, DCStatusEl, StatECEl, ECStatusEl, TimeECEl, PathECEl, Chi2ECEl, StatSCEl, SCStatusEl, TimeSCEl, PathSCEl, StatCCEl, CCStatusEl, NpheEl, Chi2CCEl, StatusEl;
  Double_t NRowsDCEl, NRowsECEl, NRowsSCEl, NRowsCCEl;
  // particle (49)
  Double_t Eh, Zh, ThetaPQ, Pt2, Pl2, PhiPQ, Mx2, T;
  Double_t ThetaLab, PhiLab;
  Double_t vxh, vyh, vzh;
  Double_t Sector;
  Double_t Px, Py, Pz, P;
  Double_t Betta, Mass2, Etot, Ein, Eout;
  Double_t XEC, YEC, ZEC;
  Double_t pid, T4, deltaZ;
  Double_t StatDC, DCStatus, StatEC, ECStatus, TimeEC, PathEC, Chi2EC, StatSC, SCStatus, TimeSC, PathSC, StatCC, CCStatus, Nphe, Chi2CC, Status;
  Double_t NRowsDC, NRowsEC, NRowsSC, NRowsCC;
  // event (1)
  Double_t evnt;
};

struct sim_e {
  // (64 variables)
  // simrec (46)
  Double_t Q2, W, Nu, Xb, Yb;
  Double_t vxe, vye, vze;
  Double_t Sector;
  Double_t TargType;
  Double_t Px, Py, Pz, P;
  Double_t Betta, Etot, Ein, Eout;
  Double_t vxec, vyec, vzec;
  Double_t XEC, YEC, ZEC;
  Double_t ThetaLab, PhiLab;
  Double_t StatDC, DCStatus, StatEC, ECStatus, TimeEC, PathEC, Chi2EC, StatSC, SCStatus, TimeSC, PathSC, StatCC, CCStatus, Nphe, Chi2CC, Status;
  Double_t NRowsDC, NRowsEC, NRowsSC, NRowsCC;
  // event (1)
  Double_t evnt;
  // gsim (17)
  Double_t mc_Q2, mc_W, mc_Nu, mc_Xb, mc_Yb;
  Double_t mc_vxe, mc_vye, mc_vze;
  Double_t mc_Sector;
  Double_t mc_TargType;
  Double_t mc_Px, mc_Py, mc_Pz, mc_P;
  Double_t mc_Betta;
  Double_t mc_ThetaLab, mc_PhiLab;
};

struct sim_p {
  // (135 variables)
  // simrec electron (46)
  Double_t Q2, W, Nu, Xb, Yb;
  Double_t vxe, vye, vze;
  Double_t SectorEl, TargType;
  Double_t Pex, Pey, Pez, Pe;
  Double_t BettaEl, Etote, Eine, Eoute;
  Double_t vxec, vyec, vzec;
  Double_t XECe, YECe, ZECe;
  Double_t ThetaLabEl, PhiLabEl;
  Double_t StatDCEl, DCStatusEl, StatECEl, ECStatusEl, TimeECEl, PathECEl, Chi2ECEl, StatSCEl, SCStatusEl, TimeSCEl, PathSCEl, StatCCEl, CCStatusEl, NpheEl, Chi2CCEl, StatusEl;
  Double_t NRowsDCEl, NRowsECEl, NRowsSCEl, NRowsCCEl;
  // simrec particle (49)
  Double_t Eh, Zh, ThetaPQ, Pt2, Pl2, PhiPQ, Mx2, T;
  Double_t ThetaLab, PhiLab;
  Double_t vxh, vyh, vzh;
  Double_t Sector;
  Double_t Px, Py, Pz, P;
  Double_t Betta, Mass2, Etot, Ein, Eout;
  Double_t XEC, YEC, ZEC;
  Double_t pid;
  Double_t T4, deltaZ;
  Double_t StatDC, DCStatus, StatEC, ECStatus, TimeEC, PathEC, Chi2EC, StatSC, SCStatus, TimeSC, PathSC, StatCC, CCStatus, Nphe, Chi2CC, Status;
  Double_t NRowsDC, NRowsEC, NRowsSC, NRowsCC;
  // event-related (1)
  Double_t evnt;
  // gsim electron (17)
  Double_t mc_Q2, mc_W, mc_Nu, mc_Xb, mc_Yb;
  Double_t mc_vxe, mc_vye, mc_vze;
  Double_t mc_SectorEl;
  Double_t mc_TargType;
  Double_t mc_Pex, mc_Pey, mc_Pez, mc_Pe;
  Double_t mc_BettaEl;
  Double_t mc_ThetaLabEl, mc_PhiLabEl;
  // gsim particle (22)
  Double_t mc_Eh, mc_Zh, mc_ThetaPQ, mc_Pt2, mc_Pl2, mc_PhiPQ;
  Double_t mc_ThetaLab, mc_PhiLab;
  Double_t mc_Mx2, mc_T;
  Double_t mc_vxh, mc_vyh, mc_vzh;
  Double_t mc_Sector;
  Double_t mc_Px, mc_Py, mc_Pz, mc_P;
  Double_t mc_Betta;
  Double_t mc_Mass2, mc_deltaZ;
  Double_t mc_pid;
};

#endif
