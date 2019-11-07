#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


double dis_to_circle(int x1, int y1, int xc, int yc, int rc)
{
	double result = (x1 - xc) * (x1 - xc) + (y1 - yc) * (y1 - yc) - rc * rc;
	return sqrt(result); 
}


int main(void)
{
	int xc, yc, xd, yd;
	cin >> xc >> yc >> xd >> yd;

	int xb, yb, rb, xr, yr, rr;
	cin >> xb >> yb >> rb >> xr >> yr >> rr;

	double dis_source = dis_to_circle(xc, yc, xr, yr, rr);
	double dis_destin = dis_to_circle(xd, yd, xr, yr, rr); 

	double tan_source = dis_source / rr;
	double tan_destin = dis_destin / rr;

	double angle = atan(tan_source) + atan(tan_destin);

	double t = ((xc  - xr) * (xd - xr) + (yc - yr) * (yd - yr)) / (sqrt((xc - xr) * (xc - xr) + (yc - yr) * (yc - yr)) * sqrt((xd - xr) * (xd - xr) + (yd - yr) * (yd - yr)));
	double x = acos(t);

	double a1 = x - angle;
	double dis1 = dis_source + dis_destin + a1 * rr;
	cout << fixed << setprecision(12) << dis1 << endl;
	return 0;
}