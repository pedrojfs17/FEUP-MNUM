#include <iostream>
#include <math.h>

using namespace std;

//METODO DE PICARD-PEANO

/* EXPRESSOES ERRADAS
double g1(double x, double y) {
	return ((-2 * pow(x, 2) + 5 * x - 1) / y);
}

double g2(double x, double y) {
	return ((x + 3 * log10(x)) / y);
}
*/

double g1(double x, double y) {
	return (sqrt((x * (y + 5) - 1) / 2));
}

double g2(double x, double y) {
	return (sqrt(x + 3*log(x)));
}


int main()
{
	double guess_x, guess_y, x, y, x1, y1, it = 0;

	cout << "Guess x: ";
	cin >> guess_x;
	x1 = guess_x;

	cout << "Guess y: ";
	cin >> guess_y;
	y1 = guess_y;

	//Picard-Peano
	do {
		x = x1;
		y = y1;
		x1 = g1(x, y);
		y1 = g2(x, y);
		cout << it << " iteracao: x = " << x << "\ty = " << y << endl;
		it++;
	} while (abs(x1 - x) > pow(10, -5) || abs(y1 - y) > pow(10, -5));
	

}