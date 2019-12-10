 **LISP**



 

# Chapitre 1 – Introduction

Inventé par John Mac Carthy en 1958 au MIT (plus vieux langage après Fortran et qu’on utilise encore).

**Caractéristique du langage :**

- langage symbolique : conçu pour la programmation non numérique

  ⇒ Traitement d’expressions symboliques

  ⇒ Travaux sur la logique mathématique

  ⇒ Traitement d’intégrales et d’équations différentielles

## 1. Généralités sur la syntaxe et la sémantique

- Langage orienté expression → aucune distinction entre les expressions et les déclarations.

​	⇒ Code + données = expressions

- Langage fonctionnel (applicatif) → calcul symbolique est exprimé sous forme de fonction.

  - - ### a. L’atome

Donnée élémentaire.

A = {atomes} : domaine d’utilisation du langage

**Types présents :** booléen, chaînes de caractères, nombres, identificateurs (variables)

S-expression = symbolic expression

Les atomes permettent de construire les S-expressions dont l’ensemble se définit comme suit :

- Pour tout x appartenant à A, x est une S-expression. *Ex : (1 2 3), (add 1 2), ( ) (s-expression vide)*
- Toute suite de S-expressions est une S-expression.

- - - ### b. S-expression

Représentée par une notation préfixée ( = notation dont la fonction ou l’opérateur utilisé est placé devant) totalement parenthésée. *Ex : (+ 1 2)*

***NB :*** Les parenthèses servent à définir le début et la fin de la S-expression.

## **2. Exemples de LISP (lisp moderne)**

Utilisation du **common LISP (CLISP)** regroupant un ensemble de compilateurs tels que MacLisp, InterLisp,…

**Autres versions :**

- Scheme (version minimaliste)
- Emacs Lisp (langage stricte pour Emacs)



 

# Chapitre 2 : Vue d’ensemble

## 1. La forme

Lisp est un langage interactif ⇒ toute expression tapée est évaluée.

```lisp
>  1
>  1

> (+ 2 3)
> 5

> (+ 2 3 5)
> 10

> (+  )
> 0

> (+ 2)
> 2

> ( / ( - 7 1) ( - 4 2))
> 3
```

Une expression Lisp peut soit être un **atome** ou soit une **liste** (entre 0 et plusieurs expressions).

## 2. Evaluation

Sur l’exemple ( + 2 3 5), + est une fonction et ( + 2 3 5) est l’appel de la fonction.

L’appel de la fonction se fait en 2 temps :

1. Evaluation des arguments de gauche à droite
2. Passage des arguments à la fonction

Pour Lisp, tout est fonction sauf les expressions non évaluées. 

```lisp
> (quote (+ 3 5)) ou ‘(+ 3 5)
> (+ 3 5)
```

*NB : quote ou ‘ permet de ne pas évaluer une expression.*

## 3. Données

- Tous les types standards : integer, string, …
- Symboles : ceux sont des mots
- Listes : une suite d’éléments

### a. Les symboles

Ne sont jamais évalues. 

> > ```lisp
> > > Licence
> > > LICENCE (toujours en majuscule)
> > ```
> >
> > 
>
> 

### b.  Les listes

Ensemble de zéro ou plusieurs éléments n’ayant pas de types, c’est-à-dire qu’ils peuvent être de n’importe quel type.

*Ex : >’(mes 3 « cartouches ») renvoie (MES 3 « cartouches »)*

*> ‘ (la liste (a b c) a 3 elements) renvoie (LA LISTE (A B C) A 3 ELEMENTS)*

Pour construire une liste : utilisation de ***list*****.**  

*Ex : > (list ‘mes (+ 2 1) « cartouches ») renvoie  (MES 3 « cartouches »)*

*> (list ‘(+ 2 1) (+ 2 1)) renvoie ( (+ 2 1) 3)*

Pour représenter une liste vide, on peut écrire *( )*  ou  *nil*.

## 4. Opérations sur les listes

- List : permet de créer une liste

### a. Cons

*Ex :  > (cons ‘a ‘(b c d)) renvoie (A B C D)*  

Permet d’ajouter un élément à une liste non vide (concaténation).

