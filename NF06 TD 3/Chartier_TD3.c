#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void exo35()
{
    int taille, i, ind1, ind2, inter;
    printf("Saisissez la longueur du tableau\n");
    scanf("%d", &taille);
    int tab[taille];
    for (i = 1; i <= taille; i++)
    {
        printf("Entrez la valeur %d\n", i);
        scanf("%d", &tab[i]);
    }
    for (i = 1; i <= taille; i++)
    {
        printf("%d\n", tab[i]);
    }

    printf("Entrer l'indice de la premiere valeur à echanger (de 1 à %d\n", taille);
    scanf("%d", &ind1);
    printf("Entrer l'indice de la deuxieme valeur à echanger (de 1 à %d\n", taille);
    scanf("%d", &ind2);

    inter = tab[ind1];
    tab[ind1] = tab[ind2];
    tab[ind2] = inter;

    for (i = 1; i <= taille; i++)
    {
        printf("%d \n", tab[i]);
    }
}

void exo36()
{
    int maj = 0, min = 0, spaces = 0, i, size;
    char car;
    printf("Combien de caractères dans la phrase ?");
    scanf("%d", &size);
    printf("Entrer un texte\n");

    for (i = 0; i <= size; i++)
    {
        scanf("%c", &car);
        if ('a' <= car && car <= 'z')
        {
            min++;
        }
        else if ('A' <= car && car <= 'Z')
        {
            maj++;
        }
        else if (car == ' ')
        {
            spaces++;
        }
    }
    printf("Il y a %d majuscules, %d minuscules et %d espaces", maj, min, spaces);
}

void exo37()
{
    // On considère des matrices carrées de mêmes dimensions car ce n'est pas possible sinon
    int taille, i, j, k;
    printf("Quelle est la taille des matrices (carrées) ?");
    scanf("%d", &taille);
    float mat1[taille][taille], mat2[taille][taille];
    float sum[taille][taille], diff[taille][taille], prod[taille][taille];
    // Remplissage matrice 1
    for (i = 1; i <= taille; i++)
    {
        for (j = 1; j <= taille; j++)
        {
            printf("Entrer l'element %d,%d de la matrice 1\n", i, j);
            scanf("%f", &mat1[i][j]);
        }
    }
    // Remplissage matrice 2
    for (i = 1; i <= taille; i++)
    {
        for (j = 1; j <= taille; j++)
        {
            printf("Entrer l'element %d,%d de la matrice 2\n", i, j);
            scanf("%f", &mat2[i][j]);
        }
    }
    // Addition
    for (i = 1; i <= taille; i++)
    {
        for (j = 1; j <= taille; j++)
        {
            sum[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    printf("Resultat de l'addition :\n");
    for (i = 1; i <= taille; i++)
    {
        for (j = 1; j <= taille; j++)
        {
            printf("%f   ", sum[i][j]);
        }
        printf("\n");
    }

    // Soustraction
    for (i = 1; i <= taille; i++)
    {
        for (j = 1; j <= taille; j++)
        {
            sum[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
    printf("Resultat de la soustraction :\n");
    for (i = 1; i <= taille; i++)
    {
        for (j = 1; j <= taille; j++)
        {
            printf("%f   ", sum[i][j]);
        }
        printf("\n");
    }

    // Multiplication
    for (i = 1; i <= taille; i++)
    {
        for (j = 1; j <= taille; j++)
        {
            prod[i][j] = 0;
            for (k = 1; k <= taille; k++)
            {
                prod[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    printf("Resultat de la multiplication :\n");
    for (i = 1; i <= taille; i++)
    {
        for (j = 1; j <= taille; j++)
        {
            printf("%f   ", prod[i][j]);
        }
        printf("\n");
    }
}

typedef struct
{
    double reel, imag;
} Cartesien;
typedef struct
{
    double mod, arg;
} Polaire;
typedef struct
{
    Cartesien cart;
    Polaire pol;
} Cplx;

Polaire CartToPol(Cartesien fcart)
{
    Polaire fpol;
    fpol.mod = sqrt(fcart.reel * fcart.reel + fcart.imag * fcart.imag);
    fpol.arg = atan(fcart.imag / fcart.reel);
    return fpol;
}
Cartesien PolToCart(Polaire fpol)
{
    Cartesien fcart;
    fcart.reel = fpol.mod * cos(fpol.arg);
    fcart.imag = fpol.mod * sin(fpol.arg);
    return fcart;
}
Cplx SommeCplx(Cplx nb1, Cplx nb2)
{
    Cplx Somme;
    Somme.cart.reel = nb1.cart.reel + nb2.cart.reel;
    Somme.cart.imag = nb2.cart.imag + nb2.cart.imag;
    Somme.pol = CartToPol(Somme.cart);
    return Somme;
}
Cplx SousCplx(Cplx nb1, Cplx nb2)
{
    Cplx Diff;
    Diff.cart.reel = nb1.cart.reel - nb2.cart.reel;
    Diff.cart.imag = nb2.cart.imag - nb2.cart.imag;
    Diff.pol = CartToPol(Diff.cart);
    return Diff;
}
Cplx MultCplx(Cplx nb1, Cplx nb2)
{
    Cplx Produit;
    Produit.pol.mod = nb1.pol.mod * nb2.pol.mod;
    Produit.pol.arg = nb1.pol.arg + nb2.pol.arg;
    Produit.cart = PolToCart(Produit.pol);
}
Cplx DivCplx(Cplx nb1, Cplx nb2)
{
    Cplx Quotient;
    Quotient.pol.mod = nb1.pol.mod / nb2.pol.mod;
    Quotient.pol.arg = nb1.pol.arg - nb2.pol.arg;
    Quotient.cart = PolToCart(Quotient.pol);
}
void exo38()
{
}
int main()
{
    int exo;
    printf("Quel exo lancer?\n");
    scanf("%d", &exo);
    switch (exo)
    {
    case 35:
        exo35();
        break;
    case 36:
        exo36();
        break;
    case 37:
        exo37();
        break;
    case 38:
        exo38();
        break;
    }
}