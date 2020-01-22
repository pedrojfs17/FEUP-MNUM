#include <vector>
#include <iostream>

using namespace std;

double dz(double t, double z) {
	return 2 + pow(t, 2) + t * z;
}

int main()
{
	//z = dy/dt
	//dz = dz/dt = d^2y/dt^2

	double t = 1, y = 1, z = 0, h = 0.25, deltaz = 0;

	int n = 0;

	cout << "EULER\n";
	while (n < 3) {
		cout << "N: " << n << endl;
		cout << "t = " << t << endl;
		cout << "y = " << y << endl;
		cout << "-----------------------------------" << endl;

		deltaz = dz(t, z);
		t += h;
		y += h * z;
		z += h * deltaz;
		n++;
	}

	t = 1; y = 1; z = 0; n = 0;

	double deltay1, deltay2, deltay3, deltay4;
	double deltaz1, deltaz2, deltaz3, deltaz4;

	cout << "\nRK4\n";
	while (n < 3) {
		cout << "N: " << n << endl;
		cout << "t = " << t << endl;
		cout << "y = " << y << endl;
		cout << "-----------------------------------" << endl;

		deltay1 = h * z;
		deltaz1 = h * dz(t, z);
		deltay2 = h * (z + deltaz1 / 2.0);
		deltaz2 = h * (dz(t, z + deltaz1 / 2.0));
		deltay3 = h * (z + deltaz2 / 2.0);
		deltaz3 = h * (dz(t, z + deltaz2 / 2.0));
		deltay4 = h * (z + deltaz3);
		deltaz4 = h * (dz(t, z + deltaz3));

		t += h;
		y += deltay1 / 6.0 + deltay2 / 3.0 + deltay3 / 3.0 + deltay4 / 6.0;
		z += deltaz1 / 6.0 + deltaz2 / 3.0 + deltaz3 / 3.0 + deltaz4 / 6.0;
		n++;
	}
}
