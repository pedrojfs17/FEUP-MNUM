#include <math.h>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<double>> solveMatrix(vector<vector<double>> matrix) {
	double aux;

	for (int i = 0; i < matrix.size(); i++) {
		//Primeiro valor
		aux = matrix[i][i];

		//Dividir a primeira linha + a solucao (Adx) pelo valor inicial colocando-o a 1
		for (int j = 0; j < matrix[i].size(); j++) {
			matrix[i][j] /= aux;
		}

		//Correr as proximas linhas, subtraindo a primeira linha multiplicada pelo primeiro valor da linha j
		for (int j = i + 1; j < matrix.size(); j++) {
			aux = matrix[j][i];
			for (int k = i; k < matrix[j].size(); k++) {
				matrix[j][k] -= matrix[i][k] * aux;
			}
		}
	}

	return matrix;
}

void printMatrix(vector<vector<double>> matrix) {
	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			cout << matrix[i][j] << "\t";
		}
		cout << endl;
	}
}

vector<double> resultsMatrix(vector<vector<double>> matrix) {
	vector<double> results = { matrix[0][matrix[0].size() - 1],matrix[1][matrix[0].size() - 1],matrix[2][matrix[0].size() - 1] };

	for (int i = matrix.size() - 1; i >= 0; i--) {
		for (int j = i + 1; j < matrix.size(); j++) {
			results[i] -= matrix[i][j] * results[j];
		}
	}

	return results;
}

int main()
{
	vector<vector<double>> matrix = { {1.0,1.0 / 2.0,1.0 / 3.0,-1.0},{1.0 / 2.0,1.0 / 3.0,1.0 / 4.0,1.0},{1.0 / 3.0,1.0 / 4.0,1.0 / 5.0,1.0} };

	vector<vector<double>> solvedmatrix = solveMatrix(matrix);

	printMatrix(solvedmatrix);

	vector<double> results = resultsMatrix(solvedmatrix);

	for (int i = 0; i < results.size(); i++) {
		cout << "Resultado x" << i + 1 << " = " << results[i] << endl;
	}

	double residuo = 0.05;
	vector<double> resi = { 0,0,0 };

	for (int i = 0; i < resi.size(); i++) {
		resi[i] = residuo;
		for (int j = 0; j < results.size(); j++) {
			resi[i] -= residuo * results[j];
		}
	}

	for (int i = 0; i < 3; i++) {
		matrix[i][matrix[i].size() - 1] = resi[i];
	}

	printMatrix(solveMatrix(matrix));

	results = resultsMatrix(solveMatrix(matrix));

	for (int i = 0; i < results.size(); i++) {
		cout << "Resultado x" << i + 1 << " = " << results[i] << endl;
	}
}

