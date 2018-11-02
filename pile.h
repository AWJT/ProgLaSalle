/************************************************************************/
/*  INF-145 TRAVAIL PRATIQUE No. 2                                      */
/*  PAR   : Renato Mauricio & Yannick Aworet					        */
/************************************************************************/

/************************************************************************/
/* D�finition pour le programme pile.c								    */
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

//proc�dure pour afficher les �l�ments du bas au haut d'une pile
void affiche_pile(const t_pile *);

//fonction pour avoir acc�s au nombre d'�l�ments actuel
int get_nbr_elem(const t_pile *);

//fonction qui interroge une position de la pile
int seek_pile(const t_pile *, int pos, t_element *cible);

//fonction destructeur qui met la pile � l'�tat VIDE
void detruire_pile(t_pile *);

//proc�dure pour initialiser une pile, la pile sera vide apr�s un appel
//de cette proc�dure. Peut aussi �tre utilis�e pour vider une pile.
t_pile init_pile(int taille);

//fonction pour v�rifier si une pile est pleine
int  pleine(const t_pile *);

//fonction pour v�rifier si une pile est vide
int  vide(const t_pile *);

//proc�dure pour ajouter un �l�ment de plus sur une pile
void push(t_pile *, t_element);

//proc�dure pour enlever un �l�ment du haut d'une pile
void pop(t_pile *, t_element *);

#endif
