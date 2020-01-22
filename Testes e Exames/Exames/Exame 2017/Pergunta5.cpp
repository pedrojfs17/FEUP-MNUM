#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

double f(double x, double y) {
	return -1.1 * x * y + 12 * y + 7 * pow(x, 2) - 8 * x;
}

double dfdx(double x, double y) {
	return -1.1 * y + 14 * x - 8;
}

double dfdy(double x, double y) {
	return -1.1 * x + 12;
}

vector<double> subtract(vector<double> v1, vector<double> v2) {
	vector<double> res = { 0,0 };

	res[0] = v1[0] - v2[0];
	res[1] = v1[1] - v2[1];

	return res;
}

int main()
{
	double h = 0.1;
	int numIteracoes = 1;
	vector<double> x0 = { 3,1 }, x1 = x0, temp;
	vector<double> gradiente = { h * dfdx(x0[0],x0[1]), h * dfdy(x0[0],x0[1]) };

	for (int i = 0; i <= numIteracoes; i++) {
		x0 = x1;
	GRAD:
		cout << "Iteracao " << i << ": h = " << h << endl;
		cout << "x1 = {" << x1[0] << " , " << x1[1] << " }" << endl;
		cout << "f(x1) = " << f(x1[0], x1[1]) << endl;

		gradiente = { h * dfdx(x0[0],x0[1]), h * dfdy(x0[0],x0[1]) };
		x1 = subtract(x0, gradiente);

		if (f(x1[0], x1[1]) < f(x0[0], x0[1])) {
			h *= 2;
		}
		else {
			h /= 2;
			i++;
			goto GRAD;
		}
	}
	
	

}
