#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char * mirroir(const char *s)
{
	int taille = strlen(s);
	char* resultat = malloc(sizeof(char) * taille + 1);
	if (resultat == NULL)
		printf("Erreur malloc\n");

	int i;
	int j = 0;

	for(i = (taille-1); i >= 0; i--){
		resultat[j] = s[i];
		j++;
	}
	resultat[taille] = '\0';
	return resultat;
}

char* saisie(){
	char saisie = 'a';
	char* chaine = malloc(sizeof(char));
	int i = 0;

	printf("Saisir un mot : ");

	while(!isspace((int)saisie)){
		scanf("%c", &saisie);
		printf("carac entré : %c\n", saisie);
		i++;

		if(strlen(chaine) > compteur){
			chaine = realloc(chaine, sizeof(char)*i);
		}
		
		if(!isspace((int)saisie)){
			chaine[i-1] = saisie;
		}
	}
	printf("Taille : %d\n", strlen(chaine));
	return chaine;
}

 int main(int argC, char** argV){
	char* chaine;
	const char* c = argV[0];
	
	if(argC == 1){
		printf("Mauvaise utilisation.\n");
		return 0;
	}

	if(strcmp(c, "-m" == 0)){
		printf("Pouet");
	}

	return 1;
}