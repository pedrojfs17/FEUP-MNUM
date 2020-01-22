#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

double dz(double x, double y, double z) {
	return -7 * z - 4 * y;
}

double dy(double x, double y, double z) {
	return z;
}

int main()
{
	cout << fixed;
	cout.precision(5);
	
	double h = 0.2;
	double x = 0.4, y = 2.0, z = 1.0, temp;

	for (int i = 0; i < 5; i++) {
		cout << "Iteracao " << i << endl;
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
		cout << "z = " << z << endl << endl;

		temp = y;
		y += h * dy(x, y, z);
		z += h * dz(x, temp, z);
		x += h;
	}
}

