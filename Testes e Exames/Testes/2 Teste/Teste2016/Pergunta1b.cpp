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
	double h = 0.25;

	int n = 0;

	while (n < 3) {
		cout << "N: " << n << endl;
		cout << "t: " << t << endl;
		cout << "c: " << c << endl;
		cout << "T: " << T << endl;
		cout << "-------------------------------------" << endl;
		t += h;
		temp = c;
		c += h * dC(T, c);
		T += h * dT(T, temp);
		n++;
	}


}