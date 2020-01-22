#include <cmath>
#include <iostream>

using namespace std;

double dy(double t, double y) {
	return y / (t - 1);
}

int main()
{
	cout << fixed;
	cout.precision(5);

	double h = 0.25;
	double t = 2.0, y = 2.0;

	//EULER
	for (int i = 0; i < 3; i++) {
		cout << "Iteracao " << i << "\tt = " << t << "\ty = " << y << endl;

		y += h * dy(t, y);
		t += h;
	}

	//RK4
	cout << endl << endl;
	double delta1, delta2, delta3, delta4;
	t = 2.0; y = 2.0;

	for (int i = 0; i < 3; i++) {
		cout << "Iteracao " << i << "\tt = " << t << "\ty = " << y << endl;

		delta1 = h * dy(t, y);
		delta2 = h * dy(t + h / 2.0, y + delta1 / 2.0);
		delta3 = h * dy(t + h / 2.0, y + delta2 / 2.0);
		delta4 = h * dy(t + h, y + delta3);

		cout << delta1 << "\t" << delta2 << "\t" << delta3 << "\t" << delta4 << endl << endl;

		y += delta1 / 6.0 + delta2 / 3.0 + delta3 / 3.0 + delta4 / 6.0;
		t += h;
	}
}

