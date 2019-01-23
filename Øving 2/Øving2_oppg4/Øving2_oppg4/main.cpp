// Example program in TDT4102_Graphics template, from PPP page 415
#include "std_lib_facilities.h"
#include "Graph.h"
#include "Simple_window.h" 
#include "loan_drawer.h"

vector<int> CalculateSeries(double loan, double years, double interest) {
	vector<int> payments(years);
	int curLoan = loan;
	for (int i = 0; i < years; i++) {
		payments[i] = int((loan / years) + (interest / 100) * curLoan);
		curLoan -= int(loan / years);
	}
	return payments;
}

vector<int> CalculateAnnuity(double loan, double years, double interest) {
	int total = loan * ((interest / 100) /( 1 - pow(1 + interest / 100, -years)));
	vector<int> payments(10);
	for (int i = 0; i < years; i++) {
		payments[i] = total;
	}
	return payments;
}

int SumVector(vector<int>& vec) {
	int total = 0;
	for (int i = 0; i < vec.size(); i++)
		total += vec[i];
	return total;
}


void DrawLoanTable(vector<int>& seriesLoan, vector<int>& annuityLoan) {
	int tableW = 12;
	cout << setw(tableW) << "Year" << setw(tableW) << "Series" << setw(tableW) << "Annuity" << setw(tableW) << "Difference" << endl;

	for (int i = 0; i < seriesLoan.size(); i++) {
		cout << setw(tableW) << (i + 1) << setw(tableW) << seriesLoan[i] << setw(tableW) << annuityLoan[i] << setw(tableW) << (seriesLoan[i] - annuityLoan[i]) << endl;
	}

	cout << setw(tableW) << "Total" << setw(tableW) << SumVector(seriesLoan) << setw(tableW) << SumVector(annuityLoan) << setw(tableW) << (SumVector(seriesLoan) - SumVector(annuityLoan)) << endl;
}

int main() {
	vector<int> seriesLoan = CalculateSeries(10000, 10, 3);
	vector<int> annuityLoan = CalculateAnnuity(10000, 10, 3);
	DrawLoanTable(seriesLoan, annuityLoan);
	//drawPlot(annuityLoan, seriesLoan, 10000, 3);
	keep_window_open();
	return 0;
}

