#include <vector>
#include <iostream>

using namespace std;

int main()
{
	vector<double> f = { 0.36,1.19,1.32,0.21,1.15,1.39,0.12,1.22,0.6 };
	double dx = 0.25;

	vector<double> sol = { 0,0,0 };

	double h = 1;
	int counter;

	for (int i = 0; i < 3; i++) {
		sol[i] = f[0];
		counter = 1;

		for (int j = h / dx; j < f.size() - h / dx; j += h/dx) {
			if (counter % 2 == 0)
				sol[i] += 2 * f[j];
			else
				sol[i] += 4 * f[j];
			counter++;
		}

		sol[i] += f[8];
		sol[i] *= h / 3.0;

		h /= 2;
	}

	for (int i = 0; i < 3; i++) {
		cout << "Solucao " << i + 1 << ": " << sol[i] << endl;
	}

	cout << "Erro: " << ((sol[2] - sol[1]) / 15.0) << endl;
}