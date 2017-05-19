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

void ParticleTree::AddParticle(Short_t charge, Float_t px, Float_t py, Float_t pz, Float_t dedx, Float_t dedx_vtpc1, Float_t dedx_vtpc2, Float_t dedx_mtpc, 
		Float_t vtpc1fx, Float_t vtpc1fy, Float_t vtpc1bx, Float_t vtpc1by,
		Float_t gtpcfx, Float_t gtpcfy, Float_t gtpcbx, Float_t gtpcby,
		Float_t vtpc2fx, Float_t vtpc2fy, Float_t vtpc2bx, Float_t vtpc2by,
		Float_t mtpcfx, Float_t mtpcfy, Float_t mtpcbx, Float_t mtpcby)
{
	event->AddParticle(++part_id, charge, px, py, pz, dedx, dedx_vtpc1, dedx_vtpc2, dedx_mtpc, vtpc1fx, vtpc1fy, vtpc1bx, vtpc1by, gtpcfx, gtpcfy, gtpcbx, gtpcby, vtpc2fx, vtpc2fy, vtpc2bx, vtpc2by, mtpcfx, mtpcfy, mtpcbx, mtpcby);
}

void ParticleTree::AddParticle(UInt_t pid, Short_t charge, Float_t px, Float_t py, Float_t pz, Float_t dedx, Float_t dedx_vtpc1, Float_t dedx_vtpc2, Float_t dedx_mtpc, 
		Float_t vtpc1fx, Float_t vtpc1fy, Float_t vtpc1bx, Float_t vtpc1by,
		Float_t gtpcfx, Float_t gtpcfy, Float_t gtpcbx, Float_t gtpcby,
		Float_t vtpc2fx, Float_t vtpc2fy, Float_t vtpc2bx, Float_t vtpc2by,
		Float_t mtpcfx, Float_t mtpcfy, Float_t mtpcbx, Float_t mtpcby)
{
	event->AddParticle(++part_id, charge, px, py, pz, dedx, dedx_vtpc1, dedx_vtpc2, dedx_mtpc, vtpc1fx, vtpc1fy, vtpc1bx, vtpc1by, gtpcfx, gtpcfy, gtpcbx, gtpcby, vtpc2fx, vtpc2fy, vtpc2bx, vtpc2by, mtpcfx, mtpcfy, mtpcbx, mtpcby);
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
