#include <cmath>
#include <iostream>

using namespace std;

#define K 20.0

double dx(double t, double x, double z) {
	return z;
}

double dz(double t, double x, double z) {
	return (-z - K * x) / 20.0;
}

int main()
{
	cout << fixed;
	cout.precision(5);

	//t, x, z = dx/dt

	double t = 0, x = 1, z = 0;
	double h = 0.1;
	double temp;

	for (int i = 0; i < 51; i++) {
		cout << "Iteracao " << i << ":\tt = " << t << "\tx = " << x << endl;

		temp = x;
		x += h * dx(t, x, z);
		z += h * dz(t, temp, z);
		t += h;
	}
	
}


