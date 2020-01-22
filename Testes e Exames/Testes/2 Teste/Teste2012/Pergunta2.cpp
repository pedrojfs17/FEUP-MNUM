#include <vector>
#include <iostream>

using namespace std;

double f1(double x1, double x2, double x3, double x4) {
	return (1 + x2 + x3 - x4) / 4.8;
}

double f2(double x1, double x2, double x3, double x4) {
	return (-1 + x1 - x3 + x4) / 4.8;
}

double f3(double x1, double x2, double x3, double x4) {
	return (-1 + x1 - 2 * x2 + x4) / 4.8;
}

double f4(double x1, double x2, double x3, double x4) {
	return (0 - 2 * x1 + x2 + x3) / 4.8;
}

int main()
{
	double x1 = 0, x2 = 0, x3 = 0, x4 = 0;
	double next1, next2, next3, next4;

	next1 = f1(x1, x2, x3, x4);
	next2 = f2(next1, x2, x3, x4);
	next3 = f3(next1, next2, x3, x4);
	next4 = f4(next1, next2, next3, x4);

	for (int i = 0; i < 2; i++) {
		cout << "Iteracao: " << i << endl;
		cout << "x1 = " << next1 << endl;
		cout << "x2 = " << next2 << endl;
		cout << "x3 = " << next3 << endl;
		cout << "x4 = " << next4 << endl;

		x1 = next1;
		x2 = next2;
		x3 = next3;
		x4 = next4;

		next1 = f1(x1, x2, x3, x4);
		next2 = f2(next1, x2, x3, x4);
		next3 = f3(next1, next2, x3, x4);
		next4 = f4(next1, next2, next3, x4);
	}
}
