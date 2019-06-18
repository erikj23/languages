#include <iostream>
#include <ctime>

// pour les nombres aléatoires
#include <random>
#include <cstring> // strlen

using namespace std;

// ======================================================================
// Couleur au hasard
std::uniform_int_distribution<int> distribution;
std::default_random_engine generateur(time(NULL)); /* NOT using std::random_device since not
                                                    * all compilers seems to support it :-( */

char tirer_couleur()
{
  static const char* const couleurs = ".RGBCYM";
  static const int nb = strlen(couleurs) - 1;

  return couleurs[distribution(generateur,
                               std::uniform_int_distribution<int>::param_type {0, nb})];
}

// ======================================================================
char poser_question()
{
  char lu(' ');
  cout << "Entrez une couleur : ";
  cin >> lu;
  return lu;
}

// ---- prototype -------------------------------------------------------
bool couleur_valide(char c);

// ======================================================================
char lire_couleur()
{
  char lu(poser_question());
  while (not couleur_valide(lu)) {
    cout << "'" << lu << "' n'est pas une couleur valide." << endl;
    cout << "Les couleurs possibles sont : ., R, G, B, C, Y ou M." << endl;
    lu = poser_question();
  }
  return lu;
}

// ======================================================================
void afficher_couleurs(char c1, char c2, char c3, char c4)
{
  cout << ' ' << c1 << ' ' << c2 << ' ' << c3 << ' ' << c4;
}

// ======================================================================
void afficher(int nb, char c)
{
  while (nb-- > 0) {
    cout << c;
  }
}

// ---- prototype -------------------------------------------------------
void afficher_reponses(char c1, char c2, char c3, char c4,
                       char r1, char r2, char r3, char r4);

// ======================================================================
void afficher_coup(char c1, char c2, char c3, char c4,
                   char r1, char r2, char r3, char r4)
{
  afficher_couleurs(c1, c2, c3, c4);
  cout << " : ";
  afficher_reponses(c1, c2, c3, c4,
                    r1, r2, r3, r4);
  cout << endl;
}

// ======================================================================
void message_gagne(int nb_coups)
{
  cout << "Bravo ! Vous avez trouvé en " << nb_coups << " coups." << endl;
}

// ======================================================================
void message_perdu(char c1, char c2, char c3, char c4)
{
  cout << "Perdu :-(" << endl;
  cout << "La bonne combinaison était : ";
  afficher_couleurs(c1, c2, c3, c4);
  cout << endl;
}

/*****************************************************
 * Compléter le code à partir d'ici
 *****************************************************/

// ======================================================================
bool couleur_valide(char c)
{
	switch(c) {
		
		case '.':
		case 'R':
		case 'G':
		case 'B':
		case 'C':
		case 'Y':
		case 'M':
			return true;
			
		default:
			return false;
		
	}
}

// ======================================================================
bool verifier(char control, char& test, int& score)
{
	// if they match increment the score
	if(couleur_valide(control) and couleur_valide(test)) {
		
		if(control == test) {
			
			test = '#';
			++score;
		
			return true;
		}
		
	}

	test = '-';
	
	return false;
}

// ======================================================================
void apparier(char& guess, char& r1, char& r2, char& r3, char& r4, int& score)
{
	
	verifier(r1, guess, score);
	verifier(r2, guess, score);
	verifier(r3, guess, score);
	verifier(r4, guess, score);
	
}

bool contains(char guess, char r1, char r2, char r3, char r4) 	
{
	if(guess == r1 or guess == r2 or guess == r3 or guess == r4) return true;
	else return false;
}

// ======================================================================
void afficher_reponses(char c1, char c2, char c3, char c4,
                       char r1, char r2, char r3, char r4)
{ // c is player r is ref
	
	int score(0);
	
	if(contains(c1, r1, r2, r3, r4)) 
		if(verifier(r1, c1, score));
		else c1 = '+';
	else c1 = '-';
	
	if(contains(c2, r1, r2, r3, r4)) 
		if(verifier(r2, c2, score));
		else c2 = '+';
	else c2 = '-';
	
	if(contains(c3, r1, r2, r3, r4)) 
		if(verifier(r3, c3, score));
		else c3 = '+';
	else c3 = '-';
	
	if(contains(c4, r1, r2, r3, r4)) 
		if(verifier(r4, c4, score));
		else c4 = '+';
	else c4 = '-';


	for(int i(0); i < 3; ++i) {
		
		if(i == 1) {
			
			if(c1 == '#') afficher(1, c1);
			if(c2 == '#') afficher(1, c2);
			if(c3 == '#') afficher(1, c3);
			if(c4 == '#') afficher(1, c4);
			
		}
		
		if(i == 2) {
			
			if(c1 == '+') afficher(1, c1);
			if(c2 == '+') afficher(1, c2);
			if(c3 == '+') afficher(1, c3);
			if(c4 == '+') afficher(1, c4);
			
		}
		
		if(i == 3) {
			
			if(c1 == '-') afficher(1, c1);
			if(c2 == '-') afficher(1, c2);
			if(c3 == '-') afficher(1, c3);
			if(c4 == '-') afficher(1, c4);
			
		}
		
	}
	
}

// ======================================================================
bool gagne(char c1, char c2, char c3, char c4,
           char r1, char r2, char r3, char r4)
{
	
	if(c1 == r1 and c2 == r2 and c3 == r3 and c4 == r4) return true;
	else return false;
	
}

// ======================================================================
void jouer(int max=8)
{
	bool won(true);
	int guesses(0);
	char c1(tirer_couleur()), c2(tirer_couleur()), c3(tirer_couleur()),
	c4(tirer_couleur()), r1('x'), r2('x'), r3('x'), r4('x');
	
	do {
		
		r1 = lire_couleur();
		r2 = lire_couleur();
		r3 = lire_couleur();
		r4 = lire_couleur();
		
		afficher_coup(r1, r2, r3, r4, c1, c2, c3, c4);
		
		won = gagne(c1, c2, c3, c4, r1,r2, r3, r4);
		
	} while(not won and ++guesses < max);
	
	if(won) message_gagne(guesses);
	else message_perdu(c1, c2, c3, c4);
	
}

/*******************************************
 * Ne rien modifier après cette ligne.
 *******************************************/

int main()
{
  jouer();
  return 0;
}