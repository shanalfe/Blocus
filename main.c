#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include <time.h>
#define TITRE_JEU "Blokus"
#define AUTEURS "Shana LEFEVRE & Arthur DECORBEZ"

/*constantes couleurs*/
#define NOIR 0x000000
#define GRIS 0x808080
#define BLANC 0xffffff
#define ROUGE 0xff0000
#define VERT 0x00ff00
#define BLEU 0x0000ff
#define BLEU_CIEL 0x33ccff
#define VERT_CLAIR 0x00cc00
#define MARRON 0x663300

/*Constantes reglages*/
#define LARGEUR_FENETRE 1280
#define HAUTEUR_FENETRE 720
#define TAILLE_CASE 80

/*Déclaration de variable*/
int taille_grille = 6;
int nb_joueur = 1;


/*============================================================================================*/

/*--- CREATION DU MENU ---*/

int menu() {

	char nb_joueur_affichage [40];
	char string_grille[2];
	int clique = 0;			/*--- Detection du clique ---*/
	
	
	CreerFenetre((Maxx()-LARGEUR_FENETRE)/2, (Maxy()-HAUTEUR_FENETRE)/2, LARGEUR_FENETRE, HAUTEUR_FENETRE);		/* Création d'une fenêtre centrée sur l'écran */
	ChoisirTitreFenetre(TITRE_JEU " par " AUTEURS);																/* Nomme la fenêtre */
	ChoisirCouleurDessin(BLEU_CIEL);
    RemplirRectangle((LARGEUR_FENETRE / 2) - ((TailleChaineEcran(TITRE_JEU, 2) + 100) / 2), (HAUTEUR_FENETRE * 10) / 100, TailleChaineEcran(TITRE_JEU, 2) + 100, TailleSupPolice(2) + 50);
    ChoisirCouleurDessin(NOIR);
    DessinerRectangle((LARGEUR_FENETRE / 2) - ((TailleChaineEcran(TITRE_JEU, 2) + 100) / 2), (HAUTEUR_FENETRE * 10) / 100, TailleChaineEcran(TITRE_JEU, 2) + 100, TailleSupPolice(2) + 50);
    EcrireTexte((LARGEUR_FENETRE / 2) - (TailleChaineEcran(TITRE_JEU, 2) / 2), ((HAUTEUR_FENETRE * 10) / 100) + (TailleSupPolice(2) + 25), TITRE_JEU, 2);
	   
	/*--- Panneau "Taille de la grille" ---*/

    ChoisirCouleurDessin(BLEU_CIEL);
    RemplirRectangle((LARGEUR_FENETRE * 15) / 100, (HAUTEUR_FENETRE * 30) / 100, (LARGEUR_FENETRE * 25) / 100, (HAUTEUR_FENETRE * 30) / 100);
    ChoisirCouleurDessin(NOIR);
    DessinerRectangle((LARGEUR_FENETRE * 15) / 100, (HAUTEUR_FENETRE * 30) / 100, (LARGEUR_FENETRE * 25) / 100, (HAUTEUR_FENETRE * 30) / 100);

    /*--- Panneau "Mode de jeu" ---*/

    ChoisirCouleurDessin(BLEU_CIEL);
    RemplirRectangle((LARGEUR_FENETRE * 60) / 100, (HAUTEUR_FENETRE * 30) / 100, (LARGEUR_FENETRE * 25) / 100, (HAUTEUR_FENETRE * 30) / 100);
    ChoisirCouleurDessin(NOIR);
    DessinerRectangle((LARGEUR_FENETRE * 60) / 100, (HAUTEUR_FENETRE * 30) / 100, (LARGEUR_FENETRE * 25) / 100, (HAUTEUR_FENETRE * 30) / 100);

    /* --------------------------------------------------------------------------------------------------------------------------------------------------*/
		
	EcrireTexte(10, 100, "Taille de la grille :", 1);		/*--- Taille de la grille ---*/
	EcrireTexte (250, 100, "-", 2); 						/*--- Bouton "-" ---*/
	DessinerRectangle (236, 68,40, 40);
	EcrireTexte (400, 100, "+", 2);							/*--- Bouton "+" ---*/
	DessinerRectangle (387, 68, 40, 40);
	EcrireTexte (10, 150, "Nombre de joueur(s) : ", 1);		/*--- Nombre de joueurs ---*/
	EcrireTexte (250, 150, "1 joueur", 1);					/*--- Bouton "1 joueur" ---*/
	DessinerRectangle (236, 120, 100, 45);
	EcrireTexte (400, 150, "2 joueurs", 1);					/*--- Bouton "2 joueurs" ---*/
	DessinerRectangle (387, 120, 100, 45);
	/*--- Bouton JOUER ---*/
	ChoisirCouleurDessin(BLEU_CIEL);
	RemplirRectangle(128, 576, 1024, 72);
	ChoisirCouleurDessin(NOIR);
	DessinerRectangle(128, 576, 1024, 72);
	EcrireTexte(640 - TailleChaineEcran("JOUER", 2) / 2, 576 + 47, "JOUER", 2);
	sprintf(string_grille, "%d", taille_grille);
	EcrireTexte(320, 100, string_grille, 2);

	while(clique == 0){
		if(SourisCliquee()) {
			if(_X > 236 && _X < 276 && _Y > 68 && _Y < 108){			/*--- Bouton "-" ---*/
				if((taille_grille > 3) && (taille_grille < 9)) {	
					taille_grille--;
				} else if(taille_grille == 9){
					taille_grille--;
				}
				ChoisirCouleurDessin(BLANC);
				RemplirRectangle(320, 68, 40, 40);
				sprintf(string_grille, "%d", taille_grille);
				ChoisirCouleurDessin(NOIR);
				EcrireTexte(320, 100, string_grille, 2);

			}else if(_X > 387 && _X < 427 && _Y > 68 && _Y < 108){	/* Bouton "+" */
		
				if((taille_grille > 3) && (taille_grille < 9)){
					taille_grille++;
				}else if(taille_grille == 3){
					taille_grille++;
				}
				ChoisirCouleurDessin(BLANC);
				RemplirRectangle(320, 68, 40, 40);
				sprintf(string_grille, "%d", taille_grille);
				ChoisirCouleurDessin(NOIR);
				EcrireTexte(320, 100, string_grille, 2);
			}

			if(_X > 236 && _X < 336 && _Y > 120 && _Y < 165){			/* Bouton "1 joueur" */
				nb_joueur = 1;
			}else if(_X > 387 && _X < 487 && _Y > 120 && _Y < 165){	/* Bouton "2 joueurs" */
				nb_joueur = 2;
			}

			ChoisirCouleurDessin(BLANC);
			RemplirRectangle(820, 125, 25, 25);
			sprintf(nb_joueur_affichage, "Nombre de joueur : %d joueur(s)", nb_joueur);
			ChoisirCouleurDessin(NOIR);
			EcrireTexte(550, 150, nb_joueur_affichage, 2);

			if(_X >= 128 && _X <= 1152 && _Y >= 576 && _Y <= 648){		/* Bouton "Jouer" */
				clique = 1;
			}
		}
	}	
	return taille_grille;
	return nb_joueur;
}



/*--- DESSINER GRILLE ---*/

void DessinerGrille (){
	int colonne = 0, ligne = 0;
	for (colonne = 0; colonne < taille_grille*TAILLE_CASE; colonne = colonne + TAILLE_CASE){
		for (ligne = 0; ligne < taille_grille*TAILLE_CASE; ligne = ligne + TAILLE_CASE){
			DessinerRectangle (colonne, ligne, TAILLE_CASE,TAILLE_CASE);
		}
	}
}




/*--- BLOQUER JEU VS ---*/

