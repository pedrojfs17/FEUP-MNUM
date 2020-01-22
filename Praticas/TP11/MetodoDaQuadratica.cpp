#include <iostream>
#include <vector>

using namespace std;

double f(double x, double y) {
	return pow(y, 2) - 2 * x * y - 6 * y + 2 * pow(x, 2) + 12;
}

double dfdx(double x, double y) {
	return -2 * y + 4 * x - 4 * sin(4 * x);
}

double dfdy(double x, double y) {
	return 2 * y - 2 * x - 6;
}

vector<vector<double>> hessian(double x, double y) {
	vector<vector<double>> hess = { {1,1},{1,1} };

	hess[0][0] = 4 - 16 * cos(4 * x);
	hess[0][1] = -2;
	hess[1][0] = -2;
	hess[1][1] = 2;

	return hess;
}

vector<double> subtract(vector<double> v1, vector<double> v2) {
	vector<double> res = { 1,1 };

	res[0] = v1[0] - v2[0];
	res[1] = v1[1] - v2[1];

	return res;
}

int main()
{
	double h = 1;
	int numIter = 1;
	vector<double> x0 = { 1,1 }, x1 = { 1,1 }, temp;

	vector<double> gradiente = { h * dfdx(x0[0],x0[1]), h * dfdy(x0[0],x0[1]) };

	x1 = subtract(x0, gradiente);

	while (abs(subtract(x1, x0)[0]) > pow(10, -2) && abs(subtract(x1, x0)[1]) > pow(10, -2)) {
		x0 = x1;
	GRAD:
		gradiente = { h * dfdx(x0[0],x0[1]), h * dfdy(x0[0],x0[1]) };
		x1 = subtract(x0, gradiente);
		numIter++;
		//PRINTS------------------------------------------------------------------------
		cout << "h = " << h << endl;
		cout << "x0 = [" << x0[0] << ", " << x0[1] << "]\n";
		cout << "f(x0) = " << f(x0[0], x0[1]) << endl;
		cout << "gradiente = [" << gradiente[0] << ", " << gradiente[1] << "]\n";
		cout << "x1 = [" << x1[0] << ", " << x1[1] << "]\n";
		cout << "f(x1) = " << f(x1[0], x1[1]) << endl;
		//------------------------------------------------------------------------------
		if (f(x1[0], x1[1]) < f(x0[0], x0[1])) {
			h = 2.0 * h;
			cout << "------------------------------------------------------\n";
		}
		else {
			h = h / 2.0;
			cout << "FAIL\n\n";
			goto GRAD;
		}
	}

	cout << endl << "Numero de iteracoes: " << numIter << endl;
	cout << endl << "RESPOSTA: [" << x1[0] << ", " << x1[1] << "]\n";
}
