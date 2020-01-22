#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<double> f = { 1.04,0.37,0.38,1.49,1.08,0.13,0.64,0.84,0.12 };
	vector<double> res = { 0,0,0 };

	double err;

	double h = 1;
	double dx = 0.25;
	int counter = 1;

	for (int i = 0; i < 3; i++) {
		cout << "h: " << h << endl;
		res[i] = f[0];
		counter = 1;
		for (int j = h / dx; j < f.size() - h / dx; j += h / dx) {
			if (counter % 2 == 0)
				res[i] += 2 * f[j];
			else
				res[i] += 4 * f[j];
			counter++;
		}
		res[i] += f[8];
		res[i] *= h / 3.0;
		cout << "Solucao " << i << ": " << res[i] << endl;
		h /= 2;
	}

	err = (res[2] - res[1]) / 15.0;
	cout << "Erro: " << err << endl;
}
