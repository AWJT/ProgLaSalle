/************************************************************************/
/*  INF-145 TRAVAIL PRATIQUE No. 2                                      */
/*  PAR   : Renato Mauricio & Yannick Aworet					        */
/************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "t_pile.h"
#include "t_pile_Wilson.h"	
//
/************************************************************************/
/*Obtenir la position d'une valeur										*/
/*Empiler des valeurs et obtenez la position de la première, de la		*/
/*dernière, d’une au centre et finalement, d’une valeur absente.		*/
/*La fonction doit retourner -1 dans ce cas.							*/
void test_wilson_1();

/************************************************************************/
/*Concaténer deux piles													*/
/*Concaténer une pile de plusieurs éléments dans une pile non vide		*/
/*et l’afficher.														*/
void test_wilson_2();

/************************************************************************/
/*Tronquer une pile														*/
/*Tronquer une pile de plusieurs éléments au premier élément, au dernier*/
/*et au centre.  Afficher la pile à chaque fois.						*/
void test_wilson_3();
#if(0)
int main(void)
{
	// Entrez le test souhaité.

	test_wilson_2();

}
#endif
//Test 1: Obtenir la position d'une valeur
void test_wilson_1()
{
	int i;
	int pos;
	t_pile pile;

	pile = init_pile(10);
	// génère une pile de 10 éléments

	for (i = 10; i <= 19; i++)
	{
		// pile allant de 10 a 19
		push(&pile, i);
	}

	printf("La pile est: ");
	affiche_pile(&pile);
	// affiche notre nouvelle pile

	pos = get_pos_valeur(&pile, 10);
	printf("\n\nLa position de la premiere valeur est: %d", pos);
	// affiche la position de la première valeur(0)

	pos = get_pos_valeur(&pile, 19);
	printf("\nLa position de la derniere valeur est: %d", pos);
	// affiche la position de la dernière valeur(9)

	pos = get_pos_valeur(&pile, 12);
	printf("\nLa position de la derniere valeur est: %d", pos);
	// affiche la position de la troisième valeur(2)

	pos = get_pos_valeur(&pile, 100);
	printf("\nLa position de la derniere valeur est: %d", pos);
	// affiche la position d'une valeur absente(-1)

	printf("\n\n");
	system("pause");

	detruire_pile(&pile);

}

//Test 2: Concaténer deux piles
void test_wilson_2()
{
	int i;
	int j;
	t_pile pile_1;
	t_pile pile_2;

	pile_1 = init_pile(10);
	// génère une première pile de 10 éléments

	for (i = 10; i <= 15; i++)
	{
		// pile allant de 10 a 15
		push(&pile_1, i);
	}

	pile_2 = init_pile(10);
	// génère une pile de 10 éléments

	for (j = 20; j <= 26; j++)
	{
		// pile allant de 20 a 26
		push(&pile_2, j);
	}

	printf("La premiere pile est: ");
	affiche_pile(&pile_1);
	// affiche notre nouvelle pile

	printf("\nLa deuxieme pile est: ");
	affiche_pile(&pile_2);
	// affiche notre nouvelle pile

	concat_piles(&pile_1, &pile_2);
	// Va concater les 2 piles

	printf("\n\nLa nouvelle pile concater est: ");
	affiche_pile(&pile_1);
	// affiche la pile apres concatisation

	printf("\n\n");
	system("pause");

	detruire_pile(&pile_1);
	detruire_pile(&pile_2);

}

//Test 3: Tronquer une pile	
void test_wilson_3()
{
	int i;
	int pos;
	t_pile pile_1;

	pile_1 = init_pile(10);
	// génère une pile de 10 éléments

	for (i = 10; i < 20; i++)
	{
		// pile allant de 10 a 20
		push(&pile_1, i);
	}

	pos = get_pos_valeur(&pile_1, 12);
	printf("position de la valeur 12 recherche est: %d\n", pos);
	// affiche la position de la valeur 12

	affiche_pile(&pile_1);
	printf("\n");

	tronquer_pile(&pile_1, 7);
	// Va tronquer la pile de 5

	affiche_pile(&pile_1);
	printf("\n");
	// Affiche la nouvelle pile de 5 éléments
}