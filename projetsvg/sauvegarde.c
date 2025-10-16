// ===== SAUVEGARDE =====

#ifndef SAUVEGARDE_C
#define SAUVEGARDE_C
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "sauvegarde.h"

void sauvegarderCercle(Cercle c) {
    FILE *f = fopen("formes.txt", "a");
    if (!f) return;
    fprintf(f, "Cercle : %d %d %d %s %s\n", c.x, c.y, c.rayon, c.couleurDuTrait, c.couleurDuRemplissage);
    fclose(f);
}
void sauvegarderEllipse(Ellipse e) {
    FILE *f = fopen("formes.txt", "a");
    if (!f) return;
    fprintf(f, "Ellipse : %d %d %d %d %s %s\n", e.x, e.y, e.rayonX, e.rayonY, e.couleurDuTrait, e.couleurDuRemplissage);
    fclose(f);
}
void sauvegarderLigne(Ligne l) {
    FILE *f = fopen("formes.txt", "a");
    if (!f) return;
    fprintf(f, "Ligne : %d %d %s\n", l.x, l.y, l.couleurDuTrait);
    fclose(f);
}
void sauvegarderCarre(Carre ca) {
    FILE *f = fopen("formes.txt", "a");
    if (!f) return;
    fprintf(f, "Carre : %d %d %d %s %s\n", ca.x, ca.y, ca.cote, ca.couleurDuTrait, ca.couleurDuRemplissage);
    fclose(f);
}
void sauvegarderRectangle(Rectangle r) {
    FILE *f = fopen("rectangles.txt", "a");
    if (!f) return;
    fprintf(f, "Rectangle : %d %d %d %d %s %s\n", r.x, r.y, r.largeur, r.hauteur, r.couleurDuTrait, r.couleurDuRemplissage);
    fclose(f);
}

void sauvegarderPolyline(Polyline p) {
    FILE *f = fopen("polylines.txt", "a");
    if (!f) return;
    fprintf(f, "Polyline : %d ", p.nbPoints);
    for (int i = 0; i < p.nbPoints; i++)
        fprintf(f, "%d,%d ", p.points[i][0], p.points[i][1]);
    fprintf(f, "%s %s\n", p.couleurDuTrait, p.couleurDuRemplissage);
    fclose(f);
}

void sauvegarderPolygone(Polygone p) {
    FILE *f = fopen("polygones.txt", "a");
    if (!f) return;
    fprintf(f, "Polygone : %d ", p.nbPoints);
    for (int i = 0; i < p.nbPoints; i++)
        fprintf(f, "%d,%d ", p.points[i][0], p.points[i][1]);
    fprintf(f, "%s %s\n", p.couleurDuTrait, p.couleurDuRemplissage);
    fclose(f);
}

void sauvegarderTrajectoire(Trajectoire t) {
    FILE *f = fopen("trajectoires.txt", "a");
    if (!f) return;
    fprintf(f, "Trajectoire : %s %s %s\n", t.d, t.couleurDuTrait, t.couleurDuRemplissage);
    fclose(f);
}

void sauvegarderGroupe(Groupe g) {
    FILE *f = fopen("groupes.txt", "a");
    if (!f) return;
    fprintf(f, "Groupe : %s\n", g.id);
    fclose(f);
}

#endif