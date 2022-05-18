

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Person {
public:
	Person(){}
	Person(string f, string s, int a) : f{f}, s{s}, a{a} {
	if(a < 0 || a >= 150){
		throw runtime_error("Invalid age");
	}
	for(int i = 0; i <= first().length(); ++i){
		switch(first()[i]) {
			case ';':
			case ':':
			case '"':
			case '\'':
			case '[':
			case ']':
			case '*':
			case '&':
			case '^':
			case '%':
			case '$':
			case '#':
			case '@':
			case '!':
				throw runtime_error("Invalid first name");
		}
	}
	for(int i = 0; i <= second().length(); ++i){
		switch(second()[i]) {
			case ';':
			case ':':
			case '"':
			case '\'':
			case '[':
			case ']':
			case '*':
			case '&':
			case '^':
			case '%':
			case '$':
			case '#':
			case '@':
			case '!':
				throw runtime_error("Invalid second name");
		}
	}
	/*
	if(first() == "" || second() == ""){
		throw runtime_error("A first and second name are required");
	}
	*/
	}
	int age() const { return a; }
	string first() const { return f; }
	string second() const { return s; }

private:
	int a;
	string f;
	string s;

};

ostream& operator<<(ostream& os, const Person& p){
	return os << p.first() << ' ' << p.second() << ", " << p.age() << endl;
}

istream& operator>>(istream& is, Person& p){
	string f;
	string s;
	int a;
	is >> f >> s >> a;

	p = Person(f,s,a);

	return is;
}



int main(){

	//Person person;
	//person.n = "Goofy";
	//person.a = 63;

	//cout << person.n << ", " << person.a << endl;

	Person p1;
	cin >> p1;
	cout << p1;

	Person p2;
	vector<Person> vec;
	while(cin >> p2){
		if(p2.first() == "end" && p2.second() == "end"){
			break;
		}
		vec.push_back(p2);
	}

	for(Person p2 : vec){
		cout << p2;
	}

}
