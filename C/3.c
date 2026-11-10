#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

// 1
void test(){
    int x = 1;
    int *p = &x;
    printf("x : %d\nadresse de x : %d\n", *p, p);
    *p += 1;
    printf("x : %d\n", *p);
}


// 2
void swap(int *a, int *b){
    int temp = *a ;
    *a = *b;
    *b = temp ;
}


// 3
void minetmax(int tab[], int n, int *min, int *max){
    *min = tab[0];
    *max = tab[0];
    for(int i=0; i<n; i++){
        if(*min > tab[i]){
            *min = tab[i];
        }
        if(*max < tab[i]){
            *max = tab[i];
        }
    }
}


// 4
int somme(int tab[],int n){
    int buffer = 0;
    for(int i=0; i<n; i++){
        buffer += *tab;
        *tab++ ;
    }
    return buffer;
}  


int moyenne(int tab[], int n){
    return somme(tab, n) / n ;
}


void afficherTab(int tab[], int n) {
    // print(tab) btw (zbi)
    for (int i = 0; i < n; i++){
        printf("%d ", tab[i]);
    }
    printf("\n");
}


void inverser(int tab[], int n){
    // obligé de mettre n pour droite ( int **droite = &tab[-1]; )
    // error: initialization of ‘int **’ from incompatible pointer type ‘int *’ 
    int *droite = &tab[n-1];
    int *gauche = tab;
    int temp;
    while(gauche < droite){
        temp = *droite;
        *droite = *gauche;
        *gauche = temp;
        gauche ++;
        droite --;
    }
}


int len(char *s){
    int compteur = 0;
    while (*s!='\0'){
        s++; // comme c'est un tableau de plusieurs caracteres ca marche :D
        compteur++;
    }
    return compteur;
}


void copier(char *copie, char *base){
    for(int i = 0 ; i <= len(base) ; i++ ){ 
        // on recupere le \0 pour mettre une fin à notre copie 
        copie[i] = base[i]; 
    }
}


int nb_voyelles(char *chaine){
    int buffer = 0;
    while(*chaine != '\0'){
        char c = tolower(*chaine);
        // c in 'aeiouy' ?  oui -> pointeur vers ce caractere / non -> renvoie NULL
        if (strchr("aeiouy", c) != NULL) {
            buffer++;
        }
        chaine++;
    }
    return buffer;
}


void retirer_espaces(char *s){
    char *lecture = s;
    char *ecriture = s; 
    // on réecrit tout par dessus notre texte de base ( sans les espaces )
    while (*lecture != '\0'){
        if (*lecture != ' '){
            *ecriture = *lecture;
            *ecriture++;
        }
        *lecture++ ;
    }
    *ecriture = '\0';
}


int min_p(int tab[], int n){
    int *min = tab;
    for(int i=0; i<n; i++){
        if(*min > tab[i]){
            *min = tab[i];
        }
    }
    return min;
}


int main(){
    // 1
    // test();

    /* // 2 
    int a = 1, b=2;
    printf("a : %d\nb : %d\n", a, b);
    swap (&a, &b);
    printf("a : %d\nb : %d\n", a, b);
    */
 
    /* // 3
    int tab[] = {25, 50, 75, 100};
    int min, max ;
    minetmax(tab, 4, &min, &max);
    printf("min : %d\nmax : %d\n", min, max);
    */
    
    /* // 4 
    int tab[] = {25, 50, 75, 100};
    printf("somme : %d\nmoyenne : %d\n", somme(tab, 4), moyenne(tab, 4));
    */

    /* // 5
    int tab[] = {25, 50, 75, 100};
    inverser(tab, 4);
    printf("tableau inversé !\n");
    afficherTab(tab, 4);    
    */

    /* // 6
    char *chaine = "Hello World!";
    printf("il y a %d caract dans la chaine\n", len(chaine));
    */

    /* // 7 
    char *base = "blabla";
    char copie[100]; // Segmentation fault (core dumped) :(
    copier(copie, base);
    printf("copie de la chaine : %s\n", copie);
    */

    /* // 8
    char *s = "hello";
    printf("il y a %d voyelles dans la chaine\n", nb_voyelles(s));
    */

    /* // 9 
    char chaine[] = "Hello world o/ ! ";
    // je viens de découvrir la fameuse difference entre *chaine et chaine[]  (je hais les docs)
    // *chaine -> pointeur vers une chaine en mode lecture seule
    // chaine[] -> tab de caractere ( la base ) donc modifiable 
    printf("chaine de base : %s\n", chaine);
    retirer_espaces(chaine);
    printf("chaine sans espaces : %s\n", chaine);
    */
    
    /* // 10 
    int tab[] = {25, 50, 75, 100};
    int *p_min = min_p(tab, 4);

    if (p_min != NULL){
        int indice = p_min - tab;
        printf("minimum : %d\n", *p_min);
        printf("indice : %d\n", indice);
    }
    */
    
    return 0;
}
