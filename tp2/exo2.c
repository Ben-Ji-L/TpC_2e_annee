#include <stdio.h>

#include "exo2.h"

int main()
{
	Rat n1 = {1, 2};
    Rat n2 = {5,10};
    Rat n3 = rat_produit(n1, n2);
    printf("%d/%d*%d/%d=%d/%d\n\n", n1.num, n1.den, n2.num,
    n2.den, n3.num, n3.den);

    Rat n4 = rat_somme(n1, n2);
    printf("%d/%d+%d/%d=%d/%d\n\n", n1.num,n1.den, n2.num,
    n2.den, n4.num, n4.den);
  
    Rat n5 = {0, 0};
    Rat liste[] = {n1, n2, n3, n4, n5};
    Rat n6 = rat_plus_petit(liste);
    printf("plus petit: %d/%d\n", n6.num, n6.den);
	return 0;
}


Rat rat_produit(Rat n1, Rat n2)
{
	Rat result;

    result.den = n1.den * n2.den;
    result.num = n1.num * n2.num;

    return result;
}

Rat rat_somme(Rat n1, Rat n2)
{
	Rat result;

	result.den = n1.den * n2.den;
	result.num = n1.num * n2.den + n2.num * n1.den;

	return result;
}

Rat rat_plus_petit(Rat list[])
{
	Rat min = list[0];

	int compteur = 0;

	while(list[compteur].den != 0)
	{
		if (min.num / min.den > list[compteur].num / list[compteur].den) {
            min = list[compteur];
        }

        compteur++;
	}

	return min;
}