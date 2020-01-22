#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

double dy(double x) {
	return 2.5 * exp(2.5 * x);
}

double f(double x) {
	return sqrt(1 + pow(dy(x), 2));
}

int main()
{
	double a = 0, b = 1, h = 0.125, sum = 0;
	vector<double> solT = { 0,0,0 }, solS = { 0,0,0 };

	for (int i = 0; i < 3; i++) {
		cout << "Iteracao " << i + 1 << endl;
		cout << "h = " << h << endl;

		//TRAPEZIOS
		sum = f(a);
		for (int j = 1; j < (b-a)/h; j++) {
			sum += 2 * f(a + j * h);
		}
		sum += f(b);

		solT[i] = h / 2 * sum;

		cout << "Solucao Trapezios = " << solT[i] << endl;

		//SIMPSON
		sum = f(a);
		for (int j = 1; j < (b - a) / h; j++) {
			if (j % 2 == 0)
				sum += 2 * f(a + j * h);
			else
				sum += 4 * f(a + j * h);
		}
		sum += f(b);

		solS[i] = h / 3 * sum;

		cout << "Solucao Simpson = " << solS[i] << endl;

		h /= 2;
	}

	double QCt = (solT[1] - solT[0]) / (solT[2] - solT[1]);
	double QCs = (solS[1] - solS[0]) / (solS[2] - solS[1]);

	cout << "QC Trapezios = " << QCt << endl;
	cout << "QC Simpson = " << QCs << endl;

	double eT = abs(solT[2] - solT[1]) / 3;
	double eS = abs(solS[2] - solS[1]) / 15;

	cout << "Erro Trapzeios = " << eT << endl;
	cout << "Erro Simpson = " << eS << endl;


}

