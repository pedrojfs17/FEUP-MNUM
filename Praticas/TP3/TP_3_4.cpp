#include <iostream>
#include <math.h>

using namespace std;

double f(double x) {
	double res = -2.75 * pow(x, 3) + 18 * pow(x, 2) - 21 * x - 12;
	return res;
}

int main()
{
	double rtemp, r1, r2, r3, min, max;
	int n = 0;

	//R1
	min = -2;
	max = 0;

	do
	{
		rtemp = max;
		n++;
		r1 = (min * f(max) - max * f(min)) / (f(max) - f(min));
		max = r1;
	} while (abs(rtemp - r1) > pow(10, -5));

	cout << "R1 = " << r1 << " e demorou " << n << " iteracoes." << endl;

	//R2
	min = 1;
	max = 3;
	n = 0;

	do
	{
		rtemp = max;
		n++;
		r2 = (min * f(max) - max * f(min)) / (f(max) - f(min));
		max = r2;
	} while (abs(rtemp - r2) > pow(10, -5));

	cout << "R2 = " << r2 << " e demorou " << n << " iteracoes." << endl;

	//R3
	min = 4;
	max = 7;
	n = 0;

	do
	{
		rtemp = max;
		n++;
		r3 = (min * f(max) - max * f(min)) / (f(max) - f(min));
		max = r3;
	} while (abs(rtemp - r3) > pow(10, -5));

	cout << "R3 = " << r3 << " e demorou " << n << " iteracoes." << endl;
}