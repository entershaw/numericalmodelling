#include <iostream>
#include <iomanip> 
#include <cmath>

using namespace std;

double subtractionDouble(double phin, double phin1, int n, int N);
float subtractionFloat(float phin, float phin1, int n, int N);

int main(){

	//headings
	cout<<"********Double*********"<<endl;
	cout<< left << setw(15) << "n" << setw(15) << "phi ^ n" << endl;

	//Subtraction recursion with doubles:
	double silverDouble = (-1 + sqrt(5))/2;
	subtractionDouble(1, silverDouble, 0, 50);
	
	
	//headings
	cout<<"********Float**********"<<endl;
	cout<< left << setw(15) << "n" << setw(15) << "phi ^ n" << endl;

	//Subtraction recursion with floats:
	float silverFloat = (-1 + sqrt(5))/2;
	subtractionFloat(1, silverFloat, 0, 50);		
}

double subtractionDouble(double phin, double phin1, int n, int N){
	double phin2 = phin - phin1;
	cout<< left << setw(15) << n << setw(15) << phin << endl;
	if(n<N-2)
	{

		return subtractionDouble(phin1, phin2, n+1, N);
	}
	else
	{
		cout<< left << setw(15) << n+1 << setw(15) << phin1 << endl;
		cout<< left << setw(15) << n+2 << setw(15) << phin2 << endl;
		return phin2;
	}
}

float subtractionFloat(float phin, float phin1, int n, int N){
	float phin2 = phin - phin1;
	cout<< left << setw(15) << n << setw(15) << phin << endl;
	if(n<N-2)
	{
		return subtractionFloat(phin1, phin2, n+1, N);
	}
	else
	{
		cout<< left << setw(15) << n+1 << setw(15) << phin1 << endl;
		cout<< left << setw(15) << n+2 << setw(15) << phin2 << endl;
		return phin2;
	}
}