*Ex : > (cons ‘a (cons ‘b nil)) renvoie (A B) équivalent à (list ‘a ‘b)*

*NB : Privilégier list si la liste est vide.*

### b. Car

Extraction du premier élément de la liste.

*Ex :* >(car ‘(a b c)) renvoie A

**Fonction complémentaire à car :** **cdr** qui extrait tous les éléments de la liste sauf le premier.

*Ex : >(cdr ‘(a b c)) renvoie (B C)*

*> ( car (cdr (cdr ‘(a b c)))) renvoie C*

On peut utiliser *first, second, third …* pour récupérer un élément d’une liste.

*Ex : > (third ‘(a b c)) renvoie C*

## 5. Booléens

Tout est vrai excepté la liste nil (NULL).

- ***Nil*** représente **faux**
- ***t*** représente **vrai**

```
> (listp ‘(a b c)) renvoie T → l’ajout de p représente un prédicat et permet de dire si l’argument est une liste.

> (listp ‘27) renvoie NIL

> (if (listp ‘(a b c))

​	(+ 1 2)		← alors

​	(+ 5 6)		← sinon

)

renvoie 3

> (if (listp 27)

​	*(+ 1 2)*

​	*(+ 5 6)*

*)*

*renvoie 11*

*> (if (listp 27)*

​	*(+ 1 2))*

*renvoie NIL car pas d’évalution dans le cas contraire (sinon).*

*> (if 27 1 2) renvoie 1. → Si 27 alors 1 sinon 2.*

*>( and t (+ 1 2)) renvoie t puis 3 ou seulement 3.
```



## 6. Les fonctions

Pour créer une fonction, utilisation de ***defun***.

*Ex : > (defun mon_third (X)*

​		*(car (cdr (cdr X)))*

​	*)*

​	*renvoie MON_THIRD*

*> (mon_third ‘(a b c d)) renvoie c*

*NB : On ne met pas de parenthèses pour délimiter l’argument.*

*> (mon_third maliste)*

*> ( > (+ 1 4) 3) renvoie T*

*écrit en fonction donne :*

*> (defun sommesup(x y z)*

​	*(> (+ x y) z)*

  *)*

*> (sommesup 1 4 3) renvoie T*

**Remarques :** Lisp ne fait aucune distinction entre une fonction, une procédure et un programme car pour lui, tout est fonction.

## 7. Récursivité

```lisp
> (defun mon_member(obj maliste)

​	(if (null maliste)

​		nil

​		(if (eql (car maliste) obj)

​			maliste

​			(mon_member obj (cdr ma liste))

​		)

​	)

​     )

> (mon_member ‘b ‘(a b c))
> (B C)

> (mon_member ‘z ‘(a b c))
> NIL	
```

## 8. Entrées/sorties

format : fonction de sortie

- 1er argument : où s'effectue la sortie
- 2ème argument : chaîne de caractères qui donne le format de sortie
- 1 ou plusieurs arguments à écrire

```lisp
> (format t "~A plus ~A égale ~A.~%" 2 3 (+ 2 3))
```

- t : sortie standard
- ~A : emplacement à remplir
- ~% : retour chariot
- Autres arguments : remplissage des emplacements de ~A

```lisp
> (2 plus 3 egale 5)
> NIL (dans l'utilisation intéractive)
```

read : fonction de lecture sans arguments

```lisp
> (defun demandeNombre (chaine)
    (format t "~A" chaine)
    (read)
  )
> (demandeNombre "Donner un nombre ")
> Donner un nombre 40
> 40 <-- prise en compte par read
```

## 9. Les variables

### a. Variables locales

let : permet de déclarer des variables locales et d'initialiser

```lisp
> (let ((x 1) (y 2)) (+ x y)) <-- la première et la dernière parenthèse permettent de délimiter le contexte des variables (elles sont locales à ce contexte)
```

```lisp
(defun ask_number()
    (format t "Entrer un nombre")
    (let ((val (read)))	<-- liste de paires de couples
         (if (numberp val) <-- si val est un nombre
             val		   <-- alors val
             (ask_number)  <-- sinon on rappelle la fonction
         )
    )
)
```

### b. Variables globales

