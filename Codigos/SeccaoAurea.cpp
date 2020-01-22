pair<double,double> seccaoAurea(double a0, double b0, double final_interval){
	// Initial values
	double x1 = a0;
	double x2 = b0;
	double x3 = x1 + A*(x2-x1);
	double x4 = x1 + B*(x2-x1);
	unsigned int iterations_counter = 0;

	cout << iterations_counter << ":\t" << x1 << "\t" << x2 << "\t" << abs(x2-x1) << endl;

	// Loop until final interval is reached
	while(abs(x2-x1) > final_interval){
		// Decide which extreme changes
		if (f(x3) < f(x4)){
			x2 = x4;
			x4 = x3;
			x3 = x1 + B*(x4-x1);
		}
		else{
			x1 = x3;
			x3 = x4;
			x4 = x3 + B*(x2-x3);
		}

		// Print current values
		iterations_counter ++;
		cout << iterations_counter << ":\t" << x1 << "\t" << x4 << "\t" << abs(x2-x1) << endl;
	}

	// Return the final interval that was reached
	return make_pair(x1,x2);
}