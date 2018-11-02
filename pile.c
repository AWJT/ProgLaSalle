/************************************************************************/
/*  INF-145 TRAVAIL PRATIQUE No. 2                                      */
/*  PAR   : Renato Mauricio & Yannick Aworet					        */
/************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "pile.h"


//procédure pour afficher les éléments du bas au haut d'une pile
void affiche_pile(const t_pile *p)
{
	int i;

	for (i = 0; i < p->nb_elem; i++)
	{
		printf("%d ", p->items[i]);
	}
}

//fonction pour avoir accès au nombre d'éléments actuel
int get_nbr_elem(const t_pile *p)
{
	int nbr_element;

	nbr_element = p->nb_elem;

	return nbr_element;
}

//fonction qui interroge une position de la pile
int seek_pile(const t_pile *p, int pos, t_element *cible)
{
	int seek = 0;

	if (pos <= p->nb_elem)
	{
		*cible = p->items[pos];
		seek = 1;
	}

	return seek;
}

//fonction destructeur qui met la pile à l'état VIDE
void detruire_pile(t_pile *p)
{
	free(p->items);
	p->items = NULL;
	p->nb_elem = 0;
	p->taille = 0;

}

//procédure pour initializer une pile, la pile sera vide 
t_pile init_pile(int taille)
{
	t_pile new_pile;

	new_pile.items = (t_element*) malloc(taille * sizeof(t_element));
	
	new_pile.nb_elem = 0;

	new_pile.taille = taille;

	if (new_pile.items==NULL)
	{
		new_pile.taille = 0;
	}
	
return new_pile;
}

//fonction pour vérifier si une pile est pleine
int  pleine(const t_pile *p)
{
	return (p->nb_elem == p->taille);
}

//fonction pour vérifier si une pile est vide
int  vide(const t_pile *p)
{
	return (p->nb_elem == 0);
}

//procédure pour ajouter un élément de plus sur une pile
void push(t_pile *p, t_element el)
{
	if (pleine(p)) {
		
	}
	else {
		p->items[p->nb_elem] = el;
		p->nb_elem++;
	}
}

//procédure pour enlever un élément du haut d'une pile
void pop(t_pile *p, t_element *el)
{
	if (vide(p)) {
		
	}
	else {
		p->nb_elem--;
		*el = p->items[p->nb_elem];
	}
}