#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

double f(double x, double y) {
	return pow(y, 2) - 2.0 * x * y - 6.0 * y + 2.0 * pow(x, 2) + 12.0;
}

vector<double> subMatrix(vector<double> X, double h) {
	vector<double> temp = {0,0};

	temp[0] = X[0] - (X[0] - 3) - (h * (4.0 * X[0] - 2.0 * X[1]));
	temp[1] = X[1] - (X[1] - 6) - (h * (2.0 * X[1] - 2.0 * X[0] - 6.0));

	return temp;
}

vector<double> matrixDiff(vector<double> m1, vector<double> m2) {
	for (int i = 0; i < m1.size(); i++)
		m1[i] -= m2[i];
	return m1;
}


int main()
{
	vector<double> X1, diff = { 1.0,1.0 }, X0 = { 1.0,1.0 };
	double h = 0.5;

	//Iteracoes
	for (int i = 0; i < 20; i++) {
		cout << "Iteracao " << i + 1 << endl;

		X1 = subMatrix(X0,h);
		cout << endl << f(X0[0], X0[1]) << endl << f(X1[0], X1[1]) << endl << endl;

		if (f(X1[0], X1[1]) < f(X0[0], X0[1]))
			h /= 2.0;
		else
			h *= 2.0;

		X0 = X1;

		cout << "x = " << X1[0] << endl;
		cout << "y = " << X1[1] << endl;
		cout << "h = " << h << endl << endl;
		cout << "f(x,y) = " << f(X1[0], X1[1]) << endl << "-------------------------" << endl;
	}

	cout << endl << endl << "_____________________________________" << endl;
	//Modulo
	int i = 0; X0 = { 1.0,1.0 }; X1 = { 1.0,1.0 }; h = 0.5;
	while (abs(diff[0]) > 0.01 || abs(diff[1]) > 0.01) {
		cout << "Iteracao " << i + 1 << endl;
		i++;

		X1 = subMatrix(X0, h);
		diff = matrixDiff(X1, X0);

		if (f(X1[0], X1[1]) < f(X0[0], X0[1]))
			h /= 2;
		else
			h *= 2;

		X0 = X1;

		cout << "x = " << X1[0] << endl;
		cout << "y = " << X1[1] << endl;
		cout << "h = " << h << endl << endl;
		cout << "f(x,y) = " << f(X1[0], X1[1]) << endl << "-------------------------" << endl;
	}
}
