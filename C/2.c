#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>


// ex 1
int fDeX(int x){
    // 3x+2
    
    return 3*x+2;
}


// ex 2 
void swap(int a, int b){
    int temp = a ;
    a=b;
    b=temp;
    printf ("a = %d; b = %d\n", a, b);
}


// ex 3
bool pair(int n){
    if (n % 2 == 0){
        return true;
    }
    else{
        return false;
    }
}


int max(int a, int b, int c){
    int max = a ;
    if (max<b){
        max = b;
    }
    if (max<c){
        max = c; 
    }
    return max;
}


int fact(int n){
    // ptsd 
    assert(n>=0);
    if (n==1){
        return n;
    }
    else {
        return fact(n-1) * n ;
    }
}


int fibo(int n ){
    int a=0;
    int b=1; 
    int ret=0;
    for(int compteur=0; compteur<n; compteur++){
        ret = a+b; 
        b=a;
        a=ret;
    }
    return ret;
}


int pow_int(int a, int n){
    assert(n>=0);
    int ret=1;
    int base = a ;
    while (n>0){
        if (n % 2 == 1){
            ret *= base;
        }
        base *= base ;
        n /= 2;
    }
    return ret;
}


int pgcd(int a, int b){
    // ptsd #2
    int reste = a%b;
    while(reste!=0){
        a=b;
        b = reste;
        reste = a%b;
    }
    return b;
}


int ppcm(int a, int b){
    // PGCD(a,b)*PPCM(a,b)=a*b <=> a*b/PGCD(a,b) = PPCM(a,b)
    return a*b/pgcd(a,b);
}


int somme(int tab[], int n){
    int somme = 0;
    for(int i=0; i<n; i++){
        somme+=tab[i];
    }
    return somme;
}


int moyenne(int tab[], int n){
    return somme(tab, n) / n;
}


void minmax(int tab[], int n, int *min, int *max){
    *max = tab[0];
    *min = tab[0];
    for(int i = 0; i < n ; i++){
        if (tab[i] < *min){
            *min = tab[i];
        }
        if (tab[i] > *max){
            *max = tab[i];
        }
    }
}


int index_of(int tab[], int n, int x){
    for (int i = 0; i<n ; i++){
        if (tab[i]==x){
            return i;
        }
    }
    return -1;
}


// on va le faire en recursive prck je déteste ma vie
int recherche_dicho_recursive(int tab[], int n, int x){
    /*
    Ce que j'ai compris :
    contrairement a python, avant on peut pas partir dun endroit précis du tableau; 
        un tableau ne connait pas sa propre taille, c'est qu'un bloc de mémoire qui ne possède 
        qu'un pointeur vers son premier élément
            c'est à dire que lorsqu'on a un tableau en paramètre, on a pas réellement le tableau mais 
            uniquement son point de départ ( tab[0] ) ! 
    donc pour résoudre le problème de découper le tableau, on utilise l'index du milieu de cette manière :
        avec &tab[milieu] on indique l'adresse en mémoire de cet élément dans le tableau 
        en mettant cet argument en tant que tableau dans notre appel de fonction, on
        initie en fait un point de départ différent de celui de base (tab[0]) en mettant
        celui qu'on veut. 
    */

    if (n<=0){
        return -1;
    }

    int milieu = n/2 ;
    printf("%d\n",milieu);

    if (tab[milieu]==x){
        return milieu;
    }

    else {
       if (tab[milieu] < x){
            int ret = recherche_dicho_recursive(&tab[milieu+1], n - milieu - 1, x);
            if (ret==-1){
                return -1;
            }
            return milieu + 1 + ret ;
            /*
            Quel enfer 
            puisqu'on navique dans une parcelle de tableau, notre indice de début 
            n'est que fictif ( am I dreamin ? ) puisqu'on s'est déjà décalé en faisant de
            &tab[milieu+1] notre début. donc quand le programme trouve que en partant du milieu, 
            l'indice de x est 2, il a raison mais il prend pas en compte qu'on s'est décalé 
            de la moitié du tableau pour en arriver là
            donc au résultat trouvé, on rajoute milieu ( puis 1 pour la valeur du milieu check )
            */
       }
       return recherche_dicho_recursive(tab, milieu, x);
    }
}


void bubbleSort(int tab[], int n){
    int temp = 0;
    for (int i = 0; i<n; i++){
        for (int j = 0; j < n - 1 - i; j++){
            if (tab[j] > tab [j+1]){
                temp = tab[j];
                tab[j]=tab[j+1];
                tab[j+1]=temp;
            }
        }
    }
}


void afficherTab(int tab[], int n) {
    // print(tab) btw (zbi)
    for (int i = 0; i < n; i++){
        printf("%d ", tab[i]);
    }
    printf("\n");
}


int nb_voyelles(char chaine[]){
    int buffer = 0;
    for(int i = 0; chaine[i] != '\0'; i++){
        char c = tolower(chaine[i]);
        // c in 'aeiouy' ?  oui -> pointeur vers ce caractere / non -> renvoie NULL
        if (strchr("aeiouy", c) != NULL) {
            buffer++;
        }
    }
    return buffer;
}


