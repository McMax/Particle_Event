#include "TObject.h"
#include "Particle.h"

Particle::Particle()
{
	fPid = 0;
	fCharge = 0;
	fBx = fBy = fPx = fPy = fPz = fdEdx = fdEdxVtpc1 = fdEdxVtpc2 = fdEdxMtpc = 0.;
	fNdEdx = fNdEdxVtpc1 = fNdEdxVtpc2 = fNdEdxMtpc = 0;
}

Particle::Particle(UInt_t pid, Short_t charge, 
			Float_t bx, Float_t by,
			Float_t px, Float_t py, Float_t pz,
			Float_t dedx, Float_t dedx_vtpc1, Float_t dedx_vtpc2, Float_t dedx_mtpc,
			Int_t ndedx, Int_t ndedx_vtpc1, Int_t ndedx_vtpc2, Int_t ndedx_mtpc)
{
	fPid = pid;
	fCharge = charge;

	fBx = bx;
	fBy = by;

	fPx = px;
	fPy = py;
	fPz = pz;

	fdEdx = dedx;
	fdEdxVtpc1 = dedx_vtpc1;
	fdEdxVtpc2 = dedx_vtpc2;
	fdEdxMtpc = dedx_mtpc;

	fNdEdx = ndedx;
	fNdEdxVtpc1 = ndedx_vtpc1;
	fNdEdxVtpc2 = ndedx_vtpc2;
	fNdEdxMtpc = ndedx_mtpc;
}

Particle::~Particle()
{

}

ClassImp(Particle);
