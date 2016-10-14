#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

int main (){
	
	int N;
	ofstream file ("Ex4a.txt");
	
	cout<<"Calculates powers of the silver ratio. Input N:"<<endl;
	cin>>N;
	
	//headings
	cout<< left << setw(15) << "n" << setw(15) << "phi ^ n" << endl;
	file<< left << setw(15) << "n" << setw(15) << "phi ^ n" << endl;

	//silver ratio
	double phi = (-1.0 + sqrt(5))/2.0;

	//fill columns
	for (int n = 1; n <= N; n++) {
		cout << left << setw(15) << n << setw(15) << pow(phi,n) << endl;
		file << left << setw(15) << n << setw(15) << pow(phi,n) << endl;
	}
	
} 
