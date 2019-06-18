#include <iostream>
#include <iomanip> // pour setprecision()
using namespace std;

int main()
{
  // Réduire le format d'affichage
  cout << setprecision(4);

  // Paramètres
  double taux_croissance_lapins(0.3);
  double taux_attaque(0.01);
  double taux_croissance_renards(0.008);
  double taux_mortalite(0.1);
  int duree(50);

  double renards_i(0.0);
  double lapins_i(0.0);

  /*****************************************************
   * Compléter le code à partir d'ici
   *****************************************************/
	
   // ===== PARTIE 1 =====
   // Saisie des populations initiales

   do {
		
      cout << "Combien de renards au départ (>= 2) ? ";
      cin >> renards_i;
		
   } while(renards_i < 2);
   do {
      
		cout << "Combien de lapins au départ  (>= 5) ? ";
      cin >>  lapins_i;
		
   } while(lapins_i < 5);
  
	double o_lapins(lapins_i);
	double o_renards(renards_i);
	
   // ===== PARTIE 2 =====
   // Première simulation
	
   cout <<  endl << "***** Le taux d'attaque vaut "<< taux_attaque * 100 << "%"
        <<  endl;

   for(int i(1); i <= duree; ++i) {
	  
		renards_i = renards_i * (1.0 + taux_attaque * lapins_i *
         taux_croissance_renards - taux_mortalite);
	  
      lapins_i = lapins_i * (1.0 + taux_croissance_lapins - 
         taux_attaque * renards_i);
      
      cout << "Après " << i << " mois, il y a " << lapins_i << " lapins et " 
           << renards_i << " renards" << endl;
	  
   }

   // ===== PARTIE 3 =====
   // Variation du taux d'attaque
	
   cout << endl;
	
	do {
	
      cout << "taux d'attaque au départ en % (entre 0.5 et 6) ? ";  
      cin >> taux_attaque;  
		
   } while(taux_attaque < 0.5 or taux_attaque > 6);
	
	taux_attaque /= 100;
	
	double fin_taux_attaque(0.0);
	
   do { 
	
		cout << "taux d'attaque à la fin  en % (entre " << taux_attaque * 100
			  << " et 6) ? ";
		cin >> fin_taux_attaque;
	
   } while(fin_taux_attaque < (taux_attaque * 100) or fin_taux_attaque > 6);
	
	fin_taux_attaque /= 100;
	
	int l_fluc(0); // fluctuation of population for rabits
   int r_fluc(0); // fluctuation of population for foxes
   
	for(taux_attaque; taux_attaque <= fin_taux_attaque; taux_attaque += 0.01) {
	
		lapins_i = o_lapins;
		renards_i = o_renards;
	
		cout <<  endl << "***** Le taux d'attaque vaut "<< taux_attaque * 100 
			  << "%" <<  endl;
	
		for(int i(1); i <= duree; ++i) {
			
			if(lapins_i == 0 and renards_i == 0) break; 
			
			renards_i = renards_i * (1.0 + taux_attaque * lapins_i *
				taux_croissance_renards - taux_mortalite);
			
			lapins_i = lapins_i * (1.0 + taux_croissance_lapins - 
				taux_attaque * renards_i);
		
			if(lapins_i < 5 and l_fluc == 0) {       
         
				if(lapins_i < 2) {
				
					lapins_i = 0;
					renards_i = 0;
				
				}
         
				++l_fluc;
         
				cout << "Les lapins ont été en voie d'extinction" << endl;
  
			}
      
			if(lapins_i > 5 and l_fluc == 1) {
			
				--l_fluc;
         
				cout << "mais la population est remontée ! Ouf !" << endl;
			
			}
		
			if(renards_i < 5 and r_fluc == 0) {
		
				if(renards_i < 2) {

					renards_i = 0;
				
				}
         
				++r_fluc; 
			
				cout << "Les renards ont été en voie d'extinction" << endl;
         
			}
      
			if(renards_i > 5 and r_fluc == 1) {
         
				--r_fluc;
         
				cout << "mais la population est remontée ! Ouf !" << endl;
      
			}
   
		}
		
		if(lapins_i == 0) cout << "et les lapins ont disparu :-(" << endl;
		if(renards_i == 0) cout << "et les renards ont disparu :-(" << endl;
		else cout << "Les lapins et les renards ont des populations stables." 
				    << endl;
				 
		cout << "Après " << duree << " mois, il y a " << lapins_i << " lapins et " 
			  << renards_i << " renards" << endl;
		
	}
   
	cout << endl;
   
  /*******************************************
   * Ne rien modifier après cette ligne.
   *******************************************/

  return 0;
}