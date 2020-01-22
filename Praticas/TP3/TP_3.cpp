#include <iostream>
#include <math.h>

using namespace std;

double f(double x) {
	double res = -2.75 * pow(x, 3) + 18 * pow(x,2) - 21 * x - 12;
	return res;
}

int main()
{
	double r1, r2, r3, min, max;
	int n = 0;

	//R1
	min = -2;
	max = 0;

	while (max-min > pow(10,-5))
	{
		n++;
		r1 = (max + min) / 2;
		if (f(min) * f(r1) < 0)
			max = r1;
		else
			min = r1;
	}

	if (abs(f(min)) > abs(f(max)))
		r1 = max;
	else
		r1 = min;

	cout << "R1 = " << r1 << " e demorou " << n << " iteracoes." << endl;

	//R2
	min = 1;
	max = 3;
	n = 0;

	while (max - min > pow(10, -5))
	{
		n++;
		r2 = (max + min) / 2;
		if (f(min) * f(r2) < 0)
			max = r2;
		else
			min = r2;
	}

	if (abs(f(min)) > abs(f(max)))
		r2 = max;
	else
		r2 = min;

	cout << "R2 = " << r2 << " e demorou " << n << " iteracoes." << endl;

	//R3
	min = 4;
	max = 7;
	n = 0;

	while (max - min > pow(10, -5))
	{
		n++;
		r3 = (max + min) / 2;
		if (f(min) * f(r3) < 0)
			max = r3;
		else
			min = r3;
	}

	if (abs(f(min)) > abs(f(max)))
		r3 = max;
	else
		r3 = min;

	cout << "R3 = " << r3 << " e demorou " << n << " iteracoes." << endl;
}

