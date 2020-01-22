#include <math.h>
#include <iostream>

using namespace std;

double dz(double t, double y, double z) {
	return 0.5 + pow(t, 2) + t * z;
}

double dy(double t, double y, double z) {
	return z;
}

int main()
{
	double t = 0, y = 0, z = 1;
	double h = 0.25;
	double temp;

	//EULER
	cout << "EULER\n";
	for (int i = 0; i < 3; i++) {
		cout << "Iteracao " << i << endl;
		cout << "t = " << t << endl;
		cout << "y = " << y << endl << endl;

		temp = z;
		z += h * dz(t, y, z);
		y += h * dy(t, y, temp);
		t += h;
	}

	//RK4
	double deltay1, deltay2, deltay3, deltay4;
	double deltaz1, deltaz2, deltaz3, deltaz4;
	t = 0; y = 0.0; z = 1.0; h = 0.25;

	cout << "RK4\n";
	for (int i = 0; i < 3; i++) {
		cout << "Iteracao " << i << endl;
		cout << "t = " << t << endl;
		cout << "y = " << y << endl << endl;

		deltay1 = h * dy(t, y, z);
		deltaz1 = h * dz(t, y, z);
		deltay2 = h * dy(t + h / 2.0, y + deltay1 / 2.0, z + deltaz1 / 2.0);
		deltaz2 = h * dz(t + h / 2.0, y + deltay1 / 2.0, z + deltaz1 / 2.0);
		deltay3 = h * dy(t + h / 2.0, y + deltay2 / 2.0, z + deltaz2 / 2.0);
		deltaz3 = h * dz(t + h / 2.0, y + deltay2 / 2.0, z + deltaz2 / 2.0);
		deltay4 = h * dy(t + h, y + deltay3, z + deltaz3);
		deltaz4 = h * dz(t + h, y + deltay3, z + deltaz3);

		t += h;
		y += deltay1 / 6.0 + deltay2 / 3.0 + deltay3 / 3.0 + deltay4 / 6.0;
		z += deltaz1 / 6.0 + deltaz2 / 3.0 + deltaz3 / 3.0 + deltaz4 / 6.0;
	}

}

