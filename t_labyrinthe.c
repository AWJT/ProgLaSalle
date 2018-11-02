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

}

/***********************************************************************/

void etape_des_2piles(t_pile * chemins_W, t_pile * longueurs_W, int nb_lig, int nb_col)
{

}

/***********************************************************************/

void etape_ouverture_chemins(t_labyrinthe * lab, t_pile * chemins_W, t_pile * longueurs_W)
{
}

/***********************************************************************/

void creuser_une_porte(t_labyrinthe * lab, int no_contour)
{
}
/***********************************************************************/