#include <vector>
#include <iostream>

using namespace std;

int main()
{
	vector<vector<double>> matrix = { {0.7,8,3,12},{-6,0.45,-0.25,15},{8,-3.1,1.05,23} };
	vector<double> b = { 12,15,23 };

	double first, temp;

	for (int i = 0; i < matrix.size(); i++) {
		first = matrix[i][i];

		for (int j = 0; j < matrix[i].size(); j++)
			matrix[i][j] /= first;

		for (int j = i + 1; j < matrix.size(); j++) {
			temp = matrix[j][i];
			for (int k = 0; k < matrix[j].size(); k++)
				matrix[j][k] -= temp * matrix[i][k];
		}
	}

	vector<double> sol = { 0,0,0 };
	sol[2] = matrix[2][3];
	sol[1] = matrix[1][3] - matrix[1][2] * sol[2];
	sol[0] = matrix[0][3] - matrix[0][2] * sol[2] - matrix[0][1] * sol[1];

	for (int i = 0; i < sol.size(); i++)
		cout << endl << "Solucao x" << i + 1 << ": " << sol[i];

	vector<double> residuos = { 0,0,0 };

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < sol.size(); j++) {
			residuos[i] += 0.5 * sol[j];
		}
		residuos[i] = 0.5 - residuos[i];
	}

	cout << endl;

	vector<vector<double>> res_matrix = { {0.7,8,3,residuos[0]},{-6,0.45,-0.25,residuos[1]},{8,-3.1,1.05,residuos[2]} };

	for (int i = 0; i < res_matrix.size(); i++) {
		first = res_matrix[i][i];

		for (int j = 0; j < res_matrix[i].size(); j++)
			res_matrix[i][j] /= first;

		for (int j = i + 1; j < res_matrix.size(); j++) {
			temp = res_matrix[j][i];
			for (int k = 0; k < res_matrix[j].size(); k++)
				res_matrix[j][k] -= temp * res_matrix[i][k];
		}
	}

	vector<double> sol_res = { 0,0,0 };
	sol_res[2] = res_matrix[2][3];
	sol_res[1] = res_matrix[1][3] - res_matrix[1][2] * sol_res[2];
	sol_res[0] = res_matrix[0][3] - res_matrix[0][2] * sol_res[2] - res_matrix[0][1] * sol_res[1];

	for (int i = 0; i < sol_res.size(); i++)
		cout << endl << "Solucao residuos x" << i + 1 << ": " << sol_res[i];

	cout << endl;
}
