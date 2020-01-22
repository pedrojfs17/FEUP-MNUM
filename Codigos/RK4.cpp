void rk4(double x0 , double y0 , double h , unsigned int num_iter){

	// Variables
	double x = x0;
	double y = y0;
	double d1 , d2 , d3 , d4;

	cout << 0 << ":\t" << x << "\t" << y << endl;

	for (unsigned int i=1 ; i<=num_iter ; i++){
		// Compute the increments
		d1 = h*f(x,y);
		d2 = h*f(x + h/2 , y + d1/2);
		d3 = h*f(x + h/2 , y + d2/2);
		d4 = h*f(x + h , y + d3);

		// Perform the method
		y += (d1/6 + d2/3 + d3/3 + d4/6);
		x += h;

		// Print the current values
		cout << i << ":\t" << x << "\t" << y << endl;
	}
}