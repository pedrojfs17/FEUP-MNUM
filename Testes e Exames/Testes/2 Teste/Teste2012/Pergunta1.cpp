#include <vector>
#include <iostream>

using namespace std;

int main()
{
	vector<double> vertices = { 1.1,2.6,6.3,1.2 };
	vector<double> intermedios = { 1.4,2.1,2.2,1.5 };
	vector<double> centrais = { 4.9 };
	double hx = 0.9, hy = 0.9;

	double sol = 0;

	for (int i = 0; i < vertices.size(); i++) {
		sol += vertices[i];
	}
	for (int i = 0; i < intermedios.size(); i++) {
		sol += 4 * intermedios[i];
	}
	for (int i = 0; i < centrais.size(); i++) {
		sol += 16 * centrais[i];
	}

	sol *= hx * hy / 9.0;

	cout << "Solucao: " << sol << endl;
}
