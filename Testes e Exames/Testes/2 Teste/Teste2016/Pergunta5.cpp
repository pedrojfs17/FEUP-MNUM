#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<vector<double>> matrix = { {6,0.5,3,0.25},{1.2,3,0.25,0.2},{-1,0.25,4,2},{2,4,1,8} };
	vector<double> sol = { 2.5,3.8,10,7 };
	vector<double> results = { 0,0,0,0 };

	for (int i = 0; i < matrix.size(); i++) {
		results[i] = sol[i];
		for (int j = 0; j < matrix[i].size(); j++) {
			if (j != i)
				results[i] -= matrix[i][j] * results[j];
		}
		results[i] /= matrix[i][i];
	}
	
	for (int i = 0; i < results.size(); i++) {
		cout << "Solucao " << i << ": " << results[i] << endl;
	}
}
