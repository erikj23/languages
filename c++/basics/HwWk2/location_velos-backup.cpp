#include <iostream>
using namespace std;

int main()
{
  cout << "Donnez l'heure de début de la location (un entier) : ";
  int debut;
  cin >> debut;

  cout << "Donnez l'heure de fin de la location (un entier) : ";
  int fin;
  cin >> fin;

  /*****************************************************
   * ComplÃ©ter le code Ã  partir d'ici
   *****************************************************/
		
		if((debut < 0) or (debut > 24) or (fin < 0) or (fin > 24)) {
		
			cout << "Les heures doivent être comprises entre 0 et 24 !" << endl;
		
			return 1;
		}
    if(fin == debut) {
			
			cout << "Bizarre, vous n'avez pas loué votre vélo bien longtemps !" 
				<< endl;
			
			return 1;
		}
		if(debut > fin) {
			
			cout << "Bizarre, le début de la location est après la fin ..." 
				<< endl;

			return 1;
		}
		
		int cost(0);
		int f1_count(0);
		int f2_count(0);
		int location(0);	
		int size(fin - debut);
		
			
		switch(debut + 1) {
		
			case 0:
			case 1:
				++cost;
				++f1_count;
				++location;
				if(location == size) break;
				
			case 2:
				++cost;
				++f1_count;
				++location;
				if(location == size) break;
				
			case 3:
				++cost;
				++f1_count;
				++location;
				if(location == size) break;
				
			case 4:
				++cost;
				++f1_count;
				++location;
				if(location == size) break;
				
			case 5:
				++cost;
				++f1_count;
				++location;
				if(location == size) break;
				
			case 6:
				++cost;
				++f1_count;
				++location;
				if(location == size) break;
				
			case 7:
				++cost;
				++f1_count;
				++location;
				if(location == size) break;
				
			case 8:
				cost+=2;
				++f2_count;
				++location;
				if(location == size) break;
				
			case 9:
				cost+=2;
				++f2_count;
				++location;
				if(location == size) break;
				
			case 10:
				cost+=2;
				++f2_count;
				++location;
				if(location == size) break;
				
			case 11:
				cost+=2;
				++f2_count;
				++location;
				if(location == size) break;
				
			case 12:
				cost+=2;
				++f2_count;
				++location;
				if(location == size) break;
				
			case 13:
				cost+=2;
				++f2_count;
				++location;
				if(location == size) break;
				
			case 14:
				cost+=2;
				++f2_count;
				++location;
				if(location == size) break;
				
			case 15:
				cost+=2;
				++f2_count;
				++location;
				if(location == size) break;
				
			case 16:
				cost+=2;
				++f2_count;
				++location;
				if(location == size) break;
				
			case 17:
				cost+=2;
				++f2_count;
				++location;
				if(location == size) break;
				
			case 18:
				++cost;
				++f1_count;
				++location;
				if(location == size) break;
				
			case 19:
				++cost;
				++f1_count;
				++location;
				if(location == size) break;
	
			case 20:
				++cost;
				++f1_count;
				++location;
				if(location == size) break;
				
			case 21:
				++cost;
				++f1_count;
				++location;
				if(location == size) break;
				
			case 22:
				++cost;
				++f1_count;
				++location;
				if(location == size) break;
				
			case 23:
				++cost;
				++f1_count;
				++location;
				if(location == size) break;
				
			case 24:
				++cost;
				++f1_count;
				
		}
		
    cout << "Vous avez loué votre vélo pendant" << endl;
		
		if(f1_count > 0)
			cout << f1_count << " heure(s) au tarif horaire de 1 franc(s)" << endl;

		if (f2_count > 0)
			cout << f2_count << " heure(s) au tarif horaire de 2 franc(s)" << endl;
			
    cout << "Le montant total à payer est de " << cost
			<< " franc(s)." << endl;

  /*******************************************
   * Ne rien modifier aprÃ¨s cette ligne.
   *******************************************/

  return 0;
}