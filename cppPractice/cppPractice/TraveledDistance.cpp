#include "Header.h"
#include <iostream>
#include <math.h>

# define M_PI 3.14159265358979323846
#define d2r (M_PI/180)
constexpr auto kEarthRadius = 6371; //km;

using namespace std;

Gps::Gps(double lat, double lng)
{
	this->latitude = lat;
	this->longintude = lng;
}

Gps::~Gps()
{
	cout << "GPS point deleted" << endl;
}

int CalculateDistance(Gps point1, Gps point2)
{
	int d_lat = (point1.latitude - point2.latitude) * d2r;
	int d_long = (point1.longintude - point2.longintude) * d2r;

	auto d_lat1 = point1.latitude *d2r;
	auto d_lat2 = point2.latitude * d2r;

	auto a = sin(d_lat / 2) * sin(d_lat / 2) +
		sin(d_long / 2) * sin(d_long / 2) * cos(d_lat1) * cos(d_lat2);
	auto c = 2 * atan2(sqrt(a), sqrt(1 - a));

	return c*kEarthRadius;
}