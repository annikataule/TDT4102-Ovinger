#include "Meeting.h"





Meeting::Meeting(int d, int sT, int eT, Campus loc, string sub, Person * lead) :
	day{ d }, startTime{ sT }, endTime{ eT }, location{ loc }, subject{ sub }, leader{ lead }
{
	addParticipant(lead);
	meetings.emplace(this);
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

void Meeting::addParticipant(Person * person)
{
	participants.emplace(person);
}

set<const Person*> Meeting::getParticipants() const
{
	return participants;

}

vector<string> Meeting::getParticipantList() const
{
	vector<string> names;
	for (auto p : participants) 
	{
		names.push_back(p->getName());
	}
	return names;
}

vector<const Person*> Meeting::findPotentialCoDriving() const
{
	vector<const Person*> drivers;

	for (const auto m : meetings)
	{
		if (m->getLocation() == this->location) {
			if (m->getDay() == this->day &&
				abs(m->getStartTime() - this->startTime) <= 100 &&
				abs(m->getEndTime() - this->endTime) <= 100)
			{
				for (const auto p : m->getParticipants()) {
					if (p->hasAvalibleSeats())
						drivers.push_back(p);
				}
			}
		}
		
	}
	return drivers;
}

ostream & operator<<(ostream & os, const Campus & c)
{
	switch (c)
	{
	case Campus::Trondheim: os << "Trondheim";
		break;
	case Campus::Ålesund: os << "Ålesund";
		break;
	case Campus::Gjøvik: os << "Gjøvik";
		break;
	}
	return os;
}

ostream& operator<<(ostream & os, const Meeting & m)
{
	os << "Subject: " << m.getSubject() << endl;
	os << "Location: " << m.getLocation() << endl;
	os << "Starttime: " << m.getStartTime() << endl;
	os << "Endtime: " << m.getEndTime() << endl;
	os << "Leader: " << m.getLeader()->getName() << endl;
	os << "Participants: " << endl;

	for (auto p : m.getParticipantList())
	{
		os << p << endl;
	}
	return os;
}

set<const Meeting*> Meeting::meetings;



Meeting::~Meeting()
{
	meetings.erase(this);
}
