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
    /*Ne fonctionne pas
    Cplx a, b, c, delta, racdelta, nom1, denom, sol1, nom2, sol2;
    Cplx bcarr, ac, quatre, zero, deux, moinsb, qac;
    quatre.cart.reel = 4;
    quatre.cart.imag = 0;
    quatre.pol = CartToPol(quatre.cart);
    zero.cart.reel = 0;
    zero.cart.imag = 0;
    zero.pol = CartToPol(zero.cart);
    deux.cart.reel = 2;
    deux.cart.imag = 0;
    deux.pol = CartToPol(deux.cart);
    char right;

    do
    {
        // Saisie premier cplx
        printf("Entrer la partie réelle du premier coefficient : \n");

        scanf("%f", &a.cart.reel);
        printf("Entrer la partie imaginaire du premier coefficient : \n");

        scanf("%f", &a.cart.imag);
        // Saisie deuxieme cplx
        printf("Entrer la partie réelle du deuxieme coefficient : \n");

        scanf("%f", &b.cart.reel);
        printf("Entrer la partie imaginaire du deuxieme coefficient : \n");

        scanf("%f", &b.cart.imag);
        // Saisie troisieme cplx
        printf("Entrer la partie réelle du troisieme coefficient : \n");

        scanf("%f", &b.cart.reel);
        printf("Entrer la partie imaginaire du troisieme coefficient : \n");

        scanf("%f", &b.cart.imag);
        // Conversion des troi cplx en forme cartésienne
        a.pol = CartToPol(a.cart);
        b.pol = CartToPol(b.cart);
        c.pol = CartToPol(c.cart);

        printf("L'équation est bien : %f + %fi * x² + %f + %fi * x + %f + %fi ? \n ( O / N ) : ", a.cart.reel, a.cart.imag, b.cart.reel, b.cart.imag, b.cart.reel, b.cart.imag);

        scanf("%c", right);

    } while (right == 'N');

    bcarr = MultCplx(b, b);
    ac = MultCplx(a, c);
    qac = MultCplx(quatre, ac);
    delta = SousCplx(bcarr, qac);

    // racine module et arg/2
    racdelta.pol.arg = delta.pol.arg / 2;
    racdelta.pol.mod = sqrt(delta.pol.mod);

    moinsb = SousCplx(zero, moinsb);

    nom1 = SommeCplx(moinsb, racdelta);
    nom2 = SousCplx(moinsb, racdelta);

    denom = MultCplx(deux, a);

    sol1 = DivCplx(nom1, denom);
    sol2 = DivCplx(nom2, denom);

    printf("Solution 1 = %f + %fi, Solution 2 = %f + %fi", sol1.cart.reel, sol1.cart.imag, sol2.cart.reel, sol2.cart.imag);
    */
    printf("Ne fonctionne pas");
}
typedef enum
{
    voiture,
    camion,
    moto
} typevehicle;
typedef struct
{
    typevehicle type;

    char proprio[20];
    char mat[9];
    int annee;
    char modele[8];
    union
    {
        int portes;
        int gabarit;
        int vitmax;
    };

} Vehicule;
typedef struct
{
    Vehicule *occupant;
    struct hres
    {
        int heure;
        int minute;
    };
    int nbres;

} Place;
typedef struct
{
    Vehicule placesvoit[20];
    Vehicule placescam[10];
    Vehicule placesmoto[10];
} Parking;

void reserver(Vehicule v)
{
    if (v.type == voiture)
    {
        /* code */
    }
}

void exo45()
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

    case 45:
        exo45();
        break;
    }
}