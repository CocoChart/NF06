#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void coder(int d, char *source, char *destination)
{
    char car;
    FILE *src, *dest;
    src = fopen(source, "r");
    dest = fopen(destination, "w");
    printf("ouvert !");
    while (feof(src) == 0)
    {
        car = fgetc(src);
        car = (car + d) % 128;
        fputc(car, dest);
    }
    printf("while");
    fclose(src);
    fclose(dest);
}

int main()
{
    char *source, *destination;

    // Le fichier source s'appelle origin.txt et le destination result.txt
    coder(3, "origin.txt", "result.txt");

    return 0;
}