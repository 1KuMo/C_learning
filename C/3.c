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

    int tab[] = {25, 50, 75, 100};

    return 0;
}