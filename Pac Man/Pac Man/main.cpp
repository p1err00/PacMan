//ATTENTION vous devez faire bouger PacMan pour qu'il apparaisse dans le niveau (il est timide, il ne veut jamais faire le premier pas)
//librairie et fichiers d'en-tête nécessaire
#include <iostream>///////
#include <fstream>      //////librairies
#include <time.h>/////////

#include "GL\glut.h"//////
#include "joueur.h"     //
#include "fantôme.h" 	//
#include "fantôme2.h"	///////importation de classes
#include "fantôme3.h"	//
#include "fantôme4.h"	//
#include "EnnemiBase.h" //

//déclarations spécifiques
using namespace std; //simplification de l'écriture

int NbColonnes, NbLignes; // taille du niveau 
char** Matrice; //// m atrice contenant le niveau (double pointeur)
char niveau[] = "niveauPacMan.txt"; //fichier texte du niveau de mon Pac Man
int deplacement = 0;//variable pour l'ouiverture et la fermeture de la bouche
int score = 0; //variable pour le score
int e = 1; //variable pour l'ouiverture et la fermeture de la bouche
int droitei, gauchei, droitej, gauchej; //variable pour la téléportation
const int TIMER_MILLIS = 100; // Laps de temps entre 2 appels à l'évènement Timer

//objets
//Fantome monFantome; //objet de type Fantome
Joueur monJoueur; // objet de type Joueur

EnnemiBase* premierEnnemi = NULL;// Pointeur sur le premier ennemi de la liste

//Enumération pour le type d'ennemi
enum TYPE_ENNEMI
{
	FANTOME, FANTOME2, FANTOME3, FANTOME4 // Identificateur des ennemies
};

//déclaration des fonctions
void PMAffichage();
void PMRedim(int x, int y);
void OuvrirNiveau(char* nom_fichier);
void DessinerNiveau();
void PMClavierSpecial(int key, int x, int y);
void TestVictoire();
void LibererMemoire();
void DessinerScore();
void Manger();
void PMTimer(int value);
void AjouterEnnemi(TYPE_ENNEMI type, int Colonne, int Ligne);

//programme
void main(void) { //fonction principale du programme
	srand((int)time(NULL)); //initialisation du générateur de nombre aléatoire
	Matrice = NULL; // initialisation de la matrice
	NbColonnes = NbLignes = 0;// initialisation de la taille 

	glutInitWindowPosition(10, 10);  // position de la fenêtre
	glutInitWindowSize(500, 500);// taille de la fenêtre
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE); // double buffering
	glutCreateWindow("Pac Man"); // création de la fenêtre
	glutDisplayFunc(PMAffichage); // fonction d'affichage
	glutReshapeFunc(PMRedim);// fonction de redimentionnement
	glutSpecialFunc(PMClavierSpecial);// touches spéciales du clavier
	glutTimerFunc(TIMER_MILLIS, PMTimer, 0);// fonction timer
	OuvrirNiveau(niveau);// Ouverture de "niveauPacMan.txt"
	glutMainLoop();
}

void PMAffichage() { //fonction d'affichage

	glClearColor(0, 0, 0, 0); // définit la couleur de fond  
	glClear(GL_COLOR_BUFFER_BIT); // efface l'écran  
	glMatrixMode(GL_MODELVIEW); // définit la matrice de modélisation active 


	DessinerNiveau(); //dessine les murs du niveau
	monJoueur.Dessiner();// Affiche l’avatar du joueur
	EnnemiBase* Pointeur = premierEnnemi;
	while (Pointeur != NULL) // Si le pointeur pointe sur quelque chose d'existant
	{
		// Affichage de l'ennemi courant
		Pointeur->Dessiner();
		// Passage à l'ennemi suivant
		Pointeur = Pointeur->GetSuivant();
	}
	DessinerScore(); //dessine les points sur le niveau
	Manger();//mange les points et augmentent le score

	glFlush();
}

void PMRedim(int x, int y) {

	glViewport(0, 0, x, y);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (double)NbColonnes, (double)NbLignes, 0.0);

}

