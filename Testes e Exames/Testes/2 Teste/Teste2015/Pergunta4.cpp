#include <vector>
#include <iostream>

using namespace std;

double dT(double T) {
	return -0.25 * (T - 45);
}

int main()
{
	double T = 23, t = 1;
	double h = 0.4;
	int n = 0;

	while (n < 3) {
		cout << "N: " << n << endl;
		cout << "t = " << t << endl;
		cout << "T = " << T << endl;
		T += h * dT(T);
		t += h;
		n++;
	}


}