defparameter : permet de déclarer des variables globales et de les intialiser

```lisp
> (defparameter *glob* 100) <-- les astérix permettent de distinguer une variable locale portant le même nom de la variable globale
> *GLOB*
```

### c. Constante

defconstant : permet de définir des constantes (déclaration + initialisation)

```lisp
> (defconstant limite (+ *glob* 150))
> 250
```

**Remarques :** boundp permet de savoir si la variable est constante ou globale

```lisp
> (boundp '*glob*)
T
```

## 10. L'affectation

setf : opérateur d'affectation le plus commun

```lisp
> (setf *glob* 5)
> 5

>(let ((n 10)))
	  (setf n 2)
	   n
 )
> 2
```

*NB : si l'on entre dans setf, une variable qui n'a pas été définit auparavent, elle sera globale*

```lisp
>(setf valeur (list 'a 'b 'c))
> ( A B C )
> valeur
> ( A B C )

> (setf (car valeur) 'n)
> ( N B C )

> (setf a 3 b 5 c 2) équivalent à (setf a 3) (setf b 5) (setf c 2)
```

## 11. Programmation fonctionnelle

=> Renvoie de valeur

```lisp
> (setf maliste '(c a r a t))
> ( C A R A T )

>(remove 'a maliste)
> ( C R T )

> maliste
> ( C A R A T )
```

**<u>But de Lisp :</u> faire des tests sans modifier les variables en utilisant l'interface intéractive.**

## 12. Fonctions comme des objets

function : opérateur identique à la quote.

```lisp
> (function +)
> #<compiled-function + 17BA4E>

>#'+
> #<compiled-function + 17BA4E>

>(apply #'+ '(1 2 3)) <-- apply nécessite que le dernier argument soit une liste
> 6

>(apply #'+ 1 2 '(3 4 5))
> 15

>(funcall #'+ 1 2 3) <-- équivalent à apply sans le besoin d'avoir une liste en dernier argument
> 6
```

une expression lambda = une liste + lambda + liste de paramètres + corps avec une ou plusieurs expressions

==> lambda est une **SYMBOLE**. 

```lisp
> (lambda (x) (+ x 100)) <-- on ne peut pas rappeler la fonction
équivalence : ((x) (+ x 100))

>( lambda (x y) (+ x y))
(x y) = liste de paramètres
(+ x y) = corps de fonction
>( (lambda(x) (+ x 100))
  	10) <-- passage de 10 à x
> 110

>(funcall #'(lambda(x) (+ x 100)) 10)
> 110
```

## 13. Les types

Les variables n'ont pas de types. Par contre, les valeurs ont un type.

Les types en Lisp forment uen hiérarchie. Un objet a toujours plusieurs types. *<u>ex :</u> 54 est de type fixnum, integer, rational, number, atom, t (supertype).*

```lisp
> (typep 55 'integer)
> T
```

# Chapitre 3 - Les structures de contrôle

## 1. Les blocs

**3 types :** progn, bloc, et tagbody

### a. progn

Evaluation des expressions dans le bloc se fait dans l'ordre. Renvoie la valeur de la dernière évaluation.

```lisp
> (progn 
		(format t "a")
		(format t "b")
		(+ 11 10)
  )
> ab
21 <-- retour à la ligne à cause du renvoi de la dernière évaluation
```

### b. block

Comme un progn avec un nom et une sortie de secours.

- 1ère argument : symbole, le nom du bloc
- arrêt à n'importe quelle étape de l'évaluation
- renvoie une valeur immédiatement avec **return-from** nomdubloc

```lisp
> (block exemple
	(format t "Nous sommes ici")
	(return-from exemple 'sortie)
    (format t "On reverra jamais cela")
  )
> Nous sommes ici
sortie
```

**Cas particulier :** Block n'a pas de nom

Son nom sera **nil**. Sortie automatique à un moment donné par **return**.

```lisp
> (block nil
	(return 27)
  )
> 27

> (dolist (x '(a b c d e))
      	  (format t "~A" x)
      	  (if (eql x 'c)
              (return 'done)
          )
  )
> A B C
DONE
```

### c. tagbody

Possibilité d'utiliser des GoTo.

