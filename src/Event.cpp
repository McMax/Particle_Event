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

void Event::AddParticle(UInt_t pid, Short_t charge, Float_t px, Float_t py, Float_t pz, Short_t gpid, Float_t mass)
{
	new ((*fParticles) [fNpa]) Particle(pid, charge, px, py, pz, gpid, mass);
	fNpa++;
	(charge < 0) ? (fNneg++) : (fNpos++);
}

void Event::AddParticle(const Particle& particle)
{
	new ((*fParticles) [fNpa]) Particle(particle);
	fNpa++;
	(particle.GetCharge() < 0) ? (fNneg++) : (fNpos++);
}

void Event::Clear()
{
	fParticles->Clear();
	fNpa = fNneg = fNpos = 0;
}

ClassImp(Event);
