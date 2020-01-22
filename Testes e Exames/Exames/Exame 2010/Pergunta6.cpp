#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<double>> solveMatrix(vector<vector<double>> matrix) {
	double aux;

	for (int i = 0; i < matrix.size(); i++) {
		aux = matrix[i][i];

		for (int j = 0; j < matrix[i].size(); j++)
			matrix[i][j] /= aux;

		for (int j = i + 1; j < matrix.size(); j++) {
			aux = matrix[j][i];
			for (int k = i; k < matrix[j].size(); k++) {
				matrix[j][k] -= aux * matrix[i][k];
			}
		}
	}

	return matrix;
}

vector<double> solutionsMatrix(vector<vector<double>> matrix) {
	vector<double> solutions = { matrix[0][3], matrix[1][3], matrix[2][3] };

	for (int i = matrix.size() - 1; i >= 0; i--) {
		for (int j = i + 1; j < matrix.size(); j++) {
			solutions[i] -= matrix[i][j] * solutions[j];
		}
	}

	return solutions;
}

void printVector(vector<double> vec) {
	cout << "[ ";
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i];
		if (i + 1 < vec.size())
			cout << " , ";
	}
	cout << " ]" << endl;
}

int main()
{
	vector<vector<double>> matrix = { {16,-1,1,10},{3,-5,4,2},{6,8,29,-1} };

	vector<double> erro = { 0.1,0.1,0.1 };
	vector<double> sol = { 0.552949,-0.15347,-0.10655 };

	for (int i = 0; i < erro.size(); i++) {
		for (int j = 0; j < sol.size(); j++) {
			erro[i] -= 0.1 * sol[j];
		}
		matrix[i][matrix[i].size() - 1] = erro[i];
	}

	for (int i = 0; i < matrix.size(); i++) {
		printVector(solveMatrix(matrix)[i]);
	}
	cout << endl;

	printVector(solutionsMatrix(solveMatrix(matrix)));
}

