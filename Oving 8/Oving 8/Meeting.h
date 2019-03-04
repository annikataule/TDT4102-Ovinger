#pragma once

#include "std_lib_facilities.h"
#include "Person.h"

enum class Campus
{
	Trondheim,
	Ålesund,
	Gjøvik
};

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

	static set<const Meeting*> meetings;

public:
	Meeting(int d, int sT, int eT, Campus loc, string sub, Person* lead);
	
	int getDay() const;
	int getStartTime() const;
	int getEndTime() const;

	Campus getLocation() const;

	string getSubject() const;

	const Person* getLeader() const;

	void addParticipant(Person* person);

	set<const Person*> getParticipants() const;
	vector<string> getParticipantList() const;

	vector<const Person*> findPotentialCoDriving() const;

	~Meeting();
};

ostream& operator<<(ostream& os, const Meeting& m);







