#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Exo 16: nombres premiers
void exo16(){
    int n,div,i,prime;
    prime=1;
    div=2;
    for ( n = 3; n <= 50; n++)
    {
      div=2;
      prime=1;
        while ((prime==1)&&(div <= n-1)){
          if (n % div !=0){
            div++;
          }
          else{
            prime=0;
          }
        }
        if (div==n){
          printf("%d est premier\n", n);
        }
        
    }  
}

//Exo 17
void max(){
	int taille,max,n,i;
	printf("Quelle est la taile du tableau (max 100)\n");
	scanf("%d", &taille);
	int tab[taille];
	for ( i = 0; i < taille; i++)
	{
		printf("Entrer le nombre n° %d\n",i+1);
		scanf("%d",&tab[i]);
	}
	max=tab[0];
	for ( i = 0; i < taille; i++)
	{
		if (tab[i]>max)
		{
			max = tab[i];
		}
	}
	printf("%d est le maximum",max);
	

}
//Exo 18 : chiffres en base 10


void base10(int n){
	int zeros;

	zeros=0;
	while (n!=0 && zeros==0)
	{
		if (n%10==0)
		{
			zeros=1;
			printf("Il y a au moins un zéro");
			break;
		}
		else{
			n = n/10;
			base10(n);
		}
	}
	/*if (n==0)
	{
		printf("Il n'y a pas de zéros");
	}*/
	
}

//Exo 19
void equa(){
	float a,b,c,delta,x1,x2,i;
	printf("Entrer le coefficient de x^2\n");
	scanf("%f",&a);
	printf("Entrer le coefficient de x\n");
	scanf("%f",&b);
	printf("Entrer le dernier coefficient\n");
	scanf("%f",&c);

	delta = (b*b)- 4 * a * c;
	if (delta<=0){
		printf("Il n'y a pas de solution réelle\n");
	}
	else if (delta==0)
	{
		x1 = (-b)/(2*a);
		printf("Il y a une solution : %f", x1);
	}
	else{
		x1= (-b - sqrt(delta))/(2*a);
		x2= (-b + sqrt(delta))/(2*a);
		printf("Il y a deux solutions : %f et %f", x1, x2);
	}

}

//Exo 20		
void fibo(){
int N,Un,Un1,Un2,i;

	printf("Quel rang doit on calculer ?");
	scanf("%d", &N);
	Un2=0;
	Un1=1;
	for ( i = 2; i <= N; i++)
	{
		Un = Un1 + Un2;
		Un2=Un1;
		Un1=Un;
	}
	printf("%d", Un);
	
}
void fiboR(int N, int Un2, int Un1, int i){
	int Un;

	if (i <N)
	{
		Un = Un1 + Un2;
		Un2=Un1;
		Un1=Un;
		i++;

		fiboR(N,Un2,Un1,i);
	}
	else{
		printf("%d",Un2+Un1);
	}
	
}



int main() {
    int exo;
    printf("Choisissez votre exercice (16 à 34)\n");
    scanf("%d",&exo);
    switch(exo){

        case 16 : exo16();break;
		case 17 : max();break;
		case 18 : ;
		int n; 
		printf("Entrer un nombre");
		scanf("%d",&n);
		base10(n);	break;
		case 19 : equa(); break;
		case 201 : fibo(); break;
		case 202 : ;
		int N;
		printf("Quel rang doit on calculer ?");
		scanf("%d", &N);
		fiboR(N,0,1,2); break;
    }
    return 0;
}