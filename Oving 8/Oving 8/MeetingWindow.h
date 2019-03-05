#pragma once
#include "GUI.h"
#include "Graph.h"
#include "Meeting.h"
#include "std_lib_facilities.h"

using namespace Graph_lib;

class MeetingWindow : public Graph_lib::Window
{
	static constexpr int pad = 50;
	static constexpr int fieldPad = 100;
	static constexpr int fieldH = 50;
	static constexpr int fieldW = 200;
	static constexpr int btnH = 50;
	static constexpr int btnW = 100;

	static constexpr Point nameInPos{ pad, pad };
	static constexpr Point mailInPos{ pad, nameInPos.y + fieldH + pad };
	static constexpr Point newPersPos{ pad, mailInPos.y + fieldH + pad };


	Button quitBtn;
	Button newPersBtn;

	In_box name;
	In_box email;

	string ti;

	Vector_ref<Person> people;


public:

	Vector_ref<Person> getPeople();
	
	MeetingWindow(Point xy, int w, int h, const string& title);

	// Callback
	static void cb_quit(Address, Address pw); // cb for quitbtn
	static void cb_newPers(Address, Address pw); // cb for newPersBtn


	// Callback-functions
	void quit() { cout << ti + ": quit called\n"; hide(); } // action to be done when quit_button is pressed
	void newPers();



	virtual ~MeetingWindow() { };
};

