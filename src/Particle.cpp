#include "TObject.h"
#include "Particle.h"
#include <iostream>

Particle::Particle()
{
	fPid = 0;
	fCharge = 0;
	fPx = fPy = fPz = fdEdx = fdEdxVtpc1 = fdEdxVtpc2 = fdEdxMtpc = 0.;
	fClusters = new Point[150];
}

Particle::Particle(UInt_t pid, Short_t charge, 
			Float_t px, Float_t py, Float_t pz,
			Float_t dedx, Float_t dedx_vtpc1, Float_t dedx_vtpc2, Float_t dedx_mtpc, UInt_t nclusters, Point *clusters_positions)
			
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

	fNclusters = nclusters;
	fClusters = new Point[fNclusters];
	CopyClusters(clusters_positions, nclusters);
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

	fNclusters = source_particle.fNclusters;
	fClusters = new Point[source_particle.fNclusters];
	CopyClusters(source_particle.fClusters, source_particle.fNclusters);
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

	fNclusters = source_particle.fNclusters;
	fClusters = new Point[source_particle.fNclusters];
	CopyClusters(source_particle.fClusters, source_particle.fNclusters);
}


Particle::~Particle()
{
	delete fClusters;
}

void Particle::CopyClusters(Point* source, UInt_t size)
{
	if(size != fNclusters)
	{
		std::cout << "Cannot copy clusters. Size of source and size of fClusters are different!" << std::endl;
		return;
	}

	for(unsigned int i=0; i<size; i++)
		fClusters[i] = source[i];
}

void Particle::Print()
{
	using namespace std;

	cout << "[" << fPid << "]: ch=" << fCharge << ", px=" << fPx << ", py=" << fPy << ", pz=" << fPz << endl;
	cout << "Clusters positions: "<< endl;
	for(unsigned int i=0; i<fNclusters; i++)
		fClusters->Print();
}

ClassImp(Particle);
