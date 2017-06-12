#ifndef PARTICLE_H
#define PARTICLE_H

#include "TNtuple.h"
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
	TNtuple* fClusters;	//Positions of clusters left by track
	Short_t fPPvtpc1;
	Short_t fPPgtpc;
	Short_t fPPvtpc2;
	Short_t fPPmtpc;

public:

	enum TPCs
	{
		eVTPC1 = 0,
		eGTPC = 1,
		eVTPC2 = 2,
		eMTPC = 3,
	};

	Particle();
	Particle(UInt_t, Short_t, Float_t, Float_t, Float_t, Float_t, Float_t, Float_t, Float_t, TNtuple*, Short_t, Short_t, Short_t, Short_t);
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
	inline TNtuple* GetClustersPositions() const { return fClusters;}
	inline Short_t GetPPvtpc1() const { return fPPvtpc1;}
	inline Short_t GetPPgtpc() const { return fPPgtpc;}
	inline Short_t GetPPvtpc2() const { return fPPvtpc2;}
	inline Short_t GetPPmtpc() const { return fPPmtpc;}
	
	inline void SetPid(UInt_t pid) { fPid = pid;}
	inline void SetCharge(Short_t charge) { fCharge = charge;}
	inline void SetPx(Float_t px) { fPx = px;}
	inline void SetPy(Float_t py) { fPy = py;}
	inline void SetPz(Float_t pz) { fPz = pz;}
	inline void SetdEdx(Float_t dedx) { fdEdx = dedx;}
	inline void SetdEdxVtpc1(Float_t dedx_vtpc1) { fdEdxVtpc1 = dedx_vtpc1;}
	inline void SetdEdxVtpc2(Float_t dedx_vtpc2) { fdEdxVtpc2 = dedx_vtpc2;}
	inline void SetdEdxMtpc(Float_t dedx_mtpc) { fdEdxMtpc = dedx_mtpc;}

	ClassDef(Particle,1);
};

#endif
