#include "structures.h"
#include "couleurs.h"
#include "creations.h"
#include "modifier.h"
#include "supprimer.h"
#include "sauvegarde.h"
#include "html.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// MAIN
int main() {
    int menuPrincipal;

    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Creer une forme\n");
        printf("2. Supprimer une forme\n");
        printf("3. Generer la page HTML\n");
        printf("4. Modifier une forme\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &menuPrincipal);

        switch (menuPrincipal) {
            case 1: {
                int choixForme;
                do {
                    printf("\n--- MENU DES FORMES ---\n");
                    printf("1. Cercle\n2. Ellipse\n3. Ligne\n4. Carré\n5. Rectangle\n6. Enchainement de lignes\n7. Polygone\n8. Trajectoire\n9. Groupe\n0. Retour\nChoix : ");
                    scanf("%d", &choixForme);

                    switch (choixForme) {
                        case 1: {
                            Cercle c = creerCercle();
                            afficherCercle(c);
                            int s; printf("Sauvegarder ? (1=Oui/0=Non): "); scanf("%d", &s);
                            if (s) sauvegarderCercle(c);
                            break;
                        }
                        case 2: {
                            Ellipse e = creerEllipse();
                            afficherEllipse(e);
                            int s; printf("Sauvegarder ? (1=Oui/0=Non): "); scanf("%d", &s);
                            if (s) sauvegarderEllipse(e);
                            break;
                        }
                        case 3: {
                            Ligne l = creerLigne();
                            afficherLigne(l);
                            int s; printf("Sauvegarder ? (1=Oui/0=Non): "); scanf("%d", &s);
                            if (s) sauvegarderLigne(l);
                            break;
                        }
                        case 4: {
                            Carre ca = creerCarre();
                            afficherCarre(ca);
                            int s; printf("Sauvegarder ? (1=Oui/0=Non): "); scanf("%d", &s);
                            if (s) sauvegarderCarre(ca);
                            break;
                        }
                        case 5: {
                            Rectangle r = creerRectangle();
                            afficherRectangle(r);
                            int s; printf("Sauvegarder ? (1=Oui/0=Non): "); scanf("%d", &s);
                            if (s) sauvegarderRectangle(r);
                            break;
                        }
                        case 6: {
                            Polyline p = creerPolyline();
                            afficherPolyline(p);
                            int s; printf("Sauvegarder ? (1=Oui/0=Non): "); scanf("%d", &s);
                            sauvegarderPolyline(p);
                            break;
                        }
                        case 7: {
                            Polygone p = creerPolygone();
                            sauvegarderPolygone(p);
                            break;
                        }
                        case 8: {
                            Trajectoire t = creerTrajectoire();
                            sauvegarderTrajectoire(t);
                            break;
                        }
                        case 9: {
                            Groupe g = creerGroupe();
                            sauvegarderGroupe(g);
                            break;
                        }

                        default: break;
                    }
                } while (choixForme != 0);
                break;
            }
            case 2:
                supprimerForme();
                break;
            case 3:
                genererHTML();
                break;
            case 4:
                modifierForme();
                break;
            case 0:
                printf("Fin du programme.\n");
                break;
            default:
                printf("Choix invalide.\n");
        }

    } while (menuPrincipal != 0);

    return 0;
}