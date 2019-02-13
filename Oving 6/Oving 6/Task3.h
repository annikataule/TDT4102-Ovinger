#pragma once
#include "std_lib_facilities.h"

class CourseCatalog
{
public:
	CourseCatalog();
	friend ostream& operator<<(ostream&, const CourseCatalog&);
	void addCourse(string code, string name);
	void removeCourse(string code);
	string getCourse(string code);
private:
	map<string, string> courses;
};
