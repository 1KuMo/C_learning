#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>
// heure départ : 22H40
// aucune utilisation de source extérieure, contexte examen


// EXERCICE A - heure début : 22h40 -- heure fin : 23H31
/*
Écrire une fonction qui prend un tableau d'entiers et sa taille, 
et utilise deux pointeurs (un au début, un à la fin) 
progressant l'un vers l'autre pour placer 
tous les nombres pairs au début du tableau et les impairs à la fin (en place).
*/

bool est_pair(int x){
    return x%2 == 0;
}


void swap(int *x, int *y){
    int temp = *x; 
    *x = *y;
    *y = temp;
    printf("swapped!");
}


void trier_tab(int tab[], int n){
    /*
    4 cas : 
- gauche impair et droite pair -> on les échanges
- gauche pair et droite impair -> on touche rien
- gauche impair et droite impair OU gauche pair et droite pair -> on arrete un des deux pointeurs à sa position actuelle
        (celui dont la valeur n'est pas correctement placée) puis on attend une opportunité :
            si on en a pas dans la suite ; c'est qu'il était au bon endroit ( tous ceux d'avant / après étaient pairs / impair ( il faisait la coupure ))
    */
    int *droite = &tab[n-1]; // resté bloqué 15 minutes prck j'ai écrit &tab[-1] :D
    int *gauche = tab;
    printf("*droite = %d\ndroite = %d\n*gauche = %d\ngauche = %d\n", *droite, droite, *gauche, gauche);

    while (gauche < droite){
        printf("0-");
        if (!est_pair(*gauche) && est_pair(*droite)){
            swap(gauche, droite);
            gauche++;
            droite--;
            printf("1\n");
        }

        else if (est_pair(*gauche) && !est_pair(*droite)){
            gauche++;
            droite--;
            printf("2\n");
        }

        else{
            if (est_pair(*droite)){ // && gauche pair grâce au else if précédent
                gauche++;
                printf("3\n");
            }
            else if (!est_pair(*gauche)){
                droite--;
                printf("4\n");
            }
        }
    }
}


int afficher_tab(int *tab, int taille){ // rappel : [] pour modifier et * pour lire
    // int taille = sizeof(tab) / sizeof(tab[0]); ??
    for(int i = 0; i < taille; i++ ){
        printf("%d ", tab[i]);
    }
    printf("\n");
}



// EXERCICE B - heure début : 23h40 -- heure fin : 00h20 
// je m'autorise de reprendre la fonction afficher_tab pour ne pas avoir à la réecrire
/*
Écrire une fonction qui prend deux tableaux d'entiers 
déjà triés et leurs tailles respectives,
et les fusionne dans un troisième tableau trié. 
Contrainte : 
  interdiction d'utiliser les indices de tableau traditionnels (T[i]), 
  tout doit se faire par arithmétique et déréférencement de pointeurs.
*/

void fusionner(int tab1[], int taille1, int tab2[], int taille2){
    /*
    +/- même idée ; on prend 2 curseurs et on les fait avancer dans chacune des listes et
        on met à chaque fois le plus petit élément des 2 dans le nouveau tab
            si une liste est finie d'être parcourue et l'autre non, on peut mettre tout le 
            reste du contenu de cette liste dans le nouveau tab
    */

    int newtab[taille1+taille2];
    int *curnew = newtab;
    int *cur1 = tab1;
    int *cur2 = tab2;

    // rester bloquer 15 minutes parce que j'ai mis || au lieu de && c'est gênant (ggwp)
    while( (cur1 <= &tab1[taille1-1]) && (cur2 <= &tab2[taille2-1]) ){ 
        // si on finit de parcourir une des deux listes, on sort de la boucle
        // en attendant, on va comparer les valeurs et remplir newtab

        printf("0-");

        if(*cur1 < *cur2){
            printf("1 ( %d )\n", *cur1);
            *curnew = *cur1;
            cur1++;
        }

        else if(*cur1 > *cur2){
            printf("2 ( %d )\n", *cur2);
            *curnew = *cur2;
            cur2++;
        }

        curnew++;
    }

    // il reste maintenant à vider la bonne liste dans newtab ( et à sécher mes larmes )
    if (cur2 == &tab2[taille2]){
        printf("1-");
        while(cur1 <= &tab1[taille1-1]){
            printf("1\n");
            *curnew = *cur1;
            cur1++;
            curnew++;
        }
    }

    else if (cur1 == &tab1[taille1]){
        printf("2-");
        while(cur2 <= &tab2[taille2-1]){
            printf("1\n");
            *curnew = *cur2;
            cur2++;
            curnew++;
        }
    }

    afficher_tab(newtab, taille1 + taille2);
    //return newtab;
}




