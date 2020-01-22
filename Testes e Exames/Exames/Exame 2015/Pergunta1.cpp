#include <cmath>
#include <iostream>

using namespace std;

double g(double x) {
	return -x + 50 * cos(sqrt(x)) + 1;
}

double dg(double x) {
	return (-25 * sin(sqrt(x)) / sqrt(x)) - 1;
}

int main()
{
	cout << fixed;
	cout.precision(5);

	double x = 2.0;

	for (int i = 0; i < 4; i++) {
		cout << "Iteracao " << i << "\tx = " << x << "\tg(x) = " << g(x) << endl;

		x -= g(x) / dg(x);
	}
}

