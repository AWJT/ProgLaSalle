/************************************************************************/
/*  INF-145 TRAVAIL PRATIQUE No. 2                                      */
/*  PAR   : Renato Mauricio & Yannick Aworet					        */
/************************************************************************/

/************************************************************************/
/* D�finition pour le programme pile.c								    */
/************************************************************************/
//
#include "pile.h"

//fonction pour trouver la position d'une valeur
int get_pos_valeur(const t_pile *pile, t_element valeur);

//proc�dure qui met une pile par-dessus une autre sans perdre l�ordre 
void concat_piles(const t_pile *pile_1, t_pile *pile_2);

//proc�dure qui enl�ve tous les �l�ments exc�dentaires au nombre d��l�ments d�une pile
void tronquer_pile(const t_pile *pile, int nbr_elem_final);