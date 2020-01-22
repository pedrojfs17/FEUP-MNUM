void picardo_peano(double x0 , double y0 , unsigned int num_iter){
	// Initial values
	double x = x0;
	double y = y0;

	// Auxiliary variables
	double xn;
	double yn;

	cout << 0 << ":\t" << x << "\t" << y << endl;

	// Loop until final interval is reached
	for(unsigned int i=1 ; i <= num_iter ; i++){
		xn = f1(x,y);
		yn = f2(x,y);

		// Update the variables
		x = xn;
		y = yn;

		// Print current values
		cout << i << ":\t" << x << "\t" << y << endl;
	}

}