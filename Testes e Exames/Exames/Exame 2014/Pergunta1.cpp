#include <math.h>
#include <iostream>

using namespace std;

double dT(double T) {
	return -0.25 * (T - 37);
}

int main()
{
	double T = 3;
	double t = 5;
	double h = 0.4;

	for (int i = 0; i < 3; i++) {
		cout << "Iteracao " << i << ": T = " << T << endl;

		T += h * dT(T);
		t += h;
	}
}

