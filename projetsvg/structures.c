// structures.h
#ifndef STRUCTURES_C
#define STRUCTURES_C
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "structures.h"

typedef struct {
    int x;
    int y;
    int rayon;
    char couleurDuTrait[20];
    char couleurDuRemplissage[20];
} Cercle;

typedef struct {
    int x;
    int y;
    int rayonX;
    int rayonY;
    char couleurDuTrait[20];
    char couleurDuRemplissage[20];
} Ellipse;

typedef struct {
    int x;
    int y;
    char couleurDuTrait[20];
} Ligne;

typedef struct {
    int x;
    int y;
    int cote;
    char couleurDuTrait[20];
    char couleurDuRemplissage[20];
} Carre;

typedef struct {
    int x;
    int y;
    int largeur;
    int hauteur;
    char couleurDuTrait[20];
    char couleurDuRemplissage[20];
} Rectangle;

typedef struct {
    int nbPoints;
    int points[100][2];
    char couleurDuTrait[20];
    char couleurDuRemplissage[20];
} Polyline;

typedef struct {
    int nbPoints;
    int points[100][2];
    char couleurDuTrait[20];
    char couleurDuRemplissage[20];
} Polygone;

typedef struct {
    char d[512];
    char couleurDuTrait[20];
    char couleurDuRemplissage[20];
} Trajectoire;

typedef struct {
    char id[50]; 
} Groupe;

#endif
