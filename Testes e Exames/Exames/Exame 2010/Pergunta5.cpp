#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

double Z(vector<double> X) {
	double x = X[0], y = X[1];
	return 6 * pow(x, 2) - x * y + 12 * y + pow(y, 2) - 8 * x;
}

double dzdx(vector<double> X) {
	double x = X[0], y = X[1];
	return 12 * x - y - 8;
}

double dzdy(vector<double> X) {
	double x = X[0], y = X[1];
	return -x + 12 + 2 * y;
}

vector<double> gradiente(vector<double> X) {
	vector<double> grad = { 0,0 };
	grad[0] = dzdx(X);
	grad[1] = dzdy(X);
	return grad;
}

int main()
{
	vector<double> xn = { 0,0 };
	vector<double> grad = { 0,0 };
	double h = 0.25;

	grad = gradiente(xn);

	for (int i = 0; i < 2; i++) {
		cout << "Iter " << i << endl;
		cout << "X = " << xn[0] << "\t" << xn[1] << endl;
		cout << "Z = " << Z(xn) << endl;
		cout << "grad = " << grad[0] << "\t" << grad[1] << endl;

		xn[0] -= h * grad[0];
		xn[1] -= h * grad[1];
		grad = gradiente(xn);
	}
}
