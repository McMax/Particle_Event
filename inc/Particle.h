#ifndef PARTICLE_H
#define PARTICLE_H

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
	Float_t fVTPC1_f_x;	//Track X position on front wall of VTPC1
	Float_t fVTPC1_f_y;	//Track Y position on back wall of VTPC1
	Float_t fVTPC1_b_x;	//Track X position on front wall of VTPC1
	Float_t fVTPC1_b_y;	//Track Y position on back wall of VTPC1
	Float_t fGTPC_f_x;	//Track X position on front wall of GTPC
	Float_t fGTPC_f_y;	//Track Y position on back wall of GTPC
	Float_t fGTPC_b_x;	//Track X position on front wall of GTPC
	Float_t fGTPC_b_y;	//Track Y position on back wall of GTPC
	Float_t fVTPC2_f_x;	//Track X position on front wall of VTPC2
	Float_t fVTPC2_f_y;	//Track Y position on back wall of VTPC2
	Float_t fVTPC2_b_x;	//Track X position on front wall of VTPC2
	Float_t fVTPC2_b_y;	//Track Y position on back wall of VTPC2
	Float_t fMTPC_f_x;	//Track X position on front wall of MTPC
	Float_t fMTPC_f_y;	//Track Y position on back wall of MTPC
	Float_t fMTPC_b_x;	//Track X position on front wall of MTPC
	Float_t fMTPC_b_y;	//Track Y position on back wall of MTPC

public:
	Particle();
	Particle(UInt_t, Short_t, Float_t, Float_t, Float_t, //Pid, Charge, Px, Py, Pz
		Float_t, Float_t, Float_t, Float_t,	//dE/dx global, dE/dx VTPC1, dE/dx VTPC2, dE/dx MTPC
		Float_t, Float_t, Float_t, Float_t, //VTPC1-front-X, VTPC1-front-Y, VTPC1-back-X, VTPC1-back-Y
		Float_t, Float_t, Float_t, Float_t, //GTPC-front-X, GTPC-front-Y, GTPC-back-X, GTPC-back-Y
		Float_t, Float_t, Float_t, Float_t, //VTPC2-front-X, VTPC2-front-Y, VTPC2-back-X, VTPC2-back-Y
		Float_t, Float_t, Float_t, Float_t); //MTPC-front-X, MTPC-front-Y, MTPC-back-X, MTPC-back-Y
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
	inline Float_t GetVTPC1fX() const { return fVTPC1_f_x;}
	inline Float_t GetVTPC1fY() const { return fVTPC1_f_y;}
	inline Float_t GetVTPC1bX() const { return fVTPC1_b_x;}
	inline Float_t GetVTPC1bY() const { return fVTPC1_b_y;}
	inline Float_t GetGTPCfX() const { return fGTPC_f_x;}
	inline Float_t GetGTPCfY() const { return fGTPC_f_y;}
	inline Float_t GetGTPCbX() const { return fGTPC_b_x;}
	inline Float_t GetGTPCbY() const { return fGTPC_b_y;}
	inline Float_t GetVTPC2fX() const { return fVTPC2_f_x;}
	inline Float_t GetVTPC2fY() const { return fVTPC2_f_y;}
	inline Float_t GetVTPC2bX() const { return fVTPC2_b_x;}
	inline Float_t GetVTPC2bY() const { return fVTPC2_b_y;}
	inline Float_t GetMTPCfX() const { return fMTPC_f_x;}
	inline Float_t GetMTPCfY() const { return fMTPC_f_y;}
	inline Float_t GetMTPCbX() const { return fMTPC_b_x;}
	inline Float_t GetMTPCbY() const { return fMTPC_b_y;}
	
	inline void SetPid(UInt_t pid) { fPid = pid;}
	inline void SetCharge(Short_t charge) { fCharge = charge;}
	inline void SetPx(Float_t px) { fPx = px;}
	inline void SetPy(Float_t py) { fPy = py;}
	inline void SetPz(Float_t pz) { fPz = pz;}
	inline void SetdEdx(Float_t dedx) { fdEdx = dedx;}
	inline void SetdEdxVtpc1(Float_t dedx_vtpc1) { fdEdxVtpc1 = dedx_vtpc1;}
	inline void SetdEdxVtpc2(Float_t dedx_vtpc2) { fdEdxVtpc2 = dedx_vtpc2;}
	inline void SetdEdxMtpc(Float_t dedx_mtpc) { fdEdxMtpc = dedx_mtpc;}
	inline void GetVTPC1fX(Float_t input) { fVTPC1_f_x = input;}
	inline void GetVTPC1fY(Float_t input) { fVTPC1_f_y = input;}
	inline void GetVTPC1bX(Float_t input) { fVTPC1_b_x = input;}
	inline void GetVTPC1bY(Float_t input) { fVTPC1_b_y = input;}
	inline void GetGTPCfX(Float_t input) { fGTPC_f_x = input;}
	inline void GetGTPCfY(Float_t input) { fGTPC_f_y = input;}
	inline void GetGTPCbX(Float_t input) { fGTPC_b_x = input;}
	inline void GetGTPCbY(Float_t input) { fGTPC_b_y = input;}
	inline void GetVTPC2fX(Float_t input) { fVTPC2_f_x = input;}
	inline void GetVTPC2fY(Float_t input) { fVTPC2_f_y = input;}
	inline void GetVTPC2bX(Float_t input) { fVTPC2_b_x = input;}
	inline void GetVTPC2bY(Float_t input) { fVTPC2_b_y = input;}
	inline void GetMTPCfX(Float_t input) { fMTPC_f_x = input;}
	inline void GetMTPCfY(Float_t input) { fMTPC_f_y = input;}
	inline void GetMTPCbX(Float_t input) { fMTPC_b_x = input;}
	inline void GetMTPCbY(Float_t input) { fMTPC_b_y = input;}

	ClassDef(Particle,1);
};

#endif
