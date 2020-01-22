#include <math.h>
#include <iostream>

using namespace std;

double f1(double x, double y) { return pow(x,2) - y - 1.2; }

double df1dx(double x, double y) { return 2 * x; }

double df1dy(double x, double y) { return -1; }

double f2(double x, double y) { return -x + pow(y,2) - 1.0; }

double df2dx(double x, double y) { return -1; }

double df2dy(double x, double y) { return 2*y; }

void newton(double x0, double y0, int iter) {
	double x = x0;
	double y = y0;

	// Auxiliary variables
	double xn;
	double yn;
	double jacobian;

	cout << 0 << ":\t" << x << "\t" << y << endl;

	for (unsigned int i = 1; i <= iter; i++) {
		jacobian = df1dx(x, y) * df2dy(x, y) - df2dx(x, y) * df1dy(x, y);
		xn = x - (f1(x, y) * df2dy(x, y) - f2(x, y) * df1dy(x, y)) / jacobian;
		yn = y - (f2(x, y) * df1dx(x, y) - f1(x, y) * df2dx(x, y)) / jacobian;

		x = xn;
		y = yn;

		// Print current values
		cout << i << ":\t" << x << "\t" << y << endl;
	}
}

int main()
{
	cout << fixed;
	cout.precision(6);

	double x0 = 1.0, y0 = 1.0;

	newton(x0, y0, 3);
}

