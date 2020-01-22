#include <iostream>
#include <vector>

using namespace std;

#define B ((sqrt(5) - 1) / 2.0)
#define A pow(B, 2)

double f(double x) {
	return pow(2 * x + 1, 2) - 5 * cos(10 * x);
}

double pesquisa(double guess, double step) {
	double x0 = guess;
	double x1 = guess + step;
	double x2 = guess + 2 * step;
	cout << "PESQUISA:\n";

	while (f(x1) > f(x2)) {
		x0 = x1;
		x1 = x2;
		x2 += step;
		cout << "x0 = " << x0 << "\t\tsin(x0) = " << f(x0) << endl;
		cout << "x1 = " << x1 << "\t\tsin(x1) = " << f(x1) << endl;
		cout << "x2 = " << x2 << "\t\tsin(x2) = " << f(x2) << endl;
		cout << "---------------------------------------------------------\n";
	}

	cout << endl;
	return x0;
}

vector<double> terços(double x1, double x2) {
	double x3, x4;
	cout << "TERCOS:\n";

	while (abs(x2 - x1) > pow(10,-4)) {
		x3 = x1 + (x2 - x1) / 3.0;
		x4 = x1 + 2 * (x2 - x1) / 3.0;
		cout << "x1 = " << x1 << "\t\tx2 = " << x2 << endl;
		cout << "x3 = " << x3 << "\t\tx4 = " << x4 << endl;
		cout << "---------------------------------------------------------\n";
		if (f(x4) < f(x3))
			x1 = x3;
		else
			x2 = x4;
	}

	cout << "Intervalo: " << x1 << " a " << x2 << endl << endl;
	vector<double> res = {x1,x2};
	return res;
}

double quadratica(double x1, double x2, double x3) {
	cout << "AJUSTE DA QUADRATICA:\n";

	double h = (x3 - x1) / 2.0;

	return x2 + h * (f(x1) - f(x3)) / (2 * (f(x3) - 2 * f(x2) + f(x1)));
}

vector<double> seccaoAureaMin(double x1, double x2) {
	double x3 = x1 + A * (x2 - x1);
	double x4 = x1 + B * (x2 - x1);

	cout << "SECCAO AUREA:\n";

	while (abs(x2 - x1) > pow(10, -3)) {
		cout << "x1 = " << x1 << "\t\tx2 = " << x2 << endl;
		cout << "x3 = " << x3 << "\t\tx4 = " << x4 << endl;
		cout << "f(x1) = " << f(x1) << "\t\tf(x2) = " << f(x2) << endl;
		cout << "f(x3) = " << f(x3) << "\t\tf(x4) = " << f(x4) << endl;
		cout << "---------------------------------------------------------\n";
		if (f(x3) < f(x4)) {
			x2 = x4;
		}
		else {
			x1 = x3;
		}
		x3 = x1 + A * (x2 - x1);
		x4 = x1 + B * (x2 - x1);
	}

	cout << "Intervalo: " << x1 << " a " << x2 << endl << endl;
	vector<double> res = { x1,x2 };
	return res;
}

vector<double> seccaoAureaMax(double x1, double x2) {
	double x3 = x1 + A * (x2 - x1);
	double x4 = x1 + B * (x2 - x1);

	cout << "SECCAO AUREA:\n";

	while (abs(x2 - x1) > pow(10, -3)) {
		cout << "x1 = " << x1 << "\t\tx2 = " << x2 << endl;
		cout << "x3 = " << x3 << "\t\tx4 = " << x4 << endl;
		cout << "f(x1) = " << f(x1) << "\t\tf(x2) = " << f(x2) << endl;
		cout << "f(x3) = " << f(x3) << "\t\tf(x4) = " << f(x4) << endl;
		cout << "---------------------------------------------------------\n";
		if (f(x3) > f(x4)) {
			x2 = x4;
		}
		else {
			x1 = x3;
		}
		x3 = x1 + A * (x2 - x1);
		x4 = x1 + B * (x2 - x1);
	}

	cout << "Intervalo: " << x1 << " a " << x2 << endl << endl;
	vector<double> res = { x1,x2 };
	return res;
}

int main()
{
	//PESQUISA
	/*
	double guess = -1;
	double step = 0.1;

	if (f(guess) < f(guess + step))
		step = -step;

	double x0 = pesquisa(guess, step);
	double x2 = x0 + 2 * step;
	*/
	
	double x0 = -1;
	double x2 = 0;

	/*
	//METODO DOS TERÇOS
	vector<double> tercos = terços(x0, x2);
	x0 = tercos[0];
	x2 = tercos[1];
	*/

	//METODO DA SECÇAO AUREA
	//MINIMO
	vector<double> tercos = seccaoAureaMin(x0, x2);
	x0 = tercos[0];
	x2 = tercos[1];
	double min = x0;
	//MAXIMO
	x0 = -1;
	x2 = 0;
	tercos = seccaoAureaMax(x0, x2);
	x0 = tercos[0];
	x2 = tercos[1];
	double max = x0;

	//AJUSTE DA QUADRATICA
	/*
	double h = (x2 - x0) / 2.0;
	double x1 = x0 + h;
	

	double min = quadratica(x0,x1,x2);
	*/

	//RESULTADO
	cout << "Minimo: " << min << endl;
	cout << "f(min): " << f(min) << endl;
	cout << "Maximo: " << max << endl;
	cout << "f(max): " << f(max) << endl;
}

