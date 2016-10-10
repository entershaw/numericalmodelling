#include <iostream> 
#include <cmath>
#include <iomanip>

using namespace std;

double f(double theta);

int main() {
	
	double thetaB = 0;
	double thetaT = 3.1415926535897932384626433832795/2; 
	double thetaM = (thetaT + thetaB)/2;
	double out;
	
	//headings
	cout<< left << setw(15) << "Iteration" << setw(15) << "thetaB" << setw(15) << "thetaT" << setw(15) 
	<< setw(15) << "thetaM" << "Uncertainty" << endl;
	
	//initial
	cout << left << setw(15) << "0" << setw(15) << thetaB << setw(15) << thetaT 
	<< setw(15) << thetaM << setw(15) << thetaT - thetaB << endl;
	
	
	for (int iteration = 1; thetaT - thetaB > 1E-3; iteration++){
	
		if(f(thetaT) * f(thetaM) < 0){
			thetaT = thetaM;
		}
		else{
			thetaB = thetaM;
		}
		
		thetaM = (thetaT + thetaB)/2;
		
		//print
		cout<< left << setw(15) << iteration << setw(15) << thetaB << setw(15) << thetaT 
		<< setw(15) << thetaM << setw(15) << thetaT - thetaB << endl;
	} 
	
	return 0;
}

double f(double theta){
	return 850*0.6*(tan(theta) - sin(theta)) - 5.5*9.81;
}

