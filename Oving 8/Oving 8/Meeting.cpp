#include "Meeting.h"




Meeting::Meeting()
{
}

int Meeting::getDay() const
{
	return day;
}

int Meeting::getStartTime() const
{
	return startTime;
}

int Meeting::getEndTime() const
{
	return endTime;
}

Campus Meeting::getLocation() const
{
	return location;
}

string Meeting::getSubject() const
{
	return subject;
}

const Person* Meeting::getLeader() const
{
	return leader;
}


Meeting::~Meeting()
{
}

Campus begin(Campus c)
{
	return Campus::First;
}

Campus end(Campus c)
{
	return Campus::Last;
}

Campus operator++(Campus& x) {
	return x = (Campus)(std::underlying_type<Campus>::type(x) + 1);
}

Campus operator*(Campus c) {
	return c;
}


ostream & operator<<(ostream & os, const Campus & c)
{

	//string campus;
	for (auto city : c) {
		os << city << endl;
	}
	return os;
}
