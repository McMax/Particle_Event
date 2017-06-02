#include "TObject.h"
#include "Particle.h"
#include <iostream>

Particle::Particle()
{
	fPid = 0;
	fCharge = 0;
	fPx = fPy = fPz = fdEdx = fdEdxVtpc1 = fdEdxVtpc2 = fdEdxMtpc = 0.;
	fClusters = new TNtuple("clusters","Cluster positions","x:y:z");
}

Particle::Particle(UInt_t pid, Short_t charge, 
			Float_t px, Float_t py, Float_t pz,
			Float_t dedx, Float_t dedx_vtpc1, Float_t dedx_vtpc2, Float_t dedx_mtpc, TNtuple *clusters_positions)
			
{
	fPid = pid;
	fCharge = charge;

	fPx = px;
	fPy = py;
	fPz = pz;

	fdEdx = dedx;
	fdEdxVtpc1 = dedx_vtpc1;
	fdEdxVtpc2 = dedx_vtpc2;
	fdEdxMtpc = dedx_mtpc;

	fClusters = (TNtuple*)clusters_positions->Clone();
}

Particle::Particle(Particle& source_particle)
{
	fPid = source_particle.fPid;
	fCharge = source_particle.fCharge;

	fPx = source_particle.fPx;
	fPy = source_particle.fPy;
	fPz = source_particle.fPz;

	fdEdx = source_particle.fdEdx;
	fdEdxVtpc1 = source_particle.fdEdxVtpc1;
	fdEdxVtpc2 = source_particle.fdEdxVtpc2;
	fdEdxMtpc = source_particle.fdEdxMtpc;

	fClusters = (TNtuple*)source_particle.fClusters;
}

Particle::Particle(Particle& source_particle, UInt_t pid)
{
	fPid = pid;
	fCharge = source_particle.fCharge;

	fPx = source_particle.fPx;
	fPy = source_particle.fPy;
	fPz = source_particle.fPz;

	fdEdx = source_particle.fdEdx;
	fdEdxVtpc1 = source_particle.fdEdxVtpc1;
	fdEdxVtpc2 = source_particle.fdEdxVtpc2;
	fdEdxMtpc = source_particle.fdEdxMtpc;

	fClusters = (TNtuple*)source_particle.fClusters;
}

Particle::~Particle()
{
	std::cout << "Remove particle" << std::endl;
}

void Particle::Print()
{
	using namespace std;

	cout << "[" << fPid << "]: ch=" << fCharge << ", px=" << fPx << ", py=" << fPy << ", pz=" << fPz << endl;
	cout << "Clusters positions: "<< endl;
	fClusters->Print();
}

ClassImp(Particle);
