#include <math.h>
#include <iostream>

using namespace std;

double g(double x) {
	return pow(4 * pow(x, 3) - x + 3, (1.0 / 4.0));
}

int main()
{
	cout << fixed;
	cout.precision(5);

	double x = 3.5;

	for (int i = 0; i < 4; i++) {
		cout << "Iteracao " << i << ": x = " << x << endl;

		x = g(x);
	}
}
