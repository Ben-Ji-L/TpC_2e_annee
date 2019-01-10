#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int traiter(int f, int *car, int *mot, int *lig ) {
  char buffer[80];
  int c = 0;

  while (c != EOF) {
    c = read(f, &buffer, 80);
    if (isspace(c)) {
      mot++;
    } else if (isspace(c) && !isspace(c+1)) {
      lig++;
    } else {
      car++;
    }
  }
  printf("caracteres : %d mots : %d lignes : %d\n", *car, *mot, *lig);
  return 0;
}

int main() {
  int fd;
  int car, m, l;
  fd = open("Makefile", O_RDONLY);
  printf("fichier bien ouvert\n");
  traiter(fd, &car, &m, &l);
  close(fd);
  return 0;
}
