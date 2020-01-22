void corda(double a0, double b0, unsigned int num_iter){
	// Initial values
	double a = a0;
	double b = b0;
	double m;

	cout << 0 << ":\t" << a << "\t" << b << "\t" << abs(b-a) << endl;

	// Loop until final interval is reached
	for(unsigned int i=1 ; i <= num_iter ; i++){
		m = ( a*f(b) - b*f(a) ) / ( f(b) - f(a) );

		// Decide which extreme changes
		if (f(m) * f(a) > 0)
			a = m;
		else
			b = m;

		// Print current values
		cout << i << ":\t" << a << "\t" << b << "\t" << abs(b-a) << endl;
	}

}
