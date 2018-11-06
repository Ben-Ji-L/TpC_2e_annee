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
	
	return 0;
}

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
	int i = 0;
 	int result = 0;

	while(s1[i] != '\0' || s2[i] != '\0') {

        if (s1[i] < s2[i]) {
        	result--;
        } else if (s1[i] > s2[i]) {
        	result++;
        }
        i++;
    }

    return result;
}