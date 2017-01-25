#include "TObject.h"
#include "TClonesArray.h"

#include "Particle.h"
#include "Event.h"

Event::Event()
{
	fEid = 0;
	fParticles = new TClonesArray("Particle",15);
	fNpa = fNneg = fNpos = 0;
}

Event::Event(UInt_t eid)
{
	fEid = eid;
	fParticles = new TClonesArray("Particle",15);
	fNpa = fNneg = fNpos = 0;
}

Event::~Event()
{
	Clear();
	delete fParticles;
}

Particle* Event::GetParticle(UInt_t index) const
{
	if((index < 0) || (index >= fNpa))
		return NULL;

	return ((Particle*) fParticles->At(index));
}

UInt_t Event::GetFirstParticle() const
{
	return (((Particle*)(fParticles->At(0)))->GetPid());
}

void Event::AddParticle(UInt_t pid, Short_t charge, Float_t bx, Float_t by, Float_t px, Float_t py, Float_t pz, Float_t dedx, Float_t dedx_vtpc1, Float_t dedx_vtpc2, Float_t dedx_mtpc, Int_t ndedx, Int_t ndedx_vtpc1, Int_t ndedx_vtpc2, Int_t ndedx_mtpc, Int_t nclusters_vtpc1, Int_t nclusters_vtpc2, Int_t nclusters_gtpc, Int_t nclusters_mtpc)
{
	new ((*fParticles) [fNpa]) Particle(pid, charge, bx, by, px, py, pz, dedx, dedx_vtpc1, dedx_vtpc2, dedx_mtpc, ndedx, ndedx_vtpc1, ndedx_vtpc2, ndedx_mtpc, nclusters_vtpc1, nclusters_vtpc2, nclusters_gtpc, nclusters_mtpc);
	fNpa++;
	(charge < 0) ? (fNneg++) : (fNpos++);
}

void Event::AddParticle(Particle& source_particle)
{
	new ((*fParticles) [fNpa]) Particle(source_particle);
	fNpa++;
	(source_particle.GetCharge() < 0) ? (fNneg++) : (fNpos++);
}

void Event::AddParticle(Particle& source_particle, UInt_t pid)
{
	new ((*fParticles) [fNpa]) Particle(source_particle, pid);
	fNpa++;
	(source_particle.GetCharge() < 0) ? (fNneg++) : (fNpos++);
}

void Event::Clear()
{
	fParticles->Clear();
	fNpa = fNneg = fNpos = 0;
}

ClassImp(Event);
