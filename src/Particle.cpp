#include "TObject.h"
#include "Particle.h"
#include <iostream>

Particle::Particle()
{
	fPid = 0;
	fCharge = 0;
	fPx = fPy = fPz = fdEdx = fdEdxVtpc1 = fdEdxVtpc2 = fdEdxMtpc = 0.;
	fVTPC1_f_x = fVTPC1_f_y = fVTPC1_b_x = fVTPC1_b_y = fGTPC_f_x = fGTPC_f_y = fGTPC_b_x = fGTPC_b_y = fVTPC2_f_x = fVTPC2_f_y = fVTPC2_b_x = fVTPC2_b_y = fMTPC_f_x = fMTPC_f_y = fMTPC_b_x = fMTPC_b_y = 0.;
}

Particle::Particle(UInt_t pid, Short_t charge, 
			Float_t px, Float_t py, Float_t pz,
			Float_t dedx, Float_t dedx_vtpc1, Float_t dedx_vtpc2, Float_t dedx_mtpc,
			Float_t vtpc1fx, Float_t vtpc1fy, Float_t vtpc1bx, Float_t vtpc1by,
			Float_t gtpcfx, Float_t gtpcfy, Float_t gtpcbx, Float_t gtpcby,
			Float_t vtpc2fx, Float_t vtpc2fy, Float_t vtpc2bx, Float_t vtpc2by,
			Float_t mtpcfx, Float_t mtpcfy, Float_t mtpcbx, Float_t mtpcby)
			
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

	fVTPC1_f_x = vtpc1fx;
	fVTPC1_f_y = vtpc1fy;
	fVTPC1_b_x = vtpc1bx;
	fVTPC1_b_y = vtpc1by;
	fGTPC_f_x = gtpcfx;
	fGTPC_f_y = gtpcfy;
	fGTPC_b_x = gtpcbx;
	fGTPC_b_y = gtpcby;
	fVTPC2_f_x = vtpc2fx;
	fVTPC2_f_y = vtpc2fy;
	fVTPC2_b_x = vtpc2bx;
	fVTPC2_b_y = vtpc2by;
	fMTPC_f_x = mtpcfx;
	fMTPC_f_y = mtpcfy;
	fMTPC_b_x = mtpcbx;
	fMTPC_b_y = mtpcby;
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

	fVTPC1_f_x = source_particle.fVTPC1_f_x;
	fVTPC1_f_y = source_particle.fVTPC1_f_y;
	fVTPC1_b_x = source_particle.fVTPC1_b_x;
	fVTPC1_b_y = source_particle.fVTPC1_b_y;
	fGTPC_f_x = source_particle.fGTPC_f_x;
	fGTPC_f_y = source_particle.fGTPC_f_y;
	fGTPC_b_x = source_particle.fGTPC_b_x;
	fGTPC_b_y = source_particle.fGTPC_b_y;
	fVTPC2_f_x = source_particle.fVTPC2_f_x;
	fVTPC2_f_y = source_particle.fVTPC2_f_y;
	fVTPC2_b_x = source_particle.fVTPC2_b_x;
	fVTPC2_b_y = source_particle.fVTPC2_b_y;
	fMTPC_f_x = source_particle.fMTPC_f_x;
	fMTPC_f_y = source_particle.fMTPC_f_y;
	fMTPC_b_x = source_particle.fMTPC_b_x;
	fMTPC_b_y = source_particle.fMTPC_b_y;
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

	fVTPC1_f_x = source_particle.fVTPC1_f_x;
	fVTPC1_f_y = source_particle.fVTPC1_f_y;
	fVTPC1_b_x = source_particle.fVTPC1_b_x;
	fVTPC1_b_y = source_particle.fVTPC1_b_y;
	fGTPC_f_x = source_particle.fGTPC_f_x;
	fGTPC_f_y = source_particle.fGTPC_f_y;
	fGTPC_b_x = source_particle.fGTPC_b_x;
	fGTPC_b_y = source_particle.fGTPC_b_y;
	fVTPC2_f_x = source_particle.fVTPC2_f_x;
	fVTPC2_f_y = source_particle.fVTPC2_f_y;
	fVTPC2_b_x = source_particle.fVTPC2_b_x;
	fVTPC2_b_y = source_particle.fVTPC2_b_y;
	fMTPC_f_x = source_particle.fMTPC_f_x;
	fMTPC_f_y = source_particle.fMTPC_f_y;
	fMTPC_b_x = source_particle.fMTPC_b_x;
	fMTPC_b_y = source_particle.fMTPC_b_y;
}


Particle::~Particle()
{

}

void Particle::Print()
{
	using namespace std;

	cout << "[" << fPid << "]: ch=" << fCharge << ", px=" << fPx << ", py=" << fPy << ", pz=" << fPz << endl;
	cout << "\tVTPC1 front: (" << fVTPC1_f_x << "," << fVTPC1_f_y << ")" << " VTPC1 back: (" << fVTPC1_b_x << "," << fVTPC1_b_y << ")" << endl;
	cout << "\tGTPC front: (" << fGTPC_f_x << "," << fGTPC_f_y << ")" << " GTPC back: (" << fGTPC_b_x << "," << fGTPC_b_y << ")" << endl;
	cout << "\tVTPC2 front: (" << fVTPC2_f_x << "," << fVTPC2_f_y << ")" << " VTPC2 back: (" << fVTPC2_b_x << "," << fVTPC2_b_y << ")" << endl;
	cout << "\tMTPC front: (" << fMTPC_f_x << "," << fMTPC_f_y << ")" << " MTPC back: (" << fMTPC_b_x << "," << fMTPC_b_y << ")" << endl;
}

ClassImp(Particle);
