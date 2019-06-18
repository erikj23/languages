#include <iostream>
using namespace std;

int main()
{
  int debut(0);
  do {
    cout << "de (>= 1) ? ";
    cin >> debut;
  } while (debut < 1);

  int fin(0);
  do {
    cout << "a (>= " << debut << ") ? ";
    cin >> fin;
  } while (fin < debut);

  /*******************************************
   * Completez le programme a partir d'ici.
   *******************************************/

	++fin;
	
	for(debut; debut < fin; ++debut) {
		
		int catl(debut);
		int count(0);
		
		while(catl != 0) {
			
			++count;
			
			if(catl % 3 == 0) catl += 4;
			else if (catl % 4 == 0) catl /= 2;
			else --catl;
			
		}
		
		cout << debut << " -> " << count << endl;
		
	}
	
  /*******************************************
   * Ne rien modifier apres cette ligne.
   *******************************************/

  return 0;
}