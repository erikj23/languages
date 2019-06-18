
#include <iostream>
using namespace std;

int start();
int demander_annee();
int date_Paques(int year);
void affiche_date(int year, int number);


int start() {

	int year(demander_annee());
	
	affiche_date(year, date_Paques(year));
	
	return 0;
}

int demander_annee() {
	
	int year(0);
	// ask user for year
	do {
		
		cout << "Entrez une annee (1583-4000) : ";
		cin >> year;
	// verify year is in between 1583 and 4000
	} while (year > 4000 or year < 1583);
	
	// return the entered year 
	return year;
}

int date_Paques(int year) {
	
	int century(0), p(0), q(0), m(0), n(0), d(0), e(0), day(0);
	
	century = year / 100;
	p = (13 + (8 * century)) / 25;
	q = century / 4;
	m = (15 - p + century - q) % 30;
	n = (4 + century - q) % 7;
	d = (m + 19 * (year % 19)) % 30;
	e = (2 * (year % 4) + 4 * (year % 7) + 6 * d + n) % 7;
	// DEBUG
	// cout << "century" << century << endl;
	// cout << "p" << p << endl;
	// cout << "q" << q << endl;
	// cout << "m" << m << endl;
	// cout << "n" << n << endl;
	// cout << "d" << d << endl;
	// cout << "e" << e << endl;
	// cout << "mb" << (11 * (m + 1)) % 30 << endl;
	day = e + d + 22;
	
	if(e == 6 and d == 29 or d == 28 and (11 * (m + 1)) % 30 < 19) day = day - 7;

	return day;
}

void affiche_date(int year, int number) {
	// display the year followed by colon then month and day
	cout << "Date de Paques en " << year << " : ";
	// if the second number is <= 31 display number and march
	if(number <= 31) cout << number <<  " mars" << endl;
	else cout << number - 31 <<  " avril" << endl;
	// if >= 32 subtract 31 and display april
}

int main() {
	
	return start();
}
