/************************************************************************/
/*  INF-145 TRAVAIL PRATIQUE No. 2                                      */
/*  PAR   : Renato Mauricio & Yannick Aworet					        */
/************************************************************************/

/************************************************************************/
/* Définition pour le programme pile.c								    */
/************************************************************************/
//
#include "pile.h"

//fonction pour trouver la position d'une valeur
int get_pos_valeur(const t_pile *pile, t_element valeur);

//procédure qui met une pile par-dessus une autre sans perdre l’ordre 
void concat_piles(const t_pile *pile_1, t_pile *pile_2);

//procédure qui enlève tous les éléments excédentaires au nombre d’éléments d’une pile
void tronquer_pile(const t_pile *pile, int nbr_elem_final);