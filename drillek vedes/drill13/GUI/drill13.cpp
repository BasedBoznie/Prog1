

#include "Simple_window.h"
#include "Graph.h"



int main()
{
	try {

		Point tl {100,100};
		Simple_window win {tl,800,1000,"Window #1"};

		win.wait_for_button();

		//

		Lines grid;
		int x = 800;
		int y = 800;
		for(int i = 100; i<=x; i+=100){
			grid.add(Point(i,0), Point(i,y));
			grid.add(Point(0,i), Point(x,i));
		}

		win.attach(grid);
		win.set_label("Window #2");
		win.wait_for_button();

		//

		Rectangle r1 {Point{0,0},100,100};
		r1.set_fill_color(Color::red);
		win.attach(r1);

		Rectangle r2 {Point{100,100},100,100};
		r2.set_fill_color(Color::red);
		win.attach(r2);

		Rectangle r3 {Point{200,200},100,100};
		r3.set_fill_color(Color::red);
		win.attach(r3);

		Rectangle r4 {Point{300,300},100,100};
		r4.set_fill_color(Color::red);
		win.attach(r4);

		Rectangle r5 {Point{400,400},100,100};
		r5.set_fill_color(Color::red);
		win.attach(r5);

		Rectangle r6 {Point{500,500},100,100};
		r6.set_fill_color(Color::red);
		win.attach(r6);

		Rectangle r7 {Point{600,600},100,100};
		r7.set_fill_color(Color::red);
		win.attach(r7);

		Rectangle r8 {Point{700,700},100,100};
		r8.set_fill_color(Color::red);
		win.attach(r8);
		
		win.set_label("Window #3");
		win.wait_for_button();

		//

		Image pepli1 {Point{0,600},"pepli.jpg"};
		win.attach(pepli1);

		Image pepli2 {Point{600,100},"pepli.jpg"};
		win.attach(pepli2);

		Image pepli3 {Point{0,200},"pepli.jpg"};
		win.attach(pepli3);

		win.set_label("Window #4");
		win.wait_for_button();

		//
		//label.move(length/3, xy.y+20);
		int xi = 0;
		int yi = 0;
		Image image {Point{xi,yi},"image.jpg"};
		win.attach(image);

		while(true){

			int volt = 0;

			int xvy = randint(1,2);

			if(xvy == 1){
				int fvl = randint(1,2);

				if(xi >= 100 && xi <= 600) {
					if(fvl == 1){
						xi = xi+100;
						image.move(100,0);
					}
					if(fvl == 2){
						xi = xi-100;
						image.move(-100,0);
					}
					volt = 1;
				}
				if(xi == 700 && volt == 0){
					xi = xi-100;
					image.move(-100,0);
					volt = 1;
				}
				if(xi == 0 && volt == 0){
					xi = xi+100;
					image.move(100,0);
					volt = 1;
				}
			}

			if(xvy == 2){
				int fvl = randint(1,2);

				if(yi >= 100 && yi <= 700){
					if(fvl == 1){
						yi = yi+100;
						image.move(0,100);
					}
					if(fvl == 2){
						yi = yi-100;
						image.move(0,-100);
					}
					volt = 1;
				}
				if(yi == 0 && volt == 0){
					yi = yi+100;
					image.move(0,100);
					volt = 1;
				}
				if(yi == 800 && volt == 0){
					yi = yi-100;
					image.move(0,-100);
					volt = 1;
				}
			}
			win.wait_for_button();
		}
					

	} catch(exception& e){
		cerr << "exception: " << e.what() << endl;
		return 1;
	} catch(...){
		cerr << "exception\n";
		return 2;
	}
}
