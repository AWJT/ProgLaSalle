/************************************************************************/
/*  INF-145 TRAVAIL PRATIQUE No. 2                                      */
/*  PAR   : Renato Mauricio & Yannick Aworet					        */
/************************************************************************/

/************************************************************************/
/* Définition pour le programme pile.c								    */
/************************************************************************/
#include <stdio.h>

#include "pile_Wilson.h"
//
//fonction pour trouver la position d'une valeur
int get_pos_valeur(const t_pile *pile, t_element valeur)
{
	int val = -1;
	int i = 0;

	while ((val == -1) && (i <= pile->taille))  /**/
	{
		if (valeur == pile->items[i])   /**/
		{
			val = i;
		}
		i++;
	}

	return val;
}

/*********************************************************************************/
//procédure qui met une pile par-dessus une autre sans perdre l’ordre 
void concat_piles(t_pile *p_dest,const t_pile *p_src)
{
	int sommet_pile_1;
	int sommet_pile_2;
	int i;
	int tampon = 0;

	sommet_pile_1 = get_nbr_elem(p_dest);
	sommet_pile_2 = get_nbr_elem(p_src);
	
	if (p_dest->nb_elem < p_dest->taille)
	{ 
		for (i = 0; i < sommet_pile_2; i++)
		{
			seek_pile(p_src, i, &tampon);
			push(p_dest, tampon);
		}
	}

}

/*****************************************************************************************/
//procédure qui enlève tous les éléments excédentaires au nombre d’éléments d’une pile
void tronquer_pile(t_pile *pile, int nbr_elem_final)
{
	int i;
	t_element tampon;

	i = get_nbr_elem(pile) - nbr_elem_final;

	while(i != 0)
	{
		pop(pile, &tampon);
		i--;
	}
}