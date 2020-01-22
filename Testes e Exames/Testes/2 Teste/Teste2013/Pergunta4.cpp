#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

double dC(double C, double T) {
	return -exp(-0.5 / (T + 273.0)) * C;
}

double dT(double C, double T) {
	return 20.0 * exp(-0.5 / (T + 273.0)) * C - 0.5 * (T - 20.0);
}

int main()
{
	double t = 0;
	double C = 2.0, T = 20.0;
	double h = 0.2;
	double temp;

	//EULER
	for (int i = 0; i < 3; i++) {
		cout << "Iteracao " << i << endl;
		cout << "t = " << t << endl;
		cout << "C = " << C << endl;
		cout << "T = " << T << endl;

		t += h;
		temp = C;
		C += h * dC(C, T);
		T += h * dT(temp, T);
	}

	//RUNGE-KUTTA 4 ORDEM
	double deltat1, deltat2, deltat3, deltat4;
	double deltac1, deltac2, deltac3, deltac4;

	for (int i = 0; i < 3; i++) {
		cout << "Iteracao " << i << endl;
		cout << "t = " << t << endl;
		cout << "C = " << C << endl;
		cout << "T = " << T << endl;

		t += h;

		deltac1 = h * dC(C, T);
		deltat1 = h * dT(C, T);
		deltac2 = h * dC(C + deltac1 / 2.0, T + h / 2.0);
		deltat2 = h * dT(C + h / 2.0, T + deltat1 / 2.0);
		deltac3 = h * dC(C + deltac2 / 2.0, T + h / 2.0);
		deltat3 = h * dT(C + h / 2.0, T + deltat2 / 2.0);
		deltac4 = h * dC(C + deltac3, T + h);
		deltat4 = h * dT(C + h, T + deltat3);
		C += deltac1 / 6.0 + deltac2 / 3.0 + deltac3 / 3.0 + deltac4 / 6.0;
		T += deltat1 / 6.0 + deltat2 / 3.0 + deltat3 / 3.0 + deltat4 / 6.0;
	}
}