void OuvrirNiveau(char* nom_fichier) //fonction de l'ouverture du niveau
{
	//instruction d’ouverture du niveau
	ifstream fichier; //fichier est un objet de type ifstream
	fichier.open(nom_fichier); //ouverture du fichier en lecture seule
	if (fichier.good() == false) { //test de l'existence du fichier
		cout << "Erreur lors de l’ouverture du fichier !"
			<< endl;
		system("pause");
		exit(EXIT_SUCCESS);
	}
	fichier >> NbColonnes;
	fichier >> NbLignes;

	//allocation du tableau du niveau
	Matrice = new char* [NbColonnes];
	for (int i = 0; i < NbColonnes; i++)
		Matrice[i] = new char[NbLignes];

	//initialisation des valeurs du tableau
	for (int i = 0; i < NbColonnes; i++)
		for (int j = 0; j < NbLignes; j++)
			Matrice[i][j] = '0';

	//lecture du tableau
	for (int j = 0; j < NbLignes; j++)
	{
		for (int i = 0; i < NbColonnes; i++)
		{
			fichier >> Matrice[i][j];
			switch (Matrice[i][j])
			{
			case 'j':
			case 'J': {
				monJoueur.SetPosC(i);
				monJoueur.SetPosL(j);
				// Définir ici la position de départ
				break;
			}
			case 'f':
			case 'F': {
				AjouterEnnemi(FANTOME, i, j);
				break;
				// Définir ici la position de départ
			}
			case 'v':
			case 'V': {
				AjouterEnnemi(FANTOME2, i, j);
				break;
				// Définir ici la position de départ
			}
			case 'r':
			case 'R': {
				AjouterEnnemi(FANTOME3, i, j);
				break;
				// Définir ici la position de départ
			}
			case 'b':
			case 'B': {
				AjouterEnnemi(FANTOME4, i, j);
				break;
				// Définir ici la position de départ
			}
			case 'x':
			case 'X': {
				gauchei = i;
				gauchej = j;
				break;
				// Définir ici la position de la téléportation gauche
			}
			case 'y':
			case 'Y': {
				droitei = i;
				droitej = j;
				break;
				// Définir ici la position de la téléportation droite
			}
			}
		}
	}

}

void DessinerNiveau() { //fonction pour tracer le niveau. Elle permet de tracer des lignes bleues en fonction de chaque cellules en contact avec elles mêmes
	for (int i = 0; i < NbColonnes; i++) {
		for (int j = 0; j < NbLignes; j++) {
			if (Matrice[i][j] == '0') {
				glColor3d(0, 0, 1);
				glBegin(GL_LINES);
				if (Matrice[i][j - 1] != '0' && j != 0) {    // Test vers le haut
					glVertex2f(i, j);
					glVertex2f(i + 1, j);
				}
				if (Matrice[i][j + 1] != '0' && j < NbLignes - 1) {    // Test vers le bas
					glVertex2f(i + 1, j + 1);
					glVertex2f(i, j + 1);
				}
				if (i >= 1) {    // Test vers la gauche
					if (Matrice[i - 1][j] != '0') {
						glVertex2f(i, j);
						glVertex2f(i, j + 1);
					}
				}
				if (i < NbColonnes - 1) {    // Test vers la droite
					if (Matrice[i + 1][j] != '0') {
						glVertex2f(i + 1, j + 1);
						glVertex2f(i + 1, j);
					}
				}
				glEnd();
			}
		}
	}
}

void PMClavierSpecial(int key, int x, int y) // Evènement lors de l'appui sur une touche spéciale du clavier
{
	//la boucle if else sert à alterner bouche ouverte et bouche fermée et la variable déplacement influe le sens d'orientation de la bouche suivant le mouvement
	if (e == 1)
	{
		switch (key) {
		case GLUT_KEY_UP: {
			deplacement = 2;
			monJoueur.BougerEnHaut();
			break; }
		case GLUT_KEY_DOWN: {
			deplacement = 4;
			monJoueur.BougerEnBas();
			break; }
		case GLUT_KEY_LEFT: {
			deplacement = 3;
			monJoueur.BougerAGauche();
			break; }
		case GLUT_KEY_RIGHT: {
			deplacement = 1;
			monJoueur.BougerADroite();
			break; }
		}
		e = 0;
	}
	else {
		switch (key) {
		case GLUT_KEY_UP: {
			deplacement = 5;
			monJoueur.BougerEnHaut();
			break; }
		case GLUT_KEY_DOWN: {
			deplacement = 5;
			monJoueur.BougerEnBas();
			break; }
		case GLUT_KEY_LEFT: {
			deplacement = 5;
			monJoueur.BougerAGauche();
			break; }
		case GLUT_KEY_RIGHT: {
			deplacement = 5;
			monJoueur.BougerADroite();
			break; }
		}
		e = 1;
	}
	monJoueur.Teleportation();//permet de faire la jonction entre la partie droite et gauche du niveau
	TestVictoire();// le joueur a peut être gagné

	glutPostRedisplay();// ordre de rafraichir l'affichage
}

