/************************************************************************/
/*  INF-145 TRAVAIL PRATIQUE No. 2                                      */
/*  PAR   : Renato Mauricio & Yannick Aworet					        */
/************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "pile.h"


//procédure pour initializer une pile, la pile sera vide 
t_pile init_pile(int taille)
{
	t_pile new_pile;

	new_pile.items = (t_element*)malloc(taille * sizeof(t_element));
	new_pile.taille = taille;
	new_pile.sommet = PILE_VIDE;

	return new_pile;
}

//fonction pour afficher le contenu d'une pile d'entier
void affiche_pile(const t_pile *p)
{
	int i;

	for (i = p->sommet; i >= 0; i--)
		printf("\n%d : %d", i, p->items[i]);

}
//fonction pour avoir accès au nombre d'éléments actuel
int get_nbr_elem(const t_pile * p)
{
	return p->sommet + 1;
}
//fonction qui interroge une position de la pile
int seek_pile(const t_pile * p, int pos, t_element * cible)
{
	if (pos <= PILE_VIDE || pos > p->sommet)
		return 0;

	*cible = p->items[pos];

	return 1;
}
//fonction destructeur qui met la pile à l'état VIDE
void detruire_pile(t_pile * p) {
	free(p->items);
	p->items = NULL;
	p->taille = 0;
}
//procédure pour ajouter un élément de plus sur une pile
int push(t_pile *p, t_element el)
{
	if (pleine(p)) {
		printf("ERREUR!!! Débordement de pile.");
		return 0;
	}
	p->items[++p->sommet] = el;
	return 1;
}

//fonction pour vérifier si une pile est pleine
int  pleine(const t_pile *p)
{
	return (p->sommet == p->taille - 1);
}

//fonction pour vérifier si une pile est vide
int  vide(const t_pile *p)
{
	return (p->sommet == PILE_VIDE);
}

//procédure pour enlever un élément du haut d'une pile
int pop(t_pile *p, t_element *el)
{
	if (vide(p)) {
		printf("ERREUR!!! Pile vide.");
		return 0;
	}
	//Le sommet  est décrémenté après avoir obtenu l’élément du sommet
	*el = p->items[p->sommet--];
	return 1;
}