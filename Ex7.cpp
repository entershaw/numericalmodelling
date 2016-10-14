#include <iostream> 
#include <cmath>
#include <iomanip>
#include <cfloat>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

double convergence = 1e-5;

double f(double x);
void bisect(double xB, double xT);
void newtonRhapson(double init);

int main() {
	
	bisect(-100, 100);
	bisect(0, 100);
	bisect(-1000,1000);

	newtonRhapson(0);
	newtonRhapson(10);
	newtonRhapson(-100);
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
	
	//Create file
	string filename = 
	ofstream file (filename);
	
	//Title
	cout << "******Bisection Method*******" <<endl;
	file << "******Bisection Method*******" <<endl;
	
	//Headings. Uncertainty will be the interval size.
	cout << left << setw(15) << "Iteration" << setw(15) << "xB" << setw(15) << "xT" << setw(15) 
	<< setw(15) << "xM" << "Interval width" << endl;
	file << left << setw(15) << "Iteration" << setw(15) << "xB" << setw(15) << "xT" << setw(15) 
	<< setw(15) << "xM" << "Interval width" << endl;
	
	//Show initial parameters
	cout << left << setw(15) << "0" << setw(15) << xB << setw(15) << xT 
	<< setw(15) << xM << setw(15) << xT - xB << endl;
	file << left << setw(15) << "0" << setw(15) << xB << setw(15) << xT 
	<< setw(15) << xM << setw(15) << xT - xB << endl;
	
	
	for (int iteration = 1; xT - xB > convergence; iteration++){
	
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
		file<< left << setw(15) << iteration << setw(15) << xB << setw(15) << xT 
		<< setw(15) << xM << setw(15) << xT - xB << endl << endl;
	}
	file.close(); 
}

//Newton-Rhapson method
void newtonRhapson(double init)
{
	//Create file
	ofstream file ("Newton Rhapson with init=" + init + ".txt");
	
	//Title
	cout << "******Newton-Rhapson Method*******" <<endl;
	file << "******Newton-Rhapson Method*******" <<endl;
	
	//Headings. Uncertainty will be the difference between each iteration.
	cout<< left << setw(15) << "Iteration" << setw(15) << "x_n" << "x_n - x_{n-1}" << endl;
	file << left << setw(15) << "Iteration" << setw(15) << "x_n" << "x_n - x_{n-1}" << endl;	

	//Show initial parameters
	cout << left << setw(15) << "0"<< setw(15) << init << setw(15) << "-" << endl;
	file << left << setw(15) << "0"<< setw(15) << init << setw(15) << "-" << endl;

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
		file << left << setw(15) << iteration << setw(15) << x << setw(15) << uncertainty
		<< endl;
		
		//prepare for the next iteration
		xm1 = x;
	} 
	file.close();
	
}
