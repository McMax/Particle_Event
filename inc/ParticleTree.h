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
	void AddParticle(Short_t, Float_t, Float_t, Float_t, Float_t, Float_t, Float_t, Float_t, Float_t, Float_t, Int_t, Int_t, Int_t, Int_t, Int_t, Int_t, Int_t, Int_t); //charge, bx, by, px, py, pz, dedx, dedx_vtpc1, dedx_vtpc2, dedx_mtpc, ndedx, ndedx_vtpc1, ndedx_vtpc2, ndedx_mtpc, nclusters_vtpc1, nclusters_vtpc2, nclusters_gtpc, nclusters_mtpc
	void AddParticle(UInt_t, Short_t, Float_t, Float_t, Float_t, Float_t, Float_t, Float_t, Float_t, Float_t, Float_t, Int_t, Int_t, Int_t, Int_t, Int_t, Int_t, Int_t, Int_t); //pid, charge, bx, by, px, py, pz, dedx, dedx_vtpc1, dedx_vtpc2, dedx_mtpc, ndedx, ndedx_vtpc1, ndedx_vtpc2, ndedx_mtpc, nclusters_vtpc1, nclusters_vtpc2, nclusters_gtpc, nclusters_mtpc
	void AddParticle(Particle&);
	void AddParticle(Particle&, UInt_t);

	void Close();
	virtual ~ParticleTree();
};

#endif
