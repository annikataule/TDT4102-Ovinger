#include "Task4.h"

istream & operator>>(istream & is, Temps & t)
{
	double inMax, inMin;
	is >> inMax >> inMin;
	if (!is) return is;

	t = Temps{ inMax, inMin };
	return is;
	// TODO: insert return statement here
}

ostream & operator<<(ostream & os, vector<Temps>& temps)
{
	for (const auto t : temps)
	{
		os << t.max << '\t' << t.min << '\n';
	}
	return os;
}

void readTempsFromFile(vector<Temps>& temps, string path)
{
	ifstream ifs{ path };
	if (!ifs)
	{
		error("Cant open file ", path);
		return;
	}
	Temps t;
	string line;
	while (getline(ifs, line))
	{
		cout << line;
		istringstream iss{ line };
		iss >> t;
		temps.push_back(t);
	}
}
