#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Exercice 46
void SommeVec(int taille, float V1[taille], float V2[taille], float *sum)
{
    int i;
    for (i = 1; i <= taille; i++)
    {
        sum[i] = V1[i] + V2[i];
    }
}

void DiffVec(int taille, float V1[taille], float V2[taille], float *diff)
{
    int i;
    for (i = 1; i <= taille; i++)
    {
        diff[i] = V1[i] - V2[i];
    }
}

float ScalVec(int taille, float V1[taille], float V2[taille])
{
    int i;
    float scal;
    scal = 0;
    for (i = 1; i <= taille; i++)
    {
        scal += V1[i] * V2[i];
    }
    return scal;
}

void exo46()
{
    int taille, i;
    printf("Entrer le nombre de composantes \n");
    scanf("%d", &taille);
    float vec1[taille], vec2[taille], *Somme, *Diff, Scal;
    Somme = (float *)calloc(taille, sizeof(float));
    Diff = (float *)calloc(taille, sizeof(float));
    for (i = 1; i <= taille; i++)
    {
        printf("Saisir le composant %d du vecteur 1\n", i);
        scanf("%f", &vec1[i]);
    }
    for (i = 1; i <= taille; i++)
    {
        printf("Saisir le composant %d du vecteur 2\n", i);
        scanf("%f", &vec2[i]);
    }
    SommeVec(taille, vec1, vec2, Somme);
    printf("Le vecteur somme est :\n");
    for (i = 1; i <= taille; i++)
    {
        printf("%f \n", Somme[i]);
    }

    DiffVec(taille, vec1, vec2, Diff);
    printf("Le vecteur différence est :\n");
    for (i = 1; i <= taille; i++)
    {
        printf("%f \n", Diff[i]);
    }

    Scal = ScalVec(taille, vec1, vec2);
    printf("le scalaire est : %f", Scal);

    free(Somme);
    free(Diff);
}

// Exercice 47
typedef struct
{
    char *nom;
    char *prenom;
    float notemedian;
    float notefinal;
    float moyenne;
} etudiant;

void trietu(int taille)
{
    int i;
}

void exo47()
{
    int N, i, j;
    char c;
    etudiant *tabetu;

    printf("Indiquer le nombre d'etudiants");
    scanf("%d", &N);
    tabetu = (etudiant *)malloc(N * sizeof(etudiant));

    for (i = 0; i < N; i++)
    {
        tabetu[i].nom = (char *)malloc(20 * sizeof(char));
        tabetu[i].prenom = (char *)malloc(20 * sizeof(char));
        printf("Saisir le nom et le prenom:\n");
        scanf("%s", tabetu[i].nom);
        scanf("%s", tabetu[i].prenom);
        printf("Saisir la note du median \n");
        scanf("%f", &tabetu[i].notemedian);
        printf("Saisir la note du final \n");
        scanf("%f", &tabetu[i].notefinal);
        tabetu[i].moyenne = tabetu[i].notemedian * 0.4 + tabetu[i].notefinal * 0.6;

        // Affiche l'étudiant qui vient d'être saisi
        /*printf("%s \n", tabetu[i].nom);
        printf("%c \n", tabetu[i].nom[1]);
        printf("%s \n", tabetu[i].prenom);
        printf("%f \n", tabetu[i].notemedian);
        printf("%f \n", tabetu[i].notefinal);
        printf("%f \n", tabetu[i].moyenne);*/
    }

    // Tri
    etudiant temp;
    int lettre = 0;
    for (i = 0; i < N; i++)
    {
        for (j = i + 1; j < N; j++)
        {
            // Si les 1eres lettres sont égales, on avance jusqu'à ce qu'on en trouve qui soient différentes ou qu'un nom soit fini
            while (tabetu[i].nom[lettre] == tabetu[j].nom[lettre] && tabetu[i].nom[lettre] != '\0' && tabetu[j].nom[lettre] != '\0')
            {
                lettre++;
            }
            // Si la lettre sélectionnée dans le nom de l'etudiant i est après celle de l'étudiant j, on échange leur place.
            if (tabetu[i].nom[lettre] > tabetu[j].nom[lettre])
            {
                temp = tabetu[i];
                tabetu[i] = tabetu[j];
                tabetu[j] = temp;
            }

            // Si les noms sont égaux, on compare les prénoms
            if (tabetu[i].nom[lettre] == '\0' && tabetu[j].nom[lettre] == '\0')
            {
                lettre = 0;
                while (tabetu[i].prenom[lettre] == tabetu[j].prenom[lettre] && tabetu[i].prenom[lettre] != '\0' && tabetu[j].prenom[lettre] != '\0')
                {
                    lettre++;
                }
                // Si la lettre sélectionnée dans le prénom de l'etudiant i est après celle de l'étudiant j, on échange leur place.
                if (tabetu[i].prenom[lettre] > tabetu[j].prenom[lettre])
                {
                    temp = tabetu[i];
                    tabetu[i] = tabetu[j];
                    tabetu[j] = temp;
                }
            }
            lettre = 0;
        }
    }
    printf("Liste par ordre alphabetique : \n");
    for (i = 0; i < N; i++)
    {
        printf("%s ", tabetu[i].nom);
        printf("%s \n", tabetu[i].prenom);
    }

    // On libère la mémoire
    for (i = 0; i < N; i++)
    {
        free(tabetu[i].nom);
        free(tabetu[i].prenom);
    }
    free(tabetu);
}

int main()
{
    int c;
    printf("Quel exo lancer  ?");
    scanf("%d", &c);
    switch (c)
    {
    case 46:
        exo46();
        break;
    case 47:
        exo47();
        break;
    default:
        break;
    }
    return 0;
}
