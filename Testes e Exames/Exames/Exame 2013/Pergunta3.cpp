#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<double>> gaussElimination(vector<vector<double>> matrix) {
	double aux;

	for (int i = 0; i < matrix.size(); i++) {
		aux = matrix[i][i];

		for (int j = 0; j < matrix[i].size(); j++) {
			matrix[i][j] /= aux;
		}

		for (int j = i + 1; j < matrix.size(); j++) {
			aux = matrix[j][i];
			for (int k = i; k < matrix[i].size(); k++) {
				matrix[j][k] -= matrix[i][k] * aux;
			}
		}
	}

	return matrix;
}

vector<double> resultsMatrix(vector<vector<double>> matrix) {
	vector<double> results = { 0,0,0,0 };

	for (int i = matrix.size() - 1; i >= 0; i--) {
		results[i] = matrix[i][4];
		for (int j = i + 1; j < matrix.size(); j++) {
			results[i] -= matrix[i][j] * results[j];
		}
	}

	return results;
}

void printMatrix(vector<vector<double>> matrix) {
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
}

int main()
{
	vector<vector<double>> matrix = { {0.1,0.5,3.0,0.25,0},{1.2,0.2,0.25,0.2,1.0},{-1.0,0.25,0.3,2.0,2.0},{2.0,0.00001,1.0,0.4,3.0} };

	printMatrix(gaussElimination(matrix));

	vector<double> results = resultsMatrix(gaussElimination(matrix));

	for (int i = 0; i < results.size(); i++)
		cout << results[i] << endl;
}
