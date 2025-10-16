#ifndef CREATIONS_H
#define CREATIONS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "structures.h"

Cercle creerCercle();
void afficherCercle(Cercle c);

Ellipse creerEllipse();
void afficherEllipse(Ellipse e); 

Ligne creerLigne();
void afficherLigne(Ligne l);

Carre creerCarre();
void afficherCarre(Carre ca);

Rectangle creerRectangle();
void afficherRectangle(Rectangle r);

Polyline creerPolyline();
void afficherPolyline(Polyline p);

Polygone creerPolygone();

Trajectoire creerTrajectoire();

Groupe creerGroupe();

#endif