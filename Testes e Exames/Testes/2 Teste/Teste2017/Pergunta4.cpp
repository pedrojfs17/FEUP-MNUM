#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<vector<double>> points = { {1.1,1.4,7.7},{2.1,3.1,2.2},{7.3,1.5,1.2} };
	double vertices = 0, intermedios = 0, centrais = 0;

	double hx = 1, hy = 1;

	for (int i = 0; i < points.size(); i++) {
		for (int j = 0; j < points[i].size(); j++) {
			if ((i == 0 && j == 0) || (i == 0 && j == points[i].size() - 1) || (i == points.size() - 1 && j == 0) || (i == points.size() - 1 && j == points[i].size() - 1))
			{
				cout << "Vertice: " << points[i][j] << endl;
				vertices += points[i][j];
			}
			else if (i == 0 || j == 0 || i == points.size() - 1 || j == points[i].size() - 1)
			{
				cout << "Intermedio: " << points[i][j] << endl;
				intermedios += points[i][j];
			}
			else 
			{
				cout << "Central: " << points[i][j] << endl;
				centrais += points[i][j];
			}
		}
	}

	double sol = hx * hy / 4 * (vertices + 2 * intermedios + 4 * centrais);

	cout << "Solucao: " << sol << endl;


}

