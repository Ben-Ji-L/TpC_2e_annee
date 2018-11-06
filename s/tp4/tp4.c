#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<ctype.h>

char* mirroir(const char* s){
	int taille = strlen(s);
	char* result = malloc(sizeof(char)*(taille+1) );
	int i;
	int j = 0;

	for(i = (taille-1); i >= 0; i--){
		result[j] = s[i];
		j ++;
	}
	result[taille] = '\0';
	return result;
}

char* saisie(){
	char saisie = 'a';
	char* chaine = malloc(sizeof(char));
	int compteur = 0;

	printf("Saisir un mot : ");

	while(!isspace((int)saisie)){
		scanf("%c", &saisie);
		printf("carac entré : %c\n", saisie);
		compteur ++;

		if(strlen(chaine) > compteur){
			chaine = realloc(chaine, sizeof(char)*compteur);
		}
		
		if(!isspace((int)saisie)){
			chaine[compteur-1] = saisie;
		}
	}
	printf("Taille chaine : %d\n", strlen(chaine));
	return chaine;
}


int main(int argC, char** argV){
	int i;
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