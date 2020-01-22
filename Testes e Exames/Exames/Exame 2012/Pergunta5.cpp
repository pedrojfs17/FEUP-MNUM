#include <math.h>
#include <iostream>

using namespace std;

double f(double x) {
	return x - 3.7 + pow(cos(x + 1.2), 3);
}

double df(double x) {
	return 1 - 3 * pow(cos(x + 1.2), 2) * sin(x + 1.2);
}

int main()
{
	cout << fixed;
	cout.precision(5);

	double x = 3.8;

	for (int i = 0; i < 3; i++) {
		cout << "Iteracao " << i << ": x = " << x << endl;

		x -= f(x) / df(x);
	}
}
