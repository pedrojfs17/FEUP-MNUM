#include <math.h>
#include <iostream>

using namespace std;

double dC(double C, double T) {
	return -exp(-0.5 / (T + 273.0)) * C;
}

double dT(double C, double T) {
	return 30.0 * exp(-0.5 / (T + 273)) * C - 0.5 * (T - 20.0);
}

int main()
{
	double t = 0.0, h = 0.25;
	double C = 2.5, T = 25.0, temp;

	//EULER
	for (int i = 0; i < 3; i++) {
		cout << "iteracao " << i << ": t = " << t << endl;
		cout << "C = " << C << endl;
		cout << "T = " << T << endl;

		temp = C;
		C += h * dC(C, T);
		T += h * dT(temp, T);
		t += h;
	}

	//RK4
	double deltac1, deltac2, deltac3, deltac4;
	double deltat1, deltat2, deltat3, deltat4;

	t = 0.0; h = 0.25; C = 2.5; T = 25.0;

	cout << endl << "RK4" << endl;

	for (int i = 0; i < 3; i++) {
		cout << "iteracao " << i << ": t = " << t << endl;
		cout << "C = " << C << endl;
		cout << "T = " << T << endl;

		deltac1 = h * dC(C, T);
		deltat1 = h * dT(C, T);
		deltac2 = h * dC(C + deltac1 / 2.0, T + deltat1 / 2.0);
		deltat2 = h * dT(C + deltac1 / 2.0, T + deltat1 / 2.0);
		deltac3 = h * dC(C + deltac2 / 2.0, T + deltat2 / 2.0);
		deltat3 = h * dT(C + deltac2 / 2.0, T + deltat2 / 2.0);
		deltac4 = h * dC(C + deltac3, T + deltat3);
		deltat4 = h * dT(C + deltac3, T + deltat3);

		C += deltac1 / 6.0 + deltac2 / 3.0 + deltac3 / 3.0 + deltac4 / 6.0;
		T += deltat1 / 6.0 + deltat2 / 3.0 + deltat3 / 3.0 + deltat4 / 6.0;
		t += h;
	}
}

