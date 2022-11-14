#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void inserer(int tab[], int taille, int nb)
{
    int i, j;
    i = 1;
    while (tab[i] < nb)
    {
        i += 1;
    }
    for (j = taille; j < i; j = j - 1)
    {
        tab[j + 1] = tab[j];
    }
    tab[i] = nb;
    taille += 1;
    for (i = 1; i < taille; i++)
    {
        printf("%d \n", tab[i]);
    }
}

int rech_elem(int tab[], int taille, int elem)
{
    int M, pos;
    pos = -2; // Si on renvoie -2, ça ne fonctionne pas
    M = taille / 2;
    do
    {
        if (tab[M] == elem)
        {
            pos = M;
        }
        else if (tab[M] > elem)
        {
            M = M / 2;
            taille = taille / 2;
        }

        else if (tab[M] < elem)
        {
            M += M / 2;
            taille = taille / 2;
        }

    } while (tab[M] != elem && taille != 0);
    if (taille == 0)
    {
        pos = -1;
    }
    return (pos);
}

int main()
{
    int taille, i, nb, elem, pos;
    int tab[100];
    taille = 5;

    tab[1] = 4;
    tab[2] = 6;
    tab[3] = 11;
    tab[4] = 14;
    tab[5] = 20;

    /*printf("Quel nombre inserer ?");
    scanf("%d", &nb);
    inserer(tab, taille, nb);*/

    printf("Quel nombre chercher ?");
    scanf("%d", &elem);
    pos = 0;
    pos = rech_elem(tab, taille, elem);
    printf("Le nombre est en position %d", pos); // Fonctionne si le nombre n'est pas dans le tableau
    return 0;
}