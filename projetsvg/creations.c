// création et affichage
#ifndef CREATIONS_H
#define CREATIONS_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "creations.h"
#include "structures.h"
#include "couleurs.h"

Cercle creerCercle() {
    Cercle c;
    char tmp[64];
    printf("x : "); scanf("%d", &c.x);
    printf("y : "); scanf("%d", &c.y);
    printf("rayon : "); scanf("%d", &c.rayon);
    printf("couleur du trait (#hex ou nom CSS) : ");
    scanf("%63s", tmp);
    normalizeHexColor(tmp, c.couleurDuTrait, sizeof(c.couleurDuTrait));
    printf("couleur du remplissage (#hex ou nom CSS) : ");
    scanf("%63s", tmp);
    normalizeHexColor(tmp, c.couleurDuRemplissage, sizeof(c.couleurDuRemplissage));
    return c;
}

void afficherCercle(Cercle c) {
    printf("Cercle (%d,%d) r=%d, trait=%s, rempl=%s\n",
           c.x, c.y, c.rayon, c.couleurDuTrait, c.couleurDuRemplissage);
}

Ellipse creerEllipse() {
    Ellipse e;
    char tmp[64];
    printf("x : "); scanf("%d", &e.x);
    printf("y : "); scanf("%d", &e.y);
    printf("rayon X : "); scanf("%d", &e.rayonX);
    printf("rayon Y : "); scanf("%d", &e.rayonY);
    printf("couleur du trait : "); scanf("%63s", tmp);
    normalizeHexColor(tmp, e.couleurDuTrait, sizeof(e.couleurDuTrait));
    printf("couleur du remplissage : "); scanf("%63s", tmp);
    normalizeHexColor(tmp, e.couleurDuRemplissage, sizeof(e.couleurDuRemplissage));
    return e;
}

void afficherEllipse(Ellipse e) {
    printf("Ellipse (%d,%d) RX=%d RY=%d trait=%s rempl=%s\n",
           e.x, e.y, e.rayonX, e.rayonY, e.couleurDuTrait, e.couleurDuRemplissage);
}

Ligne creerLigne() {
    Ligne l;
    char tmp[64];
    printf("x : "); scanf("%d", &l.x);
    printf("y : "); scanf("%d", &l.y);
    printf("couleur du trait : "); scanf("%63s", tmp);
    normalizeHexColor(tmp, l.couleurDuTrait, sizeof(l.couleurDuTrait));
    return l;
}

void afficherLigne(Ligne l) {
    printf("Ligne (%d,%d) couleur=%s\n", l.x, l.y, l.couleurDuTrait);
}

Carre creerCarre() {
    Carre ca;
    char tmp[64];
    printf("x : "); scanf("%d", &ca.x);
    printf("y : "); scanf("%d", &ca.y);
    printf("côté : "); scanf("%d", &ca.cote);
    printf("couleur du trait : "); scanf("%63s", tmp);
    normalizeHexColor(tmp, ca.couleurDuTrait, sizeof(ca.couleurDuTrait));
    printf("couleur du remplissage : "); scanf("%63s", tmp);
    normalizeHexColor(tmp, ca.couleurDuRemplissage, sizeof(ca.couleurDuRemplissage));
    return ca;
}

void afficherCarre(Carre ca) {
    printf("Carré (%d,%d) côté=%d, trait=%s, rempl=%s\n",
           ca.x, ca.y, ca.cote, ca.couleurDuTrait, ca.couleurDuRemplissage);
}

Rectangle creerRectangle() {
    Rectangle r;
    char tmp[64];
    printf("x : "); scanf("%d", &r.x);
    printf("y : "); scanf("%d", &r.y);
    printf("largeur : "); scanf("%d", &r.largeur);
    printf("hauteur : "); scanf("%d", &r.hauteur);
    printf("couleur du trait : "); scanf("%63s", tmp);
    normalizeHexColor(tmp, r.couleurDuTrait, sizeof(r.couleurDuTrait));
    printf("couleur du remplissage : "); scanf("%63s", tmp);
    normalizeHexColor(tmp, r.couleurDuRemplissage, sizeof(r.couleurDuRemplissage));
    return r;
}

void afficherRectangle(Rectangle r) {
    printf("Rectangle (%d,%d) %dx%d, trait=%s, rempl=%s\n",
           r.x, r.y, r.largeur, r.hauteur, r.couleurDuTrait, r.couleurDuRemplissage);
}

Polyline creerPolyline() {
    Polyline p;
    printf("Nombre de points : ");
    scanf("%d", &p.nbPoints);
    for (int i = 0; i < p.nbPoints; i++) {
        printf("Point %d - x y : ", i + 1);
        scanf("%d %d", &p.points[i][0], &p.points[i][1]);
    }
    printf("Couleur du trait en hex : ");
    scanf("%19s", p.couleurDuTrait);
    printf("Couleur du remplissage en hex : ");
    scanf("%19s", p.couleurDuRemplissage);
    return p;
}

void afficherPolyline(Polyline p) {
    printf("Polyline (%d), trait=%s, rempl=%s\n",
           p.nbPoints, p.couleurDuTrait, p.couleurDuRemplissage);
}

Polygone creerPolygone() {
    Polygone p;
    printf("Nombre de points : ");
    scanf("%d", &p.nbPoints);
    for (int i = 0; i < p.nbPoints; i++) {
        printf("Point %d - x y : ", i + 1);
        scanf("%d %d", &p.points[i][0], &p.points[i][1]);
    }
    printf("Couleur du trait (#hex) : ");
    scanf("%19s", p.couleurDuTrait);
    printf("Couleur du remplissage (#hex) : ");
    scanf("%19s", p.couleurDuRemplissage);
    return p;
}

Trajectoire creerTrajectoire() {
    Trajectoire t;
    printf("Entrez l'attribut 'd' du chemin SVG (ex : M10 10 L90 90 Z) : ");
    scanf(" %[^\n]", t.d);
    printf("Couleur du trait (#hex) : ");
    scanf("%19s", t.couleurDuTrait);
    printf("Couleur du remplissage (#hex) : ");
    scanf("%19s", t.couleurDuRemplissage);
    return t;
}

Groupe creerGroupe() {
    Groupe g;
    printf("Nom ou ID du groupe : ");
    scanf("%49s", g.id);
    return g;
}


#endif