

#include <iostream>
#include <string>


using namespace std;

class B1 {
	public:
		virtual void vf() { cout << "B1::vf()" << endl; }
		void f() { cout << "B1::f()" << endl; }
		virtual void pvf() = 0;
};

class D1 : public B1 {
	public:
		virtual void vf() { cout << "D1::vf()" << endl; }
		void f() { cout << "D1::f()" << endl; }
};

class D2 : public D1 {
	public:
		void pvf() { cout << "D2::pvf()" << endl; }
};

class B2 {
	public:
		virtual void pvf() = 0;
};

class D21 : public B2 {
	public:
		string s;
		void pvf() { cout << s << endl; }
		void f(B2& ref) { ref.pvf(); }
};

class D22 : public B2{
	public:
		int n;
		void pvf() { cout << n << endl; }
		void f(B2& ref) { ref.pvf(); }
};




int main(){

	/*
	cout << "1)" << endl;
	B1 b1;
	b1.vf();
	b1.f();

	cout << "\n2)" << endl;
	D1 d1;
	d1.vf();
	d1.f();

	cout << "\n3)" << endl;

	B1& bref = d1;
	bref.vf();
	bref.f();
	*/

	/*

	4) Az 1) feladat eredménye nem változik
	   A 2) feladatban felülírjuk az f() függvényt, ezért megváltozik az eredmény
	   A 3) B1 vf() virtuális függvénye felül íródik, de az f() függvény nem
	   		íródik felül, mert nem virtuális.
	*/

	/*
	5) A tisztán virtuális függvény miatt, B1 absztrakt lesz, ezáltal D1 is
	   absztrakt lesz. Ezért felül kéne írni D1-ben a pvf() függvényt, hogy
	   működjön.
	*/

	cout << "\n6)" << endl;
	D2 d2;
	d2.f();
	d2.vf();
	d2.pvf();

	cout << "\n7)" << endl;
	D21 d21;
	d21.s = "D21::pvf()";
	d21.pvf();

	D22 d22;
	d22.n = 0;
	//d22.pvf();

	B2& b2ref1 = d21;
	d21.f(b2ref1);

	B2& b2ref2 = d22;
	d22.f(b2ref2);
	
}