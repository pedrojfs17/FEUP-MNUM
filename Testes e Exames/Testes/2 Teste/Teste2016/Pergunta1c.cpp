#include <iostream>
#include <math.h>

using namespace std;

double dC(double t, double c) {
	return -exp(-0.5 / (t + 273)) * c;
}

double dT(double t, double c) {
	return 20 * exp(-0.5 / (t + 273)) * c - 0.5 * (t - 20);
}

int main()
{
	double t = 0;
	double c = 1.0, T = 15.0, temp;
	double h = 0.25, h1 = 0.125, h2 = 0.0625;
	double sol1, sol2, sol3;

	int n = 0;

	cout << "\nH -> " << h << endl;

	while (n < 3) {
		cout << "N: " << n << endl;
		cout << "t: " << t << endl;
		cout << "c: " << c << endl;
		cout << "T: " << T << endl;
		cout << "-------------------------------------" << endl;
		sol1 = c;
		t += h;
		temp = c;
		c += h * dC(T, c);
		T += h * dT(T, temp);
		n++;
	}

	cout << "\nH -> " << h1 << endl;
	n = 0; t = 0; c = 1; t = 15;

	while (n < 6) {
		cout << "N: " << n << endl;
		cout << "t: " << t << endl;
		cout << "c: " << c << endl;
		cout << "T: " << T << endl;
		cout << "-------------------------------------" << endl;
		sol2 = c;
		t += h1;
		temp = c;
		c += h1 * dC(T, c);
		T += h1 * dT(T, temp);
		n++;
	}

	cout << "\nH -> " << h2 << endl;
	n = 0; t = 0; c = 1; t = 15;

	while (n < 12) {
		cout << "N: " << n << endl;
		cout << "t: " << t << endl;
		cout << "c: " << c << endl;
		cout << "T: " << T << endl;
		cout << "-------------------------------------" << endl;
		sol3 = c;
		t += h2;
		temp = c;
		c += h2 * dC(T, c);
		T += h2 * dT(T, temp);
		n++;
	}

	cout << endl << "C: " << sol1 << endl << "C1: " << sol2 << endl << "C2: " << sol3 << endl;

	double QC = (sol2 - sol1) / (sol3 - sol2);
	double erro = sol3 - sol2;

	cout << "QC: " << QC << endl << "Erro: " << erro << endl;


}
