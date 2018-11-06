#include <stdio.h>
#include "exo1.h"


int main()
{

	int l[5] = {1, 2, 3, 4, 5};

	int dest[5] = {0};

	int dest_apres[15] = {1, 2, 5, 5, 5};

	afficher(l, 5);

	printf("somme: %d\n", somme(l, 5));

	copie_dans(dest, l, 5);

	afficher(dest, 5);

	ajoute_apres(dest_apres, 5, l, 5);

	afficher(dest_apres, 15);

	return 0;
}

void afficher(int liste[], int taille)
{
	int i = 0;

	while (i < taille)
	{
		printf("%d\n", liste[i]);
		i++;
	}
}

int somme(int liste[], int taille)
{
	int somme = 0;
	int i = 0;

	while (i < taille)
	{
		somme += liste[i];
		i++;
	}
	return somme;
}

void copie_dans(int dest[], int src[], int taille)
{
	int i;

	for (i = 0; i < taille; i++)
	{
		dest[i] = src[i];
	}
}

void ajoute_apres(int dest[], int taille_dest, int src[], int taille_src)
{
	int i;
    for (i = 0 ; i < taille_src ; i++) {
        dest[taille_dest] = src[i];
        taille_dest++;
  	}
}