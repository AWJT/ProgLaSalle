/************************************************************************/
/*  INF-145 TRAVAIL PRATIQUE No. 2                                      */
/*  PAR   : Renato Mauricio & Yannick Aworet					        */
/************************************************************************/

/************************************************************************/
/* Ce programme permet de simuler un labyrinthe.					    */
/************************************************************************/

#define _CRT_SECURE_NO_WARNINGS   
#include<stdio.h>
#include<stdlib.h>
#include "t_pile.h"
#include "t_labyrinthe.h"

/************************************************************************/
/*	              DECLARATIONS DES FONCTIONS PRIVEES                    */
/************************************************************************/
static int choix_v_chemin_Wilson(const t_pile *chemins_W, int nb_val);
static int ajouter_chemin_Wilson(t_pile * chemins_W, int nb_lig, int nb_col);


/************************************************************************/
/*	              DEFINITION DES FONCTIONS PRIVEES                      */
/************************************************************************/

/*Cette fonction est utilisée pour obtenir une valeur « v » aléatoire qui 
  ne fait pas déjà partie de la pile « chemins_W ». Elle reçoit la pile ainsi
  que le nombre de valeurs (M*N).*/
/**/
int choix_v_chemin_Wilson(const t_pile * chemins_W, int nb_val)
{

}

/***********************************************************************/

int ajouter_chemin_Wilson(t_pile * chemins_W, int nb_lig, int nb_col)
{
	return 0;
}

/************************************************************************/
/*	              DEFINITION DES FONCTIONS PUBLIQUE                     */
/************************************************************************/

t_labyrinthe init_laby(int nb_lig, int nb_col)
{
	int i, j;
	t_labyrinthe laby;

	laby.matrice_laby = (int **)malloc((2 * nb_lig + 1) * sizeof(int *));

	for (i = 0; i < (2 * nb_lig + 1); i++) {
		laby.matrice_laby[i] = (int *)malloc((2 * nb_col + 1) * sizeof(int));
	}

	//les cases sont toutes initialisées à la valeur MUR
	for (i = 0; i < (2 * nb_lig + 1); i++) {
		for (j = 0; j < (2 * nb_col + 1); j++) {
			laby.matrice_laby[i][j] = MUR;
		}
	}


	laby.m = nb_lig;
	laby.n = nb_col;
	laby.nb_pos = laby.m * laby.n;

	return laby;

}

/***********************************************************************/

void etape_des_2piles(t_pile * chemins_W, t_pile * longueurs_W, int nb_lig, int nb_col)
{

}

/***********************************************************************/
/*Cette procédure réalise l'algorithme donné plus haut en étape 2 et qui permet le  
positionnement de cases LIBRE dans la matrice représentant le labyrinthe.
L’algorithme implémenté ici vide les deux piles reçues en paramètres et réalise 
l’assignation à LIBRE des cases consécutives aux valeurs dépilées de « chemins_W ».
La  procédure réalise l'algorithme et ne retourne rien.
*/
void etape_ouverture_chemins(t_labyrinthe * lab, t_pile * chemins_W, t_pile * longueurs_W)
{
	while (!vide(chemins_W)) {

	}
}

/***********************************************************************/

/*Cette procédure est utilisée pour faire la porte d’entrée 
et de sortie autour du labyrinthe.*/
void creuser_une_porte(t_labyrinthe * lab, int no_contour)
{
	//Exemple
	//pour choisir les valeurs 1(NORD) a 4(EST) au hasard
	t_direction contour;

	mt_srandSys();
	
	contour = mt_randi(OUEST) + 1;


}
void detruire_laby(t_labyrinthe * laby)
{
	int i;
	int taille = 2 * laby->n + 1;

	for (i = 0; i < taille; i++) {
		free(laby->matrice_laby[i]);
	}
	free(laby->matrice_laby);
	laby->matrice_laby = NULL;

}
/***********************************************************************/