bool palindrome(char chaine[]){
    // objectif : parcourir la chaine dans les deux sens et comparer les éléments petit a petit 
    // condition d'arret : false OU lsi les 2 curseurs se croisent (gauche < droite)
    int droite = strlen(chaine) - 1;
    int gauche = 0;
    while (gauche < droite){
        if (chaine[gauche] != chaine[droite]){
            return false;
        }
        droite--;
        gauche++;
    }
    return true;
}


void inverser(char chaine[]){
    int droite = strlen(chaine) - 1;
    int gauche = 0;
    while (gauche<droite){
        int temp = chaine[gauche];
        chaine[gauche]=chaine[droite];
        chaine[droite]=temp;
        droite--;
        gauche++;
    }
}


int trace(int matrice[][3], int n){
    int somme = 0;
    for (int i = 0; i<n; i++){
        somme += matrice[i][i];
    }
    return somme;
}


void transpose(int matrice[][3], int n){
    int temp = 0;
    for (int i = 0; i<n; i++){
        for(int j=i+1; j<n; j++){
            temp = matrice[i][j];
            matrice[i][j] = matrice[j][i];
            matrice[j][i] = temp;
        }
    }
}


/*
int variance(int tab[], int n){
    int somme = 0;
    int moy = moyenne(tab, n);
    for(int i=0; i<n; i++){
        somme += pow(tab[i] - moy, 2) ;
    }
    return somme / n;
}


float ecart_type(int variance){
    return sqrt(variance);
}
*/


bool est_premier(int n){
    if(n%2==0 || n<=1){
        if(n==2){
            return true;
        }
    return false;
    }

    for(int i = 3; i<n; i++){
        if (n%i==0){
            return false;
        }
    }
    return true;
}


int prochain_premier(int n){
    int prochain = n+1 ;
    while (!est_premier(prochain)){
        prochain++;
    }
    return prochain;
}


int main(){    
    // printf("ret : %d\n", fDeX(2));
    // swap(2, 4);

    /*
    if (pair(3)){
        printf("ce chiffre est pair\n");
    }
    else {
        printf("il n'est pas pair\n");
    }
    */

    /// printf("le maximum était : %d\n", max(23, 3, 18));

    // printf("5! = %d\n", fact(5));
    // printf("le 8 eme terme de la suite de fibo est %d\n", fibo(8));
    // printf("2^^18 vaut : %d\n", pow_int(2, 18));
    // printf("le pgcd de 12 et 18 est : %d\n", pgcd(12, 18));
    // printf("le ppcm de 12 et 18 est : %d\n", ppcm(12, 18));

    /*
    int tab[]={25, 50, 75, 100};
    printf("la somme de tous les elements de la liste est %d\n", somme(tab, 4));
    printf("la moyenne de cette liste est : %d\n", moyenne(tab, 4));
    */

    /*
    int tab[]={25, 50, 75, 100};
    int min, max;
    minmax(tab, 4, &min, &max);
    printf("min : %d\nmax : %d\n", min, max);
    */

    /*
    int tab[]={25, 50, 75, 100};
    int x = 800;
    printf("l'index de %d dans la liste est %d\n", x, index_of(tab, 4, x));
    */

    /*
    int tab[] = {1, 2, 3, 4, 5, 6, 7};
    int taille = 7;
    int x = 7;
    printf("dans le tableau, la valeur %d se trouve à l'index %d\n", x, recherche_dicho_recursive(tab, taille, x));
    */
    
    /*
    int tab[] = {2, 3, 1, 8, 4, 2, 30, 10};
    int n = 8;
    afficherTab(tab, 8);
    bubbleSort(tab, n);
    afficherTab(tab, 8);
    */

    // char chaine[] = "Hello #{→#{~¹} World!";
    // printf("il y a %d voyelles dans cette chaine\n", nb_voyelles(chaine));

    // char chaine[] = "non";
    // printf("%s palindrome ? %b\n", chaine, palindrome(chaine));

    /*
    char chaine[] = "Hello World!";
    printf("%s", chaine);
    inverser(chaine);
    printf("%s", chaine);
    */

    /*
    int n = 3;

    int matrice[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printf("trace : %d\n", trace(matrice, n));

    transpose(matrice, n);

    printf("transposée :\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }
    */

    /*
    // gcc 2.c -lm
    int tab[] = {2, 4, 4, 6};
    int var = variance(tab, 4);
    printf("variance : %d\n, ecart type : %f\n", var, ecart_type(var));
    */
   
    /*
    int n = -1;
    printf("%d premier ? %d\n", n, est_premier(n));
    printf("prochain premier après %d : %d\n", n, prochain_premier(n));
    */

    // ggwp
    return 0;
}







/* rappel
WARNING pointeur local 
// le pointeur local est redirigé vers y mais le pointeur p du main continue de pointer vers x,
// donc x vaut toujours 7

void piege(int *p) {
    int y = 100;
    p = &y; 
}     

int main(void) {
    int x = 7;
    int *p = &x;

    piege(p);

    printf("%d\n", *p);
}

*/