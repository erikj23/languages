#include <iostream>
using namespace std;

int main() 
{
	
  cout << "Pensez à un champignon : amanite tue-mouches, pied bleu, girolle,"
		<< endl << "cÃ¨pe de Bordeaux, coprin chevelu ou agaric jaunissant."
		<< endl << endl;
  
	bool layer1(0), layer2(0), layer3(0);
	// convex?
	cout << "Est-ce que votre champignon a un chapeau convexe (1 : oui, 0 : non) ? ";
	cin >> layer1;
	// yes - aj, atm, pb
	if(layer1) {
		// forrest?
		cout << "Est-ce que votre champignon vit en forêt (1 : oui, 0 : non) ? ";
		cin >> layer2;
		// yes - atm, pb
		if (layer2) {
			// ring?
			cout << "Est-ce que votre champignon a un anneau (1 : oui, 0 : non) ? ";
			cin >> layer3;
			// yes - atm
			if(layer3) {
				
				cout << "==> Le champignon auquel vous pensez est ";
				cout << "amanite tue-mouches";
			// no - pb
			} else {
				
				cout << "==> Le champignon auquel vous pensez est ";
				cout << "pied bleu"; 
				
			}
		// no - aj
		} else {
			
			cout << "==> Le champignon auquel vous pensez est ";
			cout << "agaric jaunissant";
			
		}
	// no - cdb, cc, g
	} else {
		// gills?
		cout << "Est-ce que votre champignon a des lamelles (1 : oui, 0 : non) ? ";
		cin >> layer2;
		// yes - cc, g
		if (layer2) {
			// ring?
			cout << "Est-ce que votre champignon a un anneau (1 : oui, 0 : non) ? ";
			cin >> layer3;
			// yes - cc
			if(layer3) {
			
				cout << "==> Le champignon auquel vous pensez est ";
				cout << "coprin chevelu";
			// no - g	
			} else {
			
				cout << "==> Le champignon auquel vous pensez est ";
				cout << "girolle";
				
			}
		// no - cdb	
		} else {
			
			cout << "==> Le champignon auquel vous pensez est ";
			cout << "cèpe de bordeaux";
			
		}
	}
}