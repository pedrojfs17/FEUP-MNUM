#include <iostream>

using namespace std;

double f(double x, double y, double z) {
	return z * y + x;
}

double g(double x, double y, double z) {
	return z * x + y;
}

int main()
{
	double x0 = 0, y0 = 1, z0 = 1, xn = 0, yn = 1, zn = 1, sy1, sy2, sy3, sz1, sz2, sz3;
	double h1 = 0.0125, h2 = 0.00625, h3 = 0.003125;
	double deltay1, deltay2, deltay3, deltay4;
	double deltaz1, deltaz2, deltaz3, deltaz4;

	cout << h1 << " -----------" << endl;
	for (int i = 0; i <= 40; i++) {
		x0 = xn;
		y0 = yn;
		z0 = zn;
		cout << i << ": x = " << xn << "\t\ty = " << yn << "\t\tz = " << zn << endl;
		xn = x0 + h1;
		deltay1 = h1 * f(x0, y0, z0);
		deltaz1 = h1 * g(x0, y0, z0);
		deltay2 = h1 * f(x0 + h1 / 2.0, y0 + deltay1 / 2.0, z0 + deltaz1 / 2.0);
		deltaz2 = h1 * g(x0 + h1 / 2.0, y0 + deltay1 / 2.0, z0 + deltaz1 / 2.0);
		deltay3 = h1 * f(x0 + h1 / 2.0, y0 + deltay2 / 2.0, z0 + deltaz2 / 2.0);
		deltaz3 = h1 * g(x0 + h1 / 2.0, y0 + deltay2 / 2.0, z0 + deltaz2 / 2.0);
		deltay4 = h1 * f(x0 + h1, y0 + deltay3, z0 + deltaz3);
		deltaz4 = h1 * g(x0 + h1, y0 + deltay3, z0 + deltaz3);
		yn = y0 + deltay1 / 6.0 + deltay2 / 3.0 + deltay3 / 3.0 + deltay4 / 6.0;
		zn = z0 + deltaz1 / 6.0 + deltaz2 / 3.0 + deltaz3 / 3.0 + deltaz4 / 6.0;
	}
	sy1 = y0;
	sz1 = z0;

	xn = 0; yn = 1; zn = 1;
	cout << endl << h2 << " -----------" << endl;
	for (int i = 0; i <= 80; i++) {
		x0 = xn;
		y0 = yn;
		z0 = zn;
		cout << i << ": x = " << xn << "\t\ty = " << yn << "\t\tz = " << zn << endl;
		xn = x0 + h2;
		deltay1 = h2 * f(x0, y0, z0);
		deltaz1 = h2 * g(x0, y0, z0);
		deltay2 = h2 * f(x0 + h2 / 2.0, y0 + deltay1 / 2.0, z0 + deltaz1 / 2.0);
		deltaz2 = h2 * g(x0 + h2 / 2.0, y0 + deltay1 / 2.0, z0 + deltaz1 / 2.0);
		deltay3 = h2 * f(x0 + h2 / 2.0, y0 + deltay2 / 2.0, z0 + deltaz2 / 2.0);
		deltaz3 = h2 * g(x0 + h2 / 2.0, y0 + deltay2 / 2.0, z0 + deltaz2 / 2.0);
		deltay4 = h2 * f(x0 + h2, y0 + deltay3, z0 + deltaz3);
		deltaz4 = h2 * g(x0 + h2, y0 + deltay3, z0 + deltaz3);
		yn = y0 + deltay1 / 6.0 + deltay2 / 3.0 + deltay3 / 3.0 + deltay4 / 6.0;
		zn = z0 + deltaz1 / 6.0 + deltaz2 / 3.0 + deltaz3 / 3.0 + deltaz4 / 6.0;
	}
	sy2 = y0;
	sz2 = z0;

	xn = 0; yn = 1; zn = 1;
	cout << endl << h3 << " -----------" << endl;
	for (int i = 0; i <= 160; i++) {
		x0 = xn;
		y0 = yn;
		z0 = zn;
		cout << i << ": x = " << xn << "\t\ty = " << yn << "\t\tz = " << zn << endl;
		xn = x0 + h3;
		deltay1 = h3 * f(x0, y0, z0);
		deltaz1 = h3 * g(x0, y0, z0);
		deltay2 = h3 * f(x0 + h3 / 2.0, y0 + deltay1 / 2.0, z0 + deltaz1 / 2.0);
		deltaz2 = h3 * g(x0 + h3 / 2.0, y0 + deltay1 / 2.0, z0 + deltaz1 / 2.0);
		deltay3 = h3 * f(x0 + h3 / 2.0, y0 + deltay2 / 2.0, z0 + deltaz2 / 2.0);
		deltaz3 = h3 * g(x0 + h3 / 2.0, y0 + deltay2 / 2.0, z0 + deltaz2 / 2.0);
		deltay4 = h3 * f(x0 + h3, y0 + deltay3, z0 + deltaz3);
		deltaz4 = h3 * g(x0 + h3, y0 + deltay3, z0 + deltaz3);
		yn = y0 + deltay1 / 6.0 + deltay2 / 3.0 + deltay3 / 3.0 + deltay4 / 6.0;
		zn = z0 + deltaz1 / 6.0 + deltaz2 / 3.0 + deltaz3 / 3.0 + deltaz4 / 6.0;
	}
	sy3 = y0;
	sz3 = z0;

	double QCy = (sy2 - sy1) / (sy3 - sy2);
	double QCz = (sz2 - sz1) / (sz3 - sz2);

	cout << endl << "Quociente de convergencia Y: " << QCy << endl;
	cout << endl << "Quociente de convergencia Z: " << QCz << endl;

	double Ey = sy3 - sy2;
	double Ez = sz3 - sz2;

	cout << endl << "Erro Y: " << Ey << endl;
	cout << endl << "Erro Z: " << Ez << endl;

}

