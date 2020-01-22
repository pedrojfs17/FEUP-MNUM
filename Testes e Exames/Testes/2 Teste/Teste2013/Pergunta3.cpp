#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

double L(double x) {
	return sqrt(1 + pow(1.5 * exp(1.5 * x), 2));
}

int main()
{
	double a = 0, b = 1;
	double h = 0.25;
	double sumT, sumS;
	vector<double> solT = { 1,1,1 };
	vector<double> solS = { 1,1,1 };

	for (int i = 0; i < 3; i++) {
		cout << "----------------------- " << h << " -----------------------" << endl;

		cout << "TRAPEZIOS\n";
		a = 0;
		sumT = L(a);
		for (a = 0 + h; a < b; a += h) {
			sumT += 2 * L(a);
		}
		sumT += L(b);
		solT[i] = h / 2.0 * sumT;
		cout << "Solucao: " << solT[i] << endl;

		a = 0;
		int counter = 1;

		cout << "SIMPSON\n";
		sumS = L(a);
		for (a = 0 + h; a < b; a += h) {
			if (counter % 2 == 0)
				sumS += 2 * L(a);
			else
				sumS += 4 * L(a);
			counter++;
		}
		sumS += L(b);
		solS[i] = h / 3.0 * sumS;
		cout << "Solucao: " << solS[i] << endl;

		h /= 2;
	}
	

	double QCT = (solT[1] - solT[0]) / (solT[2] - solT[1]);
	double erroT = solT[2] - solT[1];

	double QCS = (solS[1] - solS[0]) / (solS[2] - solS[1]);
	double erroS = solS[2] - solS[1];

	cout << "QCT: " << QCT << endl;
	cout << "Erro T: " << erroT << endl;
	cout << "QCS: " << QCS << endl;
	cout << "Erro S: " << erroS << endl;


}

