#include <iostream>

using namespace std;

//METODO DE NEWTON

double f(double x) {
	return (2 * pow(x,2) - 5 * x - 2);
}

double df(double x) {
	return (4 * x - 5);
}

//METODO DE PICARD-PEANO

double g1(double x) {
	return (0.4 * pow(x, 2) - 0.4);
}

double g2(double x) {
	return (sqrt(2.5 * x + 1));
}

double dg1(double x) {
	return (0.8 * x);
}

double dg2(double x) {
	return (1.25 / sqrt(2.5 * x + 1));
}


int main()
{
	double guess, x, x1;

	cout << "Guess: ";
	cin >> guess;
	x = guess;

	//Newton
	for (int i = 0; i < 20; i++) {
		x = x - f(x) / df(x);
		cout << i << " iteracao: x = " << x << endl;
	}

	//Picard-Peano
	if (abs(dg1(x)) < 1) {
		for (int i = 0; i < 10; i++) {
			x = g1(x);
			cout << i << " iteracao: x = " << x << endl;
		}
	}
	else if (abs(dg2(x)) < 1) {
		for (int i = 0; i < 10; i++) {
			x = g2(x);
			cout << i << " iteracao: x = " << x << endl;
		}
	}
	else
		cout << "Divergente" << endl;
	
}