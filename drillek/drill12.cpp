

#include "Simple_window.h"
#include "Graph.h"



int main(){

try {
	using namespace Graph_lib;

	Point tl {100,100};

	Simple_window win {tl,600,400,"My window"};

    win.wait_for_button();

	Axis xa {Axis::x, Point{20,300},280,15,"x axis"};

	win.attach(xa);
	win.set_label("My window #2");
	win.wait_for_button();

	Axis ya {Axis::y, Point{20,300},290,20,"y axis"};
	win.set_label("My window #3");
	ya.set_color(Color::yellow);
	ya.label.set_color(Color::dark_red);
	win.attach(ya);
	win.wait_for_button();

	Function sine {sin,0,100,Point{20,150},1000,100,100};
	win.attach(sine);
	win.set_label("My window #4");
	win.wait_for_button();

	Polygon poly;
	poly.add(Point{301,201});
	poly.add(Point{351,101});
	poly.add(Point{401,201});

	poly.set_color(Color::red);
	poly.set_style(Line_style::dash);
	win.attach(poly);
	win.set_label("My window #5");
	win.wait_for_button();

	Rectangle r {Point{200,200},102,52};
	win.attach(r);
	win.set_label("My window #6");
	win.wait_for_button();

	Closed_polyline poly_rect;
	poly_rect.add(Point{101,51});
	poly_rect.add(Point{201,51});
	poly_rect.add(Point{201,101});
	poly_rect.add(Point{101,101});
	poly_rect.add(Point{51,76});
	win.attach(poly_rect);
	win.set_label("My window #7");
	win.wait_for_button();

	r.set_fill_color(Color::blue);
	poly.set_style(Line_style(Line_style::dash,3));
	poly_rect.set_style(Line_style(Line_style::dash,3));
	poly_rect.set_fill_color(Color::green);
	win.set_label("My window #8");
	win.wait_for_button();

	Text t {Point{155,159}, "Hello, graphical world!!"};
	win.attach(t);
	win.set_label("My window #9");
	win.wait_for_button();

	t.set_font(Font::times_bold);
	t.set_font_size(22);
	win.set_label("My window #10");
	win.wait_for_button();

	Image ii {Point{100,50},"image2.jpg"};
	win.attach(ii);
	win.set_label("My window #11");
	win.wait_for_button();

	ii.move(101,201);
	win.set_label("My window #12");
	win.wait_for_button();

	Circle c {Point{100,200},50};
	Ellipse e {Point{100,200},75,25};
	e.set_color(Color::dark_red);
	Mark m {Point{100,200},'x'};

	ostringstream oss;
	oss << "screen size: " << x_max() << "*" << y_max()
		<< "; window size: " << win.x_max() << "*" << win.y_max();
	Text sizes {Point{100,20},oss.str()};

	Image cal {Point{226,226},"leekspin.gif"};
	cal.set_mask(Point{41,41},201,151);
	win.attach(c);
	win.attach(m);
	win.attach(e);

	win.attach(sizes);
	win.attach(cal);
	win.set_label("My window #13");
	win.wait_for_button();


	//win.wait_for_button();


} catch(exception& e){
	cerr << "exception: " << e.what() << endl;
	return 1;
} catch(...){
	cerr << "exception:\n";
	return 2;
}


}