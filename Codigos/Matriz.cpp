#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<double>> GaussElimination(vector<vector<double>> matrix) {
	double aux;

	for (int i = 0; i < matrix.size(); i++) {
		aux = matrix[i][i];

		for (int j = i; j < matrix[i].size(); j++)
			matrix[i][j] /= aux;

		for (int j = i + 1; j < matrix.size(); j++) {
			aux = matrix[j][i];
			for (int k = i; k < matrix[j].size(); k++)
				matrix[j][k] -= aux * matrix[i][k];
		}
	}

	return matrix;
}

void printMatrix(vector<vector<double>> matrix) {
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++)
			cout << matrix[i][j] << "\t";
		cout << endl;
	}
}

vector<double> getResults(vector<vector<double>> matrix) {
	vector<double> results = { matrix[0][3], matrix[1][3], matrix[2][3] };

	for (int i = matrix.size() - 1; i >= 0; i--) {
		for (int j = i + 1; j < matrix.size(); j++)
			results[i] -= matrix[i][j] * results[j];
	}

	return results;
}

vector<double> getErrors(vector<double> solutions, double error) {
	vector<double> errors = { error,error,error };

	for (int i = 0; i < errors.size(); i++) {
		for (int j = 0; j < solutions.size(); j++)
			errors[i] -= error * solutions[j];
	}

	return errors;
}

int main()
{
	cout << fixed;
	cout.precision(5);

	vector<vector<double>> matrix = {
		{1.0,1.0 / 2.0,	1.0 / 3.0,	-1},
		{1.0 / 2.0,	1.0 / 3.0,	1.0 / 4.0,	1},
		{1.0 / 3.0,	1.0 / 4.0,	1.0 / 5.0,	1}
	};

	printMatrix(GaussElimination(matrix));

	vector<vector<double>> solvedMatrix = GaussElimination(matrix);

	vector<double> solutions = getResults(solvedMatrix);
	cout << endl;
	for (int i = 0; i < solutions.size(); i++)
		cout << "x" << i + 1 << " = " << solutions[i] << endl;

	vector<double> errors = getErrors(solutions, 0.05);
	cout << endl;
	for (int i = 0; i < errors.size(); i++)
		cout << "Erro de x" << i + 1 << " = " << errors[i] << endl;

	for (int i = 0; i < 3; i++) {
		matrix[i][3] = errors[i];
	}

	solvedMatrix = GaussElimination(matrix);
	cout << endl;
	printMatrix(solvedMatrix);
	solutions = getResults(solvedMatrix);
	cout << endl;
	for (int i = 0; i < solutions.size(); i++)
		cout << "deltax" << i + 1 << " = " << solutions[i] << endl;
}

