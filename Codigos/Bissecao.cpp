void bissecao(double a0, double b0, double final_interval){
	double a = a0;
	double b = b0;
	double m;
	unsigned int iterations_counter = 0;

	cout << iterations_counter << ":\t" << a << "\t" << b << "\t" << abs(b-a) << endl;

	while(abs(b-a) > final_interval){
		m = (b+a)/2;

		if (f(m) * f(a) > 0)
			a = m;
		else
			b = m;

		iterations_counter ++;
		cout << iterations_counter << ":\t" << a << "\t" << b << "\t" << abs(b-a) << endl;
	}

}