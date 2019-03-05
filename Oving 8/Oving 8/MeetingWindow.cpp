#include "MeetingWindow.h"

using namespace Graph_lib;


Vector_ref<Person> MeetingWindow::getPeople()
{
	return people;
}

MeetingWindow::MeetingWindow(Point xy, int w, int h, const string & title) :
	Window{ xy, w, h, title },
	quitBtn{ Point{x_max() - pad - btnW, pad }, btnW, btnH, "Quit", cb_quit },
	newPersBtn{ newPersPos, btnW, btnH, "New Person", cb_newPers },
	name{nameInPos, fieldW, fieldH, "Name"},
	email{mailInPos, fieldW, fieldH, "E-Mail"}
{
	attach(quitBtn);
	attach(newPersBtn);
	attach(name);
	attach(email);

	ti = title;
}

void MeetingWindow::cb_quit(Address, Address pw) { reference_to<MeetingWindow>(pw).quit(); }

void MeetingWindow::cb_newPers(Address, Address pw){ reference_to<MeetingWindow>(pw).newPers(); }

void MeetingWindow::newPers()
{
	cout << name.get_string() << " --- " << email.get_string() << endl;
	people.push_back(new Person{ name.get_string(), email.get_string() });
	redraw();
}

