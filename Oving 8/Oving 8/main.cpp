// Example program in TDT4102_Graphics template, from PPP page 415
#include "GUI.h"
#include "Graph.h"
#include "MeetingWindow.h"

#include "Meeting.h"

// The following pragma turns off the console
//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

using namespace Graph_lib;

int main() {

	/*
	Car c1{ 5 };
	Car c2{ 0 };
	Car c3{ 4 };


	Person p1{ "Oyvind", "mail", &c1 };
	Person p2{ "Ulrik", "mail2" };
	Person p3{ "Live", "mail3", &c2 };
	Person p4{ "Per", "mail4", &c3 };

	
	cout << p1 << endl;
	cout << p2 << endl;
	cout << p3 << endl;
	

	Meeting m1{ 13, 1300, 1500, Campus::Trondheim, "Test", &p1 };
	m1.addParticipant(&p2);
	m1.addParticipant(&p3);

	Meeting m2{ 13, 1200, 1500, Campus::Trondheim, "Test", &p4 };

	cout << m1;

	m1.findPotentialCoDriving();

	*/

	MeetingWindow win{Point{100, 100}, 600, 400, "Meetings" };

	gui_main();

	for (const auto p : win.getPeople())
	{
		cout << p->getName() << endl;
	}

	keep_window_open();

	return 0;
}