// EXERCICE C - temps passé : 1h30
/*
Écrire une fonction qui prend deux chaînes de caractères (s et sub)
et retourne un pointeur vers la première occurrence de sub dans s (ou NULL si sub n'est pas trouvée),
en parcourant les chaînes uniquement à l'aide de pointeurs.
*/

/*
j'ai les pires logs de l'histoire c'est déplorable
et je suis resté bloqué 40 minutes 
à cause de *curlettre = *curs;
au lieu de curlettre = curs;
je déteste ma vie ( skill issue )
mais le sentiment de voir écrit 123 wrouf est indescriptible
*/


char* trouverSub(char s[], char sub[]){
    /*
    Ici , on va parcourir s jusqu'à trouver le premier caractere de sub dedans.
    on initialise une variable booleene à false
        une fois trouvé, cette variable devient True, puis on continue de parcourir 
        s mais cette fois-ci en avançant le pointeur de sub en simultané 
        et en vérifiant la correspondance entre 
        les caractères de s et sub depuis la lettre trouvée
            cas d'arrêts : 
- on a fini de parcourir s 
- on a fini de parcourir sub 
- erreur fatale ( ; manquant ) qui me fait partir pleurer
    */
    char *curs = s;
    char *cursub = sub;
    int temp_p = *cursub;
    bool same = false ;
    char *curlettre;

    printf("*curs = %d\n*cursub = %d\nsame = %d\n", *curs,*cursub, same);

    while( (*curs != '\0') && (*cursub != '\0') ){
        printf("0-");
        if(*curs == *cursub && !same){
            printf("1-");
            if(same){
                printf("1\n");
                *cursub++;
            }
            else{
                printf("2\n");
                same = true; 
                curlettre = curs;
            }
            printf("\n");
        }

        else if (*curs != *cursub && same){
            /*
            si on avait une combinaison correspondante mais qu'un caractère ne correspond pas,
            on remet le curseur de sub à 0 pour la prochaine fois qu'on l'utilisera 
            ( pour pas repartir de là où on en étais la dernière fois qu'on la 
            parcourrai mais bien depuis le début de la chaine sub )
            on remet aussi same à false pour pas déclencher les chemins de comparaisons
            */
            printf("2\n");
            *cursub = temp_p;
            same = false;
            *curlettre;
        }
        printf("\n");
        curs++;
    }

    return curlettre;
}



// EXERCICE D - heure début : 14h50 -- heure fin : 16h40 ( je vais pleurer )
/*
Écrire une fonction 
qui modifie une chaîne en place pour supprimer les espaces 
superflus (les espaces au début, à la fin, et réduire toute 
séquence de plusieurs espaces consécutifs à un seul espace) 
en utilisant deux pointeurs (lecture et écriture).
*/


void optiEspaces(char s[]){
    /*
    on lit le texte avec lecture en vérifiant les caracteres
    on réecrit derrière avec ecriture depuis lecture 
    ( on saute les caractères avec lecture pour les retirer )

    premier cas :
      le caractere n'est pas un espace 
        on l'écrit et on retient que le dernier n'était pas un espace

    deuxieme cas : 
      le caractere est un espace ET le dernier n'en était pas un
        on l'écrit et on retient que le dernier est un espace
        
    finition : 
      si on a écrit un espace et qu'on est arrivé au bout 
        on revient en arriere et on remplace l'espace par \0
    */
    char *lecture = s;
    char *ecriture = s;
    bool dernierEspace = true;

    while (*lecture != '\0') {
        if (*lecture != ' ') {
            *ecriture = *lecture;
            ecriture++;
            dernierEspace = false;
        }

        else if (!dernierEspace) {
            *ecriture = *lecture;
            ecriture++;
            dernierEspace = true;
        }

        lecture++;
    }

    if (dernierEspace && ecriture > s) {
        ecriture--;
    }

    *ecriture = '\0';
}