int Bloquer_Vs (){

	int  posX, posY, number =0, placement_pionR =0, placement_pionB = 0;
	int recuperation_joueurR_posX, recuperation_joueurR_posY, recuperation_joueurB_posX, recuperation_joueurB_posY;
	int tab [TAILLE_CASE*taille_grille][TAILLE_CASE*taille_grille];
	int a =2, l,m;

	printf("LANCEMENT DU JEU MODE 2 JOUEURS\n");

	while (1){	
					

		if( SourisCliquee()){
			ChoisirCouleurDessin(NOIR);
			DessinerGrille();
			SourisPosition();

			/*--- Récupération de la partie entière ---*/
			posX = (int) _X / TAILLE_CASE;
			posY = (int) _Y / TAILLE_CASE;				

			printf ("Position cliquée [%d] [%d]\n", posX, posY);

			/*--- INITIALISATION DES PIONS ---*/

			/*--- Joueur Bleu ---*/
			if (placement_pionB < 1){
				if ( (posX < taille_grille) && (posY<taille_grille) ){
					if (! tab[posX][posY]){
						ChargerImage("images/pionJoueurB.png", posX * TAILLE_CASE + 1, posY * TAILLE_CASE +1, 0, 0, TAILLE_CASE, TAILLE_CASE);
						tab[posX][posY]= 1;
						recuperation_joueurB_posX = posX;
						recuperation_joueurB_posY = posY;
					}
				}
				placement_pionB ++;
				printf ("\033[34m Anciennes coordonnées joueur B [%d][%d] OK  \033[37m \n", recuperation_joueurB_posX, recuperation_joueurB_posY);
			}

			/*--- Joueur Rouge ---*/
			if (placement_pionR < 2){
				if ( (posX < taille_grille) && (posY<taille_grille) ){
					if (! tab[posX][posY]){	
						ChargerImage("images/pionJoueurR.png", posX * TAILLE_CASE + 1, posY * TAILLE_CASE +1, 0, 0, TAILLE_CASE, TAILLE_CASE);
						tab[posX][posY]= 1;
						
						recuperation_joueurR_posX = posX;
						recuperation_joueurR_posY = posY;
					}
				}
				placement_pionR ++;
				printf ("\033[35m  Anciennes coordonées joueur R  [%d][%d] \033[37m\n", recuperation_joueurR_posX, recuperation_joueurR_posY);
			}
	

			/*-- BLOQUER LES CASES ---*/

			if ( (posX < taille_grille) && (posY<taille_grille) ){
													
				if (! tab[posX][posY]){
					
					number ++;					

					/*---------------------------------------------------------------------------------*/
					/* QUATRIEME ACTION CROIX R*/
					/*---------------------------------------------------------------------------------*/
					if (number % 4 == 0){ 

						ChargerImage("images/croixR.png", posX * TAILLE_CASE + 1, posY * TAILLE_CASE +1, 0, 0, TAILLE_CASE, TAILLE_CASE);
      					printf("\033[35m  Clique CroixR en [%d][%d] \033[37m\n", posX, posY);
						tab[posX][posY]= 1;
						
						/*--- Gestion des erreurs ---*/

						/*--- Blocage centrale ---*/
						if ( (tab[recuperation_joueurB_posX +1][recuperation_joueurB_posY+1]==1) && (tab[recuperation_joueurB_posX+1][recuperation_joueurB_posY]==1) && (tab[recuperation_joueurB_posX+1][recuperation_joueurB_posY-1]==1) && (tab[recuperation_joueurB_posX][recuperation_joueurB_posY-1]==1) && (tab[recuperation_joueurB_posX][recuperation_joueurB_posY-1]==1) && (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY+1] ==1) && (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY]==1) && (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY-1] ==1) ){
							printf("\033[34m Le joueur B a perdu  \033[37m \n");
							/*envoie sur page de fin*/
							return 2;
						} else if ( (tab[recuperation_joueurR_posX +1][recuperation_joueurR_posY+1]==1) && (tab[recuperation_joueurR_posX+1][recuperation_joueurR_posY]==1) && (tab[recuperation_joueurR_posX+1][recuperation_joueurR_posY-1]==1) && (tab[recuperation_joueurR_posX][recuperation_joueurR_posY-1]==1) && (tab[recuperation_joueurR_posX][recuperation_joueurR_posY-1]==1) && (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY+1] ==1) && (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY]==1) && (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY-1] ==1) ){
							printf ("\033[35m Le joueur R a perdu \033[37m\n");
							/*envoie sur page de fin*/
							return 1;
						}

						/*--- Bloquage coté gauche ---*/
						if ( (tab[0][recuperation_joueurB_posY+1] == 1) && (tab[0][recuperation_joueurB_posY-1] == 1) && (tab[1][recuperation_joueurB_posY] == 1) && (tab[1][recuperation_joueurB_posY+1] == 1) && (tab[1][recuperation_joueurB_posY-1] == 1) ){
							printf("\033[34m Le joueur B a perdu  \033[37m \n");
							/*envoie sur page de fin*/
							return 2;
						} else if ( (tab[0][recuperation_joueurR_posY+1] == 1) && (tab[0][recuperation_joueurR_posY-1] == 1) && (tab[1][recuperation_joueurR_posY] == 1) && (tab[1][recuperation_joueurR_posY+1] == 1) && (tab[1][recuperation_joueurR_posY-1] == 1) ){
							
							printf("\033[35m Le joueur R a perdu  \033[37m \n");
							/*envoie sur page de fin*/
							return 1;
						}

						/*--- Bloquage coin haut gauche ---*/
						if ( (tab[recuperation_joueurB_posX+1][recuperation_joueurB_posY] == 1) && (tab[0][1]==1) && (tab[1][recuperation_joueurB_posY+1]) ) {
							printf("\033[34m Le joueur B a perdu  \033[37m \n");
							/*envoie sur page de fin*/
							return 2;
						} else if ( (tab[recuperation_joueurR_posX+1][recuperation_joueurR_posY] == 1) && (tab[0][1]==1) && (tab[1][recuperation_joueurR_posY+1]) ){
							printf("\033[35m Le joueur R a perdu  \033[37m \n");
							/*envoie sur page de fin*/
							return 1;
						}

						/*--- Bloquage haut ---*/
						if ( (tab[0][recuperation_joueurB_posY] == 1) && (tab[recuperation_joueurB_posX+1][0] == 1) && (tab[recuperation_joueurB_posX-1][1] == 1) && (tab[recuperation_joueurB_posX][1] == 1) && (tab[recuperation_joueurB_posX+1][1] == 1) ){
							printf("\033[34m Le joueur B a perdu, bloqué sur la bordure du haut  \033[37m \n");
							/*envoie sur page de fin*/
							return 2;
						} else if  ( (tab[recuperation_joueurR_posX-1][0] == 1) && (tab[recuperation_joueurR_posX+1][0] == 1) && (tab[recuperation_joueurR_posX-1][1] == 1) && (tab[recuperation_joueurR_posX][1] == 1) && (tab[recuperation_joueurR_posX+1][1] == 1) ){
							printf("\033[35m Le joueur R a perdu, bloqué sur la bordure du haut  \033[37m \n");
							/*envoie sur page de fin*/
							return 1;
						}
						
							/*--- Blocage en bas à gauche ---*/
						if ( (tab[1][taille_grille-1] ==1) && (tab[1][recuperation_joueurB_posY-1]==1) && (tab[recuperation_joueurB_posX][recuperation_joueurB_posY-1] == 1) ){
							printf("\033[34m Le joueur B a perdu en bas a gauche  \033[37m \n");
							/*envoie sur page de fin*/
							return 2;
						} else 	if ( (tab[1][taille_grille-1] ==1) && (tab[1][recuperation_joueurR_posY-1]==1) && (tab[recuperation_joueurR_posX][recuperation_joueurR_posY-1] == 1) ){
							printf("\033[35m Le joueur R a perdu  en bas a gauche\033[37m \n");
							/*envoie sur page de fin*/
							return 1;
						}

						/*--- Blocage en bas ---*/

						if ( (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY-1] == 1) && (tab[recuperation_joueurB_posX-1][taille_grille-1] ==1) && (tab[recuperation_joueurB_posX][recuperation_joueurB_posY-1]==1) && (tab[recuperation_joueurB_posX+1][recuperation_joueurB_posY-1]==1) && (tab[recuperation_joueurB_posX+1][taille_grille-1]==1) ){
							printf("\033[34m Le joueur B a perdu en bas  \033[37m \n");
							/*envoie sur page de fin*/
							return 2;
						}else if ( (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY-1] == 1) && (tab[recuperation_joueurR_posX-1][taille_grille-1] ==1) && (tab[recuperation_joueurR_posX][recuperation_joueurR_posY-1]==1) && (tab[recuperation_joueurR_posX+1][recuperation_joueurR_posY-1]==1) && (tab[recuperation_joueurR_posX+1][taille_grille-1]==1) ){
							printf("\033[35m Le joueur R a perdu  en bas \033[37m \n");
							/*envoie sur page de fin*/
							return 1;
						}

						/*--- Blocage en bas à droite ---*/
						if ( (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY-1] ==1) && (tab[recuperation_joueurB_posX-1][taille_grille-1]==1) && (tab[taille_grille-1][recuperation_joueurB_posY-1] == 1) ){
							printf("\033[34m Le joueur B a perdu en bas a droite  \033[37m \n");
							/*envoie sur page de fin*/
							return 2;
						} else if ( (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY-1] ==1) && (tab[recuperation_joueurR_posX-1][taille_grille-1]==1) && (tab[taille_grille-1][recuperation_joueurR_posY-1] == 1) ){
							printf("\033[35m Le joueur R a perdu  en bas a droite\033[37m \n");
							/*envoie sur page de fin*/
							return 1;
						}

						/*-- Blocage coté droit ---*/
						if ( (tab[taille_grille-1][recuperation_joueurB_posY+1] ==1) && (tab[recuperation_joueurB_posX -1][recuperation_joueurB_posY+1]==1) && (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY] ==1) && (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY-1]==1) && (tab[taille_grille-1][recuperation_joueurB_posY-1] ==1) ){
								printf("\033[34m Le joueur B a perdu en bas a droite  \033[37m \n");
							/*envoie sur page de fin*/
							return 2;
						}else if ( (tab[taille_grille-1][recuperation_joueurR_posY+1] ==1) && (tab[recuperation_joueurR_posX -1][recuperation_joueurR_posY+1]==1) && (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY] ==1) && (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY-1]==1) && (tab[taille_grille-1][recuperation_joueurR_posY-1] ==1) ){
							printf("\033[35m Le joueur R a perdu  en bas a droite\033[37m \n");
							/*envoie sur page de fin*/
							return 1;
						}
						
						/*--- Coin haut gauche ---*/
							if ( (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY+1] ==1) && (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY]==1) && (tab[taille_grille-1][recuperation_joueurB_posY+1] == 1) ){
							printf("\033[34m Le joueur B a perdu en bas a gauche  \033[37m \n");
							/*envoie sur page de fin*/
							return 2;
						} else if ( (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY+1] ==1) && (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY]==1) && (tab[taille_grille-1][recuperation_joueurR_posY+1] == 1) ){
							printf("\033[35m Le joueur R a perdu  en bas a gauche\033[37m \n");
							/*envoie sur page de fin*/
						}
									

					/*---------------------------------------------------------------------------------*/
					/*PREMIERE ACTION JOUEUR B*/	
					/*---------------------------------------------------------------------------------*/

					}else if (number % 4 == 1){ 

														
						if (tab [recuperation_joueurB_posX][recuperation_joueurB_posY] == 1){	
					
							/*--- Réintialisation de la case ---*/
							tab [recuperation_joueurB_posX][recuperation_joueurB_posY] = 0; 
							printf(" \033[34m Anciennes coordonnées joueur B [%d][%d] OK  \033[37m \n", recuperation_joueurB_posX, recuperation_joueurB_posY); /*vérification term*/
						
												
							ChoisirCouleurDessin (BLANC);
							RemplirRectangle(recuperation_joueurB_posX * TAILLE_CASE + 1, recuperation_joueurB_posY * TAILLE_CASE +1, TAILLE_CASE -1, TAILLE_CASE - 1);
							

							/*--- LIMITAION DE CASES ---*/
							
							if ( ((posX == recuperation_joueurB_posX -1) || (posX == recuperation_joueurB_posX ) || (recuperation_joueurB_posX+1 == posX) ) && ( (recuperation_joueurB_posY -1== posY) || ( recuperation_joueurB_posY +1 == posY) || (recuperation_joueurB_posY == posY) )  ){
							
								/*--- Affichage ---*/
								ChoisirCouleurDessin (BLANC);
								RemplirRectangle(posX * TAILLE_CASE + 1, posY * TAILLE_CASE +1, TAILLE_CASE -1, TAILLE_CASE - 1);
								ChargerImage("images/pionJoueurB.png", posX * TAILLE_CASE + 1, posY * TAILLE_CASE +1, 0, 0, TAILLE_CASE, TAILLE_CASE);
								printf("\033[34m Nouvelle position du joueurB [%d][%d] \033[37m \n", posX, posY);
								tab[posX][posY]= 1;

								/*--- Stockage des nouvelles données ---*/
								recuperation_joueurB_posX = posX;
								recuperation_joueurB_posY = posY;
								printf ("\033[34m Position stocké [%d][%d] \033[37m \n", recuperation_joueurB_posX, recuperation_joueurB_posY);
							}else {
								RemplirRectangle(posX * TAILLE_CASE + 1, posY * TAILLE_CASE +1, TAILLE_CASE -1, TAILLE_CASE - 1);
								ChargerImage("images/pionJoueurB.png", recuperation_joueurB_posX * TAILLE_CASE + 1, recuperation_joueurB_posY * TAILLE_CASE +1, 0, 0, TAILLE_CASE, TAILLE_CASE);
								printf("\033[31m ERREUR DE DÉPLACEMENT !!! \033[37m \n");
								
							}

						}else {
							printf ("\033[31m ERREUR RECUPERATION DONNEES JOUEUR BLEU !!! \033[37m \n");
							//fenetre de sortie
						}		


					/*---------------------------------------------------------------------------------*/
					/* DEUXIEME ACTION CROIX B*/
					/*---------------------------------------------------------------------------------*/
					}else if (number % 4 == 2){ 

						ChargerImage("images/croixB.png", posX * TAILLE_CASE + 1, posY * TAILLE_CASE +1, 0, 0, TAILLE_CASE, TAILLE_CASE);
      					printf("\033[34m Clique croixB en [%d][%d] \033[37m\n",posX, posY);
						tab[posX][posY]= 1;
						
							/*Gestion des erreurs*/

						/*--- Blocage central ---*/
						if ( (tab[recuperation_joueurB_posX +1][recuperation_joueurB_posY+1]==1) && (tab[recuperation_joueurB_posX+1][recuperation_joueurB_posY]==1) && (tab[recuperation_joueurB_posX+1][recuperation_joueurB_posY-1]==1) && (tab[recuperation_joueurB_posX][recuperation_joueurB_posY-1]==1) && (tab[recuperation_joueurB_posX][recuperation_joueurB_posY-1]==1) && (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY+1] ==1) && (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY]==1) && (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY-1] ==1)  ){
							printf("\033[34m Le joueur B a perdu  \033[37m \n");
							/*envoie sur page de fin*/
							return 2;
						} else if ( (tab[recuperation_joueurR_posX +1][recuperation_joueurR_posY+1]==1) && (tab[recuperation_joueurR_posX+1][recuperation_joueurR_posY]==1) && (tab[recuperation_joueurR_posX+1][recuperation_joueurR_posY-1]==1) && (tab[recuperation_joueurR_posX][recuperation_joueurR_posY-1]==1) && (tab[recuperation_joueurR_posX][recuperation_joueurR_posY-1]==1) && (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY+1] ==1) && (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY]==1) && (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY-1] ==1)  ){
							printf ("\033[35m Le joueur R a perdu \033[37m\n");
							/*envoie sur page de fin*/
							return 1;
						}
						
						/*--- Bloquage coté gauche ---*/
						if ( (tab[0][recuperation_joueurB_posY+1] == 1) && (tab[0][recuperation_joueurB_posY-1] == 1) && (tab[1][recuperation_joueurB_posY] == 1) && (tab[1][recuperation_joueurB_posY+1] == 1) && (tab[1][recuperation_joueurB_posY-1] == 1) ){
							printf("\033[34m Le joueur B a perdu  \033[37m \n");
							/*envoie sur page de fin*/
							return 2;
						} else if ( (tab[0][recuperation_joueurR_posY+1] == 1) && (tab[0][recuperation_joueurR_posY-1] == 1) && (tab[1][recuperation_joueurR_posY] == 1) && (tab[1][recuperation_joueurR_posY+1] == 1) && (tab[1][recuperation_joueurR_posY-1] == 1) ){
							printf("\033[35m Le joueur R a perdu  \033[37m \n");
							/*envoie sur page de fin*/
							return 1;
						}
						
						/*--- Bloquage coin haut gauche ---*/
						if ( (tab[recuperation_joueurB_posX+1][recuperation_joueurB_posY] == 1) && (tab[0][1]==1) && (tab[1][recuperation_joueurB_posY+1]) ) {
							printf("\033[34m Le joueur B a perdu  \033[37m \n");
							/*envoie sur page de fin*/
							return 2;
						} else if ( (tab[recuperation_joueurR_posX+1][recuperation_joueurR_posY] == 1) && (tab[0][1]==1) && (tab[1][recuperation_joueurR_posY+1]) ){
							printf("\033[35m Le joueur R a perdu  \033[37m \n");
							/*envoie sur page de fin*/
							return 1;
						}

							/*--- Bloquage haut ---*/
						if ( (tab[recuperation_joueurB_posX-1][0] == 1) && (tab[recuperation_joueurB_posX+1][0] == 1) && (tab[recuperation_joueurB_posX-1][1] == 1) && (tab[recuperation_joueurB_posX][1] == 1) && (tab[recuperation_joueurB_posX+1][1] == 1) ){
							printf("\033[34m Le joueur B a perdu, bloqué sur la bordure du haut  \033[37m \n");
							/*envoie sur page de fin*/
							return 2;
						} else if  ( (tab[recuperation_joueurR_posX-1][0] == 1) && (tab[recuperation_joueurR_posX+1][0] == 1) && (tab[recuperation_joueurR_posX-1][1] == 1) && (tab[recuperation_joueurR_posX][1] == 1) && (tab[recuperation_joueurR_posX+1][1] == 1) ){
							printf("\033[35m Le joueur R a perdu, bloqué sur la bordure du haut  \033[37m \n");
							/*envoie sur page de fin*/
							return 1;
						}

							
						/*--- Blocage en bas à gauche ---*/
						if ( (tab[1][taille_grille-1] ==1) && (tab[1][recuperation_joueurB_posY-1]==1) && (tab[recuperation_joueurB_posX][recuperation_joueurB_posY-1] == 1) ){
							printf("\033[34m Le joueur B a perdu en bas a gauche  \033[37m \n");
							/*envoie sur page de fin*/
							return 2;
						} else 	if ( (tab[1][taille_grille-1] ==1) && (tab[1][recuperation_joueurR_posY-1]==1) && (tab[recuperation_joueurR_posX][recuperation_joueurR_posY-1] == 1) ){
							printf("\033[35m Le joueur R a perdu  en bas a gauche\033[37m \n");
							/*envoie sur page de fin*/
							return 1;
						}
						

						/*--- Blocage en bas ---*/

						if ( (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY-1] == 1) && (tab[recuperation_joueurB_posX-1][taille_grille-1] ==1) && (tab[recuperation_joueurB_posX][recuperation_joueurB_posY-1]==1) && (tab[recuperation_joueurB_posX+1][recuperation_joueurB_posY-1]==1) && (tab[recuperation_joueurB_posX+1][taille_grille-1]==1) ){
							printf("\033[34m Le joueur B a perdu en bas   \033[37m \n");
							/*envoie sur page de fin*/
							return 2;
						}else if ( (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY-1] == 1) && (tab[recuperation_joueurR_posX-1][taille_grille-1] ==1) && (tab[recuperation_joueurR_posX][recuperation_joueurR_posY-1]==1) && (tab[recuperation_joueurR_posX+1][recuperation_joueurR_posY-1]==1) && (tab[recuperation_joueurR_posX+1][taille_grille-1]==1) ){
							printf("\033[35m Le joueur R a perdu  en bas \033[37m \n");
							/*envoie sur page de fin*/
							return 1;
						}

							/*--- Blocage en bas à droite ---*/
						if ( (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY-1] ==1) && (tab[recuperation_joueurB_posX-1][taille_grille-1]==1) && (tab[taille_grille-1][recuperation_joueurB_posY-1] == 1) ){
							printf("\033[34m Le joueur B a perdu en bas a droite  \033[37m \n");
							/*envoie sur page de fin*/
							return 2;
						} else if ( (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY-1] ==1) && (tab[recuperation_joueurR_posX-1][taille_grille-1]==1) && (tab[taille_grille-1][recuperation_joueurR_posY-1] == 1) ){
							printf("\033[35m Le joueur R a perdu  en bas a droite\033[37m \n");
							/*envoie sur page de fin*/
							return 1;
						}

						/*-- Blocage coté droit ---*/
						if ( (tab[taille_grille-1][recuperation_joueurB_posY+1] ==1) && (tab[recuperation_joueurB_posX -1][recuperation_joueurB_posY+1]==1) && (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY] ==1) && (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY-1]==1) && (tab[taille_grille-1][recuperation_joueurB_posY-1] ==1) ){
								printf("\033[34m Le joueur B a perdu en bas a droite  \033[37m \n");
							/*envoie sur page de fin*/
								return 2;
						}else if ( (tab[taille_grille-1][recuperation_joueurR_posY+1] ==1) && (tab[recuperation_joueurR_posX -1][recuperation_joueurR_posY+1]==1) && (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY] ==1) && (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY-1]==1) && (tab[taille_grille-1][recuperation_joueurR_posY-1] ==1) ){
							printf("\033[35m Le joueur R a perdu  en bas a droite\033[37m \n");
							/*envoie sur page de fin*/
							return 1;
						}

						/*--- Coin haut gauche ---*/
							if ( (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY+1] ==1) && (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY]==1) && (tab[taille_grille-1][recuperation_joueurB_posY+1] == 1) ){
							printf("\033[34m Le joueur B a perdu en bas a gauche  \033[37m \n");
							/*envoie sur page de fin*/
							return 2;
						} else if ( (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY+1] ==1) && (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY]==1) && (tab[taille_grille-1][recuperation_joueurR_posY+1] == 1) ){
							printf("\033[35m Le joueur R a perdu  en bas a gauche\033[37m \n");
							/*envoie sur page de fin*/
							return 1;
						}			

					/*---------------------------------------------------------------------------------*/
					/* TROISIEME ACTION JOUEUR R */
					/*---------------------------------------------------------------------------------*/
					}else if (number % 4 == 3){ 
											 

						if (tab [recuperation_joueurR_posX][recuperation_joueurR_posY] == 1 ){

							/*--- Réintialisation de la case ---*/
							tab [recuperation_joueurR_posX][recuperation_joueurR_posY] = 0; 
							printf("\033[35m Anciennes coordonnées R [%d][%d] \033[37m\n", recuperation_joueurR_posX, recuperation_joueurR_posY); /*vérification term*/
							ChoisirCouleurDessin (BLANC);
							RemplirRectangle(recuperation_joueurR_posX * TAILLE_CASE + 1, recuperation_joueurR_posY * TAILLE_CASE +1, TAILLE_CASE -1, TAILLE_CASE - 1);
							
							/*--- LIMITAION DE CASES ---*/
							if ( ( (recuperation_joueurR_posX == posX -1) || (recuperation_joueurR_posX == posX+1) || (recuperation_joueurR_posX == posX) ) && ( (recuperation_joueurR_posY== posY-1) || ( recuperation_joueurR_posY== posY+1) || (recuperation_joueurR_posY == posY) ) ){
								/* Affichage*/
								ChoisirCouleurDessin (BLANC);
								RemplirRectangle(posX * TAILLE_CASE + 1, posY * TAILLE_CASE +1, TAILLE_CASE -1, TAILLE_CASE - 1);
								ChargerImage("images/pionJoueurR.png", posX * TAILLE_CASE + 1, posY * TAILLE_CASE +1, 0, 0, TAILLE_CASE, TAILLE_CASE);
								printf("\033[35m   Clique JoueurR [%d][%d]\033[37m \n ", posX, posY);
								tab[posX][posY]= 1;

								/*--- Stockage des nouvelles données ---*/
								recuperation_joueurR_posX = posX;
								recuperation_joueurR_posY = posY;
								printf("\033[35m   Position stockée [%d][%d]\033[37m \n", recuperation_joueurR_posX, recuperation_joueurR_posY);
							
							}else {
								RemplirRectangle(posX * TAILLE_CASE + 1, posY * TAILLE_CASE +1, TAILLE_CASE -1, TAILLE_CASE - 1);
								ChargerImage("images/pionJoueurR.png", recuperation_joueurR_posX * TAILLE_CASE + 1, recuperation_joueurR_posY * TAILLE_CASE +1, 0, 0, TAILLE_CASE, TAILLE_CASE);
								printf("\033[31m ERREUR DE DÉPLACEMENT !!! \033[37m \n");

							}

						
						}else {
							printf ("Erreur de stockage des données du joueur R\n");
						}
						
					}
					
				} else {
					printf (" \033[31m CASE PAS DISPONIBLE !!! \033[37m \n");
				}	

			}else {
				printf (" \033[31m HORS DE LA GRILLE !!! \033[37m \n");
			}		
		} 


	}

}


