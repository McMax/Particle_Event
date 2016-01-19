#include "TObject.h"
#include "Particle.h"

Particle::Particle()
{
	fPid = 0;
	fCharge = 0;
	fPx = fPy = fPz = 0.;
	fGeantPid = 0;
	fMass = 0.;
}

Particle::Particle(UInt_t pid, Short_t charge, 
			Float_t px, Float_t py, Float_t pz,
			Short_t gpid, Float_t mass)
			
{
	fPid = pid;
	fCharge = charge;

	fPx = px;
	fPy = py;
	fPz = pz;

	fGeantPid = gpid;
	fMass = mass;
}

Particle::~Particle()
{

}

ClassImp(Particle);
