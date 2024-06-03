The objective of this project is to develop a preliminary version of a multimedia set-top box software capable of playing music, videos, movies, and displaying photos. The development will be carried out in stages, focusing on defining and implementing essential classes and functionalities that will be gradually improved upon. It is recommended to carefully read through each step's entire text, including any notes or remarks, to ensure complete understanding before proceeding with the task.

# INF224

Ce projet a été réalisé par Elie NAKAD

***

## Build & Run 

Commencer par lancer le serveur : 
Ouvrir un terminal et aller dans le répertoir "cpp" puis taper "make run".

Le serveur se mettra en écoute sur le port 3331.

Puis lancer le client swing : 
Ouvrir un autre terminal et aller dans le répertoir "swing" puis taper "make run".

(Il faut bien lancer le serveur avant le client.)

***

Les étapes réalisées sont celles de 1 à 11 de la partie 1 ainsi que les 4 étapes de la partie 2.

## Partie C++

### Etape 1 : 

Le projet a été réalisé sur l'IDE QtCreator. 

### Etape 2 :

La classe de base s'appelle Multimedia (Multimedia.h pour le fichier header et Multimedia.cpp pour le fichier source. La classe possède deux variables d'instances (nom de l'objet et nom du fichier).
Elle possède une méthode "printVariables" qui permet d'afficher les variables de l'objet.

### Etape 3 :

Les tests effectués se trouver dans les commentaires du fichier main.cpp.

### Etape 4 :

La méthode play de la classe multimedia est une fonction virtuelle pure (ou abstraite) puisqu'elle ne peut pas être implémentée : chaque objet nécessite un utilitaire différent et le comportement devra être précisé dans les sous-classes. Il faut la déclarer avec le mot clé "virtual" au début.
La classe Multimedia est devenue abstraite puisqu'elle contient une méthode virtuelle, il n'est donc plus possible de l'instancier. 

### Etape 5 : Traitement générique (en utilisant le polymorphisme) 

La propriété caractéristique de l'orienté objet qui permet de faire cela est le polymorphisme. En effet, nous n'avons pas eu besoin de préciser le type précis de l'objet pour que le programme appelle la bonne fonction dans la boucle. Cela permet de traiter de manière uniforme les objets de type Photo et ceux de type Video avec les mêmes fonctions play et printVariables (sans connaître leur implémentation). 

En c++, il faut déclarer les méthodes de la classe mère virtual (sinon la liaison est statique et il utilise la définition de la classe mère et non de la classe fille). Les élements du tableau sont des pointeurs. Les pointeurs sont nécessaires car les objets du tableau ne sont pas tous de même taille. 

Java utilise automatiquement des références (équivalent aux pointeurs mais la valeur de l'adresse est cachéé).

### Etape 6 : Films et tableaux

Pour que l'objet Film ait plein contrôle sur ses données et que son tableau de durées ne puisse pas être modifié à son insu, il faut que le contenu du tableau passé en paramètre soit copié. De plus, pour que le contenu du tableau renvoyé par un accesseur ne soit pas modifié, il suffit d'utiliser le mot clé const (signature : const int * getChapters) et d'effectuer une copie du tableau. 
Il faut que la copie en soit pas superficielle. Pour cela, on peut créer un opérateur de copie et surcharger l'opérateur d'affectation.

### Etape 7 : Destruction et copie des objets

Pour éviter toute fuite mémoire, il faut appeler delete dans le desctructeur de Film puisque nous avons créer un nouvel objet avec new (tableau des durées). La copie d'objet peut poser problème si l'on créé un nouvel objet et qu'on oublie de le supprimer. Il ne faut pas oublier d'appeler delete.

### Etape 8 : Créer des groupes

La class group hérite de la classe template list<>.
Il faut des pointeurs d'objets car les objets ne sont pas tous de même taille. 
En Java, des références (similaires à des pointeurs) sont automatiquement utilisées.

### Etape 9 : Gestion automatique de la mémoire

Par la suite, nous utiliserons des smarts pointers (shared_ptr<type>).
Un objet est détruit s'il n'appartient plus à aucun groupe.

### Etape 10 : Gestion cohérente des données

On crée une classe Data capable de gérer les objets Multimedia et les groupes. Cela permet une meilleur cohérence des données.
Cette classe permet de créer tout type d'objet multimedia, un groupe, de rechercher et d'afficher un objet multimedia et un groupe à partir de son nom et de jouer l'objet multimedia. La classe permet également de supprimer un objet multimedia ou un groupe à partir de son nom (l'objet est totalement détruit s'il n'appartient plus à aucune table).


### Etape 11 : Client / serveur

On ajoute la méthode processRequest à notre classe Data qui permet de traiter les requêtes.
On retourne le résultat dans le string "response" donné en paramètres.

***

## Partie Java Swing

### Etape 1: 

La deuxième stratégie pour spécifier le comportement des boutons a été implémenté dans la classe 'Window'. On peut remarquer que si l'on oublie de mettre la zone de texte dans un 'scrollPane' (qui dispose d'un ascenseur), on ne voit plus le texte affiché à partir d'un certain de lignes affichées.  

### Etape 2:  Menus, barre d'outils et actions

La deuxième étape (différente de la première) a été implémenté dans la classe 'ControlWindow'.
J'ai choisi d'utiliser les actions afin de spécifier toutes les caractéristiques des boutons.
On crée donc des sous-classes de 'AbstractAction' imbriquée dans notre 'ControlWindow'.


