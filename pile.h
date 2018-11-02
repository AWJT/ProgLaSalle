/************************************************************************/
/*  INF-145 TRAVAIL PRATIQUE No. 2                                      */
/*  PAR   : Renato Mauricio & Yannick Aworet					        */
/************************************************************************/

/************************************************************************/
/* Définition pour le programme pile.c								    */
/************************************************************************/
#if !defined ( OK_PILE )
#define OK_PILE 1

typedef int t_element;

typedef struct 
{
	t_element *items;
	int nb_elem;
	int taille;

} t_pile;

//procédure pour afficher les éléments du bas au haut d'une pile
void affiche_pile(const t_pile *);

//fonction pour avoir accès au nombre d'éléments actuel
int get_nbr_elem(const t_pile *);

//fonction qui interroge une position de la pile
int seek_pile(const t_pile *, int pos, t_element *cible);

//fonction destructeur qui met la pile à l'état VIDE
void detruire_pile(t_pile *);

//procédure pour initialiser une pile, la pile sera vide après un appel
//de cette procédure. Peut aussi être utilisée pour vider une pile.
t_pile init_pile(int taille);

//fonction pour vérifier si une pile est pleine
int  pleine(const t_pile *);

//fonction pour vérifier si une pile est vide
int  vide(const t_pile *);

//procédure pour ajouter un élément de plus sur une pile
void push(t_pile *, t_element);

//procédure pour enlever un élément du haut d'une pile
void pop(t_pile *, t_element *);

#endif
