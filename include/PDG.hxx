#ifndef INVLD
#define INVLD -9999
#endif

TDatabasePDG pdg;

Int_t particleID(TString particleName) {
  if (particleName == "omega") return 223;
  else if (particleName == "pi0") return 111;
  else if (particleName == "pi+") return 211;
  else if (particleName == "pi-") return -211;
  else if (particleName == "gamma") return 22;
  else if (particleName == "electron") return 11;
  else if (particleName == "proton") return 2212;
  else if (particleName == "neutron") return 2112;
  else return 0;
}

Float_t particleMass(Float_t fPid) {
  if (fPid == INVLD) return INVLD; // closure
  return pdg.GetParticle((Int_t) fPid)->Mass();
}
