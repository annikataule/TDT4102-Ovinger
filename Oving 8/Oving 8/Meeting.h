#pragma once

#include "std_lib_facilities.h"
#include "Person.h"

enum class Campus
{
	trondheim,
	ålesund,
	gjøvik,

	First = trondheim,
	Last = gjøvik
};

Campus begin(Campus c);
Campus end(Campus c);
Campus operator++(Campus& x);
Campus operator*(Campus c);

ostream& operator<<(ostream& os, const Campus& c);


class Meeting
{
	int day;
	int startTime;
	int endTime;
	Campus location;
	string subject;
	const Person* leader;
	set<const Person*> participants;
public:
	Meeting();

	int getDay() const;
	int getStartTime() const;
	int getEndTime() const;
	Campus getLocation() const;
	string getSubject() const;
	const Person* getLeader() const;

	virtual ~Meeting();
};



