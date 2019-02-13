#include "Task3.h"

CourseCatalog::CourseCatalog()
{
}

void CourseCatalog::addCourse(string code, string name)
{
	courses.insert(code, name);
}

void CourseCatalog::removeCourse(string code)
{
	courses.erase(code);
}

string CourseCatalog::getCourse(string code)
{
	return courses[code];
}

ostream & operator<<(ostream &, const CourseCatalog &)
{
	// TODO: insert return statement here
}
