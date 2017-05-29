#include "Point.h"
#include <iostream>

Point::Point()
{
	fX = fY = fZ = 0.;
}

Point::Point(Float_t x, Float_t y, Float_t z)
{
	fX = x;
	fY = y;
	fZ = z;
}

Point::Point(Point& source_point)
{
	fX = source_point.fX;
	fY = source_point.fY;
	fZ = source_point.fZ;
}

Point::~Point()
{

}

void Point::Print()
{
	using namespace std;

	cout << "(" << fX << ", " << fY << ", " << fZ << ")" << endl;
}

ClassImp(Point);