### Etape 3: Intéraction client/serveur

Nous utilisons le code Client.java pour communiquer avec le serveur C++.
Les insctructions d'utilisations de la fenêtre de contrôle sont spécifiées dans la zone de texte. En plus des boutons, j'ai utilisé une zone de texte supplémentaire (JTextField) permettant d'entrer le nom de l'objet demandé.
 


 
 ### Réponses aux questions 

### Etape 4
					                                            

Q: Comment appelle-t'on ce type de méthode et comment faut-il les déclarer ?

R: La méthode utilisée pour jouer les objets multimédia ne doit pas être implémentée dans la classe de base donc elle doit etre déclarée comme abstract en utilisant le keyword virtual et mettant la fonction=0.

										

Q: Si vous avez fait ce qui précède comme demandé, il ne sera plus possible d'instancer des objets de la classe de base. Pourquoi ?

R: Dans les classes vidéo et image on l'implémente en ajoutant le keyword override.
   Dans la classe main des erreurs vont apparaitre car on a créé un objet de type multimédia alors que cette classe est abstract donc on ne peut pas créer des objets si la classe est abstraite.


				                                                  
### Etape 5
				                                                    
		   
Q: Quelle est la propriété caractéristique de l'orienté objet qui permet de faire cela ? 

R: La propriété qui permet de traiter les objets appartenant à la même classe de base de la même manière est le polymorphisme.


### Etape 6									

Q: Qu'est-il spécifiquement nécessaire de faire dans le cas du C++ ? 

R: Dans C++, il faut ajouter le keyword "virtual" avant la méthode dans la classe de base ce qui oblige à utiliser la méthode de la classe fille.



Q: Quel est le type des éléments du tableau : le tableau doit-il contenir des objets ou des pointeurs vers ces objets ? Pourquoi ? Comparer à Java. 

R: Les éléments du tableau sont des pointeurs vers les objets. On ne peut pas créer un tableau contenant des objets de type multimédia parce que la classe est abstract (on ne peut pas créer des objets de cette classe). Les élements sont donc des pointeurs qui pointent vers des éléments de type video et photo qui ne sont pas abstract. Dans c++, les éléments du tableau doivent être de même type, donc les éléments doivent être des pointeurs car les pointeurs ont la même taille. De cette facon, les pointeurs peuvent pointer vers des éléments de types différents appartenant au même tableau.




### Etape 7


Q: Parmi les classes précédemment écrites quelles sont celles qu'il faut modifier afin qu'il n'y ait pas de fuite mémoire quand on détruit les objets ?

R: Dans la classe Film, quand on modifie le tableau de facon à ce qu'il pointe vers un nouveau tableau, l'ancien tableau n'est pas détruit automatiquement, ce qui cause un problème de gestion de mémoire, donc il faut modifier la classe Film et mettre un delete pour détruire l'ancien pointé. De plus, quand on détruit l'objet Film, le tableau de chapitre n'est pas détruit car il est créé avec un new, donc on doit ajouter un destructeur et mettre un delete pour détruire le tableau et par suite éviter le problème de fuite de mémoire.




Q: La copie d'objet peut également poser problème quand ils ont des variables d'instance qui sont des pointeurs. Quel est le problème et quelles sont les solutions ?

R: Concernant la copie d'objet, quand on copie un objet Film vers un autre en utilisant l'opérateur = les deux objets vont pointer vers le même élément. Donc quand on va détruire les deux objets consécutivement, le premier objet détruit va détruire avec lui le pointé qui est le tableau de chapitres, quand le deuxième objet va être détruit, ca va causer une erreur parce qu'il essaye de détruire un tableau déjà détruit.
Une solution c'est de définir un nouveau opérateur = qui sépare les deux objets, donc les deux pointeurs vont pointer vers deux pointés différents qui ont la même valeur.

### Etape 8


Q: Le groupe ne doit pas détruire les objets quand il est détruit car un objet peut appartenir à plusieurs groupes (on verra ce point à la question suivante). On rappelle aussi que la liste d'objets doit en fait être une liste de pointeurs d'objets. Pourquoi ? Comparer à Java. 

R: Dans c++, les éléments de la liste doivent être de même type, donc les éléments doivent être des pointeurs car les pointeurs ont la même taille. De cette facon, les pointeurs peuvent pointer vers des éléments de types différents appartenant à la même liste.


### Etape 9


Q: Les méthodes précédentes permettent d'assurer la cohérence de la base de données car quand on crée un objet on l'ajoute à la table adéquate. Par contre, ce ne sera pas le cas si on crée un objet directement avec new (il n'appartiendra à aucune table). Comment peut-on l'interdire, afin que seule la classe servant à manipuler les objets puisse en créer de nouveaux ? 

R: Afin d'éviter la manipulation des objets en dehors du database, on peut supprimer les opérateurs new et new[], les objets ne seront pas créés par allocation mémoire dynamique, mais on ne peut plus faire delete des objets smart pointers. On peut aussi mettre les constructeurs comme private et écrire une méthode private pour la création des smart pointers, en plus on doit mettre la classe database comme friend.


### Java Swing


Q: Lancez votre programme, cliquez plusieurs fois sur les deux premiers bouton, retaillez la fenêtre. Que constate-t'on ? 

R: On remarque quand on retaille la fenêtre que les boutons changent de position.

