void gradient(double x0 , double y0 , double h0 , unsigned int num_iter){
	// Initial values
	double x = x0;
	double y = y0;
	double h = h0;

	// Auxiliary Variables
	double xn, yn;

	cout << 0 << ":\t" << x << '\t' << y << endl;

	// Perform the method the indicated number of times
	for (unsigned int i=1 ; i<=num_iter ; i++){
		// Compute the new values
		xn = x - h*dfx(x,y);
		yn = y - h*dfy(x,y);

		// Make the decision
		if ( !(f(xn,yn) < f(x,y)) ){
			h = h/2;
		}
		else{
			x = xn;
			y = yn;
			h = h*2;
		}

		// Print the current values
		cout << i << ":\t" << x << '\t' << y << endl;
	}

}