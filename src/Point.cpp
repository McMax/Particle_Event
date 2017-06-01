#include "Point.h"
#include <iostream>

Point::Point()
{
	//std::cout << "One point()" << std::endl;
	fX = fY = fZ = 0.;
}

Point::Point(Float_t x, Float_t y, Float_t z)
{
	std::cout << "One point (" << x << ", " << y << "," << z << ")" << std::endl;
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
	std::cout << "Point destructor" << std::endl;
}

void Point::Print()
{
	using namespace std;

	cout << "(" << fX << ", " << fY << ", " << fZ << ")" << endl;
}

ClassImp(Point);
