#ifndef EVENT_H
#define EVENT_H

#include "TObject.h"
#include "Particle.h"

class Event : public TObject
{
	UInt_t fEid;			//Event number
	TClonesArray* fParticles;	//Array of particles
	UInt_t fNpa;			//Number of all charged particles
	UInt_t fNneg;			//Number of negatively charged particles
	UInt_t fNpos;			//Number of positively charged particles

public:
	Event();
	Event(UInt_t);
	virtual ~Event();
	
	inline UInt_t GetEid() const { return fEid;}
	inline UInt_t GetNpa() const { return fNpa;}
	inline UInt_t GetNneg() const { return fNneg;}
	inline UInt_t GetNpos() const { return fNpos;}
	inline TClonesArray* GetParticles() const { return fParticles;}
	Particle* GetParticle(UInt_t) const;
	UInt_t GetFirstParticle() const;

	inline void SetEid(UInt_t eid) { fEid = eid;}

	void AddParticle(UInt_t, Short_t, Float_t, Float_t, Float_t, Float_t, Float_t, Float_t, Float_t, Float_t, Float_t,
			Int_t, Int_t, Int_t, Int_t);
			
	void AddParticle(Particle&);
	void AddParticle(Particle&, UInt_t);
	void Clear();

	ClassDef(Event,1);
};

#endif
