/************************************************************************/
/*  INF-145 TRAVAIL PRATIQUE No. 2                                      */
/*  PAR   : Renato Mauricio & Yannick Aworet					        */
/************************************************************************/

/************************************************************************/
/* Ce programme permet de simuler un labyrinthe.					    */
/************************************************************************/

#define _CRT_SECURE_NO_WARNINGS   
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#include "mtwister.h"	/*inclure le module externe à la compilation pour
						  simuler des valeurs aléatoires.*/

/************************************************************************/
/*								COSNTANTES								*/
/************************************************************************/
#define NB_LIG 5
#define NB_COL 8
#define MUR    1
#define LIBRE  0


/************************************************************************/
/*								 TYPEDEF								*/
/************************************************************************/
/* Description: Tableau de données pour représenter le "labyrinthe"		*/
/*			    c'est a dire la matrice avec les chemins et les murs.	*/
/* Taille: La taille du tableau va constamment varier dépendant du		*/
/*		   de nombre de colonne et de ligne précédement choisit.		*/
typedef int t_labyrinthe[2 * NB_LIG + 1][2 * NB_COL + 1];
typedef enum { NORD=1, SUD=2, OUEST=3, EST=4 } t_direction;
/************************************************************************/
/*	                 DECLARATIONS DES FONCTIONS                         */
/************************************************************************/
void remplir_de_murs(t_labyrinthe, int m, int n);
void afficher_tableau(t_labyrinthe, int m, int n);
int voisine_nord(int k, int n);
int voisine_ouest(int k, int n);
int voisine_est(int k, int n);
int voisine_sud(int k, int m, int n);
int trouver_voisine(int k, int direction, int m, int n);
void allees_aleatoires(t_labyrinthe labyrinthe, int m, int n);
void mettre_postion_libre(t_labyrinthe labyrinthe, int k, int m, int n, int direction);
void afficher_layrinthe(t_labyrinthe labyrinthe, int m, int n);


/************************************************************************/
/*                         PROGRAMME PRINCIPAL                          */
/************************************************************************/
int main(void)
{
	mt_srandSys();

	t_labyrinthe labyrinthe = {0} ;

	remplir_de_murs(labyrinthe, NB_LIG, NB_COL);

	allees_aleatoires(labyrinthe, NB_LIG, NB_COL);
	afficher_tableau(labyrinthe, NB_LIG, NB_COL);

	afficher_layrinthe(labyrinthe, NB_LIG, NB_COL);

	system("pause");
}

/************************************************************************/
/*                       DEFINITIONS DES FONCTIONS                      */
/************************************************************************/
void remplir_de_murs(t_labyrinthe labyrinthe, int m, int n)
{
	int i;
	int j;

	for (i = 0; i < (2 * n + 1); i++)
	{
		for (j = 0; j < (2 * m + 1); j++)
		{
			labyrinthe[i][j] = MUR;
		}
	}
}

/************************************************************************/
void afficher_tableau(t_labyrinthe labyrinthe, int m, int n)
{
	int i;
	int j;

	printf("\n");

	for (i = 0; i < (2 * n + 1); i++)
	{
		for (j = 0; j < (2 * m + 1); j++)
		{
			printf("%d ", labyrinthe[i][j]);
		}

		printf("\n");
	}

}

/************************************************************************/
int voisine_nord(int k, int n)
{
	int voisine_n = k;

	if (k < n)
	{
		voisine_n = -1;
	}
	else
	{
		voisine_n = k - n;
	}
	return voisine_n;
}

/************************************************************************/
int voisine_ouest(int k, int n)
{
	int voisine_o = k;

	if ((k % n) == 0)
	{
		voisine_o = -1;
	}
	else
	{
		voisine_o = k - 1;
	}
	return voisine_o;
}

/************************************************************************/
int voisine_est(int k, int n)
{
	int voisine_e = k;

	if ((k % n) == (n -1))
	{
		voisine_e = -1;
	}
	else
	{
		voisine_e = k +1;
	}
	return voisine_e;
}

/************************************************************************/
int voisine_sud(int k, int m, int n)
{
	int voisine_s = k;

	if ((k + n) > ((m * n) - 1))
	{
		voisine_s = -1;
	}
	else
	{
		voisine_s = k + n;
	}
	return voisine_s;
}

/************************************************************************/
void allees_aleatoires(t_labyrinthe labyrinthe, int m, int n)
{
	int i;
	int k = 0;
	int max;
	int cycle_max = m * n;
	int dir_aleatoire;
	int longueur_aleatoire;
	t_direction direction;

	if (m > n)
	{
		max = m;
	}
	else
	{
		max = n;
	}

	for (i = 0; i < cycle_max; i++)
	{
		k = (mt_randi(cycle_max)) - 1;

		dir_aleatoire = mt_randi(EST);

		longueur_aleatoire = (mt_randi(max-1)) + 1;

		while ((k != -1) && (longueur_aleatoire != 0))
		{
			mettre_postion_libre(labyrinthe, k, m, n, dir_aleatoire);

			k = trouver_voisine(k, dir_aleatoire, m, n);

			longueur_aleatoire--;
		}

	}
}

/************************************************************************/
int trouver_voisine(int k, int direction, int m, int n)
{
	int nouvelle_voisine;

	switch (direction)
	{
		case NORD	: nouvelle_voisine = voisine_nord(k, n);
		break;

		case OUEST	: nouvelle_voisine = voisine_ouest(k, n);
		break;

		case EST	: nouvelle_voisine = voisine_est(k, n);
		break;
	
		case SUD	: nouvelle_voisine = voisine_sud(k, m ,n);
		break;
	}
	return nouvelle_voisine;
}

/************************************************************************/
void mettre_postion_libre(t_labyrinthe labyrinthe, int k, int m, int n, int direction)
{
	int ligne = 0;
	int colonne = 0;
	int voisine = 0;

	ligne = 2 * (k / n) + 1;
	colonne = 2 * (k % n) + 1;

	labyrinthe[ligne][colonne] = 0;

	switch (direction)
	{
		case NORD	: labyrinthe[ligne - 1][colonne] = 0;
		break;

		case OUEST	: labyrinthe[ligne][colonne - 1] = 0;
		break;

		case EST	: labyrinthe[ligne][colonne + 1] = 0;
		break;

		case SUD	: labyrinthe[ligne + 1][colonne] = 0;
		break;
	}
}

/************************************************************************/
void afficher_layrinthe(t_labyrinthe labyrinthe, int m, int n)
{
	int i;
	int j;
	int espace;

	printf("\n");

	for (i = 0; i < (2 * n + 1); i++)
	{
		for (espace = 0; espace < (50 - (m / 2)); espace++)
		{
			printf(" ");
		}
		for (j = 0; j < (2 * m + 1); j++)
		{
			if (labyrinthe[i][j] == 1)
			{
				printf("%c%c", 219, 219);
			}
			else
			{
				printf("%c%c", 32, 32);
			}
		}

		printf("\n");
	}

}