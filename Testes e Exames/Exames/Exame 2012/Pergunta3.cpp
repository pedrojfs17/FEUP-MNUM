#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

double f(vector<double> X) {
	double x = X[0], y = X[1];
	return 3 * pow(x, 2) - x * y + 11 * y + pow(y, 2) - 8 * x;
}

double dfdx(vector<double> X) {
	double x = X[0], y = X[1];
	return -y + 6 * x - 8;
}

double dfdy(vector<double> X) {
	double x = X[0], y = X[1];
	return 2 * y - x + 11;
}

vector<double> grad(vector<double> X) {
	vector<double> grad = { 0,0 };
	grad[0] = dfdx(X);
	grad[1] = dfdy(X);
	return grad;
}

int main()
{
	vector<double> xn = { 2,2 };
	double h = 0.5;
	vector<double> gradient = { 0,0 };

	gradient = grad(xn);

	for (int i = 0; i < 2; i++) {
		cout << "Iteracao " << i << endl;
		cout << "X = [ " << xn[0] << " , " << xn[1] << " ]" << endl;
		cout << "Gradiente = [ " << gradient[0] << " , " << gradient[1] << " ]" << endl;
		cout << "Z(X) = " << f(xn) << endl << endl;

		xn[0] -= h * gradient[0];
		xn[1] -= h * gradient[1];
		gradient = grad(xn);
	}
}

