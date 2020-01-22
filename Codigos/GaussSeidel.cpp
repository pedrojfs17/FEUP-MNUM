void gauss_seidel(matrix & m , double x1_i , double x2_i , double x3_i , double x4_i , unsigned int num_iter){
	// Initial Values
	double x1 = x1_i;
	double x2 = x2_i;
	double x3 = x3_i;
	double x4 = x4_i;

	cout << 0 << ":\t" << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << "\t" << endl;

	for (unsigned int i=1 ; i<=num_iter ; i++){
		// Compute the values
		x1 = (m[0][4] - (m[0][1]*x2 + m[0][2]*x3 + m[0][3]*x4))/m[0][0];
		x2 = (m[1][4] - (m[1][0]*x1 + m[1][2]*x3 + m[1][3]*x4))/m[1][1];
		x3 = (m[2][4] - (m[2][0]*x1 + m[2][1]*x2 + m[2][3]*x4))/m[2][2];
		x4 = (m[3][4] - (m[3][0]*x1 + m[3][1]*x2 + m[3][2]*x3))/m[3][3];

		// Print the current values
		cout << i << ":\t" << x1 << "\t" << x2 << "\t" << x3 << "\t" << x4 << "\t" << endl;
	}

}