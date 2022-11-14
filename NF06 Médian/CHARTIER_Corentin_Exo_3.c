#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct type_chanson
{
    char *titre;
    char *chanteur;
    int sortie;
} typedef chanson;

chanson *ajouter(chanson *cat, int taille, chanson s)
{
    cat[1] = s;
}

void afficher(chanson *cat, int taille)
{
    int i;
    for (i = 0; i < taille; i++)
    {
        printf("%s, ", cat[i].titre);
        printf("%s, ", cat[i].chanteur);
        printf("%d\n", cat[i].sortie);
    }
}

void liberer(chanson *cat, int taille)
{
    int i;
    for (i = 0; i < taille; i++)
    {
        free(cat[i].titre);
        free(cat[i].chanteur);
    }
    free(cat);
}

int main()
{
    int taille;
    printf("Entrer la taille du catalogue");
    scanf("%d", &taille);
    chanson *cat;
    chanson s; // chanson pour les tests
    s.titre = "Ca doit bugger";
    s.chanteur = "Spider Zed";
    s.sortie = 2022;
    cat = (chanson *)malloc(taille * sizeof(chanson));

    ajouter(cat, taille, s);
    afficher(cat, taille);

    return 0;
}