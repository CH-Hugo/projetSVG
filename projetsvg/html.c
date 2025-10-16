// html pour affichage

#ifndef HTML_C
#define HTML_C
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "html.h"

void genererHTML() {
    FILE *in = fopen("formes.txt", "r");
    if (!in) {
        printf("Aucune forme enregistrée.\n");
        return;
    }

    FILE *out = fopen("formes.html", "w");
    if (!out) {
        printf("Impossible de créer formes.html\n");
        fclose(in);
        return;
    }

    fprintf(out,
        "<!DOCTYPE html><html lang='fr'><head><meta charset='UTF-8'><title>Formes SVG</title>"
        "<style>svg{border:1px solid #aaa;background:white}</style></head><body>"
        "<h1>Formes enregistrées</h1><svg width='1000' height='800'>\n");

    char line[256];
    while (fgets(line, sizeof(line), in)) {
        if (strncmp(line, "Cercle", 6) == 0) {
            int x, y, r; char t[20], fcol[20];
            if (sscanf(line, "Cercle : %d %d %d %19s %19s", &x, &y, &r, t, fcol) == 5)
                fprintf(out, "<circle cx='%d' cy='%d' r='%d' stroke='%s' fill='%s' stroke-width='2'/>\n",
                        x, y, r, t, fcol);
        }
        else if (strncmp(line, "Ellipse", 7) == 0) {
            int x, y, rx, ry; char t[20], fcol[20];
            if (sscanf(line, "Ellipse : %d %d %d %d %19s %19s", &x, &y, &rx, &ry, t, fcol) == 6)
                fprintf(out, "<ellipse cx='%d' cy='%d' rx='%d' ry='%d' stroke='%s' fill='%s' stroke-width='2'/>\n",
                        x, y, rx, ry, t, fcol);
        }
        else if (strncmp(line, "Ligne", 5) == 0) {
            int x, y; char t[20];
            if (sscanf(line, "Ligne : %d %d %19s", &x, &y, t) == 3)
                fprintf(out, "<line x1='%d' y1='%d' x2='%d' y2='%d' stroke='%s' stroke-width='2'/>\n",
                        x, y, x + 80, y, t);
        }
        else if (strncmp(line, "Carre", 5) == 0) {
            int x, y, c; char t[20], fcol[20];
            if (sscanf(line, "Carre : %d %d %d %19s %19s", &x, &y, &c, t, fcol) == 5)
                fprintf(out, "<rect x='%d' y='%d' width='%d' height='%d' stroke='%s' fill='%s' stroke-width='2'/>\n",
                        x, y, c, c, t, fcol);
        }
        else if (strncmp(line, "Rectangle", 9) == 0) {
            int x, y, w, h; char t[20], fcol[20];
            if (sscanf(line, "Rectangle : %d %d %d %d %19s %19s", &x, &y, &w, &h, t, fcol) == 6)
                fprintf(out, "<rect x='%d' y='%d' width='%d' height='%d' stroke='%s' fill='%s' stroke-width='2'/>\n",
                        x, y, w, h, t, fcol);
        }
    }

    fprintf(out, "</svg></body></html>");
    fclose(in);
    fclose(out);
    printf("Fichier 'formes.html' généré. Ouvre-le dans ton navigateur.\n");
}

#endif