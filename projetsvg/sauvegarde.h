// ===== SAUVEGARDE =====

#ifndef SAUVEGARDE_H
#define SAUVEGARDE_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "structures.h"


void sauvegarderCercle(Cercle c);
void sauvegarderEllipse(Ellipse e);
void sauvegarderLigne(Ligne l);
void sauvegarderCarre(Carre ca);
void sauvegarderRectangle(Rectangle r);

void sauvegarderPolyline(Polyline p);
void sauvegarderPolygone(Polygone p);

void sauvegarderTrajectoire(Trajectoire t);
void sauvegarderGroupe(Groupe g);

#endif