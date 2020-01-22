#include <math.h>
#include <iostream>

using namespace std;

double f(double x) {
	return -x + 40 * cos(sqrt(x)) + 3;
}

double df(double x) {
	return (-(20 * sin(sqrt(x))) / sqrt(x)) - 1;
}

int main()
{
	double guess = 1.7;

	for (int i = 0; i < 5; i++) {
		cout << "guess = " << guess << "\nf(guess) = " << f(guess) << endl;

		guess = guess - f(guess) / df(guess);
	}
}

