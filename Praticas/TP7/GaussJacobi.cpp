#include <iostream>
using namespace std;

double first(double x2, double x3) {
	return (7 - x2 - x3) / 3;
}

double second(double x1, double x3) {
	return (4 - x1 - 2*x3) / 4;
}

double third(double x2) {
	return (5 - 2*x2) / 5;
}

int main()
{
	double x1 = 0, x2 = 0, x3 = 0;
	double nextx1, nextx2, nextx3;

	//Gauss-Jacobi
	/*nextx1 = first(x2,x3);
	nextx2 = second(x1, x3);
	nextx3 = third(x2);*/

	//Gauss-Seidel
	nextx1 = first(x2, x3);
	nextx2 = second(nextx1, x3);
	nextx3 = third(nextx2);

	int n = 1;
	cout << "N = " << n << endl;
	cout << x1 << " para " << nextx1 << endl;
	cout << x2 << " para " << nextx2 << endl;
	cout << x3 << " para " << nextx3 << endl << endl;

	while (abs(nextx1 - x1) > pow(10, -3) || abs(nextx2 - x2) > pow(10, -3) || abs(nextx3 - x3) > pow(10, -3)) {
		x1 = nextx1;
		x2 = nextx2;
		x3 = nextx3;
		n++;

		//Gauss-Jacobi 
		/*nextx1 = first(x2, x3);
		nextx2 = second(x1, x3);
		nextx3 = third(x2);*/

		//Gauss-Seidel
		nextx1 = first(x2, x3);
		nextx2 = second(nextx1, x3);
		nextx3 = third(nextx2);

		cout << "N = " << n << endl;
		cout << x1 << " para " << nextx1 << endl;
		cout << x2 << " para " << nextx2 << endl;
		cout << x3 << " para " << nextx3 << endl << endl;

	}

}
