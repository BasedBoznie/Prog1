#include <iostream>

class abstract {
public:
	virtual void pvf() = 0;
};

class notabs : public abstract{
public:
	void pvf() { std::cout << "Not abstract\n"; }
};


int main(){

	//abstract abs;
	
	notabs n;
	n.pvf();

	return 0;

}
