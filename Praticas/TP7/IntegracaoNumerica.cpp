// IntegracaoNumerica.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define M_PI           3.14159265358979323846
#include <iostream>
#include <math.h>
using namespace std;

double f(double x) {
	return sin(x) / pow(x, 2);
}

int main()
{
	//ALINEA 1
	
	double h = M_PI / 8;
	double solT, solS;
	double sumT = 0, sumS = 0, a = M_PI/2, b = M_PI;

	//TRAPEZIOS
	sumT = f(a);
	for (int n = 1; n < 4; n++) {
		sumT += 2 * f(a + n * h);
	}
	sumT += f(b);
	solT = h / 2 * sumT;

	cout << "Solucao Trapezios: " << solT << endl;

	//SIMPSON
	sumS = f(a);
	for (int n = 1; n < 4; n++) {
		if (n % 2 == 0)
			sumS += 2 * f(a + n * h);
		else
			sumS += 4 * f(a + n * h);
	}
	sumS += f(b);
	solS = h / 3 * sumS;
	
	cout << "Solucao Simpson: " << solS << endl << endl;

	//ALINEA 2
	double h1 = M_PI / 16, h2 = M_PI / 32;
	double solT1, solT2, solS1, solS2, QCT, QCS;

	//TRAPEZIOS
	sumT = f(a);
	for (int n = 1; n < 8; n++) {
		sumT += 2 * f(a + n * h1);
	}
	sumT += f(b);
	solT1 = h1 / 2 * sumT;

	cout << "Solucao Trapezios 1: " << solT1 << endl;

	sumT = f(a);
	for (int n = 1; n < 16; n++) {
		sumT += 2 * f(a + n * h2);
	}
	sumT += f(b);
	solT2 = h2 / 2 * sumT;

	cout << "Solucao Trapezios 2: " << solT2 << endl;

	QCT = (solT1 - solT) / (solT2 - solT1);

	cout << "Quociente Trapezios: " << QCT << endl << endl;

	//SIMPSON
	sumS = f(a);
	for (int n = 1; n < 8; n++) {
		if (n % 2 == 0)
			sumS += 2 * f(a + n * h1);
		else
			sumS += 4 * f(a + n * h1);
	}
	sumS += f(b);
	solS1 = h1 / 3 * sumS;

	cout << "Solucao Simpson 1: " << solS1 << endl;

	sumS = f(a);
	for (int n = 1; n < 16; n++) {
		if (n % 2 == 0)
			sumS += 2 * f(a + n * h2);
		else
			sumS += 4 * f(a + n * h2);
	}
	sumS += f(b);
	solS2 = h2 / 3 * sumS;

	cout << "Solucao Simpson 2: " << solS2 << endl;

	QCS = (solS1 - solS) / (solS2 - solS1);

	cout << "Quociente Simpson: " << QCS << endl << endl;

	//NOVO QUOCIENTE

	double solS3;
	double h3 = M_PI / 64;

	sumS = f(a);
	for (int n = 1; n < 32; n++) {
		if (n % 2 == 0)
			sumS += 2 * f(a + n * h3);
		else
			sumS += 4 * f(a + n * h3);
	}
	sumS += f(b);
	solS3 = h3 / 3 * sumS;

	cout << "Solucao Simpson 3: " << solS3 << endl;

	QCS = (solS2 - solS1) / (solS3 - solS2);

	cout << "Quociente Simpson: " << QCS << endl << endl;

	//ALINEA 3
	double eT, eS;

	eT = abs((solT2 - solT1) / 3);
	eS = abs((solS3 - solS2) / 15);

	cout << "Erro Trapezios: " << eT << endl;
	cout << "Erro Simpson: " << eS << endl;

}
