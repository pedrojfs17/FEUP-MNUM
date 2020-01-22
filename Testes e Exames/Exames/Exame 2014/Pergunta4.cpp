#include <math.h>
#include <iostream>

using namespace std;

double f(double x) {
	return 2 * log(2 * x);
}

int main()
{
	double guess = 1.1;

	cout << f(guess) << endl;
}

