I used ai to make this file look better for me to read it back but the content is mine ཐི ₍^.  ̫.^₎ ཋྀ
# `malloc` et `free`

* **`pile (stack)`** : `int tab[10];`
  * **principe** : automatique, mais on doit connaitre la taille à l'avance (limitée) et la mémoire disparait dès que la fonction se termine (pouf)

* **`tas (heap)`** : `int *tab = malloc(n * sizeof(int));` (equivalent de `tab = [VIDE] * n`)
  `free(tab);` 
  * **principe** : la mémoire est géante et libre ; pas besoin de connaitre la taille à l'avance
  * **exemple d'utilisation** ;
    * charger un fichier 
    * données exterieures à stocker (bot qui recoit des données etc)

### fonctionnement de base : 
```c
int *tab = malloc(n * sizeof(int));
```
demande un bloc de memory capable de stocker n entiers ( de type int ici )
réponse de la france ;
* si il peut stocker, il renvoie un pointeur vers le premier elt de ce bloc alloué 
* si il ne peut pas, il renvoie NULL

```c
free(tab);
```
permet de libérer la mémoire allouée ( sinon memory leak :C )

---

# `realloc`

c'est ce qui donne le coté dynamique sur le cv
si on a plus assez de place dans l'ancien bloc de memoire demandé ( ou trop peu importe )
on peut changer la taille du bloc de mémoire 
`realloc` (re-allocation) prend un ancien bloc de mémoire, en demande un nouveau gentilement (plus grand ou plus petit) copie automatiquement les anciennes données dedans, libère l'ancien bloc, et nous retourne le nouveau pointeur (good boy realloc pour le coup)

### syntaxe : 
```c
void *realloc(void *pt, size_t new_size);
```
avec : 
* `pt` le pointeur vers l'ancien bloc de mémoire
* `new_size` la taille en octets ( `(nouveau_nombre_d_elements) * sizeof(type)` )
* `ret` : pointeur vers le nouveau bloc de mémoire 

> **IMPORTANT :** 
> avec `realloc`, ca peut rater (après tout on sait pas trop cq'un fait la faut bien qu'ca casse quelque part)
> alors on implémente toujours une variable test pour ne pas écraser toutes nos données au passage 
> exemple : 
> ```c
> int *tab = malloc(3 * sizeof(int));
> // toudincou, ON A BESOIN de plus de place ( ca va aller )
> int new_size = 5;
> 
> int *temp = realloc(tab, new_size * sizeof(int));
> if (temp == NULL) {
>     free(tab);
>     exit(1);
> }
> 
> tab = temp;
> ```

### points notoires (oui jparle comme ca) : 
* si `pt` est `NULL` : `realloc(NULL, size)` fait la même chose que `malloc(size)` 
* si `new_size` vaut 0, `realloc(NULL, size)` fait la même chose que `free(pt)`
* **IA point** : S'il y a de la place libre juste à côté en mémoire, realloc élargit le bloc sur place sans même bouger les données. S'il n'y a pas la place, il va chercher un autre endroit plus grand, copie tout tout seul, et supprime l'ancien. C'est magique, mais ça a un coût (la copie), donc on évite de l'appeler à chaque ajout d'élément si on peut faire des allocations par blocs doublés.

---

# `structures` et double pointeurs ( `**` )

structures <=> `class` sans methodes en python
```c
struct Tache {
    int id;
    char description[50];
};
```

### doubles pointeurs : 
* **cas** : listes chainées / tableau dynamique qui doit changer d'adresse en mémoire ( `realloc` ) ( pour grandir par exemple )
* **utilisation** : 
  * `*t` est une copie du pointeur, l'original dans le `main` pointe toujours vers l'ancienne adresse
  * `**t` est l'adresse du pointeur. on modifie directement le pointeur du `main` depuis la fonction
