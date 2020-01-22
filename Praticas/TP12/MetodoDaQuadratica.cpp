#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

double f(double x, double y) {
	return sin(y) + pow(y, 2) / 4.0 + cos(x) + pow(x, 2) / 4.0 - 1;
}

vector<double> subMatrix(vector<double> X) {
	X[0] -= (X[0] / 2.0 - sin(X[0])) / (1.0 / 2.0 - cos(X[0]));
	X[1] -= (X[1] / 2.0 + cos(X[1])) / (1.0 / 2.0 - sin(X[1]));

	return X;
}


int main()
{
	vector<double> X = { 0,0 };

	for (int i = 0; i < 4; i++) {
		cout << "Iteracao " << i + 1 << endl;

		X = subMatrix(X);

		cout << "x = " << X[0] << endl;
		cout << "y = " << X[1] << endl;
		cout << "f(x,y) = " << f(X[0], X[1]) << endl << "-------------------------" << endl;
	}
}


