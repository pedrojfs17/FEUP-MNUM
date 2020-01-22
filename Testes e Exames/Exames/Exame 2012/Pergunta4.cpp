#include <math.h> 
#include <iostream>
#include <vector>

using namespace std;

double f(double x) {
	return exp(1.5 * x);
}

int main()
{
	//cout << fixed;
	//cout.precision(7);

	double h = 0.125, a = 1, b = 1.5;
	double sumS;
	vector<double> solS = { 0,0,0 };
	int counter;

	for (int i = 0; i < 3; i++) {
		cout << "H = " << h << endl;

		sumS = f(a);
		counter = 1;
		for (double j = a + h; j < b; j += h) {
			if (counter % 2 == 0)
				sumS += 2 * f(j);
			else
				sumS += 4 * f(j);
			counter++;
		}
		sumS += f(b);
		solS[i] = h / 3.0 * sumS;
		cout << "Solucao = " << solS[i] << endl << endl;
		h /= 2;
	}

	cout << "QC = " << (solS[1] - solS[0]) / (solS[2] - solS[1]) << endl;
	cout << "Erro = " << (solS[2] - solS[1]) / 15.0 << endl;

	cout << "Erro relativo = " << abs(solS[2] - 3.337364510680308) / 3.337364510680308 << endl;
}
