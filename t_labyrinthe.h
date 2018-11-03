/*  INF-145 TRAVAIL PRATIQUE No. 2                                      */
/*  PAR   : Renato Mauricio & Yannick Aworet					        */
/************************************************************************/

/************************************************************************/
/* Définition pour le programme t_labyrinthe.c						    */

/************************************************************************/
/*								COSNTANTES								*/
/************************************************************************/
#define NB_LIG 4
#define NB_COL 4
#define MUR    1
#define LIBRE  0

//typedef int t_labyrinthe[2 * NB_LIG + 1][2 * NB_COL + 1];

typedef enum { NORD = 1, SUD, OUEST, EST } t_direction;

typedef struct
{
	//La matrice du labyrinthe
	int ** matrice_laby;
	//les dimensions (M, N) du labyrinthe théorique
	int m, n;
	//contient le nombre total de « positions » possibles (M*N)
	int nb_pos;

} t_labyrinthe;

/************************************************************************/
/*	             DECLARATIONS DES FONCTIONS PUBLIQUE                    */
/************************************************************************/

t_labyrinthe init_laby(int nb_lig, int nb_col);

void etape_des_2piles(t_pile * chemins_W, t_pile * longueurs_W, int nb_lig,
	int nb_col);

void etape_ouverture_chemins(t_labyrinthe * lab, t_pile * chemins_W,
	t_pile * longueurs_W);

void creuser_une_porte(t_labyrinthe * lab, int no_contour);

void detruire_laby(t_labyrinthe * laby);