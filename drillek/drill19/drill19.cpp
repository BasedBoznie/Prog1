#include <iostream>
#include <vector>
#include <string>

template<typename T>
struct S {
public: 
	S(T v = 0) : val{v} {}
	T& get();
	const T& get() const;
	T& set(T v) { return val = v; }

	S<T>& operator=(const T& v);

	T& read_val(T& v);

private:
	T val;
};

template<typename T>
T& S<T>::get(){
	return val;
}

template<typename T>
const T& S<T>::get() const {
	return val;
}

template<typename T>
S<T>& S<T>::operator=(const T& v){
	val = v;
	return *this;
}

template<typename T>
void read_val (T& v){
	std::cin >> v;
}

using namespace std;



int main(){

	S<int> Sint {42};
	S<char> Schar {'c'};
	S<double> Sdouble {42.42};
	S<string> Sstring {"string"};
	S<vector<int>> Svector {vector<int>{ 1,2,3,4,5,6,7,8,9 }};

	cout << Sint.get() << endl;
	cout << Schar.get() << endl;
	cout << Sdouble.get() << endl;
	cout << Sstring.get() << endl;
	for(int a : Svector.get()){
		cout << a << ' ';
	}
	cout << "\n";

	Sint.set(28);
	cout << Sint.get() << endl;

	Sint = 67;
	cout << Sint.get() << endl;

	int i;
	read_val(i);
	Sint = i;

	char c;
	read_val(c);
	Schar = c;

	double d;
	read_val(d);
	Sdouble = d;

	cout << Sint.get() << endl;
	cout << Schar.get() << endl;
	cout << Sdouble.get() << endl;


}