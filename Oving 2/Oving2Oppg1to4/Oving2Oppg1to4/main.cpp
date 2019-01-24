#include "std_lib_facilities.h"

#pragma region Oppgave 1 og 2


void inputAndPrintInteger() {
	cout << "Skriv inn et tall: ";
	int input = 0;
	cin >> input;
	cout << "Du skrev: " << input << "\n";
}


int inputInteger() {
	cout << "Skriv inn et tall: ";
	int input = 0; cin >> input;
	return input;
}

void inputIntegersAndPrintSum() {
	int a = inputInteger();
	int b = inputInteger();
	int number = a + b;
	cout << "Summen av tallene: " << number << "\n";
}

bool IsOdd(int number) {
	if (number % 2)
		return true;
	return false;
}

void printHumanReadableTime(int seconds) {
	int minSek = 60, timeSek = pow(minSek, 2);
	int timer = seconds / timeSek;
	int timeLeft = seconds - timer * timeSek;
	int minutter = timeLeft / minSek;
	timeLeft = timeLeft - minutter * minSek;
	cout << timer << " timer, " << minutter << " minutter, " << timeLeft << " sekunder" << "\n";
}

void inputIntegersUsingLoopAndPrintSum() {
	int sum = 0;
	int innlest = 0;
	while (true) {
		innlest = inputInteger();
		if (innlest == 0)
			break;
		sum += innlest;
	}
	cout << "Summen er: " << sum << "\n";
}

double inputDouble() {
	double inndata = 0.0;
	cout << "Skriv inn et desimaltall: ";
	cin >> inndata;
	return inndata;
}

void NOKtoEUR(double eurValue = 9.75) {
	double nok = inputDouble();
	while (nok < 0)
	{
		cout << "Tallet er negativt, skriv inn et positivt tall." << endl;
		nok = inputDouble();
	}
	cout << nok << " kroner er " << (nok / eurValue) << " euro." << endl;
}


#pragma endregion

#pragma region Oppgave 3

void Gangetabell(int width, int height) {
	string leng = std::to_string(width * height);
	for (int i = 1; i <= width; i++) {
		for (int j = 1; j <= height; j++) {
			cout << setw(leng.length() + 1) << i * j;
		}
		cout << endl;
	}
}

void DrawGangetabell() {
	int width = 0, height = 0;
	cout << "Skriv inn bredden på gangetabellen: ";
	cin >> width;
	cout << "Skriv inn høyden på gangetabellen: ";
	cin >> height;
	Gangetabell(width, height);
}
#pragma endregion

#pragma region Oppgave 4

double Discriminant(double a, double b, double c) {
	return pow(b, 2) - (4 * a * c);
}

void PrintRealRoots(double a, double b, double c) {
	double disc = Discriminant(a, b, c);
	if (disc > 0) {
		double solved1 = (-b + sqrt(disc)) / (2 * a);
		double solved2 = (-b - sqrt(disc)) / (2 * a);
		cout << "The solutions are x_1 = " << solved1 << " and x_2 = " << solved2 << endl;
	}
	else if (disc == 0)
		cout << "The solution are x = " << (-b / (2 * a)) << endl;
	else if (disc < 0)
		cout << "There are no real solutions.";
}

void SolveQuadradicEquation() {
	double a = 0, b = 0, c = 0;
	cout << "ax^2 + bx + c = 0" << endl;
	cout << "Enter a = ";
	cin >> a;
	cout << "Enter b = ";
	cin >> b;
	cout << "Enter c = ";
	cin >> c;
	PrintRealRoots(a, b, c);
}

#pragma endregion


#pragma region Menu

bool menyFunc() {
	cout << "\nVelg funksjon:\n";
	cout << "(0) Avslutt\n";
	cout << "(1) Summer to tall\n";
	cout << "(2) Summer flere tall\n";
	cout << "(3) Konverter fra NOK til EURO\n";
	cout << "(4) Tegn gangetabell" << endl;
	cout << "(5) Løs 2. gradsplynom" << endl;
	cout << "Angi valg (0-5): ";
	int valg = 0;
	cin >> valg;
	switch (valg)
	{
	case 0:
		return false;
		break;
	case 1:
		inputIntegersAndPrintSum();
		break;
	case 2:
		inputIntegersUsingLoopAndPrintSum();
		break;
	case 3:
		NOKtoEUR();
		break;
	case 4:
		DrawGangetabell();
		break;
	case 5:
		SolveQuadradicEquation();
		break;
	default:
		cout << "Tast inn et tall mellom 0 og 5. Prøv igjen.\n";
		break;
	}
	return true;
}
#pragma endregion


int main() {
	{
		/*
		// Oppgave 1a
		inputAndPrintInteger();


		// 1b
		int number = inputInteger();
		cout << "Du skrev: " << number << "\n";

		// 1c
		cout << "\n\n1c\n";
		inputIntegersAndPrintSum();

		// 1d - TEORI
		//
		//Jeg valgte inputInteger fordi den ikke printer tallet du skrev inn tilbake til skjermen.
		//

		// 1e
		for (int i = 0; i < 16; i++) {
			cout << i << ": " << IsOdd(i) << "\n";
		}

		// 1f
		printHumanReadableTime(10000);
		*/
	}

	{
		/*
		// Oppgave 2a
		inputIntegersUsingLoopAndPrintSum();

		// 2b - TEORI
		/*
		Dersom man velger å avslutte summing med 0, burde man bruke en "while"-løkke. Den kan fortsette i all evighet, siden den ikke krever noen start- og sluttverider.

		Der du sier hvor mange summinger du ønsker er en "for"-løkke det beste, da kjører den kun sp mange ganger du ønsker at den skal kjøre
		*/
		/*
		// 2c
		cout << "Halvparten :" << inputDouble() / 2;
		*/
		//2d
		//NOKtoEUR();
	}


#pragma region Oppgave 3 - Menysystem
	// a

	while (menyFunc()) {}

	//Gangetabell(14, 14);

#pragma endregion


	return 0;
}