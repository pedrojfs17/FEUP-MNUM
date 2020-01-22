void newton(double x0 , double y0 , unsigned int num_iter){
	// Initial values
	double x = x0;
	double y = y0;

	// Auxiliary variables
	double xn;
	double yn;
	double jacobian;

	cout << 0 << ":\t" << x << "\t" << y << endl;

	// Loop until final interval is reached
	for(unsigned int i=1 ; i <= num_iter ; i++){
		jacobian = df1x(x,y)*df2y(x,y) - df2x(x,y)*df1y(x,y);
		xn = x - (f1(x,y)*df2y(x,y) - f2(x,y)*df1y(x,y)) / jacobian;
		yn = y - (f2(x,y)*df1x(x,y) - f1(x,y)*df2x(x,y)) / jacobian;

		// Update the variables
		x = xn;
		y = yn;

		// Print current values
		cout << i << ":\t" << x << "\t" << y << endl;
	}

}