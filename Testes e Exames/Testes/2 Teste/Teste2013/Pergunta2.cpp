#include < vector>
#include <iostream>
#include <math.h>

using namespace std;

double dx(double x, double t) {
	return sin(2 * x) + sin(2 * t);
}

int main()
{
	double t = 1, x = 1;
	double delta1, delta2, delta3, delta4;
	vector<double> sol = { 1,1,1 };
	double h = 0.5;

	for (int i = 0; i < 3; i++) {
		cout << "H = " << h << endl;
		x = 1;
		for (t = 1; t <= 1.5; t += h) {
			cout << "t = " << t << endl;
			cout << "x = " << x << endl;
			sol[i] = x;
			delta1 = h * dx(x, t);
			delta2 = h * dx(x + h / 2.0, t + delta1 / 2.0);
			delta3 = h * dx(x + h / 2.0, t + delta2 / 2.0);
			delta4 = h * dx(x + h, t + delta3);
			x += delta1 / 6.0 + delta2 / 3.0 + delta3 / 3.0 + delta4 / 6.0;
		}
		cout << "---------------------------" << endl;
		h /= 2;
	}

	for (int i = 0; i < 3; i++) {
		cout << sol[i] << endl;
	}
	double QC = (sol[1] - sol[0]) / (sol[2] - sol[1]);
	cout << endl << "QC: " << QC << endl;
}
