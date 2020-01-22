#include <cmath>
#include <iostream>

using namespace std;

double f(double x, double y) {
	return sin(y) + pow(y, 2) / 4.0 + cos(x) + pow(x, 2) / 4.0 - 1;
}

double dfx(double x, double y) {
	return x / 2.0 - sin(x);
}

double dfy(double x, double y) {
	return cos(y) + y / 2.0;
}

double hessianx(double x, double y) {
	return (1.0 / (1.0 / 2.0 - cos(x)));
}

double hessiany(double x, double y) {
	return (1.0 / (1.0 / 2.0 - sin(y)));
}

int main()
{
	cout << fixed;
	cout.precision(9);

	double x = 1.0, y = 1.0;
	double lambda = 0.1;
	double xn, yn;

	for (int i = 0; i < 14; i++) {
		cout << "Iteracao " << i << endl;
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
		cout << "f(x,y) = " << f(x, y) << endl << endl;

		xn = x - lambda * dfx(x, y) - hessianx(x, y) * dfx(x, y);
		yn = y - lambda * dfy(x, y) - hessiany(x, y) * dfy(x, y);

		if (f(xn, yn) < f(x, y)) {
			lambda /= 2.0;
		}
		else {
			lambda *= 2.0;
		}

		x = xn;
		y = yn;
	}

}

