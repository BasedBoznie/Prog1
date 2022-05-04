

#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

double one(double x) {return 1;}
double slope(double x) {return x/2;}
double square(double x) {return x*x;}
double sloping_cos(double x) {return cos(x)+slope(x);}

int main(){

	Point tl{100,100};
	Simple_window win{tl,600,600,"Function graphs"};
	win.wait_for_button();

	Axis xa{Axis::x, Point{100,300},400,20,"1 == 20 pixels"};
	Axis ya{Axis::y, Point{300,500},400,20,"1 == 20 pixels"};

	win.attach(xa);
	win.attach(ya);
	win.set_label("Function graphs");

	xa.set_color(Color::red);
	ya.set_color(Color::red);

	win.wait_for_button();

	Function f1 {one,-10,11,Point{300,300},400,20,20};

	win.attach(f1);
	win.set_label("Function graphs");
	win.wait_for_button();

	Function f2 {slope,-10,11,Point{300,300},400,20,20};

	win.attach(f2);

	Text tf2{Point{100,380},"x/2"};

	win.attach(tf2);
	win.set_label("Function graphs");
	win.wait_for_button();

	Function f3 {square,-10,11,Point{300,300},400,20,20};

	win.attach(f3);
	win.set_label("Function graphs");
	win.wait_for_button();

	Function cos1 {cos,-10,11,Point{300,300},400,20,20};
	cos1.set_color(Color::blue);
	win.attach(cos1);
	win.set_label("Function graphs");
	win.wait_for_button();

	Function cos2 {sloping_cos,-10,11,Point{300,300},400,20,20};
	win.attach(cos2);
	win.set_label("Function graphs");
	win.wait_for_button();
}
