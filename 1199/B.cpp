#include <iostream>
using namespace std;
#include <algorithm>
#include <stdio.h>
#include <math.h>
#define PI 3.14159265
#include <stdio.h>

int main(){
	double H, L;
	cin >> H >> L;
	double x = atan(H / L);
	double y = atan(L / H);
	double p = (y - x) * 180 / PI;
	double a = L * tan(p * PI / 180);
	//cout << a << endl;
	printf("%.10lf\n", a);
	return 0;
}