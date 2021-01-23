# drunkmachine
Construction d'une machine à cocktail

Auteur: Louis D

Le but de cette est d'apprend a se servir de differents outils tel que les ecrans LCD, boutons poussoirs et les relais.

Materiel de depart:
===================

- 2 arduinos UNO
- 1 bloc relais
- 1 pompe alimentaire
- 1 ecran LCD (DMC 40457)
- Joystick shield (NOKIA 5110)

Pourquoi ce choix?
==================

Beaucoup de materiel de recup' notamment le joystick shield et l'ecran (qui va me poser bien des soucis)


Premiere Etape: La recherche de cocktail
========================================

Je voudrais un minimu
m de boissons de bases pour donner un maximum de cocktails.

Internet etant mon ami et n'etant pas barman j'ai fait un grand tableau excel contenant mes resultat (cf cocktail.xls)

Oui c'étais long mais je suis plutôt content du resultat.

Deuxieme Etape: Maitriser les ecrans LCD
========================================
 
Je n'en ai jamais utilise du coup c'etais le moment rever, j'ai regarder un grand nombre de tuto sur internet qui m'ont bien fait comprendre le principe.

Je decide alors de regarder le datasheet de mon ecran et je remarque que j'ai 2 enable . Je regarde alors sur la librairie liquid.h de arduino et ce n'est pas pris en charge.

Je cherche donc si quelqu'un etait dans ma situation et le seul que j'ai trouve
a prefere changer d'ecran. Mon budget etant tres limite je suis moyen chaud pourchanger d'ecran. 

En fait, la librairie n'est pas conçu pour gerer un ecran de 40x4. Je decide de passe outre en reliant les deux enable mais rien ne s'affiche.

Il faut que je mette du constraste je branche la broche du constraste (VEE) sur un pin PWM de la carte (3,5,6,9,10 ou 11) je cherche cherche le constraste idéal en ne branchant que le premier enable.

Ce "bricolage" fonction convenablement je branche le constraste sur le pin 6 et j'utilise la fonction analogWrite(6,5) ça suffit je mettrais une option plus tard pour le régler.

Je test mon ecran et remarque que je ne peux utiliser que les deux premiere lignes ce qui me permet d'ecrire 80 caractere, je devrais m'en sortir. Je reglerais ce probleme en achetant un petit module TWILCD 40x4 dès que je trouverais un peu de fond.

Bref mon ecran marche ne reste plus qu'a coder.

Etape 3: Maitriser le shield
============================

Pour ce projet je ne pense pas utiliser le joystick mais seulement les 6 boutons poussoirs

A,B,C,D comme choix et E,F pour naviguer dans le menu

Je regarde sur le net et je trouve tous les test dont j'ai besoin

J'utilise ce shield uniquement parce que je l'avais déjà, je vous encourage plutot à prendre des boutons poussoir se sera plus logique prenait en deux minimum  
un pour la selection l'autre pour la navigation

Etape 4: Coder les menus et faire discuter mes arduinos entre elles
===================================================================

Je suis etudiant en informatique donc le code n'est pas un vrai obstacle j'aurais prefere que des threads (multitache) soit possible sur arduino mais je vais faire sans.

1/ La structure de données
--------------------------

Je décide arbitrairement de faire un tableau de chaine de caractère contenant les noms des boissons, la reference de chaque boissons sera donc sa position dans le tableau 

2/ Construction du menu 
-----------------------

Je dispositionne les boissons quatre par quatre de manière à ce que ça ressembleà la disposition de mon shield

		   A:Boisson1
	D:Boisson2		B:Boisson3
		   C:Boisson4
	F:precedent		E:suivant

Il faudra que je fasse attention que le nom des boissons de rang 2*i%4 et 3*i%4 n'excede pas 19 caractere


Etape 5: Calibrage de la pompe
==============================

J'ai une pompe alimentaire, et un bloc je vais son debit par seconde pour savoir les quantité dans les différents cocktail.

A ce niveau j'hesite encore entre deux stategie soit j'utilise une pompe et une electrovanne par boisson, soit je n'utilise que des electrovanne soit j'utilise une pompe par boisson .

Pour l'instant je penche plutôt pour une pompe par boisson car c'est le plus facile mais aussi le plus couteux donc j'y reviendrais plus tard.

