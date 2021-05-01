// C program to illustrate the feupdateenv() function

/*	Source by GeeksForGeeks
	Modified For Learn by Rizky Khapidsyah
	I.D.E : Visual Studio 2019
*/

#include <stdio.h>
#include <math.h>
#include <fenv.h>
#include <conio.h>

#pragma fenv_access (on)

// Function to use the function
double answer(double y) {
	// struct defined
	fenv_t trial;

	// use the function feholdexcept
	feholdexcept(&trial);

	// find log valye
	y = log(y);

	// clears exception
	feclearexcept(FE_OVERFLOW | FE_DIVBYZERO);

	// call the function for success or not
	feupdateenv(&trial);
	return y;
}

int main() {
	// It is a combination of all of
	// the possible floating-point exception
	feclearexcept(FE_ALL_EXCEPT);

	// it returns the log value
	// if it is to be found
	printf("log(10.0): %f\n", answer(10.0));

	// the function does not throws any exception
	if (!fetestexcept(FE_ALL_EXCEPT)) {
		printf("no exceptions raised");
	} else {
		printf("exceptions raised");
	}
		
	_getch();
	return 0;
}
