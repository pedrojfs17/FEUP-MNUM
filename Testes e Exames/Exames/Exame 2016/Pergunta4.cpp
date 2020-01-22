#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

double f(double x) {
	return pow(x, 7) + 0.5 * x - 0.5;
}

int main()
{
	double x0 = 0.0, x1 = 0.8, temp;

	for (int i = 0; i < 5; i++) {
		cout << "Iteracao " << i << endl;
		cout << "x0 = " << x0 << "\nx1 = " << x1 << endl;

		temp = (x0 * f(x1) - x1 * f(x0)) / (f(x1) - f(x0));
		cout << "temp = " << temp << endl << endl;

		if (f(x0) * f(temp) < 0)
			x1 = temp;
		else
			x0 = temp;
	}
}
