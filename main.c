/*--- BIBLIOTHQUES DU PROGRAMME ---*/

#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include <time.h>

/*--- CREDITS ---*/

#define TITRE_JEU "Blocus"
#define AUTEURS "Shana LEFEVRE & Arthur DECORBEZ"

/*--- CONSTANTES  COULEURS ---*/
#define NOIR 0x000000
#define GRIS 0x808080
#define BLANC 0xffffff
#define ROUGE 0xff0000
#define VERT 0x00ff00
#define BLEU 0x0000ff
#define BLEU_CIEL 0x33ccff
#define VERT_CLAIR 0x00cc00
#define MARRON 0x663300
#define BLEU_WALLE 0x4D519D

/*--- CONSTANTES REGLABLES ---*/
#define LARGEUR_FENETRE 1280
#define HAUTEUR_FENETRE 720
#define TAILLE_CASE 80

/*--- DECLARATION DES VARIABLES GLOBALES ---*/
int taille_grille = 6;
int nb_joueur = 1;

/*============================================================================================*/

/*--- CREATION DU MENU ---*/

void menu()
{
	int clique = 0;			/*--- Detection du clique ---*/
	
	CreerFenetre((Maxx()-LARGEUR_FENETRE)/2, (Maxy()-HAUTEUR_FENETRE)/2, LARGEUR_FENETRE, HAUTEUR_FENETRE);		/* Création d'une fenêtre centrée sur l'écran */
	ChoisirTitreFenetre(TITRE_JEU " par " AUTEURS);																/* Nomme la fenêtre */

	ChargerImageFond("images/menuDebut/fondMenu.jpg");

	ChargerImage("images/menuDebut/menu.png", 128, 144, 0, 0, 385, 360);
	ChargerImage("images/menuDebut/jouer.png", 128, 576, 0, 0, 1026, 72);
	ChargerImage("images/menuDebut/j1check.png", 160, 300, 0, 0, 130, 30);
	ChargerImage("images/menuDebut/6.png", 305, 441, 0, 0, 31, 31);


    /* --------------------------------------------------------------------------------------------------------------------------------------------------*/
		

	while(clique == 0)
	{
		if(SourisCliquee())
		{
			if(_X > 160 && _X < 290 && _Y > 441 && _Y < 471)							/*--- Bouton "-" ---*/
			{
				if((taille_grille > 3) && (taille_grille < 9))
				{	
					taille_grille--;
				}
				else if(taille_grille == 9)
				{
					taille_grille--;
				}

				if(taille_grille == 3)
				{
					ChargerImage("images/menuDebut/3.png", 305, 441, 0, 0, 31, 31);
				}
				else if(taille_grille == 4)
				{
					ChargerImage("images/menuDebut/4.png", 305, 441, 0, 0, 31, 31);
				}
				else if(taille_grille == 5)
				{
					ChargerImage("images/menuDebut/5.png", 305, 441, 0, 0, 31, 31);
				}
				else if(taille_grille == 6)
				{
					ChargerImage("images/menuDebut/6.png", 305, 441, 0, 0, 31, 31);
				}
				else if(taille_grille == 7)
				{
					ChargerImage("images/menuDebut/7.png", 305, 441, 0, 0, 31, 31);
				}
				else if(taille_grille == 8)
				{
					ChargerImage("images/menuDebut/8.png", 305, 441, 0, 0, 31, 31);
				}
				else if(taille_grille == 9)
				{
					ChargerImage("images/menuDebut/9.png", 305, 441, 0, 0, 31, 31);
				}
			}
			else if(_X > 366 && _X < 496 && _Y > 441 && _Y < 471)						/* Bouton "+" */
			{
				if((taille_grille > 3) && (taille_grille < 9))
				{
					taille_grille++;
				}
				else if(taille_grille == 3)
				{
					taille_grille++;
				}

				if(taille_grille == 3)
				{
					ChargerImage("images/menuDebut/3.png", 305, 441, 0, 0, 31, 31);
				}
				else if(taille_grille == 4)
				{
					ChargerImage("images/menuDebut/4.png", 305, 441, 0, 0, 31, 31);
				}
				else if(taille_grille == 5)
				{
					ChargerImage("images/menuDebut/5.png", 305, 441, 0, 0, 31, 31);
				}
				else if(taille_grille == 6)
				{
					ChargerImage("images/menuDebut/6.png", 305, 441, 0, 0, 31, 31);
				}
				else if(taille_grille == 7)
				{
					ChargerImage("images/menuDebut/7.png", 305, 441, 0, 0, 31, 31);
				}
				else if(taille_grille == 8)
				{
					ChargerImage("images/menuDebut/8.png", 305, 441, 0, 0, 31, 31);
				}
				else if(taille_grille == 9)
				{
					ChargerImage("images/menuDebut/9.png", 305, 441, 0, 0, 31, 31);
				}
			}
			else if(_X > 160 && _X < 290 && _Y > 300 && _Y < 330)						/* Bouton "1 joueur" */
			{
				nb_joueur = 1;
				ChargerImage("images/menuDebut/j1check.png", 160, 300, 0, 0, 130, 30);
				ChargerImage("images/menuDebut/j2.png", 351, 300, 0, 0, 130, 30);
			}
			else if(_X > 351 && _X < 481 && _Y > 300 && _Y < 330)						/* Bouton "2 joueurs" */
			{
				nb_joueur = 2;
				ChargerImage("images/menuDebut/j2check.png", 351, 300, 0, 0, 130, 30);
				ChargerImage("images/menuDebut/j1.png", 160, 300, 0, 0, 130, 30);
			}
			else if(_X >= 128 && _X <= 1154 && _Y >= 576 && _Y <= 648)					/* Bouton "Jouer" */
			{
				clique = 1;
			}
		}
	}
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

/*--- AFFICHER LES REGLES DU JEU VS ---*/
void RegleJeu_VS(){
	EcrireTexte (730, 30, "Voici les regles du jeu en VS : ", 1);
	EcrireTexte (730, 55, "- Initialiser Wall-e puis Eve en les placant dans la grille.", 1);
	EcrireTexte (730, 80, "- Le tour commence : bougez wall-e dans le perimetre ", 1);
	EcrireTexte (730, 105, "autorise et placez votre croix.", 1);
	EcrireTexte (730, 130, "- Puis au tour de Eve, deplacez la dans son perimetre", 1);
	EcrireTexte (730, 155, "autorise puis placez votre croix.", 1);
	EcrireTexte (730, 180, "- Repetez ces actions a tour de role durant toute la ", 1);
	EcrireTexte (730, 205, "partie.", 1);
	EcrireTexte (730, 230, "- Le jeu se finit quand l'un des deux joueurs est ", 1);
	EcrireTexte (730, 255, "bloque.", 1);
}

/*--- AFFICHER LES REGLES DU JEU SOLO ---*/
void RegleJeu_Solo(){
	EcrireTexte (730, 30, "Voici les regles du jeu en SOLO :", 1);
	EcrireTexte (730, 55, "- Initialiser Wall-e en le placant dans la grille.", 1);
	EcrireTexte (730, 80, "- Le tour commence : bougez wall-e dans le perimetre ", 1);
	EcrireTexte (730, 105, "autorise et placez votre croix.", 1);
	EcrireTexte (730, 130, "- Le deplacement de Eve se fait automatiquement.", 1);
	EcrireTexte (730, 155, "- Repetez cette action tout au long du jeu.", 1);
	EcrireTexte (730, 180, "- Le jeu se finit quand l'un des deux joueurs est ", 1);
	EcrireTexte (730, 205, "bloque.", 1);
}


/*--- BLOQUER JEU VS ---*/

int Bloquer_Vs (){

	int  posX, posY, number =0, placement_pionR =0, placement_pionB = 0;
	int recuperation_joueurR_posX, recuperation_joueurR_posY, recuperation_joueurB_posX, recuperation_joueurB_posY;
	int tab [TAILLE_CASE*taille_grille][TAILLE_CASE*taille_grille];
	int i, j;
	

	printf("LANCEMENT DU JEU MODE 2 JOUEURS\n");

	RegleJeu_VS();
	
	while (1){					

		if( SourisCliquee()){
			ChoisirCouleurDessin(NOIR);
			DessinerGrille();
			SourisPosition();

			/*--- Récupération de la partie entière ---*/
			posX = ( (int) _X )/ TAILLE_CASE;
			posY = ((int) _Y ) / TAILLE_CASE;	

			printf ("Position cliquée [%d] [%d] = %d \n", posX, posY, tab[posX][posY]);

			/*--- INITIALISATION DES PIONS ---*/

			/*--- Joueur Bleu ---*/
			if (placement_pionB < 1){
				if ( (posX < taille_grille) && (posY<taille_grille) && (! tab[posX][posY] ) ){
						ChargerImage("images/wall-e.png", posX * TAILLE_CASE + 1, posY * TAILLE_CASE +1, 0, 0, TAILLE_CASE, TAILLE_CASE);
						tab[posX][posY]= 1;
						recuperation_joueurB_posX = posX;
						recuperation_joueurB_posY = posY;

						// /*--- Affichage Arthur---*/
						// for (i = 0; i <= taille_grille ; i++)
						// {
						// 	for (j = 0; j <= taille_grille ; j++)
						// 	{
						// 		printf("%d ", tab[j][i]);
						// 	}
						// 	printf("\n");
						// }

					
				}
				placement_pionB ++;
			}

			/*--- Joueur Rouge ---*/
			if (placement_pionR < 2){
				if ( (posX>=0) && (posY>=0) && (posX < taille_grille) && (posY<taille_grille) && (! tab[posX][posY] ) ){
			
						ChargerImage("images/eve.png", posX * TAILLE_CASE + 1, posY * TAILLE_CASE +1, 0, 0, TAILLE_CASE, TAILLE_CASE);
						tab[posX][posY]= 1;
						
						recuperation_joueurR_posX = posX;
						recuperation_joueurR_posY = posY;

						/*--- Affichage Arthur---*/
						for (i = 0; i <= taille_grille ; i++)
						{
							for (j = 0; j <= taille_grille ; j++)
							{
								printf("%d ", tab[j][i]);
							}
							printf("\n");
						}

					
				}else {
					printf ("033[31m ERREUR : HORS DE LA GRILLE ET CASE NON DISPONIBLE !!! \033[37m  ");
				}
				placement_pionR ++;
				printf ("\033[35m  Anciennes coordonées joueur R  [%d][%d] \033[37m\n", recuperation_joueurR_posX, recuperation_joueurR_posY);
			}
	

			/*-- BLOQUER LES CASES ---*/

			if ( (posX>=0) && (posY>=0) && (posX < taille_grille) && (posY<taille_grille) && (! tab[posX][posY]) ){
																		
					number ++;	
								
					/*---------------------------------------------------------------------------------*/
					/* QUATRIEME ACTION CROIX R*/
					/*---------------------------------------------------------------------------------*/
					if (number % 4 == 0){ 
						printf("N° clique %d", number);	

						ChargerImage("images/croixR.png", posX * TAILLE_CASE + 1, posY * TAILLE_CASE +1, 0, 0, TAILLE_CASE, TAILLE_CASE);
      					printf("\033[35m  Clique CroixR en [%d][%d] \033[37m\n", posX, posY);
						tab[posX][posY]= 1;

						// /*--- Affichage Arthur---*/
						// for (i = 0; i <= taille_grille ; i++)
						// {
						// 	for (j = 0; j <= taille_grille ; j++)
						// 	{
						// 		printf("%d ", tab[i][j]);
						// 	}
						// 	printf("\n");
						// }


						
						/*--- GESTIONS DES ERREURS ---*/
						/*--- Blocage centrale ---*/
						if ( (tab[recuperation_joueurB_posX][recuperation_joueurB_posY] == 1) && (tab[recuperation_joueurB_posX +1][recuperation_joueurB_posY+1]==1) && (tab[recuperation_joueurB_posX+1][recuperation_joueurB_posY]==1) && (tab[recuperation_joueurB_posX+1][recuperation_joueurB_posY-1]==1) && (tab[recuperation_joueurB_posX][recuperation_joueurB_posY-1]==1) && (tab[recuperation_joueurB_posX][recuperation_joueurB_posY-1]==1) && (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY+1] ==1) && (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY]==1) && (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY-1] ==1) ){
							printf("\033[34m Le joueur B a perdu : blocage central  \033[37m \n");
							/*envoie sur page de fin*/
							return 2;
						}					
						/*--- BLOCAGE COTE---*/
						/*--- Bloquage gauche ---*/
						else if ( (tab[0][recuperation_joueurB_posY] == 1) && (tab[0][recuperation_joueurB_posY-1] == 1) && (tab[recuperation_joueurB_posX+1][recuperation_joueurB_posY] == 1) && (tab[recuperation_joueurB_posX+1][recuperation_joueurB_posY+1] == 1) && (tab[0][recuperation_joueurB_posY+1] == 1) && (tab[recuperation_joueurB_posX+1][recuperation_joueurB_posY]==1) ){
							printf("\033[34m Le joueur B a perdu : Blocage coté gauche \033[37m \n");
							/*envoie sur page de fin*/
							return 2;
						} 
						/*--- Bloquage haut ---*/
						else if ( (tab[recuperation_joueurB_posX][recuperation_joueurB_posY] == 1) && (tab[recuperation_joueurB_posX-1][0] == 1) && (tab[recuperation_joueurB_posX+1][0] == 1) && (tab[recuperation_joueurB_posX-1][1] == 1) && (tab[recuperation_joueurB_posX][1] == 1) && (tab[recuperation_joueurB_posX+1][1] == 1) ){
							printf("\033[34m Le joueur B a perdu : blocage haut \033[37m \n");
							/*envoie sur page de fin*/
							return 2;
						} 
						/*--- Blocage bas ---*/
						else if ( (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY-1] == 1) && (tab[recuperation_joueurB_posX-1][taille_grille-1] ==1) && (tab[recuperation_joueurB_posX][recuperation_joueurB_posY-1]==1) && (tab[recuperation_joueurB_posX+1][recuperation_joueurB_posY-1]==1) && (tab[recuperation_joueurB_posX+1][taille_grille-1]==1) ){
							printf("\033[34m Le joueur B a perdu : blocage bas  \033[37m \n");
							/*envoie sur page de fin*/
							return 2;
						}
						/*-- Blocage coté droit ---*/
						else if ( (tab[taille_grille-1][recuperation_joueurB_posY+1] == 1) && (tab[recuperation_joueurB_posX -1][recuperation_joueurB_posY+1]==1) && (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY] ==1) && (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY-1]==1) && (tab[recuperation_joueurB_posX][recuperation_joueurB_posY-1] ==1) && tab[recuperation_joueurB_posX][recuperation_joueurB_posY+1]== 1 ){
								printf("\033[34m Le joueur B a perdu : blocage coté droit \033[37m \n");
							/*envoie sur page de fin*/
							return 2;
						}						
						/*--- BLOCAGE COIN HAUT ---*/		
						/*--- Bloquage coin haut gauche ---*/
						else if ( (tab[0][0] == 1 ) && (tab[recuperation_joueurB_posX+1][recuperation_joueurB_posY+1] == 1) && (tab[0][recuperation_joueurB_posY+1]==1) && (tab[recuperation_joueurB_posX+1][0])==1 ) {
							printf("\033[34m Le joueur B a perdu : blocage coin haut gauche \033[37m \n");
							/*envoie sur page de fin*/
							return 2;
						} 
						/*--- Blocage coin haut droit ---*/
						else if ( (tab[taille_grille-1][0]==1) && (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY]==1) && (tab[taille_grille-1][recuperation_joueurB_posY+1]==1) && (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY+1] ==1) ) {
							printf("\033[34m Le joueur B a perdu : blocage coin haut droit \033[37m \n");
							/*envoie sur page de fin*/
							return 2;
						} 
						/*--- BLOCAGE COIN BAS ---*/
						/*--- Blocage coin bas gauche ---*/
						else if ( (tab [0][taille_grille-1] == 1) && (tab[0][recuperation_joueurB_posY-1] ==1) && (tab[recuperation_joueurB_posX+1][recuperation_joueurB_posY-1]==1) && (tab[recuperation_joueurB_posX+1][taille_grille-1] == 1) ){
							printf("\033[34m Le joueur B a perdu : blocage coin bas gauche  \033[37m \n");
							/*envoie sur page de fin*/
							return 2;
						} 
						/*--- Blocage coin bas droite ---*/
						else if ( (tab[taille_grille-1][taille_grille-1] == 1) && (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY-1] ==1) && (tab[recuperation_joueurB_posX-1][taille_grille-1]==1) && (tab[taille_grille-1][recuperation_joueurB_posY-1] == 1) ){
							printf("\033[34m Le joueur B a perdu : blocage bas droite  \033[37m \n");
							/*envoie sur page de fin*/
							return 2;
						} 
									

					/*---------------------------------------------------------------------------------*/
					/*PREMIERE ACTION JOUEUR B*/	
					/*---------------------------------------------------------------------------------*/

					}else if (number%4 == 1){ 
						printf("N° clique %d\n", number);	

														
						if (tab [recuperation_joueurB_posX][recuperation_joueurB_posY] == 1){	
					
							/*--- Réintialisation de la case ---*/
							tab [recuperation_joueurB_posX][recuperation_joueurB_posY] = 0; 
							printf(" \033[34m Anciennes coordonnées joueur B [%d][%d] OK  \033[37m \n", recuperation_joueurB_posX, recuperation_joueurB_posY); /*vérification term*/
						
							ChoisirCouleurDessin (BLANC);
							RemplirRectangle(recuperation_joueurB_posX * TAILLE_CASE + 1, recuperation_joueurB_posY * TAILLE_CASE +1, TAILLE_CASE -1, TAILLE_CASE - 1);

							if (tab[recuperation_joueurB_posX][recuperation_joueurB_posY] == 0){
								printf(" \033[32m Réinitalisation de la case de Wall-e \33[37m\n");
							}else {
								printf("033[31m ERREUR : PAS DE REINITIALISATION DE LA CASE DE WALL-E !!! \033[37m ");
							}
							

							/*--- LIMITAION DE CASES ---*/
							
							if ( ((posX == recuperation_joueurB_posX -1) || (posX == recuperation_joueurB_posX ) || (recuperation_joueurB_posX+1 == posX) ) && ( (recuperation_joueurB_posY -1== posY) || ( recuperation_joueurB_posY +1 == posY) || (recuperation_joueurB_posY == posY) )  ){
							
								/*--- Affichage ---*/
								ChoisirCouleurDessin (BLANC);
								RemplirRectangle(posX * TAILLE_CASE + 1, posY * TAILLE_CASE +1, TAILLE_CASE -1, TAILLE_CASE - 1);
								ChargerImage("images/wall-e.png", posX * TAILLE_CASE + 1, posY * TAILLE_CASE +1, 0, 0, TAILLE_CASE, TAILLE_CASE);
								printf("\033[34m Nouvelle position du joueurB [%d][%d] \033[37m \n", posX, posY);
								tab[posX][posY]= 1;

						// 		/*--- Affichage Arthur---*/
						// for (i = 0; i <= taille_grille ; i++)
						// {
						// 	for (j = 0; j <= taille_grille ; j++)
						// 	{
						// 		printf("%d ", tab[i][j]);
						// 	}
						// 	printf("\n");
						// }


								/*--- Stockage des nouvelles données ---*/
								recuperation_joueurB_posX = posX;
								recuperation_joueurB_posY = posY;
								printf ("\033[34m Position stocké [%d][%d] \033[37m \n", recuperation_joueurB_posX, recuperation_joueurB_posY);
							}else {
								RemplirRectangle(posX * TAILLE_CASE + 1, posY * TAILLE_CASE +1, TAILLE_CASE -1, TAILLE_CASE - 1);
								ChargerImage("images/wall-e.png", recuperation_joueurB_posX * TAILLE_CASE + 1, recuperation_joueurB_posY * TAILLE_CASE +1, 0, 0, TAILLE_CASE, TAILLE_CASE);
								printf("\033[31m ERREUR DE DÉPLACEMENT !!! \033[37m \n");
								
							}

						}else {
							printf ("\033[31m ERREUR RECUPERATION DONNEES JOUEUR BLEU !!! \033[37m \n");
							/* fenetre de sortie */
						}		


					/*---------------------------------------------------------------------------------*/
					/* DEUXIEME ACTION CROIX B*/
					/*---------------------------------------------------------------------------------*/
					}else if (number%4 == 2){ 
						printf("N° clique %d\n", number);	

						ChargerImage("images/croixB.png", posX * TAILLE_CASE + 1, posY * TAILLE_CASE +1, 0, 0, TAILLE_CASE, TAILLE_CASE);
      					printf("\033[34m Clique croixB en [%d][%d] \033[37m\n",posX, posY);
						tab[posX][posY]= 1;
						
						
						/*--- GESTIONS DES ERREURS ---*/
						/*--- Blocage centrale ---*/
					
						if ( (tab[recuperation_joueurR_posX][recuperation_joueurR_posY] == 1) && (tab[recuperation_joueurR_posX +1][recuperation_joueurR_posY+1]==1) && (tab[recuperation_joueurR_posX+1][recuperation_joueurR_posY]==1) && (tab[recuperation_joueurR_posX+1][recuperation_joueurR_posY-1]==1) && (tab[recuperation_joueurR_posX][recuperation_joueurR_posY-1]==1) && (tab[recuperation_joueurR_posX][recuperation_joueurR_posY-1]==1) && (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY+1] ==1) && (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY]==1) && (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY-1] ==1) ){
							printf ("\033[35m Le joueur R a perdu : blocage central \033[37m\n");
							/*envoie sur page de fin*/
							return 1;
						}
						/*--- BLOCAGE COTE---*/
						/*--- Bloquage gauche ---*/
						else  if ( (tab[0][recuperation_joueurR_posY] == 1) && (tab[0][recuperation_joueurR_posY-1] == 1) && (tab[recuperation_joueurR_posX+1][recuperation_joueurR_posY] == 1) && (tab[recuperation_joueurR_posX+1][recuperation_joueurR_posY+1] == 1) && (tab[0][recuperation_joueurR_posY+1] == 1) && (tab[recuperation_joueurR_posX+1][recuperation_joueurR_posY]==1) ){
							printf("\033[35m Le joueur R a perdu : blocage coté gauche \033[37m \n");
							/*envoie sur page de fin*/
							return 1;
						}
						/*--- Bloquage haut ---*/
						else if ( (tab[recuperation_joueurB_posX][recuperation_joueurB_posY] == 1) && (tab[recuperation_joueurR_posX-1][0] == 1) && (tab[recuperation_joueurR_posX+1][0] == 1) && (tab[recuperation_joueurR_posX-1][1] == 1) && (tab[recuperation_joueurR_posX][1] == 1) && (tab[recuperation_joueurR_posX+1][1] == 1) ){
							printf("\033[35m Le joueur R a perdu : blocage haut \033[37m \n");
							/*envoie sur page de fin*/
							return 1;
						}
						/*--- Blocage bas ---*/
						else if ( (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY-1] == 1) && (tab[recuperation_joueurR_posX-1][taille_grille-1] ==1) && (tab[recuperation_joueurR_posX][recuperation_joueurR_posY-1]==1) && (tab[recuperation_joueurR_posX+1][recuperation_joueurR_posY-1]==1) && (tab[recuperation_joueurR_posX+1][taille_grille-1]==1) ){
							printf("\033[35m Le joueur R a perdu : blocage bas \033[37m \n");
							/*envoie sur page de fin*/
							return 1;
						}
						/*-- Blocage coté droit ---*/
						else if ( (tab[taille_grille-1][recuperation_joueurR_posY+1] == 1) && (tab[recuperation_joueurR_posX -1][recuperation_joueurR_posY+1]==1) && (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY] ==1) && (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY-1]==1) && (tab[recuperation_joueurR_posX][recuperation_joueurR_posY-1] ==1) && tab[recuperation_joueurR_posX][recuperation_joueurR_posY+1]== 1 ){
							printf("\033[35m Le joueur R a perdu  : blocage coté droit \033[37m \n");
							/*envoie sur page de fin*/
							return 1;
						}
						/*--- BLOCAGE COIN HAUT ---*/			
						/*--- Bloquage coin haut gauche ---*/
						else if ( (tab[0][0] == 1 ) &&  (tab[recuperation_joueurR_posX+1][recuperation_joueurR_posY+1] == 1) && (tab[0][recuperation_joueurR_posY+1]==1) && (tab[recuperation_joueurR_posX+1][0])==1 ) {
							printf("\033[35m Le joueur R a perdu : blocage coin haut gauche \033[37m \n");
							/*envoie sur page de fin*/
							return 1;
						}
						/*--- Blocage coin haut droit ---*/
						else if ( (tab[taille_grille-1][0]==1) && (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY]==1) && (tab[taille_grille-1][recuperation_joueurR_posY+1]==1) && (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY+1] ==1) ) {
							printf("\033[35m Le joueur R a perdu : blocage coin haut droit \033[37m \n");
							/*envoie sur page de fin*/
							return 1;
						}
						/*--- BLOCAGE COIN BAS ---*/
						/*--- Blocage coin bas gauche ---*/
						else if ( (tab [0][taille_grille-1] == 1) && (tab[0][recuperation_joueurR_posY-1] ==1) && (tab[recuperation_joueurR_posX+1][recuperation_joueurR_posY-1]==1) && (tab[recuperation_joueurR_posX+1][taille_grille-1] == 1) ){
							printf("\033[35m Le joueur R a perdu : blocage coin bas gauche \033[37m \n");
							/*envoie sur page de fin*/
							return 1;
						}
						/*--- Blocage coin bas droite ---*/
						else  if ( (tab[taille_grille-1][taille_grille-1] == 1) && (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY-1] ==1) && (tab[recuperation_joueurR_posX-1][taille_grille-1]==1) && (tab[taille_grille-1][recuperation_joueurR_posY-1] == 1) ){
							printf("\033[35m Le joueur R a perdu : bloacage bas droite\033[37m \n");
							/*envoie sur page de fin*/
							return 1;
						}	


					/*---------------------------------------------------------------------------------*/
					/* TROISIEME ACTION JOUEUR R */
					/*---------------------------------------------------------------------------------*/
					}else if (number%4 == 3){ 
						printf("N° clique %d\n", number);	
											 
						if (tab [recuperation_joueurR_posX][recuperation_joueurR_posY] == 1 ){

							/*--- Réintialisation de la case ---*/
							tab [recuperation_joueurR_posX][recuperation_joueurR_posY] = 0; 
							printf("\033[35m Anciennes coordonnées R [%d][%d] \033[37m\n", recuperation_joueurR_posX, recuperation_joueurR_posY); /*vérification term*/
							ChoisirCouleurDessin (BLANC);
							RemplirRectangle(recuperation_joueurR_posX * TAILLE_CASE + 1, recuperation_joueurR_posY * TAILLE_CASE +1, TAILLE_CASE -1, TAILLE_CASE - 1);

							if (tab[recuperation_joueurR_posX][recuperation_joueurR_posY] == 0){
								printf("\033[32m   Réinitalisation de la case de Eve \33[37m\n");
							}else {
								printf("033[31m ERREUR : PAS DE REINITIALISATION DE LA CASE DE EVE !!! \033[37m ");
							}
							
							
							/*--- LIMITAION DE CASES ---*/
							if ( ( (recuperation_joueurR_posX == posX -1) || (recuperation_joueurR_posX == posX+1) || (recuperation_joueurR_posX == posX) ) && ( (recuperation_joueurR_posY== posY-1) || ( recuperation_joueurR_posY== posY+1) || (recuperation_joueurR_posY == posY) ) ){
								/* Affichage*/
								ChoisirCouleurDessin (BLANC);
								RemplirRectangle(posX * TAILLE_CASE + 1, posY * TAILLE_CASE +1, TAILLE_CASE -1, TAILLE_CASE - 1);
								ChargerImage("images/eve.png", posX * TAILLE_CASE + 1, posY * TAILLE_CASE +1, 0, 0, TAILLE_CASE, TAILLE_CASE);
								printf("\033[35m   Clique JoueurR [%d][%d]\033[37m \n ", posX, posY);
								tab[posX][posY]= 1;

								/*--- Stockage des nouvelles données ---*/
								recuperation_joueurR_posX = posX;
								recuperation_joueurR_posY = posY;
								printf("\033[35m   Position stockée [%d][%d]\033[37m \n", recuperation_joueurR_posX, recuperation_joueurR_posY);

								/*--- Affichage Arthur---*/
								// for (i = 0; i <= taille_grille ; i++)
								// {
								// 	for (j = 0; j <= taille_grille ; j++)
								// 	{
								// 		printf("%d ", tab[i][j]);
								// 	}
								// 	printf("\n");
								// }

							
							}else {
								RemplirRectangle(posX * TAILLE_CASE + 1, posY * TAILLE_CASE +1, TAILLE_CASE -1, TAILLE_CASE - 1);
								ChargerImage("images/eve.png", recuperation_joueurR_posX * TAILLE_CASE + 1, recuperation_joueurR_posY * TAILLE_CASE +1, 0, 0, TAILLE_CASE, TAILLE_CASE);
								printf("\033[31m ERREUR DE DÉPLACEMENT !!! \033[37m \n");
								
							}
						
						}else {
							printf ("\033[31m ERREUR : STOCKAGE DES COORDONNÉES DU JOUEUR R !!! \033[37m \n");
						}
	
					}

			}else {
				printf (" \033[31m ERREUR : HORS DE LA GRILLE ET CASE NON DISPONIBLE !!! \033[37m \n");
			
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

	RegleJeu_Solo();

	int i, j;



    /*--- Affichage Shana---*/
    for(i = 0; i <= taille_grille - 1; i++)
    {
        for(j = 0; j <= taille_grille - 1; j++)
        {
            printf ("[%d][%d] = %d\n", i  ,j, tab[i][j]);
        }
    }

    // /*--- Affichage Arthur---*/
    // for (i = 0; i <= taille_grille - 1; i++)
    // {
    //     for (j = 0; j <= taille_grille - 1; j++)
    //     {
    //         printf("%d ", tab[i][j]);
    //     }
    //     printf("\n");
    // }



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

			if ( (posX>=0) && (posY>=0) && (posX < taille_grille) && (posY<taille_grille) && (! tab[posX][posY]) ){
			
				ChargerImage("images/wall-e.png", posX * TAILLE_CASE + 1, posY * TAILLE_CASE +1, 0, 0, TAILLE_CASE, TAILLE_CASE);
				tab[posX][posY]= 1;
					
				// /*--- Affichage Arthur---*/
				// for (i = 0; i <= taille_grille ; i++)
				// {
				// 	for (j = 0; j <= taille_grille; j++)
				// 	{
				// 		printf("%d ", tab[i][j]);
				// 	}
				// 	printf("\n");
				// }
					
				recuperation_joueurB_posX = posX;
				recuperation_joueurB_posY = posY;
					
			}
			placement_pionB ++;
			printf ("\033[34m Initialisation coordonnées joueur B [%d][%d] OK  \033[37m \n", recuperation_joueurB_posX, recuperation_joueurB_posY);
		
					
			
			
			
			}
			
		}

		/*--- Joueur Rouge ---*/

		if (placement_pionR < 1){

			while (verification_aleatoire == 1){
				
				posX = rand()% taille_grille - 0;
				posY = rand()% taille_grille - 0;		
				
				if ( (posX < taille_grille) && (posY<taille_grille) && (! tab[posX][posY] ) ){

					tab[posX][posY]=1;	
					ChargerImage("images/eve.png", posX * TAILLE_CASE + 1, posY * TAILLE_CASE +1, 0, 0, TAILLE_CASE, TAILLE_CASE);

					// /*--- Affichage Arthur---*/
					// for (i = 0; i <= taille_grille ; i++)
					// {
					// 	for (j = 0; j <= taille_grille ; j++)
					// 	{
					// 		printf("%d ", tab[i][j]);
					// 	}
					// 	printf("\n");
					// }




					recuperation_joueurR_posX = posX;
					recuperation_joueurR_posY= posY;
					verification_aleatoire = 0;
					
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
				printf("N° clique %d\n", number);
				printf ("Position cliquée [%d] [%d]\n", posX, posY);
			
					if  (tab [recuperation_joueurB_posX][recuperation_joueurB_posY] == 1){

						/*--- Réintialisation de l'ancienne case ---*/
						tab [recuperation_joueurB_posX][recuperation_joueurB_posY] = 0; 
						printf(" \033[34m Anciennes coordonnées joueur B [%d][%d] OK  \033[37m \n", recuperation_joueurB_posX, recuperation_joueurB_posY); /*vérification term*/											
						ChoisirCouleurDessin (BLANC);
						RemplirRectangle(recuperation_joueurB_posX * TAILLE_CASE + 1, recuperation_joueurB_posY * TAILLE_CASE +1, TAILLE_CASE -1, TAILLE_CASE - 1);

						// /*--- Affichage Arthur---*/
						// for (i = 0; i <= taille_grille ; i++)
						// {
						// 	for (j = 0; j <= taille_grille ; j++)
						// 	{
						// 		printf("%d ", tab[i][j]);
						// 	}
						// 	printf("\n");
						// }


						
						if (tab [recuperation_joueurB_posX][recuperation_joueurB_posY] == 0 ){
							printf("\033[32m  Reinitialisation de la case de Wall-e est ok \033[37m \n");
						}else {
							printf("\033[31m  ERREUR: PAS DEREINITIALISARION DE LA CASE Wall-e  \033[37m \n");
						}


						if ( (! tab[posX][posY])  && (posX < taille_grille) && (posY< taille_grille) ) {						

							/*--- LIMITAION DE CASES ---*/
									
							if ( ((posX == recuperation_joueurB_posX -1) || (posX == recuperation_joueurB_posX ) || (recuperation_joueurB_posX+1 == posX) ) && ( (recuperation_joueurB_posY -1== posY) || ( recuperation_joueurB_posY +1 == posY) || (recuperation_joueurB_posY == posY) )  ){
									
								/*--- Affichage ---*/
								ChoisirCouleurDessin (BLANC);
								RemplirRectangle(posX * TAILLE_CASE + 1, posY * TAILLE_CASE +1, TAILLE_CASE -1, TAILLE_CASE - 1);
								ChargerImage("images/wall-e.png", posX * TAILLE_CASE + 1, posY * TAILLE_CASE +1, 0, 0, TAILLE_CASE, TAILLE_CASE);
								printf("\033[34m Nouvelle position du joueurB [%d][%d] \033[37m \n", posX, posY);
								tab[posX][posY]= 1;

								/*--- Stockage des nouvelles données ---*/
								recuperation_joueurB_posX = posX;
								recuperation_joueurB_posY = posY;
								printf ("\033[34m Position stocké [%d][%d] \033[37m \n", recuperation_joueurB_posX, recuperation_joueurB_posY);
							}else {
								RemplirRectangle(posX * TAILLE_CASE + 1, posY * TAILLE_CASE +1, TAILLE_CASE -1, TAILLE_CASE - 1);
								ChargerImage("images/wall-e.png", recuperation_joueurB_posX * TAILLE_CASE + 1, recuperation_joueurB_posY * TAILLE_CASE +1, 0, 0, TAILLE_CASE, TAILLE_CASE);
								printf("\033[31m ERREUR : DÉPLACEMENT !!! \033[37m \n");
							
							}
						}

					}else {
						printf ("\033[31m ERREUR : RECUPERATION DONNEES JOUEUR BLEU !!! \033[37m \n");
						/* fenetre de sortie */
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

				printf("N° clique %d\n", number);	

				posX = (int) _X / TAILLE_CASE;
				posY = (int) _Y / TAILLE_CASE;	

				if ( (posX < taille_grille) && (posY<taille_grille) && (! tab[posX][posY]) ){
						ChargerImage("images/croixB.png", posX * TAILLE_CASE + 1, posY * TAILLE_CASE +1, 0, 0, TAILLE_CASE, TAILLE_CASE);
						printf("\033[34m Clique croixB en [%d][%d] \033[37m\n",posX, posY);
						tab[posX][posY]= 1;

						// /*--- Affichage Arthur---*/
						// for (i = 0; i <= taille_grille ; i++)
						// {
						// 	for (j = 0; j <= taille_grille ; j++)
						// 	{
						// 		printf("%d ", tab[i][j]);
						// 	}
						// 	printf("\n");
						// }
			
				} else {
					printf ("\033[35m ERREUR : HORS DE LA GRILLE ET CASE NON DISPONIBLE \033[37m\n ");
				}
			}

			/*--- GESTIONS DES ERREURS ---*/
				/*--- Blocage centrale ---*/					
				if ( (tab[recuperation_joueurR_posX][recuperation_joueurR_posY] == 1) && (tab[recuperation_joueurR_posX +1][recuperation_joueurR_posY+1]==1) && (tab[recuperation_joueurR_posX+1][recuperation_joueurR_posY]==1) && (tab[recuperation_joueurR_posX+1][recuperation_joueurR_posY-1]==1) && (tab[recuperation_joueurR_posX][recuperation_joueurR_posY-1]==1) && (tab[recuperation_joueurR_posX][recuperation_joueurR_posY-1]==1) && (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY+1] ==1) && (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY]==1) && (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY-1] ==1) ){
					printf ("\033[35m Le joueur R a perdu : blocage central \033[37m\n");
					/*envoie sur page de fin*/
					return 1;
				}
			/*--- BLOCAGE COTE---*/
				/*--- Bloquage gauche ---*/					
				else if ( (tab[0][recuperation_joueurR_posY] == 1) && (tab[0][recuperation_joueurR_posY-1] == 1) && (tab[recuperation_joueurR_posX+1][recuperation_joueurR_posY] == 1) && (tab[recuperation_joueurR_posX+1][recuperation_joueurR_posY+1] == 1) && (tab[0][recuperation_joueurR_posY+1] == 1) && (tab[recuperation_joueurR_posX+1][recuperation_joueurR_posY]==1) ){
					printf("\033[35m Le joueur R a perdu : blocage coté gauche \033[37m \n");
					/*envoie sur page de fin*/
					return 1;
				}
				/*--- Bloquage haut ---*/					
				else if ( (tab[recuperation_joueurB_posX][recuperation_joueurB_posY] == 1) && (tab[recuperation_joueurR_posX-1][0] == 1) && (tab[recuperation_joueurR_posX+1][0] == 1) && (tab[recuperation_joueurR_posX-1][1] == 1) && (tab[recuperation_joueurR_posX][1] == 1) && (tab[recuperation_joueurR_posX+1][1] == 1) ){
					printf("\033[35m Le joueur R a perdu : blocage haut \033[37m \n");
					/*envoie sur page de fin*/
					return 1;
				}
				/*--- Blocage bas ---*/					
				else if ( (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY-1] == 1) && (tab[recuperation_joueurR_posX-1][taille_grille-1] ==1) && (tab[recuperation_joueurR_posX][recuperation_joueurR_posY-1]==1) && (tab[recuperation_joueurR_posX+1][recuperation_joueurR_posY-1]==1) && (tab[recuperation_joueurR_posX+1][taille_grille-1]==1) ){
					printf("\033[35m Le joueur R a perdu : blocage bas \033[37m \n");
					/*envoie sur page de fin*/
					return 1;
				}
				/*-- Blocage coté droit ---*/					
				else if ( (tab[taille_grille-1][recuperation_joueurR_posY+1] == 1) && (tab[recuperation_joueurR_posX -1][recuperation_joueurR_posY+1]==1) && (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY] ==1) && (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY-1]==1) && (tab[recuperation_joueurR_posX][recuperation_joueurR_posY-1] ==1) && tab[recuperation_joueurR_posX][recuperation_joueurR_posY+1]== 1 ){
					printf("\033[35m Le joueur R a perdu  : blocage coté droit \033[37m \n");
					/*envoie sur page de fin*/
					return 1;
				}
			/*--- BLOCAGE COIN HAUT ---*/	
				/*--- Bloquage coin haut gauche ---*/					
				else if ( (tab[0][0] == 1 ) &&  (tab[recuperation_joueurR_posX+1][recuperation_joueurR_posY+1] == 1) && (tab[0][recuperation_joueurR_posY+1]==1) && (tab[recuperation_joueurR_posX+1][0])==1 ) {
					printf("\033[35m Le joueur R a perdu : blocage coin haut gauche \033[37m \n");
					/*envoie sur page de fin*/
					return 1;
				}
				/*--- Blocage coin haut droit ---*/					
				else if ( (tab[taille_grille-1][0]==1) && (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY]==1) && (tab[taille_grille-1][recuperation_joueurR_posY+1]==1) && (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY+1] ==1) ) {
					printf("\033[35m Le joueur R a perdu : blocage coin haut droit \033[37m \n");
					/*envoie sur page de fin*/
					return 1;						}
			/*--- BLOCAGE COIN BAS ---*/
				/*--- Blocage coin bas gauche ---*/					
				else if ( (tab [0][taille_grille-1] == 1) && (tab[0][recuperation_joueurR_posY-1] ==1) && (tab[recuperation_joueurR_posX+1][recuperation_joueurR_posY-1]==1) && (tab[recuperation_joueurR_posX+1][taille_grille-1] == 1) ){
					printf("\033[35m Le joueur R a perdu : blocage coin bas gauche \033[37m \n");
					/*envoie sur page de fin*/
					return 1;
				}
				/*--- Blocage coin bas droite ---*/					
				else if ( (tab[taille_grille-1][taille_grille-1] == 1) && (tab[recuperation_joueurR_posX-1][recuperation_joueurR_posY-1] ==1) && (tab[recuperation_joueurR_posX-1][taille_grille-1]==1) && (tab[taille_grille-1][recuperation_joueurR_posY-1] == 1) ){
					printf("\033[35m Le joueur R a perdu : bloacage bas droite\033[37m \n");
					/*envoie sur page de fin*/
					return 1;
				}			
		}


		/*---------------------------------------------------------------------------------*/
		/* TROISIEME ACTION JOUEUR R (BOT) */
		/*---------------------------------------------------------------------------------*/
		else if (number%4 == 3 ){	
			
			if (tab [recuperation_joueurR_posX][recuperation_joueurR_posY] == 1 ){
				
				number++;
				printf("N° clique %d\n", number);

				while (verification_aleatoire == 1){
								
					/*--- Limitation déplacement de la case ---*/			
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

					if ( (! tab[posX][posY]) && (posX>= 0 ) && (posY>=0) && (posX<taille_grille) && (posY<taille_grille) ){

						tab [posX][posY]=1;
						ChargerImage("images/eve.png", posX * TAILLE_CASE + 1, posY * TAILLE_CASE +1, 0, 0, TAILLE_CASE, TAILLE_CASE);
						

						/*--- Réintialisation de la case ---*/

						tab [recuperation_joueurR_posX][recuperation_joueurR_posY] = 0; 
						printf("\033[35m Anciennes coordonnées R [%d][%d] \033[37m\n", recuperation_joueurR_posX, recuperation_joueurR_posY); /*vérification term*/
						ChoisirCouleurDessin (BLANC);
						RemplirRectangle(recuperation_joueurR_posX * TAILLE_CASE + 1, recuperation_joueurR_posY * TAILLE_CASE +1, TAILLE_CASE -1, TAILLE_CASE - 1);
						/* number++; */

						/*--- Vérification ---*/
						if (tab [recuperation_joueurR_posX][recuperation_joueurR_posY] == 0 ){
							printf("\033[32m Réanitialisation de la case de Eve est ok \033[37m\n");						
						}else {
							printf("\033[31m  ERREUR: PAS DE REINITIALISARION DE LA CASE Eve  \033[37m \n");
						}

						// /*--- Affichage Arthur---*/
						// for (i = 0; i <= taille_grille ; i++)
						// {
						// 	for (j = 0; j <= taille_grille ; j++)
						// 	{
						// 		printf("%d ", tab[posX][posY]);
						// 	}
						// 	printf("\n");
						// }
						
					
						/*--- Stockage des coordonees ---*/
						recuperation_joueurR_posX= posX;
						recuperation_joueurR_posY = posY;
						
						verification_aleatoire = 0;
				
					}else if ( (tab[posX][posY] ==  1) &&  (posX<taille_grille) && (posY<taille_grille)) {
						verification_aleatoire = 1;
					}
				
				}	
			
				verification_aleatoire = 1;	
					

			}else {
				printf("\033[35m ERREUR :  SAUVEGARDE DES COORDONNEES !!! \033[37m\n");
			}			
		
		}
			
		/*---------------------------------------------------------------------------------*/
		/* QUATRIEME ACTION CROIX R (BOT) */
		/*---------------------------------------------------------------------------------*/

		else if (number % 4 == 0 ){		
			number++;
			printf("N° clique %d\n", number);
		
			while (verification_aleatoire == 1){
			
				posX = rand ()% (taille_grille-1)-0;
				posX = rand ()% (taille_grille-1)-0;

				if ( (posX < taille_grille) && (posY>=0) && (posX >= 0) && (posY<taille_grille) && (!tab[posX][posY]) ){
			
						tab[posX][posY]= 1;
						ChargerImage("images/croixR.png", posX * TAILLE_CASE + 1, posY * TAILLE_CASE +1, 0, 0, TAILLE_CASE, TAILLE_CASE);
						printf("\033[35m  CroixR en [%d][%d] \033[37m\n", posX, posY);
						verification_aleatoire = 0;

						// /*--- Affichage Arthur---*/
						// for (i = 0; i <= taille_grille ; i++)
						// {
						// 	for (j = 0; j <= taille_grille ; j++)
						// 	{
						// 		printf("%d ", tab[posX][posY]);
						// 	}
						// 	printf("\n");
						// }
					
				}else {
					verification_aleatoire = 1;
				}
			}


			/*--- GESTIONS DES ERREURS ---*/
				/*--- Blocage centrale ---*/
				if ( (tab[recuperation_joueurB_posX][recuperation_joueurB_posY] == 1) && (tab[recuperation_joueurB_posX +1][recuperation_joueurB_posY+1]==1) && (tab[recuperation_joueurB_posX+1][recuperation_joueurB_posY]==1) && (tab[recuperation_joueurB_posX+1][recuperation_joueurB_posY-1]==1) && (tab[recuperation_joueurB_posX][recuperation_joueurB_posY-1]==1) && (tab[recuperation_joueurB_posX][recuperation_joueurB_posY-1]==1) && (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY+1] ==1) && (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY]==1) && (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY-1] ==1) ){
					printf("\033[34m Le joueur B a perdu : blocage central  \033[37m \n");
					/*envoie sur page de fin*/
					return 2;
				}					
				/*--- BLOCAGE COTE---*/
				/*--- Bloquage gauche ---*/
				else if ( (tab[0][recuperation_joueurB_posY] == 1) && (tab[0][recuperation_joueurB_posY-1] == 1) && (tab[recuperation_joueurB_posX+1][recuperation_joueurB_posY] == 1) && (tab[recuperation_joueurB_posX+1][recuperation_joueurB_posY+1] == 1) && (tab[0][recuperation_joueurB_posY+1] == 1) && (tab[recuperation_joueurB_posX+1][recuperation_joueurB_posY]==1) ){
					printf("\033[34m Le joueur B a perdu : Blocage coté gauche \033[37m \n");
					/*envoie sur page de fin*/
					return 2;
				} 
				/*--- Bloquage haut ---*/
				else if ( (tab[recuperation_joueurB_posX][recuperation_joueurB_posY] == 1) && (tab[recuperation_joueurB_posX-1][0] == 1) && (tab[recuperation_joueurB_posX+1][0] == 1) && (tab[recuperation_joueurB_posX-1][1] == 1) && (tab[recuperation_joueurB_posX][1] == 1) && (tab[recuperation_joueurB_posX+1][1] == 1) ){
					printf("\033[34m Le joueur B a perdu : blocage haut \033[37m \n");
					/*envoie sur page de fin*/
					return 2;
				} 
				/*--- Blocage bas ---*/
				else if ( (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY-1] == 1) && (tab[recuperation_joueurB_posX-1][taille_grille-1] ==1) && (tab[recuperation_joueurB_posX][recuperation_joueurB_posY-1]==1) && (tab[recuperation_joueurB_posX+1][recuperation_joueurB_posY-1]==1) && (tab[recuperation_joueurB_posX+1][taille_grille-1]==1) ){
					printf("\033[34m Le joueur B a perdu : blocage bas  \033[37m \n");
					/*envoie sur page de fin*/
					return 2;
				}
				/*-- Blocage coté droit ---*/
				else if ( (tab[taille_grille-1][recuperation_joueurB_posY+1] == 1) && (tab[recuperation_joueurB_posX -1][recuperation_joueurB_posY+1]==1) && (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY] ==1) && (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY-1]==1) && (tab[recuperation_joueurB_posX][recuperation_joueurB_posY-1] ==1) && tab[recuperation_joueurB_posX][recuperation_joueurB_posY+1]== 1 ){
						printf("\033[34m Le joueur B a perdu : blocage coté droit \033[37m \n");
					/*envoie sur page de fin*/
					return 2;
				}					
				/*--- BLOCAGE COIN HAUT ---*/	
				/*--- Bloquage coin haut gauche ---*/
				else if ( (tab[0][0] == 1 ) && (tab[recuperation_joueurB_posX+1][recuperation_joueurB_posY+1] == 1) && (tab[0][recuperation_joueurB_posY+1]==1) && (tab[recuperation_joueurB_posX+1][0])==1 ) {
					printf("\033[34m Le joueur B a perdu : blocage coin haut gauche \033[37m \n");
					/*envoie sur page de fin*/
					return 2;
				} 
				/*--- Blocage coin haut droit ---*/
				else if ( (tab[taille_grille-1][0]==1) && (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY]==1) && (tab[taille_grille-1][recuperation_joueurB_posY+1]==1) && (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY+1] ==1) ) {
					printf("\033[34m Le joueur B a perdu : blocage coin haut droit \033[37m \n");
					/*envoie sur page de fin*/
					return 2;
				} 
				/*--- BLOCAGE COIN BAS ---*/
				/*--- Blocage coin bas gauche ---*/
				else if ( (tab [0][taille_grille-1] == 1) && (tab[0][recuperation_joueurB_posY-1] ==1) && (tab[recuperation_joueurB_posX+1][recuperation_joueurB_posY-1]==1) && (tab[recuperation_joueurB_posX+1][taille_grille-1] == 1) ){
					printf("\033[34m Le joueur B a perdu : blocage coin bas gauche  \033[37m \n");
					/*envoie sur page de fin*/
					return 2;
				} 
				/*--- Blocage coin bas droite ---*/
				else if ( (tab[taille_grille-1][taille_grille-1] == 1) && (tab[recuperation_joueurB_posX-1][recuperation_joueurB_posY-1] ==1) && (tab[recuperation_joueurB_posX-1][taille_grille-1]==1) && (tab[taille_grille-1][recuperation_joueurB_posY-1] == 1) ){
					printf("\033[34m Le joueur B a perdu : blocage bas droite  \033[37m \n");
					/*envoie sur page de fin*/
					return 2;
				} 
						
			verification_aleatoire = 1;
		
					
		}

	}

}

