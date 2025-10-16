#ifndef SUPPRIMER_C
#define SUPPRIMER_C
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "supprimer.h"

void supprimerForme() {
    int type;
    printf("\nType de forme à supprimer :\n");
    printf("1. Cercle\n2. Ellipse\n3. Ligne\n4. Carré\n5. Rectangle\nVotre choix : ");
    scanf("%d", &type);

    char *nomFichier = NULL;
    switch(type){
        case 1: nomFichier = "cercles.txt"; break;
        case 2: nomFichier = "ellipses.txt"; break;
        case 3: nomFichier = "lignes.txt"; break;
        case 4: nomFichier = "carres.txt"; break;
        case 5: nomFichier = "rectangles.txt"; break;
        case 6: nomFichier = "polylines.txt"; break;
        case 7: nomFichier = "polylines.txt"; break;

        default: printf("Choix invalide.\n"); return;
    }

    FILE *in = fopen(nomFichier, "r");
    if(!in){ printf("Aucune forme enregistrée.\n"); return; }

    char lignes[100][256];
    int nbLignes = 0;
    while(fgets(lignes[nbLignes], sizeof(lignes[nbLignes]), in)){
        nbLignes++;
        if(nbLignes>=100) break;
    }
    fclose(in);

    if(nbLignes==0){ printf("Aucune forme dans ce fichier.\n"); return; }

    printf("\n Liste des formes \n");
    for(int i=0;i<nbLignes;i++){
        printf("%d. %s", i+1, lignes[i]);
    }

    int choix;
    printf("Numéro de la forme à supprimer : ");
    scanf("%d", &choix);

    if(choix<1 || choix>nbLignes){ printf("Choix invalide.\n"); return; }

    FILE *out=fopen(nomFichier,"w");
    for(int i=0;i<nbLignes;i++){
        if(i!=choix-1) fputs(lignes[i], out);
    }
    fclose(out);
    printf("Forme supprimée.\n");
}

#endif