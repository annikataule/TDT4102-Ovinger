// Example program in TDT4102_Graphics template, from PPP page 415
#include "Graph.h"
#include "Simple_window.h" 
#include "std_lib_facilities.h"

#include "Task1.h"
#include "Task2.h"
#include "Task3.h"
#include "Task4.h"

class Scale {
	int cbase;
	int vbase;
	double scale;
public:
	Scale(int b, int vb, double s) : cbase(b), vbase(vb), scale(s) { }
	int operator()(int v) const { return cbase + (v - vbase)*scale; }
};

int main() {

	// Your code here
	//cinToFile("inn.txt");

	//addLineNumber("inn.txt", "out.txt");

	//countCharInTxt("grunnlov.txt");


	CourseCatalog courses = CourseCatalog();

	courses.addCourse("TDT4100", "Informasjonsteknologi grunnkurs");
	courses.addCourse("TDT4102", "Prosedyre- og objektorientert programmering");
	courses.addCourse("TMA4100", "Matematikk 1");
	courses.addCourse("TDT4102", "C++");

	// map.insert funker ikke


	cout << courses;

	vector<Temps> temps;
	string file = "temperatures.txt";

	readTempsFromFile(temps, file);

	//cout << temps;

	const int base_month = 1;
	const int end_month = 12;

	const int xmax = 900;
	const int ymax = 400;

	const int xoffset = 100;
	const int yoffset = 60;

	const int xspace = 40;
	const int yspace = 40;

	const int xlength = xmax - xoffset - xspace;
	const int ylength = ymax - yoffset - yspace;

	const double xscale = double(xlength) / (end_month - base_month);
	const double yscale = double(ylength) / 40;

	Scale xs(xoffset, base_month, xscale);
	Scale ys(ymax - yoffset, -10, -yscale);

	Simple_window win(Point(100, 100), xmax, ymax, "Temperaturer");

	Axis x(Axis::x, Point(xoffset, ymax - yoffset), xlength, 12,
		"Måned          2             3             4             5             6             7             "
		"8             9             10            11            12            1");
	x.label.move(-200, 0);

	Axis y(Axis::y, Point(xoffset, ymax - yoffset), ylength, 8, "Average maximum temperature [°C]");

	Line zero_line(Point(xs(1), ys(0)), Point(xs(12), ys(0)));
	zero_line.set_style(Line_style::dash);

	Open_polyline max;
	Open_polyline min;

	for (int i = 0; i < temps.size(); i++)
	{
		max.add(Point()
	}


	return 0;
}

