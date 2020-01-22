void euler(double x0 , double y0 , double h , unsigned int num_iter){

	// Variables
	double x = x0;
	double y = y0;

	cout << 0 << ":\t" << x << "\t" << y << endl;

	for (unsigned int i=1 ; i<=num_iter ; i++){
		// Perform the method
		y += h*f(x,y);
		x += h;

		// Print the current values
		cout << i << ":\t" << x << "\t" << y << endl;
	}
}