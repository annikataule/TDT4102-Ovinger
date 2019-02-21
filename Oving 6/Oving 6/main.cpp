#include "std_lib_facilities.h"
#include "Task1.h"
#include "Task2.h"
#include "Task3.h"
#include "Task4.h"



int main(){

	// Your code here
	//cinToFile("inn.txt");

	//addLineNumber("inn.txt", "out.txt");

	//countCharInTxt("grunnlov.txt");

	/*
	
	CourseCatalog courses = CourseCatalog();

	courses.addCourse("TDT4100", "Informasjonsteknologi grunnkurs");
	courses.addCourse("TDT4102", "Prosedyre- og objektorientert programmering");
	courses.addCourse("TMA4100", "Matematikk 1");

	cout << courses;

	courses.addCourse("TDT4103", "C++");

	*/

	// map.insert funker ikke


	//cout << courses;

	
	vector<Temps> temps;
	string file = "temperatures.txt";

	readTempsFromFile(temps, file);

	cout << temps;

	

	return 0;
}
