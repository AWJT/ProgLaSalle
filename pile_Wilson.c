/************************************************************************/
/*  INF-145 TRAVAIL PRATIQUE No. 2                                      */
/*  PAR   : Renato Mauricio & Yannick Aworet					        */
/************************************************************************/

/************************************************************************/
/* Définition pour le programme pile.c								    */
/************************************************************************/
#include <stdio.h>
#include "pile_Wilson.h"


//fonction pour trouver la position d'une valeur
int get_pos_valeur(const t_pile *pile, t_element valeur)
{
	int pos = PILE_VIDE;;

	for (pos = 0; pos < get_nbr_elem(pile); pos++) {
		if (valeur == pile->items[pos])
			return pos;
	}

	return pos;
}

/*********************************************************************************/

//procédure qui met une pile par-dessus une autre sans perdre l’ordre 
void concat_piles(t_pile *pile_1, const t_pile *pile_2)
{
	int i;
	int espace_libre_pile_1;
	int nouvelle_taille;
	t_element tampon;

	espace_libre_pile_1 = get_taille(pile_1) - get_nbr_elem(pile_1);

	if (get_nbr_elem(pile_2) >= espace_libre_pile_1) {
		nouvelle_taille = get_taille(pile_1) + get_nbr_elem(pile_2);
		pile_1->items = (t_element *)realloc(pile_1->items, nouvelle_taille
			* sizeof(t_element));
		pile_1->taille = nouvelle_taille;
	}

	for (i = 0; i < get_nbr_elem(pile_2); i++)
	{
		seek_pile(pile_2, i, &tampon);
		push(pile_1, tampon);
	}
}

/*****************************************************************************************/

//procédure qui enlève tous les éléments excédentaires au nombre d’éléments d’une pile
void tronquer_pile(t_pile *pile, int nbr_elem_final)
{
	int nb_elem_retirer;
	t_element elem_temp;

	nb_elem_retirer = get_nbr_elem(pile) - nbr_elem_final;

	while (nb_elem_retirer) {
		pop(pile, &elem_temp);
		nb_elem_retirer--;
	}

}