#include <math.h>
#include <iostream>

using namespace std;

double f(double x) {
	return pow(x - 7, 2) + pow(x, 4);
}

int main()
{
	double x1 = -1.0, x2 = 3.0;
	int iter = 0;

	const double B = (sqrt(5) - 1) / 2;
	const double A = B * B;

	double x3 = x1 + A * (x2 - x1);
	double x4 = x1 + B * (x2 - x1);

	while (abs(x1 - x4) > 0.0001 && abs(x3 - x2) > 0.0001) {
		iter++;
		if (f(x3) < f(x4)) {
			x2 = x4;
			x4 = x3;
			x3 = x1 + A * (x2 - x1);
		}
		else {
			x1 = x3;
			x3 = x4;
			x4 = x1 + B * (x2 - x1);
		}

		cout << "Iteracao " << iter << ":\nx1 = " << x1 << endl;
		cout << "x2 = " << x2 << endl;
		cout << "x3 = " << x3 << endl;
		cout << "x4 = " << x4 << endl;
		cout << endl;
	}

}

