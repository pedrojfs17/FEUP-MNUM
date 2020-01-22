#include <vector>
#include <iostream>

using namespace std;

double first(double x1, double x2, double x3, double x4) {
	return (1 + x2 + x3 - x4) / 4.5;
}

double second(double x1, double x2, double x3, double x4) {
	return (-1 + x1 - x3 + x4) / 4.5;
}

double third(double x1, double x2, double x3, double x4) {
	return (-1 + x1 - 2 * x2 + x4) / 4.5;
}

double fourth(double x1, double x2, double x3, double x4) {
	return (0 - 2 * x1 + x2 + x3) / 4.5;
}

int main()
{
	double x1 = 0.25, x2 = 0.25, x3 = 0.25, x4 = 0.25;
	double next1, next2, next3, next4;

	next1 = first(x1, x2, x3, x4);
	next2 = second(x1, x2, x3, x4);
	next3 = third(x1, x2, x3, x4);
	next4 = fourth(x1, x2, x3, x4);

	for (int i = 1; i < 3; i++) {
		cout << "Iteracao: " << i << endl;
		cout << "x1 = " << next1 << endl;
		cout << "x2 = " << next2 << endl;
		cout << "x3 = " << next3 << endl;
		cout << "x4 = " << next4 << endl;

		x1 = next1; 
		x2 = next2;
		x3 = next3;
		x4 = next4;

		next1 = first(x1, x2, x3, x4);
		next2 = second(x1, x2, x3, x4);
		next3 = third(x1, x2, x3, x4);
		next4 = fourth(x1, x2, x3, x4);
	}

}