void jeu();

/*--- MENU DE FIN ---*/

void menu_fin(int valGagnant, int modeJeu)
{
	int status_clique = 0;
	int clique = 0;

	printf("valGagnant : %d\n", valGagnant);
	printf("modeJeu : %d\n", modeJeu);

	ChargerImageFond("images/menuFin/fondMenu.png");

	if(valGagnant == 1 && modeJeu == 1)
	{
		printf("Wall-e a vaincu Eve !\n");
		/* EcrireTexte(0, 22, "Wall-e a vaincu Eve (IA) !", 2); */

		ChargerImage("images/menuFin/wall-eGagne.png", 127, 50, 0, 0, 1026, 72);
	}
	else if(valGagnant == 2 && modeJeu == 1)
	{
		printf("L'IA à vaincu le joueur 1 (Bleu) !\n");
		/* EcrireTexte(0, 22, "Eve (IA) a vaincu Wall-e !", 2); */

		ChargerImage("images/menuFin/eveGagne.png", 127, 50, 0, 0, 1026, 72);
	}
	else if(valGagnant == 1 && modeJeu == 2)
	{
		printf("Wall-e a vaincu Eve !\n");
		/* EcrireTexte(0, 22, "Wall-e a vaincu Eve !", 2); */

		ChargerImage("images/menuFin/wall-eGagne.png", 127, 50, 0, 0, 1026, 72);
	}
	else if(valGagnant == 2 && modeJeu == 2)
	{
		printf("Eve a vaincu Wall-e!\n");
		/* EcrireTexte(0, 22, "Eve à vaincu Wall-e !", 2); */

		ChargerImage("images/menuFin/eveGagne.png", 127, 50, 0, 0, 1026, 72);
	}
	else
	{
		printf("\033[31m/!\\ Erreur lors du test du gagnant (fonction menu_fin)\033[37m\n");
	}

	ChargerImage("images/menuFin/rejouer.png", 769, 266, 0, 0, 384, 72);
	ChargerImage("images/menuFin/quitter.png", 769, 410, 0, 0, 384, 72);

	while (status_clique == 0)
	{
		if(SourisCliquee())
		{
			if(_X > 769 && _X < 1153 && _Y > 266 && _Y < 328)
			{
				printf("Rejouer\n");

				ChargerImageFond("images/menuFin/fondMenu.png");
				ChargerImage("images/menuFin/menu.png", 817, 100, 0, 0, 384, 360);
				ChargerImage("images/menuFin/jouer.png", 817, 496, 0, 0, 384, 72);

				if(nb_joueur == 1)
				{
					ChargerImage("images/menuFin/j1check.png", 849, 256, 0, 0, 130, 30);
					ChargerImage("images/menuFin/j2.png", 1040, 256, 0, 0, 130, 30);
				}
				else if(nb_joueur == 2)
				{
					ChargerImage("images/menuFin/j1.png", 849, 256, 0, 0, 130, 30);
					ChargerImage("images/menuFin/j2check.png", 1040, 256, 0, 0, 130, 30);
				}

				if(taille_grille == 3)
				{
					ChargerImage("images/menuFin/3.png", 994, 397, 0, 0, 31, 31);
				}
				else if(taille_grille == 4)
				{
					ChargerImage("images/menuFin/4.png", 994, 397, 0, 0, 31, 31);
				}
				else if(taille_grille == 5)
				{
					ChargerImage("images/menuFin/5.png", 994, 397, 0, 0, 31, 31);
				}
				else if(taille_grille == 6)
				{
					ChargerImage("images/menuFin/6.png", 994, 397, 0, 0, 31, 31);
				}
				else if(taille_grille == 7)
				{
					ChargerImage("images/menuFin/7.png", 994, 397, 0, 0, 31, 31);
				}
				else if(taille_grille == 8)
				{
					ChargerImage("images/menuFin/8.png", 994, 397, 0, 0, 31, 31);
				}
				else if(taille_grille == 9)
				{
					ChargerImage("images/menuFin/9.png", 994, 397, 0, 0, 31, 31);
				}

				while(clique == 0)
				{
					if(SourisCliquee())
					{
						if(_X > 849 && _X < 964 && _Y > 397 && _Y < 428)							/*--- Bouton "-" ---*/
						{
							if((taille_grille > 3) && (taille_grille < 9))
							{	
								taille_grille--;
							}
							else if(taille_grille == 9)
							{
								taille_grille--;
							}

							if(taille_grille == 3)
							{
								ChargerImage("images/menuFin/3.png", 994, 397, 0, 0, 31, 31);
							}
							else if(taille_grille == 4)
							{
								ChargerImage("images/menuFin/4.png", 994, 397, 0, 0, 31, 31);
							}
							else if(taille_grille == 5)
							{
								ChargerImage("images/menuFin/5.png", 994, 397, 0, 0, 31, 31);
							}
							else if(taille_grille == 6)
							{
								ChargerImage("images/menuFin/6.png", 994, 397, 0, 0, 31, 31);
							}
							else if(taille_grille == 7)
							{
								ChargerImage("images/menuFin/7.png", 994, 397, 0, 0, 31, 31);
							}
							else if(taille_grille == 8)
							{
								ChargerImage("images/menuFin/8.png", 994, 397, 0, 0, 31, 31);
							}
							else if(taille_grille == 9)
							{
								ChargerImage("images/menuFin/9.png", 994, 397, 0, 0, 31, 31);
							}
						}
						else if(_X > 1055 && _X < 1170 && _Y > 397 && _Y < 428)						/* Bouton "+" */
						{
							if((taille_grille > 3) && (taille_grille < 9))
							{
								taille_grille++;
							}
							else if(taille_grille == 3)
							{
								taille_grille++;
							}

							if(taille_grille == 3)
							{
								ChargerImage("images/menuFin/3.png", 994, 397, 0, 0, 31, 31);
							}
							else if(taille_grille == 4)
							{
								ChargerImage("images/menuFin/4.png", 994, 397, 0, 0, 31, 31);
							}
							else if(taille_grille == 5)
							{
								ChargerImage("images/menuFin/5.png", 994, 397, 0, 0, 31, 31);
							}
							else if(taille_grille == 6)
							{
								ChargerImage("images/menuFin/6.png", 994, 397, 0, 0, 31, 31);
							}
							else if(taille_grille == 7)
							{
								ChargerImage("images/menuFin/7.png", 994, 397, 0, 0, 31, 31);
							}
							else if(taille_grille == 8)
							{
								ChargerImage("images/menuFin/8.png", 994, 397, 0, 0, 31, 31);
							}
							else if(taille_grille == 9)
							{
								ChargerImage("images/menuFin/9.png", 994, 397, 0, 0, 31, 31);
							}
						}
						else if(_X > 849 && _X < 979 && _Y > 256 && _Y < 286)						/* Bouton "1 joueur" */
						{
							nb_joueur = 1;
							ChargerImage("images/menuFin/j1check.png", 849, 256, 0, 0, 130, 30);
							ChargerImage("images/menuFin/j2.png", 1040, 256, 0, 0, 130, 30);
						}
						else if(_X > 1041 && _X < 1171 && _Y > 256 && _Y < 286)							/* Bouton "2 joueurs" */
						{
							nb_joueur = 2;
							ChargerImage("images/menuFin/j1.png", 849, 256, 0, 0, 130, 30);
							ChargerImage("images/menuFin/j2check.png", 1040, 256, 0, 0, 130, 30);
						}
						else if(_X > 817 && _X < 1201 && _Y > 496 && _Y < 568)					/* Bouton "Jouer" */
						{
							clique = 1;
							jeu();
						}	
					}
				}
			}
			else if(_X > 769 && _X < 1153 && _Y > 410 && _Y < 482)
			{
				printf("Quitter\n");
				status_clique = 1;
			}
		}
	}
}



/*--- JEU ---*/
void jeu()
{        
	int i = 0;
    int j = 0;
    int tab [TAILLE_CASE*taille_grille][TAILLE_CASE*taille_grille];

    /*DECLARATION DES VARIABLES*/

    int gagnant = 0;
        
   


    /*-----------------------------------------*/

    printf("Nombre de joueur :  %d\n", nb_joueur);                        /* Affichage après d'avoir fermé l'écran */
    printf("Taille de la grille : %d\n", taille_grille);
    printf("Initialisation des grilles : \n");
    EffacerEcran(BLANC);

    /*-----------------------------------------*/

        
    
    DessinerGrille();
    
   

    if(nb_joueur == 1)
    {
        gagnant = Bloquer_Solo();
        menu_fin(gagnant, nb_joueur);
    }
    else if(nb_joueur == 2)
    {
        gagnant = Bloquer_Vs();
        menu_fin(gagnant, nb_joueur);
    }
}



int main(int argc, char * const argv [])
{
	InitialiserGraphique();

	if(InitialiserGraphique() == 1)
	{
		menu();
		jeu();	

		FermerGraphique();
	}
	else
	{
		printf("Erreur lors de l'initialisation du graphique.\n");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}