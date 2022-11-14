#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  /*Exo 1
  printf("Hello world!\n");
  printf("Nous sommes le 15 septembre\n");
  printf("Semaine 37\n");
  printf("corentin.chartier@utt.fr\n");
  */

  /*Exo 2
  int i = 0;
  int j = 5;
  // Division de i par j
  printf("Division de i par j = %d", i/j);
  */

  /*Exo 3
  printf("int %d octets \n",sizeof(int));
  printf("short %d octets \n",sizeof(short));
  printf("char %d octets \n",sizeof(char));
  printf("float %d octets \n",sizeof(float));
  printf("double %d octets \n",sizeof(double));
*/

  /*Exo 4
  A += (unsigned short)C ; //A devient A+C
  A = ~A; //A devient le complémentaire de A en binaire
  B =A^(A+2); //A est monté à la puissance A + C
  C = (float)(A<<B); //C prend la valeur de A avec un décalage de B bits vers la gauche
  A = A&(unsigned short)C; //A prend la valeur du nombre qui en binaire a les bits présents dans A ET dans C
  */

  /*Exo 5
  int x,n,p,i;
  long mask;
  printf("Choisir la valeur x\n");
  scanf("%d",&x);
  printf("Choisir le nombre p de bits inverses\n");
  scanf("%d",&p);
  printf("Choisir la position de depart n\n");
  scanf("%d",&n);

  mask=0; //Vaut 000000... en binaire

  for ( i = 0; i < p; i++) //On ajoute des 1 p fois à partir de la position n
  {
   mask += pow(2,(n-1+i)) ;
  }

  x = x^mask;
  printf("Valeur de x :%d",x);

  */
  /*Exercice 6*/
  /*Question 1
  int x,y;
  x=0;
  y=0;
  while (x==0)
  {
    printf("Entrer un premier entier non nul\n");
    scanf("%d", &x);
  }
  while (y==0)
  {
    printf("Entrer le deuxième entier non nul\n");
    scanf("%d", &y);
  }

  printf("La somme est %d\n", x+y);
  printf("La différence %d - %d est %d\n",x,y, x-y);
  printf("Le produit est %d\n", x*y);
  printf("Le quotient est %d\n", x/y);
  printf("Le reste de la division euclidienne de %d par %d est %d\n",x,y, x%y);
  */

  /*Question 2
  float a,b,temp;
  printf("valeur de a ?");
  scanf("%f",&a);
  printf("valeur de b ?");
  scanf("%f",&b);
  temp = a;
  a=b;
  b=temp;
  printf("a  = %f, b = %f", a,b);
*/

  // Ne fonctionne pas avec les caractères
  char a, b, temp;
  printf("valeur de a ?\n");
  scanf("%c", &a);
  printf("valeur de b ?\n");
  scanf("%c", &b);
  temp = a;
  a = b;
  b = temp;
  printf("a  = %c, b = %c", a, b);

  /* Question 3*/

  return 0;
}