/*--- BLOQUER LE JEU INDIVIDUEL ---*/

int Bloquer_Solo (){

	int number =0;
	srand( time( NULL ) );
	int  posX, posY, placement_pionR =0, placement_pionB = 0;
	int recuperation_joueurR_posX, recuperation_joueurR_posY, recuperation_joueurB_posX, recuperation_joueurB_posY;
	int tab [TAILLE_CASE*taille_grille][TAILLE_CASE*taille_grille];
	int alx, aly, verification_aleatoire = 1;


	printf("LANCEMENT DU JEU MODE 1 JOUEUR \n");

	while (1){

		ChoisirCouleurDessin(NOIR);
		DessinerGrille();	
		

		/*--- INITIALISATION DES PIONS ---*/
		

		/*--- Joueur Bleu ---*/
		if (placement_pionB < 1){

			if( SourisCliquee()){		
			SourisPosition();	
			/*--- Récupération de la partie entière ---*/
			posX = (int) _X / TAILLE_CASE;
			posY = (int) _Y / TAILLE_CASE;	
		
			printf ("Position cliquée [%d] [%d]\n", posX, posY);

				if ( (posX < taille_grille) && (posY<taille_grille) ){
					if (! tab[posX][posY]){
						ChargerImage("images/pionJoueurB.png", posX * TAILLE_CASE + 1, posY * TAILLE_CASE +1, 0, 0, TAILLE_CASE, TAILLE_CASE);
						tab[posX][posY]= 1;
						recuperation_joueurB_posX = posX;
						recuperation_joueurB_posY = posY;
					}
				}
				placement_pionB ++;
				printf ("\033[34m Anciennes coordonnées joueur B [%d][%d] OK  \033[37m \n", recuperation_joueurB_posX, recuperation_joueurB_posY);
			}
			
		}

		/*--- Joueur Rouge ---*/

		if (placement_pionR < 1){

			while (verification_aleatoire == 1){
				
				posX = rand()% taille_grille - 0;
				posY = rand()% taille_grille - 0;		
				
				if ( (posX < taille_grille) && (posY<taille_grille) ){

					if (! tab[posX][posY]) {
						tab[posX][posY]=1;	
						ChargerImage("images/pionJoueurR.png", posX * TAILLE_CASE + 1, posY * TAILLE_CASE +1, 0, 0, TAILLE_CASE, TAILLE_CASE);
						recuperation_joueurR_posX = posX;
						recuperation_joueurR_posY= posY;
						verification_aleatoire = 0;
					}

				}
				placement_pionR++;
				printf ("\033[31m Coordonnées Joueur Rouge [%d][%d] \033[37m \n", recuperation_joueurR_posX, recuperation_joueurR_posY);
			}

			verification_aleatoire = 1;
			number++; /*permer de lancer le tour*/

		}

		
		/*---------------------------------------------------------------------------------*/
		/* PREMIERE ACTION PION JOUEUR B (UTILISATEUR) */
		/*---------------------------------------------------------------------------------*/
		if (number%4 == 1){

			if (SourisCliquee ()){
				SourisPosition();
				posX = (int) _X / TAILLE_CASE;
				posY = (int) _Y / TAILLE_CASE;	
				number ++;
			
				if (tab [recuperation_joueurB_posX][recuperation_joueurB_posY] == 1){	
					
					/*--- Réintialisation de la case ---*/
					tab [recuperation_joueurB_posX][recuperation_joueurB_posY] = 0; 
					printf(" \033[34m Anciennes coordonnées joueur B [%d][%d] OK  \033[37m \n", recuperation_joueurB_posX, recuperation_joueurB_posY); /*vérification term*/											
					ChoisirCouleurDessin (BLANC);
					RemplirRectangle(recuperation_joueurB_posX * TAILLE_CASE + 1, recuperation_joueurB_posY * TAILLE_CASE +1, TAILLE_CASE -1, TAILLE_CASE - 1);
						

					/*--- LIMITAION DE CASES ---*/
							
					if ( ((posX == recuperation_joueurB_posX -1) || (posX == recuperation_joueurB_posX ) || (recuperation_joueurB_posX+1 == posX) ) && ( (recuperation_joueurB_posY -1== posY) || ( recuperation_joueurB_posY +1 == posY) || (recuperation_joueurB_posY == posY) )  ){
							
						/*--- Affichage ---*/
						ChoisirCouleurDessin (BLANC);
						RemplirRectangle(posX * TAILLE_CASE + 1, posY * TAILLE_CASE +1, TAILLE_CASE -1, TAILLE_CASE - 1);
						ChargerImage("images/pionJoueurB.png", posX * TAILLE_CASE + 1, posY * TAILLE_CASE +1, 0, 0, TAILLE_CASE, TAILLE_CASE);
						printf("\033[34m Nouvelle position du joueurB [%d][%d] \033[37m \n", posX, posY);
						tab[posX][posY]= 1;

						/*--- Stockage des nouvelles données ---*/
						recuperation_joueurB_posX = posX;
						recuperation_joueurB_posY = posY;
						printf ("\033[34m Position stocké [%d][%d] \033[37m \n", recuperation_joueurB_posX, recuperation_joueurB_posY);
					}else {
						RemplirRectangle(posX * TAILLE_CASE + 1, posY * TAILLE_CASE +1, TAILLE_CASE -1, TAILLE_CASE - 1);
						ChargerImage("images/pionJoueurB.png", recuperation_joueurB_posX * TAILLE_CASE + 1, recuperation_joueurB_posY * TAILLE_CASE +1, 0, 0, TAILLE_CASE, TAILLE_CASE);
						printf("\033[31m ERREUR : DÉPLACEMENT !!! \033[37m \n");
					
					}

				}else {
					printf ("\033[31m ERREUR : RECUPERATION DONNEES JOUEUR BLEU !!! \033[37m \n");
					//fenetre de sortie
				}
			}	
					
		}	
					

		/*---------------------------------------------------------------------------------*/
		/* DEUXIEME ACTION CROIX B */
		/*---------------------------------------------------------------------------------*/ 
		else if (number %4 == 2){
			
			if (SourisCliquee ()){
			
				SourisPosition();
				number++;

				posX = (int) _X / TAILLE_CASE;
				posY = (int) _Y / TAILLE_CASE;	

				if ( (posX < taille_grille) && (posY<taille_grille) ){
					if (! tab[posX][posY] ) {
						ChargerImage("images/croixB.png", posX * TAILLE_CASE + 1, posY * TAILLE_CASE +1, 0, 0, TAILLE_CASE, TAILLE_CASE);
						printf("\033[34m Clique croixB en [%d][%d] \033[37m\n",posX, posY);
						tab[posX][posY]= 1;
					}
				}
			}


						/*--- Gestion des erreurs ---*/

						/*--- Blocage centrale ---*/
						if ( (tab[recuperation_joueurB_posX +1][recuperation_joueurB_posY+1]==1) && (tab[recuperation_joueurB_posX+1][recuperation_joueurB_posY]==1) && (tab[recuperation_joueurB_posX+1][recuperation_joueurB_posY-1]==1) && (tab[recuperation_joueurB_posX][recuperation_joueurB_posY-1]==1) && (tab[recuperation_joueurB_posX][recuperation_joueurB_posY-1]==1) && (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY+1] ==1) && (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY]==1) && (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY-1] ==1) ){
							printf("\033[34m Le joueur B a perdu  \033[37m \n");
							/*envoie sur page de fin*/
							return 2;
						} else if ( (tab[recuperation_joueurR_posX +1][recuperation_joueurR_posY+1]==1) && (tab[recuperation_joueurR_posX+1][recuperation_joueurR_posY]==1) && (tab[recuperation_joueurR_posX+1][recuperation_joueurR_posY-1]==1) && (tab[recuperation_joueurR_posX][recuperation_joueurR_posY-1]==1) && (tab[recuperation_joueurR_posX][recuperation_joueurR_posY-1]==1) && (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY+1] ==1) && (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY]==1) && (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY-1] ==1) ){
							printf ("\033[35m Le joueur R a perdu \033[37m\n");
							/*envoie sur page de fin*/
							return 1;
						}

						/*--- Bloquage coté gauche ---*/
						if ( (tab[0][recuperation_joueurB_posY+1] == 1) && (tab[0][recuperation_joueurB_posY-1] == 1) && (tab[1][recuperation_joueurB_posY] == 1) && (tab[1][recuperation_joueurB_posY+1] == 1) && (tab[1][recuperation_joueurB_posY-1] == 1) ){
							printf("\033[34m Le joueur B a perdu  \033[37m \n");
							/*envoie sur page de fin*/
							return 2;
						} else if ( (tab[0][recuperation_joueurR_posY+1] == 1) && (tab[0][recuperation_joueurR_posY-1] == 1) && (tab[1][recuperation_joueurR_posY] == 1) && (tab[1][recuperation_joueurR_posY+1] == 1) && (tab[1][recuperation_joueurR_posY-1] == 1) ){
							
							printf("\033[35m Le joueur R a perdu  \033[37m \n");
							/*envoie sur page de fin*/
							return 1;
						}

						/*--- Bloquage coin haut gauche ---*/
						if ( (tab[recuperation_joueurB_posX+1][recuperation_joueurB_posY] == 1) && (tab[0][1]==1) && (tab[1][recuperation_joueurB_posY+1]) ) {
							printf("\033[34m Le joueur B a perdu  \033[37m \n");
							/*envoie sur page de fin*/
							return 2;
						} else if ( (tab[recuperation_joueurR_posX+1][recuperation_joueurR_posY] == 1) && (tab[0][1]==1) && (tab[1][recuperation_joueurR_posY+1]) ){
							printf("\033[35m Le joueur R a perdu  \033[37m \n");
							/*envoie sur page de fin*/
							return 1;
						}

						/*--- Bloquage haut ---*/
						if ( (tab[recuperation_joueurB_posX-1][0] == 1) && (tab[recuperation_joueurB_posX+1][0] == 1) && (tab[recuperation_joueurB_posX-1][1] == 1) && (tab[recuperation_joueurB_posX][1] == 1) && (tab[recuperation_joueurB_posX+1][1] == 1) ){
							printf("\033[34m Le joueur B a perdu  \033[37m \n");
							/*envoie sur page de fin*/
							return 2;
						} else if  ( (tab[recuperation_joueurR_posX-1][0] == 1) && (tab[recuperation_joueurR_posX+1][0] == 1) && (tab[recuperation_joueurR_posX-1][1] == 1) && (tab[recuperation_joueurR_posX][1] == 1) && (tab[recuperation_joueurR_posX+1][1] == 1) ){
							printf("\033[35m Le joueur R a perdu  \033[37m \n");
							/*envoie sur page de fin*/
							return 1;
						}
						
							/*--- Blocage en bas à gauche ---*/
						if ( (tab[1][taille_grille-1] ==1) && (tab[1][recuperation_joueurB_posY-1]==1) && (tab[recuperation_joueurB_posX][recuperation_joueurB_posY-1] == 1) ){
							printf("\033[34m Le joueur B a perdu en bas a gauche  \033[37m \n");
							/*envoie sur page de fin*/
							return 2;
						} else 	if ( (tab[1][taille_grille-1] ==1) && (tab[1][recuperation_joueurR_posY-1]==1) && (tab[recuperation_joueurR_posX][recuperation_joueurR_posY-1] == 1) ){
							printf("\033[35m Le joueur R a perdu  en bas a gauche\033[37m \n");
							/*envoie sur page de fin*/
							return 1;
						}

						/*--- Blocage en bas ---*/

						if ( (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY-1] == 1) && (tab[recuperation_joueurB_posX-1][taille_grille-1] ==1) && (tab[recuperation_joueurB_posX][recuperation_joueurB_posY-1]==1) && (tab[recuperation_joueurB_posX+1][recuperation_joueurB_posY-1]==1) && (tab[recuperation_joueurB_posX+1][taille_grille-1]==1) ){
							printf("\033[34m Le joueur B a perdu en bas  \033[37m \n");
							/*envoie sur page de fin*/
							return 2;
						}else if ( (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY-1] == 1) && (tab[recuperation_joueurR_posX-1][taille_grille-1] ==1) && (tab[recuperation_joueurR_posX][recuperation_joueurR_posY-1]==1) && (tab[recuperation_joueurR_posX+1][recuperation_joueurR_posY-1]==1) && (tab[recuperation_joueurR_posX+1][taille_grille-1]==1) ){
							printf("\033[35m Le joueur R a perdu  en bas \033[37m \n");
							/*envoie sur page de fin*/
							return 1;
						}

						/*--- Blocage en bas à droite ---*/
						if ( (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY-1] ==1) && (tab[recuperation_joueurB_posX-1][taille_grille-1]==1) && (tab[taille_grille-1][recuperation_joueurB_posY-1] == 1) ){
							printf("\033[34m Le joueur B a perdu en bas a droite  \033[37m \n");
							/*envoie sur page de fin*/
							return 2;
						} else if ( (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY-1] ==1) && (tab[recuperation_joueurR_posX-1][taille_grille-1]==1) && (tab[taille_grille-1][recuperation_joueurR_posY-1] == 1) ){
							printf("\033[35m Le joueur R a perdu  en bas a droite\033[37m \n");
							/*envoie sur page de fin*/
							return 1;
						}

						/*-- Blocage coté droit ---*/
						if ( (tab[taille_grille-1][recuperation_joueurB_posY+1] ==1) && (tab[recuperation_joueurB_posX -1][recuperation_joueurB_posY+1]==1) && (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY] ==1) && (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY-1]==1) && (tab[taille_grille-1][recuperation_joueurB_posY-1] ==1) ){
								printf("\033[34m Le joueur B a perdu en bas a droite  \033[37m \n");
							/*envoie sur page de fin*/
							return 2;
						}else if ( (tab[taille_grille-1][recuperation_joueurR_posY+1] ==1) && (tab[recuperation_joueurR_posX -1][recuperation_joueurR_posY+1]==1) && (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY] ==1) && (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY-1]==1) && (tab[taille_grille-1][recuperation_joueurR_posY-1] ==1) ){
							printf("\033[35m Le joueur R a perdu  en bas a droite\033[37m \n");
							/*envoie sur page de fin*/
							return 1;
						}
						
						/*--- Coin haut gauche ---*/
							if ( (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY+1] ==1) && (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY]==1) && (tab[taille_grille-1][recuperation_joueurB_posY+1] == 1) ){
							printf("\033[34m Le joueur B a perdu en bas a gauche  \033[37m \n");
							/*envoie sur page de fin*/
							return 2;
						} else if ( (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY+1] ==1) && (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY]==1) && (tab[taille_grille-1][recuperation_joueurR_posY+1] == 1) ){
							printf("\033[35m Le joueur R a perdu  en bas a gauche\033[37m \n");
							/*envoie sur page de fin*/
						}
		
		}


		/*---------------------------------------------------------------------------------*/
		/* TROISIEME ACTION JOUEUR R (BOT) */
		/*---------------------------------------------------------------------------------*/
		else if (number%4 == 3 ){
			
			number++;
			
			if (tab [recuperation_joueurR_posX][recuperation_joueurR_posY] == 1 ){
					
				/*--- Réintialisation de la case ---*/
				tab [recuperation_joueurR_posX][recuperation_joueurR_posY] = 0; 
				printf("\033[35m Anciennes coordonnées R [%d][%d] \033[37m\n", recuperation_joueurR_posX, recuperation_joueurR_posY); /*vérification term*/
				ChoisirCouleurDessin (BLANC);
				RemplirRectangle(recuperation_joueurR_posX * TAILLE_CASE + 1, recuperation_joueurR_posY * TAILLE_CASE +1, TAILLE_CASE -1, TAILLE_CASE - 1);
				
				while (verification_aleatoire == 1){
								
					alx = rand ()%3+1;
					aly = rand ()%3+1;

					/*--- Aleatoire de posX ---*/
					if (alx == 1){
						posX = recuperation_joueurR_posX;
					}else if (alx == 2){
						posX = recuperation_joueurR_posX +1;
					} else if (alx == 3){
						posX = recuperation_joueurR_posX-1;
					}

					/*--- Aleatoire de posY ---*/
					if (aly == 1){
						posY = recuperation_joueurR_posY;						
					}else if (aly == 2){
						posY = recuperation_joueurR_posY +1;
					} else if (aly == 3){
						posY = recuperation_joueurR_posY - 1;
					}

					if ( (posX < taille_grille) && (posY<taille_grille) ){
						if (! tab[posX][posY] ){
							
							tab [posX][posY]=1;
							ChoisirCouleurDessin (BLANC);
							RemplirRectangle(posX * TAILLE_CASE + 1, posY * TAILLE_CASE +1, TAILLE_CASE -1, TAILLE_CASE - 1);
							ChargerImage("images/pionJoueurR.png", posX * TAILLE_CASE + 1, posY * TAILLE_CASE +1, 0, 0, TAILLE_CASE, TAILLE_CASE);
							
							/*--- Stockage des coordonees ---*/
							recuperation_joueurR_posX= posX;
							recuperation_joueurR_posY = posY;

							
							verification_aleatoire = 0;

						}else {
							printf ("\033[35m ERREUR : CASE NON DISPONIBLE !!!  \033[37m\n");
						}
					} else {
						printf ("\033[35m ERREUR : HORS DE LA GRILLE !!!\033[37m\n");
					}
				}
			

			}else {
				printf("\033[35m ERREUR :  SAUVEGARDE DES COORDONNEES !!! \033[37m\n");
			}	

			verification_aleatoire = 1;
		
		}
			
		/*---------------------------------------------------------------------------------*/
		/* QUATRIEME ACTION CROIX R (BOT) */
		/*---------------------------------------------------------------------------------*/

		else if (number % 4 == 0 ){		
			number++;
		
			while (verification_aleatoire == 1){
			
				posX = rand ()% (taille_grille-1)-0;
				posX = rand ()% (taille_grille-1)-0;

				if ( (posX < taille_grille) && (posY<taille_grille) ){
					if (! tab[posX][posY] ){
						tab[posX][posY]= 1;
						ChargerImage("images/croixR.png", posX * TAILLE_CASE + 1, posY * TAILLE_CASE +1, 0, 0, TAILLE_CASE, TAILLE_CASE);
						printf("\033[35m  CroixR en [%d][%d] \033[37m\n", posX, posY);
						verification_aleatoire = 0;
					}
				}
			}


						/*--- Gestion des erreurs ---*/

						/*--- Blocage centrale ---*/
						if ( (tab[recuperation_joueurB_posX +1][recuperation_joueurB_posY+1]==1) && (tab[recuperation_joueurB_posX+1][recuperation_joueurB_posY]==1) && (tab[recuperation_joueurB_posX+1][recuperation_joueurB_posY-1]==1) && (tab[recuperation_joueurB_posX][recuperation_joueurB_posY-1]==1) && (tab[recuperation_joueurB_posX][recuperation_joueurB_posY-1]==1) && (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY+1] ==1) && (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY]==1) && (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY-1] ==1) ){
							printf("\033[34m Le joueur B a perdu  \033[37m \n");
							/*envoie sur page de fin*/
							return 2;
						} else if ( (tab[recuperation_joueurR_posX +1][recuperation_joueurR_posY+1]==1) && (tab[recuperation_joueurR_posX+1][recuperation_joueurR_posY]==1) && (tab[recuperation_joueurR_posX+1][recuperation_joueurR_posY-1]==1) && (tab[recuperation_joueurR_posX][recuperation_joueurR_posY-1]==1) && (tab[recuperation_joueurR_posX][recuperation_joueurR_posY-1]==1) && (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY+1] ==1) && (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY]==1) && (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY-1] ==1) ){
							printf ("\033[35m Le joueur R a perdu \033[37m\n");
							/*envoie sur page de fin*/
							return 1;
						}

						/*--- Bloquage coté gauche ---*/
						if ( (tab[0][recuperation_joueurB_posY+1] == 1) && (tab[0][recuperation_joueurB_posY-1] == 1) && (tab[1][recuperation_joueurB_posY] == 1) && (tab[1][recuperation_joueurB_posY+1] == 1) && (tab[1][recuperation_joueurB_posY-1] == 1) ){
							printf("\033[34m Le joueur B a perdu  \033[37m \n");
							/*envoie sur page de fin*/
							return 2;
						} else if ( (tab[0][recuperation_joueurR_posY+1] == 1) && (tab[0][recuperation_joueurR_posY-1] == 1) && (tab[1][recuperation_joueurR_posY] == 1) && (tab[1][recuperation_joueurR_posY+1] == 1) && (tab[1][recuperation_joueurR_posY-1] == 1) ){
							
							printf("\033[35m Le joueur R a perdu  \033[37m \n");
							/*envoie sur page de fin*/
							return 1;
						}

						/*--- Bloquage coin haut gauche ---*/
						if ( (tab[recuperation_joueurB_posX+1][recuperation_joueurB_posY] == 1) && (tab[0][1]==1) && (tab[1][recuperation_joueurB_posY+1]) ) {
							printf("\033[34m Le joueur B a perdu  \033[37m \n");
							/*envoie sur page de fin*/
							return 2;
						} else if ( (tab[recuperation_joueurR_posX+1][recuperation_joueurR_posY] == 1) && (tab[0][1]==1) && (tab[1][recuperation_joueurR_posY+1]) ){
							printf("\033[35m Le joueur R a perdu  \033[37m \n");
							/*envoie sur page de fin*/
							return 1;
						}

						/*--- Bloquage haut ---*/
						if ( (tab[recuperation_joueurB_posX-1][0] == 1) && (tab[recuperation_joueurB_posX+1][0] == 1) && (tab[recuperation_joueurB_posX-1][1] == 1) && (tab[recuperation_joueurB_posX][1] == 1) && (tab[recuperation_joueurB_posX+1][1] == 1) ){
							printf("\033[34m Le joueur B a perdu  \033[37m \n");
							/*envoie sur page de fin*/
							return 2;
						} else if  ( (tab[recuperation_joueurR_posX-1][0] == 1) && (tab[recuperation_joueurR_posX+1][0] == 1) && (tab[recuperation_joueurR_posX-1][1] == 1) && (tab[recuperation_joueurR_posX][1] == 1) && (tab[recuperation_joueurR_posX+1][1] == 1) ){
							printf("\033[35m Le joueur R a perdu  \033[37m \n");
							/*envoie sur page de fin*/
							return 1;
						}
						
							/*--- Blocage en bas à gauche ---*/
						if ( (tab[1][taille_grille-1] ==1) && (tab[1][recuperation_joueurB_posY-1]==1) && (tab[recuperation_joueurB_posX][recuperation_joueurB_posY-1] == 1) ){
							printf("\033[34m Le joueur B a perdu en bas a gauche  \033[37m \n");
							/*envoie sur page de fin*/
							return 2;
						} else 	if ( (tab[1][taille_grille-1] ==1) && (tab[1][recuperation_joueurR_posY-1]==1) && (tab[recuperation_joueurR_posX][recuperation_joueurR_posY-1] == 1) ){
							printf("\033[35m Le joueur R a perdu  en bas a gauche\033[37m \n");
							/*envoie sur page de fin*/
							return 1;
						}

						/*--- Blocage en bas ---*/

						if ( (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY-1] == 1) && (tab[recuperation_joueurB_posX-1][taille_grille-1] ==1) && (tab[recuperation_joueurB_posX][recuperation_joueurB_posY-1]==1) && (tab[recuperation_joueurB_posX+1][recuperation_joueurB_posY-1]==1) && (tab[recuperation_joueurB_posX+1][taille_grille-1]==1) ){
							printf("\033[34m Le joueur B a perdu en bas  \033[37m \n");
							/*envoie sur page de fin*/
							return 2;
						}else if ( (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY-1] == 1) && (tab[recuperation_joueurR_posX-1][taille_grille-1] ==1) && (tab[recuperation_joueurR_posX][recuperation_joueurR_posY-1]==1) && (tab[recuperation_joueurR_posX+1][recuperation_joueurR_posY-1]==1) && (tab[recuperation_joueurR_posX+1][taille_grille-1]==1) ){
							printf("\033[35m Le joueur R a perdu  en bas \033[37m \n");
							/*envoie sur page de fin*/
							return 1;
						}

						/*--- Blocage en bas à droite ---*/
						if ( (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY-1] ==1) && (tab[recuperation_joueurB_posX-1][taille_grille-1]==1) && (tab[taille_grille-1][recuperation_joueurB_posY-1] == 1) ){
							printf("\033[34m Le joueur B a perdu en bas a droite  \033[37m \n");
							/*envoie sur page de fin*/
							return 2;
						} else if ( (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY-1] ==1) && (tab[recuperation_joueurR_posX-1][taille_grille-1]==1) && (tab[taille_grille-1][recuperation_joueurR_posY-1] == 1) ){
							printf("\033[35m Le joueur R a perdu  en bas a droite\033[37m \n");
							/*envoie sur page de fin*/
							return 1;
						}

						/*-- Blocage coté droit ---*/
						if ( (tab[taille_grille-1][recuperation_joueurB_posY+1] ==1) && (tab[recuperation_joueurB_posX -1][recuperation_joueurB_posY+1]==1) && (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY] ==1) && (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY-1]==1) && (tab[taille_grille-1][recuperation_joueurB_posY-1] ==1) ){
								printf("\033[34m Le joueur B a perdu en bas a droite  \033[37m \n");
							/*envoie sur page de fin*/
							return 2;
						}else if ( (tab[taille_grille-1][recuperation_joueurR_posY+1] ==1) && (tab[recuperation_joueurR_posX -1][recuperation_joueurR_posY+1]==1) && (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY] ==1) && (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY-1]==1) && (tab[taille_grille-1][recuperation_joueurR_posY-1] ==1) ){
							printf("\033[35m Le joueur R a perdu  en bas a droite\033[37m \n");
							/*envoie sur page de fin*/
							return 1;
						}
						
						/*--- Coin haut gauche ---*/
							if ( (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY+1] ==1) && (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY]==1) && (tab[taille_grille-1][recuperation_joueurB_posY+1] == 1) ){
							printf("\033[34m Le joueur B a perdu en bas a gauche  \033[37m \n");
							/*envoie sur page de fin*/
							return 2;
						} else if ( (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY+1] ==1) && (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY]==1) && (tab[taille_grille-1][recuperation_joueurR_posY+1] == 1) ){
							printf("\033[35m Le joueur R a perdu  en bas a gauche\033[37m \n");
							/*envoie sur page de fin*/
						}

			verification_aleatoire = 1;
					
		}

	}

}

