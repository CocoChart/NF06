#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Vecfile()
{
    int M, N, i, j;

    printf("Entrer le nombre de vecteurs et leur taille\n");
    scanf("%d", &M);
    scanf("%d", &N);

    float **Vect;
    Vect = (float **)calloc(M, sizeof(float *));
    if (Vect)
    {
        for (i = 0; i < M; i++)
        {
            Vect[i] = (float *)calloc(N, sizeof(float *));
        }
    }

    FILE *ptr;
    char *name = "vec.txt";
    ptr = fopen(name, "w+");
    for (i = 1; i <= M; i++)
    {
        for (j = 1; j <= N; j++)
        {
            printf("Entrer la composante %d du vecteur %d : ", j, i);
            scanf("%f", &Vect[i - 1][j - 1]);
            fprintf(ptr, "%f ", Vect[i - 1][j - 1]);
        }
        fprintf(ptr, "\n");
    }
    fclose(ptr);
    for (i = 0; i < M; i++)
    {
        free(Vect[i]);
    }
    free(Vect);
}

void SommeVec(int N, int M)
{
    int i, j;
    FILE *src;
    src = fopen("vec.txt", "a+");
    float **Vect;
    Vect = (float **)calloc(M, sizeof(float *));
    if (Vect)
    {
        for (i = 0; i < M; i++)
        {
            Vect[i] = (float *)calloc(N, sizeof(float *));
        }
    }
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            fscanf(src, "%f", &Vect[i][j]);
        }
    }
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%f ", Vect[i][j]);
        }
        printf("\n");
    }
    // Somme des vecteurs
    float sum = 0;
    printf("somme\n");
    for (j = 0; j < M; j++)
    {
        for (i = 0; i < N; i++)
        {
            sum += Vect[i][j];
        }
        printf("%f\n", sum);
        fprintf(src, "%f ", sum);
        sum = 0;
    }

    printf("fin \n");
    fclose(src);
}

int concat(char *sResultat, char *sFichier1, char *sFichier2)
{
    FILE *res, *f1, *f2;
    char car;
    f1 = fopen(sFichier1, "r+");
    f2 = fopen(sFichier2, "r+");
    res = fopen(sResultat, "w+");
    while (feof(f1) == 0)
    {
        car = fgetc(f1);
        fputc(car, res);
    }
    while (feof(f2) == 0)
    {
        car = fgetc(f2);
        fputc(car, res);
    }
}

int main()
{
    /*Vecfile();
    int N, M;
    printf("Entrer le nombre de vecteurs et leur taille\n");
    scanf("%d", &M);
    scanf("%d", &N);*/

    // SommeVec(3, 3);
    concat("result", "file1", "file2");
    return 0;
}