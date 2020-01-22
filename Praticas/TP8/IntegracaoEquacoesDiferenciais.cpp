#include <iostream>

using namespace std;

double dy(double x, double y) {
	return pow(x, 2) + pow(y, 2);
}

int main()
{
	double x0 = 0, y0 = 0, xn = 0, yn = 0, s1, s2, s3;
	double h1 = 0.1, h2 = 0.05, h3 = 0.025;

	cout << h1 << " -----------" << endl;
	for (int i = 0; i <= 14; i++) {
		x0 = xn;
		y0 = yn;
		cout << i << ": x = " << xn << "\t\ty = " << yn << endl;
		xn = x0 + h1;
		yn = y0 + h1 * dy(x0, y0);
	}
	s1 = y0;

	xn = 0; yn = 0;
	cout << endl << h2 << " -----------" << endl;
	for (int i = 0; i <= 28; i++) {
		x0 = xn;
		y0 = yn;
		cout << i << ": x = " << xn << "\t\ty = " << yn << endl;
		xn = x0 + h2;
		yn = y0 + h2 * dy(x0, y0);
	}
	s2 = y0;

	xn = 0; yn = 0;
	cout << endl << h3 << " -----------" << endl;
	for (int i = 0; i <= 56; i++) {
		x0 = xn;
		y0 = yn;
		cout << i << ": x = " << xn << "\t\ty = " << yn << endl;
		xn = x0 + h3;
		yn = y0 + h3 * dy(x0, y0);
	}
	s3 = y0;
	
	double QC = (s2 - s1) / (s3 - s2);

	cout << endl << "Quociente de convergencia: " << QC << endl;

	double E = s3 - s2;

	cout << endl << "Erro: " << E << endl;

}

