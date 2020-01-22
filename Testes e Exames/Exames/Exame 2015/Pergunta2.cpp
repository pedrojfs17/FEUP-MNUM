#include <cmath>
#include <iostream>

using namespace std;

double f(double x) {
	return -2 * (-sin(x) + 5 * cos(x));
}

int main()
{
	cout << fixed;
	cout.precision(5);

	double B = (sqrt(5) - 1) / 2.0;
	double A = B * B;

	double x1 = 8.0, x2 = 10.0;
	double x3 = x1 + A * (x2 - x1);
	double x4 = x1 + B * (x2 - x1);

	for (int i = 0; i < 3; i++) {
		cout << "Iteracao " << i << endl;
		cout << "x1 = " << x1 << "\tf(x1) = " << f(x1) << endl;
		cout << "x2 = " << x2 << "\tf(x2) = " << f(x2) << endl;
		cout << "x3 = " << x3 << "\tf(x3) = " << f(x3) << endl;
		cout << "x4 = " << x4 << "\tf(x4) = " << f(x4) << endl;

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

	cout << endl << "Intervalo: " << x2 - x1 << endl;
}

