#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

double f(double x) {
	return pow(x - 7, 2) + pow(x, 4);
}

int main()
{
	cout << fixed;
	cout.precision(5);

	double B = (sqrt(5) - 1) / 2.0;
	double A = B * B;

	double x1 = 0, x2 = 3;
	double x3 = x1 + A * (x2 - x1);
	double x4 = x1 + B * (x2 - x1);

	while (abs(x2 - x1) > 0.0001) {
		cout << "x1 = " << x1 << "\tx2 = " << x2 << endl;
		cout << "x3 = " << x3 << "\tx4 = " << x4 << endl << endl;

		if (f(x3) < f(x4)) {
			x2 = x4;
			x4 = x3;
			x3 = x1 + B * (x4 - x1);
		}
		else {
			x1 = x3;
			x3 = x4;
			x4 = x3 + B * (x2 - x3);
		}
	}
}

