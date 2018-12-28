#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tp4.h"

char *miroir(const char *s) {
  int taille = strlen(s);
  char *resultat = calloc(taille + 1, sizeof(char));
  if (resultat == NULL) {
    return resultat;
  }

  int i;
  for (i = taille - 1; i >= 0; i--) {
    *resultat = s[i];
    resultat++;
  }
  *resultat = '\0';

  resultat = resultat - taille;
  return resultat;
}

char* saisie() {
  int nb = 50;
  char* resultat = calloc(nb, sizeof(char));
  if (resultat == NULL) {
    return resultat;
  }

  int nbChar = 0;
  char carac = getchar();
  while (!isspace(carac)) {
    if (nbChar > nb-1) {
      nb += 50;
      resultat = realloc(resultat, nb * sizeof(char));
      if (resultat == NULL) {
        return resultat;
      }
    }

    resultat[nbChar] = carac;
    nbChar++;
    carac = getchar();
  }

  resultat[nbChar] = '\0';
  return resultat;
}

/* int main(void) {
  printf("%s\n", miroir("Bonjour"));
  printf("%s\n", saisie());

  return 0;
}*/
