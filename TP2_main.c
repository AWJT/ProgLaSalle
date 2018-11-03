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

//
/************************************************************************/
/*								COSNTANTES								*/
/************************************************************************/



/************************************************************************/
/*								 TYPEDEF								*/
/************************************************************************/

/************************************************************************/
/*	              DECLARATIONS DES FONCTIONS PRIVEES                    */
/************************************************************************/
static int valider_entier(char * msg_sollic, int min, int max);

/************************************************************************/
/*                         PROGRAMME PRINCIPAL                          */
/************************************************************************/
int main(void) {
	system("pause");
}

int valider_entier(char * msg_sollic, int min, int max) {
	int entier_valide;

	printf("\n%s\n", msg_sollic);

	do {
		scanf("%d", &entier_valide);

		if (entier_valide < min || entier_valide > max)
			printf("Erreur: valeur invalide." 
				"Entrez une valeur entre [%d..%d]\n", min, max);

	} while (entier_valide < min || entier_valide > max);

	return entier_valide;

}
