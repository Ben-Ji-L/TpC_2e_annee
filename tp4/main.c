#include <stdio.h>
#include <unistd.h>
#include <getopt.h>

#include "tp4.h"

int main(int argc, char *argv[]) {
	int main_saisie = 0;
	int main_miroir = 0;
	int erreur = 0;
	int options;

	while ((options = getopt(argc, argv, "sm")) != -1) {
		switch (options) {
			case 's':
				main_saisie = 1;
				break;
			case 'm':
				main_miroir = 1;
				break;
			default:
				erreur = 1;
		}
	}
	if (!erreur && main_miroir && main_saisie && argv[argc - 1][0] == '-') {
		printf("%s\n", miroir(saisie()));
	} else if (!erreur && main_saisie && argv[argc - 1][0] == '-') {
		printf("%s\n", saisie());
	} else if (!erreur && main_miroir && !main_saisie && argv[argc - 1][0] != '-') {
		printf("%s\n", miroir(argv[argc - 1]));
	} else {
		printf("mauvaise utilisation\n");
		return 1;
	}
	return 0;
}
