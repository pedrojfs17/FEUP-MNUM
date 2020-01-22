#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	//PRIMEIRA PARTE
	/*
	double x1 = 1, x2 = 1, y1, y2;
	double step = 1;

	while (x1 <= 20) {
		x1 += step;
		y1 = exp(x1);
		//cout << "x = " << x1 << "\t\ty = " << y1 << endl;
	}

	step = 0.1;

	while (x2 <= 20) {
		x2 += step;
		y2 = exp(x2);
	}

	if (x1 == x2)
		cout << "Sao iguais!" << endl;
	else
		cout << "Nao sao iguais!" << endl;
	*/

	//SEGUNDA PARTE
	/*
	double x;
	
	cout << "Valor de x? ";
	cin >> x;

	double result = x/2, newresult;
	double low = 0, high = x;

	while (result * result != x)
	{
		if (result * result > x)
			high = result;
		else
			low = result;

		newresult = (high + low) / 2;

		if (newresult == result)
			break;
		result = newresult;
	}

	cout << "A raiz e: " << result << endl;
	*/
}