**Labels :** atomes

```lisp
> (tagbody
   		(setf x 0)
  		top				<-- label
   		(setf x (+ x 1))
   		(format t "~A  " x)
   		(if (< x 10) <-- dés que x = 10, on sort
            (go top)
        )
   )
> 1 2 3 4 5 6 7 8 9 10
```

### **Remarques **

- progn est utilisé presque tout le temps car elle permet de faire les instructions les unes derrière les autres
- block est utilisé si une sortie de secours est nécessaire (équivalent du break)
- tagbody est utilisé rarement

## 2. Contexte lexical

Avec let, on crée un contexte lexical. Ainsi les variables se trouvant dans le contexte sont locales au contexte lexical.

```lisp
> (let ((x 7)(y 2))
       (format t "Nombre ")
       (+ x y)
  )
> Nombre 9
```

### Remarques 

Une expression "let" est comme un appel de fonction.

```lisp
> ( (lambda (x y)
            (format t "Nombre ")
            (+ x y)
    )
    7
    2
  )
> 9
```

On ne peut pas créer des variables locales avec "let" qui dépendent d'autres variables locales créées avec le même let.

```lisp
> (let ((x 2)(y (+ x 1))) <-- les deux x sont différents
       (+ x y)
  )

>((lambda (x y)
          (+ x y)
  )
    2
    (+ x 1) <-- x n'est pas connu
  )
```

Pour y remédier, il existe l'opérateur **let ***. 

```lisp
> (let* ((x 1)
        (y (+ x 1)))
        (+ x y)
  )
> 3

EQUIVALENT

>(let ((x 1))
      (let ((y (+ x 1)))
           (+ x y)
      )
 )
> 3

Création de deux contextes lexicaux
```

Les valeurs par défaut du let et let* sont nil.

```lisp
> (let (x y)
       (list x y)
  )
>(NIL NIL)
```

## 3. Structures conditionnelles

### a. when

Composée d'une expression (condition) et d'un corps. Le corps est évalué si l'expression renvoie T.

```lisp
> (when (oddp nombre)
		(format t "nombre est impair")
		(+ nombre 1)
  )
> nombre est impair

EQUIVALENT

>(if (oddp nombre)
     (progn
         (format t "nombre est imapir")
         (+ nombre 1)
     )
 )
```

### b. unless

Contraire de when. Le corps est évalué si l'expression testée est fausse (renvoie nil)

### c. cond

Mère de toutes les structures conditionnelles car elle permet d'avoir plusieurs conditions auquelles elle associe un corps (et un progn implicite) et évite les if imbriquées.

```lisp
> (defun mon_member (obj maliste)
      (if (null maliste)
          nil
          (if (eql (car maliste) obj)
              maliste
              (mon_member obj (cdr maliste))
          )
      )
  )

EQUIVALENT

> (defun mom_member (obj maliste)
      (cond 
          ((null maliste) nil)
            ((eql (car maliste) obj) maliste)
          		(t mom_member obj(cdr maliste)) <-- valeur par défaut
      )
  )
```

#### Forme générale

```lisp
(cond (conditions expressions_0*)
	  (condition_1 expressions_1*)
	  				.
	  				.
	  				.
	  (condition_n expressions_n*))
)
```

#### Remarque

Si pas d'expression après la condition, la valeur renvoyé est la condition.

```lisp
> (cond (99)
> 99
```

### d. Case

Comparaison d'une valeur avec plusieurs constantes.

```lisp
>(defun longueur_mois(mois)
     (case moi
         ((jan mar mai juil aout oct dec) 31)
         ((avr juin sept nov) 30)
         (fev (if (leap_year) 29 28))
         (otherwise "mois inconnu") <-- valeur par défaut
     )
  )
```

### e. typecase

Similaire au case mais pour comparer des types.

## 4. Les structures d'itérations

### a. do

Structure itérative de base.

Sortir d'une boucle : go, return, return-from

- 1er argument : liste de spécifications des variables de la forme **(variable  valeur_initiale  maj)**

  **valeur_initiale** et **maj** sont optionnels. valeur_initiale vaudra nil.