void TestVictoire()
{
	//fonction pour arrêter le jeu en cas de victoire selon le score.
	if (score == 32100)
	{
		cout << "Vous avez gagne !" << endl;
		PMAffichage();
		LibererMemoire();
		system("pause");
		exit(1);
	}
}

void LibererMemoire() {
	if (Matrice != NULL)
	{
		for (int i = 0; i < NbColonnes; i++)
			delete[] Matrice[i];// Libération des colonnes
		delete[] Matrice; // Libération de la ligne de pointeurs
	}
}

void Manger() {
	//fonction pour augmenter le score et faire disparaître les points manger 
	if (Matrice[monJoueur.GetPosC()][monJoueur.GetPosL()] == '1' )//si les coordonnées du joueur sont les mêmes qu'un point se trouvant sur un '1'
	{
		Matrice[monJoueur.GetPosC()][monJoueur.GetPosL()] = '2';//alors le '1' est changé en '2' pour que le score ne soit augmenté de nouveau et pour que le point disparaisse
		score = score + 100;
		system("cls");
		cout << "Votre score est de " << score << endl;

	}
	if (Matrice[monJoueur.GetPosC()][monJoueur.GetPosL()] == 'c')//même fonctionnement que plus haut mais avec une superbe cerise
	{
		Matrice[monJoueur.GetPosC()][monJoueur.GetPosL()] = '2';
		score = score + 2500;
		system("cls");
		cout << "Votre score est de " << score << endl;

	}
}

void DessinerScore() {// focntion pour dessiner les points
	for (int l = 0; l < NbColonnes; l++)
		for (int m = 0; m < NbLignes; m++)
		{
			if (Matrice[l][m] == '1')//les points
			{
				glPushMatrix();
				glTranslated(l + 0.5, m + 0.5, 0.0);
				glColor3d(1.0, 1.0, 1.0);
				glutSolidSphere(0.1, 12, 12); // Sphère de la tête

				glPopMatrix();
			}
			if (Matrice[l][m] == 'c')//la superbe cerise (ATTENTION il y a le noyau)
			{
				glPushMatrix();
				glTranslated(l + 0.5, m + 0.5, 0.0);
				glBegin(GL_TRIANGLES);//triangle vert pour la tige
				glColor3d(0, 1, 0);
				glVertex2d(-0.3, 0.0);
				glVertex2d(0.3, 0.0);
				glVertex2d(0.3, -0.5);
				glEnd();

				glTranslated(0.0,  0.0, 0.0);
				glBegin(GL_TRIANGLES);//triangle noir pour la tige
				glColor3d(0, 0, 0);
				glVertex2d(-0.25, 0.0);
				glVertex2d(0.25, 0.0);
				glVertex2d(0.25, -0.3);
				glEnd();

				glTranslated(0.25, 0.2, 0.0);//cerise droite
				glColor3d(1, 0, 0);
				glutSolidSphere(0.2, 12, 12);

				glTranslated(-0.55, 0.0, 0.0);//cerise gauche
				glColor3d(1, 0, 0);
				glutSolidSphere(0.2, 12, 12);

				glPopMatrix();
			}
		}

}

void PMTimer(int value)
{
	EnnemiBase* Pointeur = premierEnnemi;// Déplacement de tous les ennemis de la liste :
	while (Pointeur != NULL)
	{
		Pointeur->DeplacementAuto(); // Déplacement de l'ennemi courant
		Pointeur->TestCollision(); // Test des collisions avec le joueur
		Pointeur = Pointeur->GetSuivant(); // Passage à l'ennemi suivant
	}
	glutPostRedisplay();// Ordre de rafraichir l'affichage

	glutTimerFunc(TIMER_MILLIS, PMTimer, 0);// Pour que la fonction Timer soit répétée
}

void AjouterEnnemi(TYPE_ENNEMI type, int Colonne, int Ligne)
{
	EnnemiBase* Pointeur = NULL;
	switch (type) {
	case FANTOME: Pointeur = new Fantome(); break;
	case FANTOME2: Pointeur = new Fantome2(); break;
	case FANTOME3: Pointeur = new Fantome3(); break;
	case FANTOME4: Pointeur = new Fantome4(); break;
	default: exit(0);
	}
	Pointeur->SetPosC(Colonne); ///////On définit la position de l'ennemi fraichement créé
	Pointeur->SetPosL(Ligne);/////
	Pointeur->SetSuivant(premierEnnemi);// Place le nouvel ennemi en tête de liste
	premierEnnemi = Pointeur;// La nouvelle tête est le nouvel ennemi
}
