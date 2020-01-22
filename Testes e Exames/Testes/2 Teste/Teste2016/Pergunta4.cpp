
#include <iostream>

using namespace std;

double dT(double t) {
	return -0.25 * (t - 42);
}

int main()
{
	double T = 10, t = 5;
	double h = 0.4;
	int n = 0;

	while (n < 3) {
		cout << "n - " << n << endl;
		cout << "T - " << T << endl;
		cout << "------------------------\n";
		t += h;
		T += h * dT(T);
		n++;
	}

}
