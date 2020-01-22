#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

double dy(double x) {
	return 1.5 * exp(1.5 * x);
}

double f(double x) {
	return sqrt(1 + pow(dy(x), 2));
}

int main()
{
	cout << fixed;
	cout.precision(6);

	double a = 0.0, b = 2.0, h = 0.5;
	double sumT, sumS;
	vector<double> solT = { 0,0,0 }, solS = { 0,0,0 };
	int count = 0;

	for (int i = 0; i < 3; i++) {
		cout << "H = " << h << endl;

		sumT = f(a);
		for (double j = h; j < b; j += h) {
			sumT += 2 * f(j);
		}
		sumT += f(b);
		solT[i] = h / 2.0 * sumT;
		cout << "Solucao Trapezios = " << solT[i] << endl;

		sumS = f(a);
		count = 1;
		for (double j = h; j < b; j += h) {
			if (count % 2 == 0)
				sumS += 2 * f(j);
			else
				sumS += 4 * f(j);
			count++;
		}
		sumS += f(b);
		solS[i] = h / 3.0 * sumS;
		cout << "Solucao Simpson = " << solS[i] << endl << endl;

		h /= 2;
	}

	cout << "QC Trapezios = " << (solT[1] - solT[0]) / (solT[2] - solT[1]) << endl;
	cout << "QC Simpson = " << (solS[1] - solS[0]) / (solS[2] - solS[1]) << endl;
	cout << "Erro trapezios = " << (solT[2] - solT[1]) / 3.0 << endl;
	cout << "Erro Simpson = " << (solS[2] - solS[1]) / 15.0 << endl;
}

