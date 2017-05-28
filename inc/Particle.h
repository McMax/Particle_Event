#ifndef PARTICLE_H
#define PARTICLE_H

#include "/opt/root/misc/table/inc/TPoints3D.h"

#include "TObject.h"


class Particle : public TObject
{
	UInt_t fPid;		//Particle index
	Short_t fCharge;	//Particle absolute charge
	Float_t fPx;		//Particle momentum on X-axis
	Float_t fPy;		//Particle momentum on Y-axis
	Float_t fPz;		//Particle momentum on Z-axis
	Float_t fdEdx;		//Particle dE/dx
	Float_t fdEdxVtpc1;	//Particle energy loss in VTPC1
	Float_t fdEdxVtpc2;	//Particle energy loss in VTPC2
	Float_t fdEdxMtpc;	//Particle energy loss in MTPCs
	TPoints3D *fClustersPositions;	//Positions of clusters left by track

public:
	Particle();
	Particle(UInt_t, Short_t, Float_t, Float_t, Float_t, Float_t, Float_t, Float_t, Float_t, TPoints3D*);	//dE/dx global, dE/dx VTPC1, dE/dx VTPC2, dE/dx MTPC
	Particle(Particle&);
	Particle(Particle&, UInt_t);
	virtual ~Particle();
	void Print();

	inline UInt_t GetPid() const { return fPid;}
	inline Short_t GetCharge() const { return fCharge;}
	inline Bool_t isPositive() const { return (fCharge <= 0 ? false : true);}
	inline Float_t GetPx() const { return fPx;}
	inline Float_t GetPy() const { return fPy;}
	inline Float_t GetPz() const { return fPz;}
	inline Float_t GetdEdx() const { return fdEdx;}
	inline Float_t GetdEdxVtpc1() const { return fdEdxVtpc1;}
	inline Float_t GetdEdxVtpc2() const { return fdEdxVtpc2;}
	inline Float_t GetdEdxMtpc() const { return fdEdxMtpc;}
	inline TPoints3D* GetClustersPositions() const { return fClustersPositions;}
	
	inline void SetPid(UInt_t pid) { fPid = pid;}
	inline void SetCharge(Short_t charge) { fCharge = charge;}
	inline void SetPx(Float_t px) { fPx = px;}
	inline void SetPy(Float_t py) { fPy = py;}
	inline void SetPz(Float_t pz) { fPz = pz;}
	inline void SetdEdx(Float_t dedx) { fdEdx = dedx;}
	inline void SetdEdxVtpc1(Float_t dedx_vtpc1) { fdEdxVtpc1 = dedx_vtpc1;}
	inline void SetdEdxVtpc2(Float_t dedx_vtpc2) { fdEdxVtpc2 = dedx_vtpc2;}
	inline void SetdEdxMtpc(Float_t dedx_mtpc) { fdEdxMtpc = dedx_mtpc;}
	inline void SetClustersPositions(TPoints3D *clusters_positions) { fClustersPositions = clusters_positions;}

	ClassDef(Particle,1);
};

#endif
