// Example program in TDT4102_Graphics template, from PPP page 415
#include "Graph.h"
#include "Simple_window.h" 

#include "Meeting.h"

int main() {

	Car c1{ 5 };
	Car c2{ 0 };


	Person p1{ "Oyvind", "mail", &c1 };
	Person p2{ "Ulrik", "mail2" };
	Person p3{ "Live", "mail3", &c2 };

	cout << p1 << endl;
	cout << p2 << endl;
	cout << p3 << endl;

	keep_window_open();
	return 0;
}

