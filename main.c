#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#define TITRE_JEU "Blocus"
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
int colonne = 0, ligne = 0;
int grille_status = 0;
int clique = 0;			/* Detection du clique */


/*Création du menu*/
int menu() {

	char nb_joueur_affichage [40];
	char string_grille[2];
	
	
	CreerFenetre((Maxx()-LARGEUR_FENETRE)/2, (Maxy()-HAUTEUR_FENETRE)/2, LARGEUR_FENETRE, HAUTEUR_FENETRE);		/* Création d'une fenêtre centrée sur l'écran */
	ChoisirTitreFenetre(TITRE_JEU " par " AUTEURS);																/* Nomme la fenêtre */

	EcrireTexte(10, 100, "Taille de la grille :", 1);		/* Taille de la grille */
	EcrireTexte (250, 100, "-", 2); 						/* Bouton "-" */
	DessinerRectangle (236, 68,40, 40);
	EcrireTexte (400, 100, "+", 2);							/* Bouton "+" */
	DessinerRectangle (387, 68, 40, 40);
	EcrireTexte (10, 150, "Nombre de joueur(s) : ", 1);		/* Nombre de joueurs */
	EcrireTexte (250, 150, "1 joueur", 1);					/* Bouton "1 joueur" */
	DessinerRectangle (236, 120, 100, 45);
	EcrireTexte (400, 150, "2 joueurs", 1);					/* Bouton "2 joueurs" */
	DessinerRectangle (387, 120, 100, 45);

	/*Bouton JOUER*/
	ChoisirCouleurDessin(BLEU_CIEL);
	RemplirRectangle(128, 576, 1024, 72);
	ChoisirCouleurDessin(NOIR);
	DessinerRectangle(128, 576, 1024, 72);

	EcrireTexte(640 - TailleChaineEcran("JOUER", 2) / 2, 576 + 47, "JOUER", 2);
	sprintf(string_grille, "%d", taille_grille);
	EcrireTexte(320, 100, string_grille, 2);

	while(clique == 0){
		if(SourisCliquee()) {
			if(_X > 236 && _X < 276 && _Y > 68 && _Y < 108){			/* Bouton "-" */
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

			if(_X >= 128 && _X <= 1152 && _Y >= 576 && _Y <= 648)		/* Bouton "Jouer" */
			{
				clique = 1;
			}
		}
	}	
	return taille_grille;
	return nb_joueur;
}


/*Déssiner grille*/
void DessinerGrille (){
	for (colonne = 0; colonne < taille_grille*TAILLE_CASE; colonne = colonne + TAILLE_CASE){
		for (ligne = 0; ligne < taille_grille*TAILLE_CASE; ligne = ligne + TAILLE_CASE){
			DessinerRectangle (colonne, ligne, TAILLE_CASE,TAILLE_CASE);
		}
	}
}

void jeu(){
		
	/*DECLARATION DES VARIABLES*/

	/*TERM*/

	int i = 0, j = 0, a,b, choix, result;

	int tableau [taille_grille][taille_grille];
	int compte = 0;


	/*BBG*/
	int x, y;
	int grille_status = 0;
	int tab [TAILLE_CASE*taille_grille][TAILLE_CASE*taille_grille];
	
	/*---------------------------------------------------------------*/

	printf("Nombre de joueur :  %d\n", nb_joueur);						/* Affichage après d'avoir fermé l'écran */
	printf("Taille de la grille : %d\n", taille_grille);
	EffacerEcran(BLANC);

	
	/*TABLEAU TERMINAL*/
	// for (i = 0; i < taille_grille; i++){
	// 	for (j = 0; j < taille_grille; j++){
	// 		tableau [i][j] = 0;
	// 		printf("tableau [%d][%d]\n", i, j);
	// 		printf ("%d", tableau [i][j]);
	// 	}
	// }

    // while (choix != 3){
    //     printf("\n");
    //     printf("1) continuer \n 2) quitter \n");
    //     result = scanf("%d", &choix);
       

    //     if (choix == 1){

    //         printf("coordonée a et b = ");
    //         scanf ("%d %d", &a, &b);
            
    //         for (i = 0; i < taille_grille; i++){
    //             for (j = 0; j < taille_grille; j++){
                    
    //                 if ( (tableau [a][b] == 1) && (tableau [a][b] !=0)){
    //                     printf("erreur\n");
                        
    //                 }
    //                 if ( (tableau [a][b] == 0) && (tableau[a][b]!=1)){
    //                     printf ("ok\n");
    //                     tableau [a][b]=1;
    //                 }
    //             }
    //         }

    //         printf ("status grille de case a et b = %d\n", tableau [a][b]);


    //         for (i = 0; i < taille_grille; i++){
    //             for (j = 0; j < taille_grille; j++){
    //                 printf ("tableau [%d] [%d] = %d\n", i, j, tableau [i][j]);
    //             }
    //         }
    //     }
    // }

		
	// for (i = 0; i < taille_grille*TAILLE_CASE; i = i + TAILLE_CASE){
	// 		for (j = 0; j < taille_grille*TAILLE_CASE; j = j + TAILLE_CASE){	
				
	// 			//grille_status = 0;

	// 			//tab [i = i + TAILLE_CASE][j = j + TAILLE_CASE] = 0;

	// 			//  if ( (i ==160) && (j ==160)){
	// 			// 		ChoisirCouleurDessin (MARRON);
	// 			// 		RemplirRectangle (i,j, TAILLE_CASE,TAILLE_CASE);
	// 			// 		grille_status = 1;*/
	// 					DessinerGrille();
	// 			//}
	// 		}
	// }

	/*------------------------------------------------------------------------*/

	DessinerGrille();

	for (i = 0; i < taille_grille*TAILLE_CASE; i = i + TAILLE_CASE){
		for (j = 0; j < taille_grille*TAILLE_CASE; j = j + TAILLE_CASE){
			tab [i][j]=0;
			printf (" [%d][%d] = %d\n", i , j, tab [i][j] );
		}
	}

	while (1){
	

		while(! SourisCliquee()){
			DessinerGrille();
			SourisPosition();

			/*STATUS DES CASES*/
			for(x = 0; x < TAILLE_CASE*taille_grille; x = x + TAILLE_CASE){
				for(y = 0; y < TAILLE_CASE*taille_grille; y = y + TAILLE_CASE){
					if(x < _X && y < _Y){
					
						ChoisirCouleurDessin(BLANC);
						RemplirRectangle(0, 0, 80*taille_grille, 80*taille_grille);
						tab [x][y]= 1;
						
						ChoisirCouleurDessin(ROUGE);
						RemplirRectangle(x, y, 80, 80);
						
						
					}
				}
			// 	/*GESTION DES COULEURS*/
			// if (SourisCliquee ()){
			// 	compte ++;
			// 	printf ("Nombre de clique %d\n", compte);
			// }
			}

						

		}
			
		DessinerGrille ();

		

		for (i = 0; i < taille_grille*TAILLE_CASE; i = i + TAILLE_CASE){
			for (j = 0; j < taille_grille*TAILLE_CASE; j = j + TAILLE_CASE){
				
				printf (" [%d][%d] = %d\n", i , j, tab [i][j] );
			}
		}

		/*CONDITION TAB pour colorer*/

		// for(x = 0; x < TAILLE_CASE*taille_grille; x = x + TAILLE_CASE){
		// 	for(y = 0; y < TAILLE_CASE*taille_grille; y = y + TAILLE_CASE){
		// 		if ( tab [x][y]== 1 ){
		// 			ChoisirCouleurDessin(MARRON);
		// 			RemplirRectangle(x, y, 80, 80);
		// 		}
		// 		if (tab [x][y] == 0) {
		// 			ChoisirCouleurDessin(BLANC);
		// 			RemplirRectangle(x, y, 80, 80);
		// 		}
		// 	}
		// }

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
