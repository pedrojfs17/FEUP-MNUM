#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<double> vertices = { 1.1, 9.8, 7.8, 1.2 };
	vector<double> intermedios = { 2.1, 1.4, 2.2, 1.5 };
	double central = 4, hx = 1, hy = 1;

	double sum = 0;
	for (int i = 0; i < vertices.size(); i++)
		sum += vertices[i];
	for (int i = 0; i < intermedios.size(); i++)
		sum += 4 * intermedios[i];
	sum += 16 * central;

	cout << "Result = " << hx * hy / 9.0 * sum << endl;
}