// EXERCICE E - heure début : 11h30 -- heure fin : Jamais
/*
Énoncé : Écrire inverser_mots(char *s) pour inverser l'ordre des mots d'une phrase en place.

Contraintes :

    En place (pas de tableau de stockage secondaire).

    Zéro crochet [] (uniquement des pointeurs et de l'arithmétique d'adresses).

*/


void inverser_mots(char s[]){

    /*
    cque je propose est terrifiant 
    on va inverser toute la chaine comme précédemment
    puis on va inverser chaque mot d'une manière terrible
        on a 2 pointeurs, l et e 
        on fait premierement avancer l et e jusqu'au début du premier mot ( on ignore les espaces au début )
        une fois qu'on arrive à ce mot, on avance uniquement l jusqu'à la fin de ce mot 
        une fois arrivé à la fin du mot, on refait partir l en arrière avec le meme principe
        que les autres exercices ( while e < l )
            une fois le mot réecrit, on replace e et l au début du prochain mot et on recommence
                une complexité déplorable mais ca a le mérite de marcher
                (je détaille pas les 800 cas limites l'implémentation de ce truc m'a fait mal au crane)
    */

    // on récupère la taille de la chaine
    char *c = s;
    int taille = 0;
    while(*c!='\0'){
        taille++;
        c++;
    }

    char *gauche = s;
    char *droite = &s[taille-1];
    char temp;

    // on gère les cas où le(s) 1er / dernier(s) caractere(s) sont des espaces
    while (*gauche == ' '){
        gauche++;
    }

    while(droite >= s && *droite == ' '){
        droite--;
    }

    // on inverse la chaine
    while(gauche<droite){
        temp = *gauche ;
        *gauche = *droite;
        *droite = temp;
        droite--;
        gauche++;
    }
    printf("%s\n", s);

    // true spaghetti
    char *l = s;
    char *e = s;
    char *t;
    char tempo;
    bool estEspace = true;
    while(*l!='\0'){
        if(*l!=' '){
            if (estEspace){
                e = l;
            }
            estEspace = false;
            /* 
            je laisse la ligne suivante en tant que trophée de ligne qui m'a
            fait perdre le plus de temps de ma vie ( 40min+ ( j'ai 3 de qi ))
            */
            // e++;
        }

        else if(*l==' ' && !estEspace){
            printf("0");
            estEspace = true;
            t=l;
            l--;
            while(e<l){
                printf("-1\n");
                tempo = *e;
                *e = *l;
                *l = tempo;
                e++;
                l--;
            }
            e = t+ 1 ;
            l = t;
            estEspace = true;
        }

        l++;

        if(*l == '\0' && !estEspace){
            estEspace = true;
            t=l;
            l--;
            while(e<l){
                printf("-2\n");
                tempo = *e;
                *e = *l;
                *l = tempo;
                e++;
                l--;
            }
            break;
        }
    }
}




int main(){
    /*
    int tab[]={1,2,3,4,5,6,7,8,9};
    int taille= 9;
    trier_tab(tab, taille);
    afficher_tab(tab, taille);
    return 0;
    */

    /*
    int tab1[] = {25,50,75,100};
    int taille1 = 4 ;
    int tab2[] = {12,24,48,60,72,84,96};
    int taille2 = 7;
    fusionner(tab1, taille1, tab2, taille2);
    //int new_tab[] = fusionner(tab1, taille1, tab2, taille2);
    //afficher_tab(new_tab, taille1 + taille2);
    return 0;
    */

    /*
    char s[] = "meow 23 | 12 3 45 | 123 wrouf";
    char sub[] = "123";
    char *p = trouverSub(s, sub);
    printf("%s\n", p);
    return 0;
    */

    /*
    char texte[] = " WROUF   meow  tchiki brr ";
    char texte2[] = "hello world ";
    char texte3[] = "   ";
    char texte4[] = "  hello  world  ";
    optiEspaces(texte);
    optiEspaces(texte2);
    optiEspaces(texte3);
    optiEspaces(texte4);
    printf("%sf\n%sf\n%sf\n%sf\n", texte, texte2, texte3, texte4);
    return 0;
    */

    char phrase[] = " Hello   world  boop ";
    inverser_mots(phrase);
    printf("%sf\n", phrase);
    return 0;
}
