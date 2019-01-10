#include "tp3.h"

int main()
{
	char str[] = "bonjour";
	char str2[] = "bonsoir";

	printf("taille de la chaine: %d\n", mon_strlen(str));
	printf("taille de la chaine(avec des pointeurs): %d\n\n", mon_strlen2(str));
	
	if (mon_strcmp(str, str2) == 0)
		printf("les chaines sont identiques\n");
	else if (mon_strcmp(str, str2) < 0)
		printf("s1 < s2\n");
	else if (mon_strcmp(str, str2) > 0)
		printf("s1 > s2\n");
	
	

	if (mon_strncmp(str, str2, 2) == 0)
		printf("les chaines sont identiques\n");
	else if (mon_strncmp(str, str2, 2) < 0)
		printf("s1 < s2\n");
	else if (mon_strncmp(str, str2, 2) > 0)
		printf("s1 > s2\n");

	mon_strcat(str, str2);

	printf("%s\n", str);
	
	return 0;
}

// Calcule la taille de la chaine sans le caractere null final.
int mon_strlen(char s[])
{
	int i = 0;
	while(s[i] != '\0')
	{
		i++;
	}

	return i;
}

int mon_strlen2(const char *s)
{
	int i = 0;
    while (s[i] != '\0')
    {
       i++;
    }
    return i;
}

int mon_strcmp(const char * s1, const char * s2)
{
	while (*s1 == *s2 && *s1 && *s2) {
    	s1++;
   		s2++;
  	}

	return *s1 - *s2;
}

// Compare les n 1e octets de la chaine pointée par s1 avec la chaine pointée par s2
int mon_strncmp(const char * s1, const char * s2, int n)
{
	int i = 0;
	while (*s1 == *s2 && *s1 && *s2 && i < n) {
    	s1++;
   		s2++;
   		i++;
  	}

	return *s1 - *s2;
}

// Ajoute la chaine pointée par s1 à la fin de la chaine pointée par s2
char *mon_strcat(char *s1, const char *s2)
{
	int taille = mon_strlen(s1);
  	char *o = s1;
  	s1 += taille;
	
	while (*s2 != '\0') {
    	*s1 = *s2;
    	s1++;
    	s2++;
  	}

  	return o;
}

// cherche un caractère dans une chaîne et renvoie un pointeur sur le caractère, en cherchant depuis le début 
char *mon_strchr(char *s, int c)
{
	while (*s != c && *s != '\0') {
    	s++;
  	}

  	if (*s == '\0') {
    	s = NULL;
  	}
  	return s;
}

// trouve la première occurrence de la chaîne needle dans la chaîne haystack
char *mon_strstr(char *haystack, char *needle)
{
	char *debut = needle;
	int taille = 0;
	while (*needle != '\0') {
    	needle++;
    	taille++;
  	}
  	needle = debut;
  	int i = 0;
  	while (*haystack != '\0' && i < taille) {

    	if (*haystack == *needle) {
      		needle++;
      		i++;
    	}
    	else if (i > 0) {
      	needle = debut;
      	haystack--;
      	i = 0;
    	}
    	else {
      		needle = debut;
      		i = 0;
    	}
    	haystack++;
  	}

  	if (i == taille) {
    	haystack -= i;
  	}
  	return haystack;	
}

char *mon_strstr2(char *haystack, char *needle) {
  char 1elettre = *needle;
  int taille = mon_strlen(needle);
  int resultat = -1;

  while (haystack != NULL && resultat != 0) {
    haystack = mon_strchr(haystack, 1elettre);

    if (haystack != NULL) {
      resultat = mon_strcmp_n(haystack, needle, taille);
      if (resultat != 0) {
        haystack++;
      }
    }
  }
  return haystack;
}
