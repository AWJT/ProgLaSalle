/*  INF-145 TRAVAIL PRATIQUE No. 2                                      */
/*  PAR   : Renato Mauricio & Yannick Aworet					        */
/************************************************************************/

/************************************************************************/
/* Définition pour le programme t_labyrinthe.c						    */

#define NB_LIG 5
#define NB_COL 8


typedef struct
{
	//La matrice du labyrinthe
	int matrice_laby[NB_LIG][NB_COL];
	//les dimensions (M, N) du labyrinthe théorique
	int m, n;
	//contient le nombre total de « positions » possibles (M*N)
	int nb_pos;

} t_labyrinthe;

/************************************************************************/
/*	             DECLARATIONS DES FONCTIONS PUBLIQUE                    */
/************************************************************************/

t_labyrinthe init_laby(int nb_lig, int nb_col);
//-------------------------------------------------------------------------
void etape_des_2piles(t_pile * chemins_W, t_pile * longueurs_W, int nb_lig,
	int nb_col);
//-------------------------------------------------------------------------
void etape_ouverture_chemins(t_labyrinthe * lab, t_pile * chemins_W,
	t_pile * longueurs_W);
//-------------------------------------------------------------------------
void creuser_une_porte(t_labyrinthe * lab, int no_contour);
//-------------------------------------------------------------------------