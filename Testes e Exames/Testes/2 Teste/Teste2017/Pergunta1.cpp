#include <vector>
#include <iostream>

using namespace std;

int main()
{
	vector<double> sol = { 0.552949,-0.15347,-0.10655 };
	vector<double> Adx = { 0,0,0 };

	//Obter a matriz dos residuos
	for (int i = 0; i < 3; i++) {
		Adx[i] = 0.1;
		for (int j = 0; j < 3; j++) {
			Adx[i] -= 0.1 * sol[j];
		}
	}

	vector<vector<double>> matrix = { {18,-1,1},{3,-5,4},{6,8,29} };
	double div, mul;

	//Simplificar o sistema de equacoes lineares
	for (int i = 0; i < matrix.size(); i++) {
		//Primeiro valor
		div = matrix[i][i];

		//Dividir a primeira linha + a solucao (Adx) pelo valor inicial colocando-o a 1
		for (int j = 0; j < matrix[i].size(); j++) {
			matrix[i][j] /= div;
		}
		Adx[i] /= div;

		//Correr as proximas linhas, subtraindo a primeira linha multiplicada pelo primeiro valor da linha j
		for (int j = i + 1; j < matrix.size(); j++) {
			mul = matrix[j][i];
			for (int k = i; k < matrix[j].size(); k++) {
				matrix[j][k] -= matrix[i][k] * mul;
			}
			Adx[j] -= Adx[i] * mul;
		}
	}
	//No fim do ciclo acima obtemos a matriz triangular inferior, com 1's na diagonal

	//Começando do ultimo valor, que já temos o resultado, obtemos os outros valores acima substituindo-os
	for (int i = matrix.size() - 1; i >= 0; i--) {
		for (int j = i + 1; j < matrix.size(); j++) {
			Adx[i] -= matrix[i][j] * Adx[j];
		}
	}

	cout << "Delta x: " << Adx[0] << endl;
	cout << "Delta y: " << Adx[1] << endl;
	cout << "Delta z: " << Adx[2] << endl;
	
}
