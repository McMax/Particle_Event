#ifndef PARTICLETREE_H
#define PARTICLETREE_H

#include "TTree.h"
#include "TBranch.h"
#include "TFile.h"

#include "Particle.h"
#include "Event.h"

class ParticleTree
{
	TFile *file;
	TTree *tree;
	Particle *particle;
	Event *event;
	UInt_t part_id;
	UInt_t ev_id;

public:
	ParticleTree(TString filename);
	void SetEvid(UInt_t);
	void BeginEvent();
	void BeginEvent(UInt_t);
	void EndEvent();
	void CancelEvent();
	UInt_t Check();
	void AddParticle(Short_t, Float_t, Float_t, Float_t, Short_t, Float_t); //charge, px, py, pz, geant_pid, mass
	void AddParticle(UInt_t, Short_t, Float_t, Float_t, Float_t, Short_t, Float_t); //pid, charge, px, py, pz, geant_pid, mass

	void Close();
	virtual ~ParticleTree();
};

#endif
