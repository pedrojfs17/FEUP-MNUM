#include <iostream>
using namespace std;

double first(double x2, double x3, double x4) {
	return (1 + x2 + x3 - x4) / 4.5;
}

double second(double x1, double x3, double x4) {
	return (-1 + x1 - x3 + x4) / 4.5;
}

double third(double x1, double x2, double x4) {
	return (-1 + x1 - 2 * x2 + x4) / 4.5;
}

double fourth(double x1, double x2, double x3) {
	return (0 - 2 * x1 + x2 + x3) / 4.5;
}

int main()
{
	double x1 = 0.25, x2 = 0.25, x3 = 0.25, x4 = 0.25;
	double nextx1, nextx2, nextx3, nextx4;

	//Gauss-Jacobi
	nextx1 = first(x2, x3, x4);
	nextx2 = second(x1, x3, x4);
	nextx3 = third(x1, x2, x4);
	nextx4 = fourth(x1, x2, x3);

	int n = 1;
	cout << "N = " << n << endl;
	cout << x1 << " para " << nextx1 << endl;
	cout << x2 << " para " << nextx2 << endl;
	cout << x3 << " para " << nextx3 << endl;
	cout << x4 << " para " << nextx4 << endl << endl;

	while (n < 2) {
		x1 = nextx1;
		x2 = nextx2;
		x3 = nextx3;
		x4 = nextx4;
		n++;

		//Gauss-Jacobi 
		nextx1 = first(x2, x3, x4);
		nextx2 = second(x1, x3, x4);
		nextx3 = third(x1, x2, x4);
		nextx4 = fourth(x1, x2, x3);

		cout << "N = " << n << endl;
		cout << x1 << " para " << nextx1 << endl;
		cout << x2 << " para " << nextx2 << endl;
		cout << x3 << " para " << nextx3 << endl;
		cout << x4 << " para " << nextx4 << endl << endl;

	}

}