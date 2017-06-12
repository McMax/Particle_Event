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

void ParticleTree::BeginEvent(UInt_t runnumber, UInt_t eventno)
{
	event->SetEid(++ev_id);
	event->SetNA61Run(runnumber);
	event->SetNA61Event(eventno);
}

void ParticleTree::BeginEvent(UInt_t eid, UInt_t runnumber, UInt_t eventno)
{
	event->SetEid(eid);
	event->SetNA61Run(runnumber);
	event->SetNA61Event(eventno);
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

void ParticleTree::AddParticle(Short_t charge, Float_t px, Float_t py, Float_t pz, Float_t dedx, Float_t dedx_vtpc1, Float_t dedx_vtpc2, Float_t dedx_mtpc, TNtuple *clusters_positions)
{
	event->AddParticle(++part_id, charge, px, py, pz, dedx, dedx_vtpc1, dedx_vtpc2, dedx_mtpc, clusters_positions);
}

void ParticleTree::AddParticle(UInt_t pid, Short_t charge, Float_t px, Float_t py, Float_t pz, Float_t dedx, Float_t dedx_vtpc1, Float_t dedx_vtpc2, Float_t dedx_mtpc, TNtuple *clusters_positions)
{
	event->AddParticle(pid, charge, px, py, pz, dedx, dedx_vtpc1, dedx_vtpc2, dedx_mtpc, clusters_positions);
}

void ParticleTree::AddParticle(Particle& source_particle)
{
	event->AddParticle(source_particle,++part_id);
}

void ParticleTree::AddParticle(Particle& source_particle, UInt_t pid)
{
	event->AddParticle(source_particle,pid);
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
