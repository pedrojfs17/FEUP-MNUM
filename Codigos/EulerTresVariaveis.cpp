void euler(double x0 , double y0 , double z0 , double h , unsigned int num_iter){

	// Variables
	double x = x0;
	double y = y0;
	double z = z0;
	double xn , yn , zn;

	cout << 0 << ":\t" << x << "\t" << y << "\t" << z << endl;

	for (unsigned int i=1 ; i<=num_iter ; i++){
		// Compute the values
		yn = y + h*f1(x,y,z);
		zn = z + h*f2(x,y,z);
		xn = x + h;

		x = xn;
		y = yn;
		z = zn;

		// Print the current values
		cout << i << ":\t" << x << "\t" << y << "\t" << z << endl;
	}
}