#ifndef MODIFIER_C
#define MODIFIER_C
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "modifier.h"

void modifierForme() {
    int type;
    printf("\nType de forme à modifier :\n");
    printf("1. Cercle\n2. Ellipse\n3. Ligne\n4. Carré\n5. Rectangle\nVotre choix : ");
    scanf("%d", &type);

    char *nomFichier = NULL;
    switch(type){
        case 1: nomFichier = "cercles.txt"; break;
        case 2: nomFichier = "ellipses.txt"; break;
        case 3: nomFichier = "lignes.txt"; break;
        case 4: nomFichier = "carres.txt"; break;
        case 5: nomFichier = "rectangles.txt"; break;
        default: printf("Choix invalide.\n"); return;
    }

    FILE *in = fopen(nomFichier, "r");
    if(!in){ 
        printf("Aucune forme enregistrée.\n"); 
        return; 
    }

    char lignes[100][256];
    int nbLignes = 0;
    while(fgets(lignes[nbLignes], sizeof(lignes[nbLignes]), in)){
        nbLignes++;
        if(nbLignes>=100) break;
    }
    fclose(in);

    if(nbLignes==0){ 
        printf("Aucune forme dans ce fichier.\n"); 
        return; 
    }

    printf("\n--- Liste des formes ---\n");
    for(int i=0;i<nbLignes;i++){
        printf("%d. %s", i+1, lignes[i]);
    }

    int choix;
    printf("\nNuméro de la forme à modifier : ");
    scanf("%d", &choix);

    if(choix<1 || choix>nbLignes){ 
        printf("Choix invalide.\n"); 
        return; 
    }


    // === MODIFICATION SELON LE TYPE ===
    if(type == 1) { // CERCLE
        int x, y, r;
        char trait[20], rempl[20];
        sscanf(lignes[choix-1], "Cercle : %d %d %d %s %s", &x, &y, &r, trait, rempl);

        printf("Ancien x=%d → Nouveau : ", x);
        scanf("%d", &x);
        printf("Ancien y=%d → Nouveau : ", y);
        scanf("%d", &y);
        printf("Ancien rayon=%d → Nouveau : ", r);
        scanf("%d", &r);
        printf("Ancienne couleur du trait=%s → Nouvelle (#hex) : ", trait);
        scanf("%63s", trait);
        printf("Ancienne couleur du remplissage=%s → Nouvelle (#hex) : ", rempl);
        scanf("%63s", rempl);

        sprintf(lignes[choix-1], "Cercle : %d %d %d %s %s\n", x, y, r, trait, rempl);
    }

    else if(type == 2) { // ELLIPSE
        int x, y, rx, ry;
        char trait[20], rempl[20];
        sscanf(lignes[choix-1], "Ellipse : %d %d %d %d %s %s", &x, &y, &rx, &ry, trait, rempl);

        printf("Ancien x=%d → Nouveau : ", x); scanf("%d", &x);
        printf("Ancien y=%d → Nouveau : ", y); scanf("%d", &y);
        printf("Ancien rayonX=%d → Nouveau : ", rx); scanf("%d", &rx);
        printf("Ancien rayonY=%d → Nouveau : ", ry); scanf("%d", &ry);
        printf("Couleur du trait=%s → Nouvelle (#hex) : ", trait); scanf("%63s", trait);
        printf("Couleur du remplissage=%s → Nouvelle (#hex) : ", rempl); scanf("%63s", rempl);

        sprintf(lignes[choix-1], "Ellipse : %d %d %d %d %s %s\n", x, y, rx, ry, trait, rempl);
    }

    else if(type == 3) { // LIGNE
        int x, y;
        char trait[20];
        sscanf(lignes[choix-1], "Ligne : %d %d %s", &x, &y, trait);

        printf("Ancien x=%d → Nouveau : ", x); scanf("%d", &x);
        printf("Ancien y=%d → Nouveau : ", y); scanf("%d", &y);
        printf("Couleur du trait=%s → Nouvelle (#hex) : ", trait); scanf("%63s", trait);

        sprintf(lignes[choix-1], "Ligne : %d %d %s\n", x, y, trait);
    }

    else if(type == 4) { // CARRE
        int x, y, cote;
        char trait[20], rempl[20];
        sscanf(lignes[choix-1], "Carre : %d %d %d %s %s", &x, &y, &cote, trait, rempl);

        printf("x=%d → Nouveau : ", x); scanf("%d", &x);
        printf("y=%d → Nouveau : ", y); scanf("%d", &y);
        printf("Côté=%d → Nouveau : ", cote); scanf("%d", &cote);
        printf("Trait=%s → Nouveau (#hex) : ", trait); scanf("%63s", trait);
        printf("Remplissage=%s → Nouveau (#hex) : ", rempl); scanf("%63s", rempl);

        sprintf(lignes[choix-1], "Carre : %d %d %d %s %s\n", x, y, cote, trait, rempl);
    }

    else if(type == 5) { // RECTANGLE
        int x, y, w, h;
        char trait[20], rempl[20];
        sscanf(lignes[choix-1], "Rectangle : %d %d %d %d %s %s", &x, &y, &w, &h, trait, rempl);

        printf("x=%d → Nouveau : ", x); scanf("%d", &x);
        printf("y=%d → Nouveau : ", y); scanf("%d", &y);
        printf("Largeur=%d → Nouvelle : ", w); scanf("%d", &w);
        printf("Hauteur=%d → Nouvelle : ", h); scanf("%d", &h);
        printf("Trait=%s → Nouveau (#hex) : ", trait); scanf("%63s", trait);
        printf("Remplissage=%s → Nouveau (#hex) : ", rempl); scanf("%63s", rempl);

        sprintf(lignes[choix-1], "Rectangle : %d %d %d %d %s %s\n", x, y, w, h, trait, rempl);
    }

    // === SAUVEGARDE ===
    FILE *out = fopen(nomFichier, "w");
    for(int i=0; i<nbLignes; i++){
        fputs(lignes[i], out);
    }
    fclose(out);

    printf("✅ Forme modifiée avec succès !\n");
}

#endif