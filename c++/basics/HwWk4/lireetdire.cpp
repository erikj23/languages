#include <iostream>
using namespace std;

int separer_chiffre_gauche(int& nombre)
{
  int dix(1);
  int temp(nombre);
  while (temp >= 10) {
    dix  *= 10;
    temp /= 10;
  }
  nombre %= dix;
  return temp;
}

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/

void ajouter_chiffre_droit(int& nombre, int chiffre) // add right digit
{

	nombre = nombre * 10 + chiffre;
	
}

void dire_chiffre(int& nombre, int repetitions_chiffre, int chiffre) // say number
{
	int n(0);
	
	ajouter_chiffre_droit(n, nombre);
	ajouter_chiffre_droit(nombre, repetitions_chiffre);
	ajouter_chiffre_droit(nombre, chiffre);
		
}

int lire_et_dire(int nombre) // read and say
{

	int stack(0);
	
	while(nombre != 0) {
		
		int number(separer_chiffre_gauche(nombre));
		
		if(number == stack % 10) stack += 10;
		else {
			
			ajouter_chiffre_droit(stack, 1);
			ajouter_chiffre_droit(stack, number);
			
		}
		
	}	

	return stack;
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

void repeter_lire_et_dire(int& nombre, int fois)
{
  while (fois-- > 0) {
    nombre = lire_et_dire(nombre);
  }
}

int main()
{
  int nombre(1);
  int fois(1);
  cin >> nombre >> fois;
  repeter_lire_et_dire(nombre, fois);
  cout << nombre << endl;
  return 0;
}