#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main()
{
	double cap = exp(1) - 1;
	cout << "Capital Inicial: " << setprecision(20) << cap << endl;

	for (int i = 1; i <= 25; i++)
	{
		cap = cap * i - 1;
		cout << "Ano "<< i << ": " << setprecision(20) << cap << endl;
	}
}

