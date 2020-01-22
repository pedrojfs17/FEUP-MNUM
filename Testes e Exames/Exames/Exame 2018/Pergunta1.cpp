#include <math.h>
#include <iostream>

using namespace std;

double f1(double x, double y) {
	return sin(x + y) - exp(x - y);
}

double df1x(double x, double y) {
	return cos(x + y) - exp(x - y);
}

double df1y(double x, double y) {
	return cos(x + y) + exp(x - y);
}

double f2(double x, double y) {
	return cos(x + y) - pow(x, 2) * pow(y, 2);
}

double df2x(double x, double y) {
	return -sin(x + y) - 2 * x * pow(y, 2);
}

double df2y(double x, double y) {
	return -sin(x + y) - 2 * pow(x,2) * y;
}

void newton(double x0, double y0, int iter) {
	double x = x0, y = y0;
	double xn, yn;
	double jacobian;

	for (int i = 0; i < iter; i++) {
		cout << "Iteracao: " << i << ": x = " << x << "\ty = " << y << endl;

		jacobian = df1x(x, y) * df2y(x, y) - df2x(x, y) * df1y(x, y);
		xn = x - (f1(x, y) * df2y(x, y) - f2(x, y) * df1y(x, y)) / jacobian;
		yn = y - (f2(x, y) * df1x(x, y) - f1(x, y) * df2x(x, y)) / jacobian;

		x = xn;
		y = yn;
	}
}

int main()
{
	cout << fixed;
	cout.precision(5);

	newton(0.5, 0.25, 10);
}

