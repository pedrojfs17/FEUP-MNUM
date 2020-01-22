#include <iostream>
#include <vector>

using namespace std;


int main()
{
	vector<double> f = { 0.18,0.91,0.83,1.23,0.88,1.37,0.8,1.34,0.43 };
	vector<double> res = { 0,0,0 };

	double dx = 0.2;
	double h = 0.8;
	int counter;

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

		res[i] += f[f.size() - 1];
		res[i] *= h / 3.0;
		cout << "Solucao " << i << ": " << res[i] << endl;
		h /= 2;
	}

	double err = (res[2] - res[1]) / 15.0;

	cout << "Erro: " << err << endl;
}
