#include "Person.h"



Person::Person(string name, string email, Car* car) : 
	name{ name }, email{ email }, car{ car }
{

}

string Person::getName() const
{
	return name;
}

string Person::getEmail() const
{
	return email;
}

bool Person::hasAvalibleSeats() const
{
	if (car != nullptr)
		return car->hasFreeSeats();
	return false;
}

void Person::setEmail(string newEmail)
{
	email = newEmail;
}

ostream & operator<<(ostream & os, const Person & p)
{
	string seats = "No";
	if (p.hasAvalibleSeats())
		seats = "Yes";
	return os << "Name: " << p.name << "\nE-Mail: " << p.email << "\nHas free seats: " << seats << endl;
}
