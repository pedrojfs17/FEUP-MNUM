#include <math.h>
#include <iostream>

using namespace std;

double f(double x) {
	return pow(x, 3) - 10 * sin(x) + 2.8;
}

int main()
{
	double a = 1.5, b = 4.2, m;

	for (int i = 0; i < 3; i++) {
		cout << "Iteracao " << i << ": a = " << a << " e b = " << b << endl;

		m = (a + b) / 2;

		if (f(m) * f(a) < 0) {
			b = m;
		}
		else {
			a = m;
		}
	}
}

