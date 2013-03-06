#ifndef PARTICLE_H
#define PARTICLE_H

#include "TObject.h"

class Particle : public TObject
{
	UInt_t fPid;		//Particle index
	Short_t fCharge;	//Particle absolute charge
	Float_t fBx;		//Particle bx parameter
	Float_t fBy;		//Particle by parameter
	Float_t fPx;		//Particle momentum on X-axis
	Float_t fPy;		//Particle momentum on Y-axis
	Float_t fPz;		//Particle momentum on Z-axis
	Float_t fdEdx;		//Particle dE/dx
	Float_t fdEdxVtpc1;	//Particle energy loss in VTPC1
	Float_t fdEdxVtpc2;	//Particle energy loss in VTPC2
	Float_t fdEdxMtpc;	//Particle energy loss in MTPCs
	Int_t fNdEdx;		//Number of dE/dx points
	Int_t fNdEdxVtpc1;	//Number of dE/dx points in VTPC1
	Int_t fNdEdxVtpc2;	//Number of dE/dx points in VTPC2
	Int_t fNdEdxMtpc;	//Number of dE/dx points in MTPCs

public:
	Particle();
	Particle(UInt_t, Short_t, Float_t, Float_t, Float_t, Float_t, Float_t,
		Float_t, Float_t, Float_t, Float_t,	//dE/dx global, dE/dx VTPC1, dE/dx VTPC2, dE/dx MTPC
		Int_t, Int_t, Int_t, Int_t);	//number of dE/dx points: global, VTPC1, VTPC2, MTPC
	virtual ~Particle();

	inline UInt_t GetPid() const { return fPid;}
	inline Short_t GetCharge() const { return fCharge;}
	inline Bool_t isPositive() const { return (fCharge <= 0 ? false : true);}
	inline Float_t GetBx() const { return fBx;}
	inline Float_t GetBy() const { return fBy;}
	inline Float_t GetPx() const { return fPx;}
	inline Float_t GetPy() const { return fPy;}
	inline Float_t GetPz() const { return fPz;}
	inline Float_t GetdEdx() const { return fdEdx;}
	inline Float_t GetdEdxVtpc1() const { return fdEdxVtpc1;}
	inline Float_t GetdEdxVtpc2() const { return fdEdxVtpc2;}
	inline Float_t GetdEdxMtpc() const { return fdEdxMtpc;}
	inline Int_t GetNdEdx() const { return fNdEdx;}
	inline Int_t GetNdEdxVtpc1() const { return fNdEdxVtpc1;}
	inline Int_t GetNdEdxVtpc2() const { return fNdEdxVtpc2;}
	inline Int_t GetNdEdxMtpc() const { return fNdEdxMtpc;}
	
	inline void SetPid(UInt_t pid) { fPid = pid;}
	inline void SetCharge(Short_t charge) { fCharge = charge;}
	inline void SetBx(Float_t bx) { fBx = bx;}
	inline void SetBy(Float_t by) { fBy = by;}
	inline void SetPx(Float_t px) { fPx = px;}
	inline void SetPy(Float_t py) { fPy = py;}
	inline void SetPz(Float_t pz) { fPz = pz;}
	inline void SetdEdx(Float_t dedx) { fdEdx = dedx;}
	inline void SetdEdxVtpc1(Float_t dedx_vtpc1) { fdEdxVtpc1 = dedx_vtpc1;}
	inline void SetdEdxVtpc2(Float_t dedx_vtpc2) { fdEdxVtpc2 = dedx_vtpc2;}
	inline void SetdEdxMtpc(Float_t dedx_mtpc) { fdEdxMtpc = dedx_mtpc;}
	inline void SetNdEdx(Int_t ndedx) { fNdEdx = ndedx;}
	inline void SetNdEdxVtpc1(Int_t ndedx_vtpc1) { fNdEdxVtpc1 = ndedx_vtpc1;}
	inline void SetNdEdxVtpc2(Int_t ndedx_vtpc2) { fNdEdxVtpc2 = ndedx_vtpc2;}
	inline void SetNdEdxMtpc(Int_t ndedx_mtpc) { fNdEdxMtpc = ndedx_mtpc;}

	ClassDef(Particle,1);
};

#endif
