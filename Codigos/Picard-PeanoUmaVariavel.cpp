void picardo_peano(double x0, unsigned int num_iter){
	// Initial values
	double x = x0;

	cout << 0 << ":\t" << x << endl;

	// Loop until final interval is reached
	for(unsigned int i=1 ; i <= num_iter ; i++){
		x = f(x);

		// Print current value
		cout << i << ":\t" << x << endl;
	}

}