```commonlisp
(defun carres(debut fin)
	(do ((i debut (+ i 1)))
		((> i fin) 'done) <-- done optionnel
		(format t "~A ~A%" i (* i i))
	)
)

> (carres 2 3)
2 4
3 9
DONE

(defun carres_recursif (debut fin)
    (if (> debut fin)
        'done
       (progn
    	(format t "~A ~A%" debut (* debut debut))
        (carres_recursif(+ debut 1) fin)
       )
    )
)
```

### b. dolist

Itérer sur les élements d'une liste.

```commonlisp
(dolist (y '(1 2 3 4) 'done')
		(format t "~A " y)
)

>1 2 3 4
DONE
```

### c. dotimes

Itérer exclusivement sur des entiers entre 0 et n-1.

```commonlisp
(dotimes (y 5 y) <- n = 5
	(format t "~A " y)
)
> 0 1 2 3 4
5
```

## 5. Abort

### a. Catch et throw

" catch label corps_expression"

```commonlisp
(defun mafonction()
    ...
	(catch 'abort
		(monautrefonction)
		(format t "On ne verra jamais cela") <-- ne sera pas exécuté
	)
)

(defun monautrefonction ()
	(throw 'abort 99) <-- 99 est un code d'erreur
)
```

### b. error

Permet d'interrompre une exécution mais le contrôle est transféré au Lisp error handler.

**Remarque :** 

**unwind-protect :** toutes les expressions après ce mot sont évaluées. Permet de ne pas laisser un programme dans un état inconsistant.

```commonlisp
(setf y 1)
1

(catch  'abort
	(unwind_protect
		(throw 'abort 99)
		(setf y 20)
	)
)
> 99
> y
20
```

# Chapitre 4 : Les structures de données dans Lisp

## 1. Les listes

Structure de données de base.

### 1.1 Cons

Paire de pointeurs :

- pointeur vers le premier élément de la liste (car)
- pointeur vers le reste de la liste (cdr)

```commonlisp
(setf y (cons 'a nil))
> (A)

(setf z (list 'a 'b 'c))
> (A B C) <- liste plate

(setf x (list 'a(list 'b 'c) 'd))
> (A (B C) D) <- liste chaînée

(car (cdr x))
> (B C)
```

**consp :** prédicat qui renvoie vrai si son argument est un cons.

**listp :** prédicat qui renvoie vrai si son argument est une liste.

```commonlisp
(defun monlistp(x)
	(or (null x)(consp x))
)
```

### 1.2 Egalite

**equal :** prédicat qui renvoie vrai si les listes en argument sont égales.

```commonlisp
(setf x (cons 'a nil))
> (A)
(eql x x) -> égalité de deux pointeurs
> T
(equal x (cons 'a nil))
> T
```

### 1.3 Pourquoi Lisp n'a pas de pointeurs ?

La notation préfixée est possible car Lisp permet de créer des listes augmentables grâce aux pointeurs.

```commonlisp
(setf x '(a b c))
> (A B C)

(setf y x)
> (A B C)

(eql x y)
> T
```

### 1.4 Construire des listes

**copy_list :** fonction qui prend une liste et renvoie une copie de cette liste dans une autre structure (cons).

```commonlisp
(setf x '(a b c)
	y(copy_list x)
)
> (A B C)

(eql x y)
> NIL

Renvoie vrai si les deux listes nulles.
```

**append :** fonction qui renvoie la concaténation de n'importe quel nombre de liste.

```commonlisp
(append '(a b) '(c d) '(e))
> (A B C D E)
```

### 1.5 Fonctions d'accès aux listes

#### a. nth

Donne l'élément de la liste se trouvant à une certaine position.

```commonlisp
(nth 0 '(a b c))
> A
```

#### b. nthcdr

Renvoie le n_ième cdr de la liste.

```commonlisp
(nthcdr 2 '(a b c))
>(C)

(defun monnthcdr (n maliste)
    (if (zerop n)
        maliste
        (monnthcdr(- n 1)(cdr maliste))
    )
)
```

#### c. last

Renvoie le dernier cons d'une liste.

```commonlisp
> (last '(a b c))
(C)
```

#### d. cadr

Equivalent à **(car (cdr x))**

#### e. carddr
