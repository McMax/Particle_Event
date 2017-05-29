#ifndef POINT_H
#define POINT_H

#include "TObject.h"

class Point : public TObject
{
	Float_t fX;
	Float_t fY;
	Float_t fZ;

public:
	Point();
	Point(Float_t, Float_t, Float_t);
	Point(Point&);
	virtual ~Point();
	void Print();

	inline Float_t GetX() const { return fX;}
	inline Float_t GetY() const { return fY;}
	inline Float_t GetZ() const { return fZ;}

	inline void SetX(Float_t x) { fX = x;}
	inline void SetY(Float_t y) { fY = y;}
	inline void SetZ(Float_t z) { fZ = z;}
	inline void SetXYZ(Float_t x, Float_t y, Float_t z) { fX = x; fY = y; fZ = z;}

	ClassDef(Point,1);
};

#endif
