#include "lecture.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STATES 100
#define MAX_SYMBOLS 100
#define MAX_TRANSITIONS 1000

int num_states, num_initial_states, num_final_states, num_transitions, num_symbols;
char states[MAX_STATES][3];
char symbols[MAX_SYMBOLS][2];
char transitions[MAX_TRANSITIONS][6];


void lecture(const char *inputPath, const char *outputPath) {
    FILE *inputFile = fopen(inputPath, "r"); // Ouvrir le fichier source en mode lecture
    if (inputFile == NULL) {
        perror("Erreur lors de l'ouverture du fichier d'entrée");
        return;
    }

    FILE *outputFile = fopen(outputPath, "w"); // Créer le fichier de sortie en mode écriture
    if (outputFile == NULL) {
        perror("Erreur lors de la création du fichier de sortie");
        fclose(inputFile);
        return;
    }

    char buffer[1024]; // Un buffer pour stocker les lignes lues
    while (fgets(buffer, sizeof(buffer), inputFile) != NULL) { // Lire chaque ligne du fichier source
        fputs(buffer, outputFile); // Écrire la ligne dans le fichier de sortie
    }

    // Fermer les fichiers ouverts
    fclose(inputFile);
    fclose(outputFile);
}
