#ifndef GSTTREE_H
#define GSTTREE_H

#ifndef HEADERS_HXX
#include "Headers.hxx"
#endif

/*
   NAMING CONVENTIONS

   rec_e : output variables for reconstructed electrons (data or simulations)
   rec_p : output variables for reconstructed particles (data or simulations)

   gen_e : output variables for generated particles (simulations)
   gen_p : output variables for generated particles (simulations)
*/

struct rec_e {
  // electron (46)
  Float_t Q2, W, Nu, Xb, Yb;
  Float_t vxe, vye, vze;
  Float_t Sector;
  Float_t Px, Py, Pz, P;
  Float_t Betta, Etot, Ein, Eout;
  Float_t vxec, vyec, vzec;
  Float_t TargType;
  Float_t XEC, YEC, ZEC;
  Float_t ThetaLab, PhiLab;
  Float_t StatDC, DCStatus, StatEC, ECStatus, TimeEC, PathEC, Chi2EC, StatSC, SCStatus, TimeSC, PathSC, StatCC, CCStatus, Nphe, Chi2CC, Status;
  Float_t NRowsDC, NRowsEC, NRowsSC, NRowsCC;
  // evnt (1)
  Float_t evnt;
};

struct rec_p {
  // electron (46)
  Float_t Q2, W, Nu, Xb, Yb;
  Float_t vxe, vye, vze;
  Float_t SectorEl;
  Float_t Pex, Pey, Pez, Pe;
  Float_t BettaEl, Etote, Eine, Eoute;
  Float_t vxec, vyec, vzec;
  Float_t TargType;
  Float_t XECe, YECe, ZECe;
  Float_t ThetaLabEl, PhiLabEl;
  Float_t StatDCEl, DCStatusEl, StatECEl, ECStatusEl, TimeECEl, PathECEl, Chi2ECEl, StatSCEl, SCStatusEl, TimeSCEl, PathSCEl, StatCCEl, CCStatusEl, NpheEl, Chi2CCEl, StatusEl;
  Float_t NRowsDCEl, NRowsECEl, NRowsSCEl, NRowsCCEl;
  // particle (49)
  Float_t Eh, Zh, ThetaPQ, Pt2, Pl2, PhiPQ, Mx2, T;
  Float_t ThetaLab, PhiLab;
  Float_t vxh, vyh, vzh;
  Float_t Sector;
  Float_t Px, Py, Pz, P;
  Float_t Betta, Mass2, Etot, Ein, Eout;
  Float_t XEC, YEC, ZEC;
  Float_t pid, T4, deltaZ;
  Float_t StatDC, DCStatus, StatEC, ECStatus, TimeEC, PathEC, Chi2EC, StatSC, SCStatus, TimeSC, PathSC, StatCC, CCStatus, Nphe, Chi2CC, Status;
  Float_t NRowsDC, NRowsEC, NRowsSC, NRowsCC;
  // event (1)
  Float_t evnt;
};

struct gen_e {
  // electron (10)
  Float_t mc_Q2, mc_W, mc_Nu, mc_Xb, mc_Yb;
  Float_t mc_vxe, mc_vye, mc_vze;
  Float_t mc_Sector;
  Float_t mc_TargType;
  // particle (7)
  Float_t mc_Px, mc_Py, mc_Pz, mc_P;
  Float_t mc_Betta;
  Float_t mc_ThetaLab, mc_PhiLab;
};

struct gen_p {
  // electron (17)
  Float_t mc_Q2, mc_W, mc_Nu, mc_Xb, mc_Yb;
  Float_t mc_vxe, mc_vye, mc_vze;
  Float_t mc_SectorEl;
  Float_t mc_TargType;
  Float_t mc_Pex, mc_Pey, mc_Pez, mc_Pe;
  Float_t mc_BettaEl;
  Float_t mc_ThetaLabEl, mc_PhiLabEl;
  // particle (22)
  Float_t mc_Eh, mc_Zh, mc_ThetaPQ, mc_Pt2, mc_Pl2, mc_PhiPQ;
  Float_t mc_ThetaLab, mc_PhiLab;
  Float_t mc_Mx2, mc_T;
  Float_t mc_vxh, mc_vyh, mc_vzh;
  Float_t mc_Sector;
  Float_t mc_Px, mc_Py, mc_Pz, mc_P;
  Float_t mc_Betta;
  Float_t mc_Mass2, mc_deltaZ;
  Float_t mc_pid;
};

#endif
