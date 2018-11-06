typedef struct rat
{
	int den;
	int num;
} Rat;

Rat rat_produit(Rat n1, Rat n2);

Rat rat_somme(Rat n1, Rat n2);

Rat rat_plus_petit(Rat liste[]);