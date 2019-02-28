#include "Task3.h"

CourseCatalog::CourseCatalog()
{
}

void CourseCatalog::addCourse(string code, string name)
{
	courses[code] = name;
}

void CourseCatalog::removeCourse(string code)
{
	courses.erase(code);
}

string CourseCatalog::getCourse(string code)
{
	return courses[code];
}


ostream& operator<<(ostream & os, const CourseCatalog & cc)
{	
	string courses;
	for (const auto c : cc.courses)
	{
		 courses += c.first + '\t' + c.second + '\n';
	}
	return os << courses;
}
