#include <iostream> 
#include <cmath>
#include <iomanip>
#include <cfloat>
#include <cmath>
#include <fstream>

using namespace std;

double convergence = 1e-5;

ofstream file;

double f(double x);
void bisect(double xB, double xT);
void newtonRhapson(double init);

int main() {
	
	bisect(-100, 100);

	file.open("Newton0.csv");
	newtonRhapson(0);
	file.open("Newton10.csv");
	newtonRhapson(10);
	file.open("Newton-100.csv");
	newtonRhapson(-100);
    file.open("Newton1000.csv");
	newtonRhapson(1000);
	
	return 0;
}

//Equation to be solved
double f(double x){
	return x*x*x + 7*x*x - 6*x + 15;
}

//Derivative of equation
double df(double x){
	return 3*x*x + 14*x - 6;
}

//Bisection method
void bisect(double xB, double xT)
{	
	double xM = (xT + xB)/2;
	double out;
		
	//Title
	cout << "******Bisection Method*******" <<endl;
	
	//Headings. Uncertainty will be the interval size.
	cout << left << setw(15) << "Iteration" << setw(15) << "xB" << setw(15) << "xT" << setw(15) 
	<< setw(15) << "xM" << "Interval width" << endl;
	
	//Show initial parameters
	cout << left << setw(15) << "0" << setw(15) << xB << setw(15) << xT 
	<< setw(15) << xM << setw(15) << xT - xB << endl;

	for (int iteration = 1; xT - xB > convergence; iteration++){

		//Bisection method	
		if(f(xT) * f(xM) < 0){
			xB = xM;
		}
		else{
			xT = xM;
		}
		
		xM = (xT + xB)/2;
		
		//print
		cout<< left << setw(15) << iteration << setw(15) << xB << setw(15) << xT 
		<< setw(15) << xM << setw(15) << xT - xB << endl << endl;
	}
}

//Newton-Rhapson method
void newtonRhapson(double init)
{
	//Title
	cout << "******Newton-Rhapson Method*******" <<endl;
	
	//Headings. Uncertainty will be the difference between each iteration.
	cout<< left << setw(15) << "Iteration" << setw(15) << "x_n" << "x_n - x_{n-1}" << endl;

	//Show initial parameters
	cout << left << setw(15) << "0"<< setw(15) << init << setw(15) << "-" << endl;
	file << "0,"<< init << endl;

	double uncertainty = DBL_MAX;
	double x; //x_n
	double xm1 = init; //x_{n-1}
	for (int iteration = 1; uncertainty > convergence; iteration++){
		
		//Newton-Rhapson method
		x = xm1 - f(xm1)/df(xm1);
		
		uncertainty = abs(x - xm1);

		//print
		cout << left << setw(15) << iteration << setw(15) << x << setw(15) << uncertainty
		<< endl;
		file << iteration << "," << x << endl;
		
		//prepare for the next iteration
		xm1 = x;
	} 
	file.close(); 
	
}
