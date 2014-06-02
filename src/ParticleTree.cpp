#include <iostream>
#include "ParticleTree.h"

ParticleTree::ParticleTree(TString filename)
{
	file = new TFile(filename, "recreate");
	tree = new TTree("events","events");
	event = new Event();
	tree->Branch("event","Event",&event);
	part_id = ev_id = 0;
}

void ParticleTree::SetEvid(UInt_t eid)
{
	ev_id = eid;
}

void ParticleTree::BeginEvent()
{
	event->SetEid(++ev_id);
}

void ParticleTree::BeginEvent(UInt_t eid)
{
	event->SetEid(eid);
}

UInt_t ParticleTree::Check()
{
	return event->GetNpa();
}		

void ParticleTree::EndEvent()
{
	using namespace std;
	
	tree->Fill();
	event->Clear();
}

void ParticleTree::CancelEvent()
{
	event->Clear();
}

void ParticleTree::AddParticle(Short_t charge, Float_t bx, Float_t by,  Float_t px, Float_t py, Float_t pz, Float_t dedx, Float_t dedx_vtpc1, Float_t dedx_vtpc2, Float_t dedx_mtpc, Int_t ndedx, Int_t ndedx_vtpc1, Int_t ndedx_vtpc2, Int_t ndedx_mtpc)
{
	event->AddParticle(++part_id, charge, bx, by, px, py, pz, dedx, dedx_vtpc1, dedx_vtpc2, dedx_mtpc, ndedx, ndedx_vtpc1, ndedx_vtpc2, ndedx_mtpc, 0.);
}

void ParticleTree::AddParticle(Short_t charge, Float_t bx, Float_t by,  Float_t px, Float_t py, Float_t pz, Float_t dedx, Float_t dedx_vtpc1, Float_t dedx_vtpc2, Float_t dedx_mtpc, Int_t ndedx, Int_t ndedx_vtpc1, Int_t ndedx_vtpc2, Int_t ndedx_mtpc, Float_t mass)
{
	event->AddParticle(++part_id, charge, bx, by, px, py, pz, dedx, dedx_vtpc1, dedx_vtpc2, dedx_mtpc, ndedx, ndedx_vtpc1, ndedx_vtpc2, ndedx_mtpc, mass);
}

void ParticleTree::AddParticle(UInt_t pid, Short_t charge, Float_t bx, Float_t by,  Float_t px, Float_t py, Float_t pz, Float_t dedx, Float_t dedx_vtpc1, Float_t dedx_vtpc2, Float_t dedx_mtpc, Int_t ndedx, Int_t ndedx_vtpc1, Int_t ndedx_vtpc2, Int_t ndedx_mtpc)
{
	event->AddParticle(pid, charge, bx, by, px, py, pz, dedx, dedx_vtpc1, dedx_vtpc2, dedx_mtpc, ndedx, ndedx_vtpc1, ndedx_vtpc2, ndedx_mtpc, 0.);
}

void ParticleTree::AddParticle(UInt_t pid, Short_t charge, Float_t bx, Float_t by,  Float_t px, Float_t py, Float_t pz, Float_t dedx, Float_t dedx_vtpc1, Float_t dedx_vtpc2, Float_t dedx_mtpc, Int_t ndedx, Int_t ndedx_vtpc1, Int_t ndedx_vtpc2, Int_t ndedx_mtpc, Float_t mass)
{
	event->AddParticle(pid, charge, bx, by, px, py, pz, dedx, dedx_vtpc1, dedx_vtpc2, dedx_mtpc, ndedx, ndedx_vtpc1, ndedx_vtpc2, ndedx_mtpc, mass);
}

void ParticleTree::Close()
{
	tree->AutoSave("overwrite");
	delete tree;
	file->Close();
	delete file;
}

ParticleTree::~ParticleTree()
{

}