void menu_fin(int valGagnant, int modeJeu)
{
	EffacerEcran(BLANC);

	printf("valGagnant : %d\n", valGagnant);
	printf("modeJeu : %d\n", modeJeu);

	if (valGagnant == 1 && modeJeu == 1)
	{
		printf("Le joueur 1 (Bleu) à vaincu l'IA !\n");
		EcrireTexte(0, 22, "Le joueur 1 (Bleu) à vaincu l'IA !", 2);
	}
	else if (valGagnant == 2 && modeJeu == 1)
	{
		printf("L'IA à vaincu le joueur 1 (Bleu) !\n");
		EcrireTexte(0, 22, "L'IA à vaincu le joueur 1 (Bleu) !", 2);
	}
	else if (valGagnant == 1 && modeJeu == 2)
	{
		printf("Le joueur 1 (Bleu) à vaincu le joueur 2 (Magenta) !\n");
		EcrireTexte(0, 22, "Le joueur 1 (Bleu) à vaincu le joueur 2 (Magenta) !", 2);
	}
	else if (valGagnant == 2 && modeJeu == 2)
	{
		printf("Le joueur 2 (Magenta) à vaincu le joueur 1 (Bleu) !\n");
		EcrireTexte(0, 22, "Le joueur 2 (Magenta) à vaincu le joueur 1 (Bleu) !", 2);
	}
	else
	{
		printf("\033[31m/!\\ Erreur lors du test du gagnant (fonction menu_fin)\033[37m\n");
	}
}


