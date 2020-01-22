#include <iostream>

using namespace std;

double dy(double x, double y) {
	return pow(x, 2) + pow(y, 2);
}

int main()
{
	double x0 = 0, y0 = 0, xn = 0, yn = 0, s1, s2, s3;
	double h1 = 0.0125, h2 = 0.00625, h3 = 0.003125;
	double deltay1, deltay2, deltay3, deltay4;

	cout << h1 << " -----------" << endl;
	for (int i = 0; i <= 112; i++) {
		x0 = xn;
		y0 = yn;
		cout << i << ": x = " << xn << "\t\ty = " << yn << endl;
		xn = x0 + h1;
		deltay1 = h1 * dy(x0, y0);
		deltay2 = h1 * dy(x0 + h1 / 2.0, y0 + deltay1 / 2.0);
		deltay3 = h1 * dy(x0 + h1 / 2.0, y0 + deltay2 / 2.0);
		deltay4 = h1 * dy(x0 + h1, y0 + deltay3);
		yn = y0 + deltay1/6.0 + deltay2/3.0 + deltay3/3.0 + deltay4/6.0;
	}
	s1 = y0;

	xn = 0; yn = 0;
	cout << endl << h2 << " -----------" << endl;
	for (int i = 0; i <= 224; i++) {
		x0 = xn;
		y0 = yn;
		cout << i << ": x = " << xn << "\t\ty = " << yn << endl;
		xn = x0 + h2;
		deltay1 = h2 * dy(x0, y0);
		deltay2 = h2 * dy(x0 + h2 / 2.0, y0 + deltay1 / 2.0);
		deltay3 = h2 * dy(x0 + h2 / 2.0, y0 + deltay2 / 2.0);
		deltay4 = h2 * dy(x0 + h2, y0 + deltay3);
		yn = y0 + deltay1 / 6.0 + deltay2 / 3.0 + deltay3 / 3.0 + deltay4 / 6.0;
	}
	s2 = y0;

	xn = 0; yn = 0;
	cout << endl << h3 << " -----------" << endl;
	for (int i = 0; i <= 448; i++) {
		x0 = xn;
		y0 = yn;
		cout << i << ": x = " << xn << "\t\ty = " << yn << endl;
		xn = x0 + h3;
		deltay1 = h3 * dy(x0, y0);
		deltay2 = h3 * dy(x0 + h3 / 2.0, y0 + deltay1 / 2.0);
		deltay3 = h3 * dy(x0 + h3 / 2.0, y0 + deltay2 / 2.0);
		deltay4 = h3 * dy(x0 + h3, y0 + deltay3);
		yn = y0 + deltay1 / 6.0 + deltay2 / 3.0 + deltay3 / 3.0 + deltay4 / 6.0;
	}
	s3 = y0;

	double QC = (s2 - s1) / (s3 - s2);

	cout << endl << "Quociente de convergencia: " << QC << endl;

	double E = s3 - s2;

	cout << endl << "Erro: " << E << endl;

}

