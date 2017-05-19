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

void Event::AddParticle(UInt_t pid, Short_t charge,
		Float_t px, Float_t py, Float_t pz,
		Float_t dedx, Float_t dedx_vtpc1, Float_t dedx_vtpc2, Float_t dedx_mtpc,
		Float_t vtpc1fx, Float_t vtpc1fy, Float_t vtpc1bx, Float_t vtpc1by,
		Float_t gtpcfx, Float_t gtpcfy, Float_t gtpcbx, Float_t gtpcby,
		Float_t vtpc2fx, Float_t vtpc2fy, Float_t vtpc2bx, Float_t vtpc2by,
		Float_t mtpcfx, Float_t mtpcfy, Float_t mtpcbx, Float_t mtpcby)
{
	new ((*fParticles) [fNpa]) Particle(pid, charge, px, py, pz, dedx, dedx_vtpc1, dedx_vtpc2, dedx_mtpc,vtpc1fx, vtpc1fy, vtpc1bx, vtpc1by, gtpcfx, gtpcfy, gtpcbx, gtpcby, vtpc2fx, vtpc2fy, vtpc2bx, vtpc2by, mtpcfx, mtpcfy, mtpcbx, mtpcby);
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