/*--- JEU ---*/

void jeu(){
		
	/*DECLARATION DES VARIABLES*/

	int i = 0, j = 0, posX, posY;
	int tab [TAILLE_CASE*taille_grille][TAILLE_CASE*taille_grille];

	int gagnant = 0;

	/*-----------------------------------------*/

	printf("Nombre de joueur :  %d\n", nb_joueur);						/* Affichage après d'avoir fermé l'écran */
	printf("Taille de la grille : %d\n", taille_grille);
	printf("Initialisation des grilles : \n");
	EffacerEcran(BLANC);

	/*-----------------------------------------*/

	DessinerGrille();

	for (i = 0; i < taille_grille; i ++){
		for (j = 0; j < taille_grille; j ++){
			tab [i][j]=0;
			printf (" [%d][%d] = %d\n", i , j, tab [i][j] );
		}
	}

	if (nb_joueur == 1){
		gagnant = Bloquer_Solo();
		
	}
	

	if (nb_joueur == 2){
		gagnant = Bloquer_Vs();
		menu_fin(gagnant, nb_joueur);	
		
			for (i = 0; i < taille_grille; i ++){
				for (j = 0; j < taille_grille; j ++){
					tab [i][j]=0;
					printf (" [%d][%d] = %d\n", i , j, tab [i][j] );
				}
			}		
	}

}




int main(int argc, char * const argv []){
	
	InitialiserGraphique();

	if(InitialiserGraphique() == 1){
		menu();
		jeu();	

		Touche();
		FermerGraphique();
	}else{
		printf("Erreur lors de l'initialisation du graphique.\n");
		return EXIT_FAILURE;
	}


	return EXIT_SUCCESS;
}