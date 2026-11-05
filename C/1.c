#include <stdio.h>
///#include <math.h>

int main(){
    /* 12 
    int theChosen1;
    printf("\n choose a number");
    scanf("%d", &theChosen1);

    int n = theChosen1;
    int ret = 1;

    if (n<0)
    {
        return -1;
    }

    while (n > 1)
    {
        ret *= n;
        n--;
    }

    printf("\n %d! vaut %d", theChosen1, ret);
    */

    /* 13 ig
    int theChosen1;
    printf("\n choose a number");
    scanf("%d", &theChosen1);
    int a = 0;
    int b = 1; 
    int ret = 0;
    int compteur;
    for (compteur=0; compteur < theChosen1; compteur++)
    {
        ret = a+b;
        b = a;
        a = ret;
    }
    printf("%d", ret);
    */

    /* 14
    int n; 
    printf("\n choose a number");
    scanf("%d", &n);
    int compteur;
    int ret = 0;
    for (compteur=0; compteur<=n ; compteur++)
    {
        ret += compteur;
    }
    printf("\nsum from 1 to %d is %d", n, ret);
    */

    /* 15 
    int n; 
    printf("\n choose a number");
    scanf("%d", &n);
    int compteur = 1; // car on utilise n/10 > 0 
    while(n/10 > 0)
    {
        n/=10;
        compteur++;
    }
    printf("\n%d", compteur);
    */

    /*
    int n; 
    printf("\nchoose a number\n");
    scanf("%d", &n);
    if (n < 0)
    {
        return -1;
    }
    int ne = 0;
    while(n > 0)
    {
        ne = ne * 10 + n % 10;
        n /= 10;
    }
    printf("\nle nombre inversé est %d\n", ne);
    */
    /*
    int j = 48; 
    int k = 18;
    /// on devrait demander a l'utilisateur
    /// 4 variables pour un bel affichage a la fin 
    int a = j;
    int b = k;
    int temp;
    /// on admet j et k > 0 et j > k 
    while (a%b > 0)
    {
        temp = a%b;
        a = b;
        b = temp;
    }
    printf("le pgcd de %d et %d est %d\n", j, k, b);
    */

    /* 19 
    int tab[] = {25, 50, 75, 100}; // flemme de demander a l'user
    int taille = 4
    int min = 0;
    int max = 0;
    int sum = 0;
    int i; 
    /// on admet que tab respecte les conditions de l'exercice
    for (i=0; i<taille; i++)
    {
        if (tab[i] > tab[max])
        {
            max = i;
        }
        if (tab[i] < tab[min])
        {
            min = i;
        }
        sum += tab[i];
    }
    float moyenne = sum / taille; 
    printf("\ntaille : %d, min : %d, max : %d, avg : %f.", taille, tab[min], tab[max], moyenne);
    */

    
    /* 20 
    ///  0  1  2  3  4  5
    ///  S  a  l  u  t \0
    
    char voyelles[] = "aeiouyAEIOUY";
    int compteur = 0;
    char texte[] = "Hello world!";
    int i; 
    for (i=0; texte[i] != '\0'; i++)
    {
        for (int j=0; voyelles[j] != '\0'; j++)
        {
            if (texte[i] == voyelles[j])
            {
                compteur++ ;
                break ; 
            }
        }
    }

    printf("ce texte contient %d voyelle(s)", compteur);
    */
    return 0;

}