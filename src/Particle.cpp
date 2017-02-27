#include "TObject.h"
#include "Particle.h"
#include <iostream>

Particle::Particle()
{
	fPid = 0;
	fCharge = 0;
	fBx = fBy = fPx = fPy = fPz = fdEdx = fdEdxVtpc1 = fdEdxVtpc2 = fdEdxMtpc = 0.;
	fNdEdx = fNdEdxVtpc1 = fNdEdxVtpc2 = fNdEdxMtpc = 0;
	fNClustersVtpc1 = fNClustersVtpc2 = fNClustersGtpc = fNClustersMtpc = 0;
}

Particle::Particle(UInt_t pid, Short_t charge, 
			Float_t bx, Float_t by,
			Float_t px, Float_t py, Float_t pz,
			Float_t dedx, Float_t dedx_vtpc1, Float_t dedx_vtpc2, Float_t dedx_mtpc,
			Int_t ndedx, Int_t ndedx_vtpc1, Int_t ndedx_vtpc2, Int_t ndedx_mtpc,
			Int_t nclusters_vtpc1, Int_t nclusters_vtpc2, Int_t nclusters_gtpc, Int_t nclusters_mtpc)
			
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

	fNClustersVtpc1 = nclusters_vtpc1;
	fNClustersVtpc2 = nclusters_vtpc2;
	fNClustersGtpc = nclusters_gtpc;
	fNClustersMtpc = nclusters_mtpc;
}

Particle::Particle(Particle& source_particle)
{
	fPid = source_particle.fPid;
	fCharge = source_particle.fCharge;

	fBx = source_particle.fBx;
	fBy = source_particle.fBy;

	fPx = source_particle.fPx;
	fPy = source_particle.fPy;
	fPz = source_particle.fPz;

	fdEdx = source_particle.fdEdx;
	fdEdxVtpc1 = source_particle.fdEdxVtpc1;
	fdEdxVtpc2 = source_particle.fdEdxVtpc2;
	fdEdxMtpc = source_particle.fdEdxMtpc;

	fNdEdx = source_particle.fNdEdx;
	fNdEdxVtpc1 = source_particle.fNdEdxVtpc1;
	fNdEdxVtpc2 = source_particle.fNdEdxVtpc2;
	fNdEdxMtpc = source_particle.fNdEdxMtpc;

	fNClustersVtpc1 = source_particle.fNClustersVtpc1;
	fNClustersVtpc2 = source_particle.fNClustersVtpc2;
	fNClustersGtpc = source_particle.fNClustersGtpc;
	fNClustersMtpc = source_particle.fNClustersMtpc;
}

Particle::Particle(Particle& source_particle, UInt_t pid)
{
	fPid = pid;
	fCharge = source_particle.fCharge;

	fBx = source_particle.fBx;
	fBy = source_particle.fBy;

	fPx = source_particle.fPx;
	fPy = source_particle.fPy;
	fPz = source_particle.fPz;

	fdEdx = source_particle.fdEdx;
	fdEdxVtpc1 = source_particle.fdEdxVtpc1;
	fdEdxVtpc2 = source_particle.fdEdxVtpc2;
	fdEdxMtpc = source_particle.fdEdxMtpc;

	fNdEdx = source_particle.fNdEdx;
	fNdEdxVtpc1 = source_particle.fNdEdxVtpc1;
	fNdEdxVtpc2 = source_particle.fNdEdxVtpc2;
	fNdEdxMtpc = source_particle.fNdEdxMtpc;

	fNClustersVtpc1 = source_particle.fNClustersVtpc1;
	fNClustersVtpc2 = source_particle.fNClustersVtpc2;
	fNClustersGtpc = source_particle.fNClustersGtpc;
	fNClustersMtpc = source_particle.fNClustersMtpc;
}


Particle::~Particle()
{

}

void Particle::Print()
{
	using namespace std;

	cout << "[" << fPid << "]: px=" << fPx << ", py=" << fPy << ", pz=" << fPz << endl;
}

ClassImp(Particle);
