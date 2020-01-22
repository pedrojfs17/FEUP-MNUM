#include <iostream>
#include <math.h>

using namespace std;

double f(double x) {
	double res = pow(2, sqrt(x)) - 10 * x + 1;
	return res;
}

int main()
{
	double r1, r2, min, max;
	int n = 0;

	//R1
	min = 0;
	max = 1;

	while (max - min > pow(10, -5))
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
	min = 98;
	max = 100;
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

}

