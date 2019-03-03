#pragma once
#include "std_lib_facilities.h"
#include "Car.h"

class Person
{
	string name, email;
	Car* car;
public:
	Person(string name, string email, Car* car = nullptr);

	string getName() const;
	string getEmail() const;

	bool hasAvalibleSeats() const;

	void setEmail(string newEmail);
	
	friend ostream& operator<<(ostream& os, const Person& p);

	/*
	operatoren burde ha const fordi den ikke skal kunne endre p� personen n�r den skal skrives ut.

	Dersom vi �nsker � endre p� dataen kan vi ikke bruke const
	Const er kjekt � bruke slik at vi er sikre p� at dataen ikke kan endres etter at vi sender den til en funksjon
	*/

	virtual ~Person() {};
};

