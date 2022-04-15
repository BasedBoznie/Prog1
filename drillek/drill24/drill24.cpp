#include <iostream>
#include <cmath>
#include <iomanip>
#include <complex>
#include "Matrix.h"
#include "MatrixIO.h"

using namespace std;
using namespace Numeric_lib;

int main()
try {

	cout << "Size of char:\t\t" << sizeof(char) << endl;
	cout << "Size of short:\t\t" << sizeof(short) << endl;
	cout << "Size of int:\t\t" << sizeof(int) << endl;
	cout << "Size of long:\t\t" << sizeof(long) << endl;
	cout << "Size of float:\t\t" << sizeof(float) << endl;
	cout << "Size of double:\t\t" << sizeof(double) << endl;
	cout << "Size of int*:\t\t" << sizeof(int*) << endl;
	cout << "Size of double*:\t" << sizeof(double*) << endl;

	cout << "\nMatrix sizes:" << endl;

	Matrix<int> a(10);
	Matrix<int> b(100);
	Matrix<double> c(10);
	Matrix<int,2> d(10,10);
	Matrix<int,3> e(10,10,10);

	cout << "Size of Matrix<int> a:\t\t" << sizeof(a) << endl;
	cout << "Size of Matrix<int> b:\t\t" << sizeof(b) << endl;
	cout << "Size of Matrix<double> c:\t" << sizeof(c) << endl;
	cout << "Size of Matrix<int,2> d:\t" << sizeof(d) << endl;
	cout << "Size of Matrix<int,3> e:\t" << sizeof(e) << endl;

	cout << "\nMatrix number of elements:" << endl;

	cout << "a:\t" << a.size() << endl;
	cout << "b:\t" << b.size() << endl;
	cout << "c:\t" << c.size() << endl;
	cout << "d:\t" << d.size() << endl;
	cout << "e:\t" << e.size() << endl;

	cout << endl;

	int n;

	while(cin >> n){
		double x = sqrt(n);
		if(x != x)
			throw runtime_error("no square root");
		else 
			cout << "square root of " << n << ":\t" << x << endl;
	}

	cin.clear();
	cin.ignore();

	cout << endl;

	cout << "Enter 10 floats:" << endl;

	Matrix<double> md(10);
	double nd;

	for(int i = 0; i<md.size(); ++i){
		cin >> nd;
		md(i) = nd;
	}

	cin.clear();
	cin.ignore();

	cout << "Elements of md:\n" << md << endl;

	cout << endl;

	cout << "Size of matrix:" << endl;
	int nn, mm;
	cin >> nn >> mm;

	Matrix<int,2> mx(nn,mm);

	int i;
	int j;
	for(Index i = 0; i<mx.dim1(); ++i){
		for(Index j = 0; j<mx.dim2(); ++j){
			mx(i,j) = (i+1)*(j+1);
			cout << setw(5) << mx(i,j);
		}
	cout << '\n';
	}

	cin.clear();
	cin.ignore();

	cout << endl;

	Matrix<complex<double>> mc(10);

	cout << "Enter 10 complex numbers:" << endl;
	complex<double> cd;

	i=0;
	while(i < 10){
		cin >> cd;
		mc[i] = cd;
		++i;
	}
	cout << mc;
	i=0;
	complex<double> sum;
	while(i < mc.size()){
		sum = sum + mc[i];
		++i;
	}

	cin.clear();
	cin.ignore();

	cout << endl;

	cout << "Sum: " << sum << endl;

	cout << endl;

	Matrix<int,2> ms(2,3);
	
	cout << "Enter six ints:" << endl;

	int num;
	for(int i = 0; i < ms.dim1(); ++i){
		for(int j = 0; j < ms.dim2(); ++j){
			cin >> num;
			ms(i,j) = num;
		}
	}
	cout << "Matrix:\n" << ms << endl;




} catch(exception& e){
	cerr << "Exception: " << e.what() << endl;
} catch(...){
	cerr << "Unknown exception" << endl;
}