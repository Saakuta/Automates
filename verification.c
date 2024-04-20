#include "verification.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024



bool verif_deterministe(char automate[MAX_SIZE][MAX_SIZE], int nb_alphabet) {
    // Implémentation de la vérification...
    return true;
}

bool verif_complet(char automate[MAX_SIZE][MAX_SIZE], int nb_alphabet) {
    // Implémentation de la vérification...
    return true;
}

// Implémentations des autres fonctions de vérification...

void afficher_automate(char automate[MAX_SIZE][MAX_SIZE], int nb_alphabet) {
    for (int i = 0; i < nb_alphabet; i++) {
        printf("%s\n", automate[i]);
    }
}

// Fonction pour ajouter l'état poubelle
char **ajouter_etat_poubelle(char **automate, int *nb_lignes, int nb_colonnes) {
    char etat_poubelle[] = "P";
    int etat_poubelle_ajoute = 0;
    char alphabet[nb_colonnes - 1];

    // Récupération de l'alphabet d'entrée (toutes les colonnes sauf la première)
    for (int i = 0; i < nb_colonnes - 1; i++) {
        alphabet[i] = automate[0][i + 1];
    }

    // Trouver les transitions vides et ajouter l'état poubelle si nécessaire
    for (int row_index = 1; row_index < *nb_lignes; row_index++) {
        if (strlen(automate[row_index]) > 2) {
            for (int col_index = 1; col_index < nb_colonnes - 1; col_index++) {
                if ((automate[row_index][col_index] == '\0' || isspace(automate[row_index][col_index])) && (automate[0][col_index] == 'a' || automate[0][col_index] == 'b' || automate[0][col_index] == 'c' || automate[0][col_index] == 'd' || automate[0][col_index] == '*')) {
                    if (!etat_poubelle_ajoute) {
                        etat_poubelle_ajoute = 1;
                        // Ajout de l'état poubelle à l'automate avec des transitions vers lui-même pour les états 'a' et 'b'
                        (*nb_lignes)++;
                        automate = realloc(automate, *nb_lignes * sizeof(char *));
                        automate[*nb_lignes - 1] = malloc((nb_colonnes + 1) * sizeof(char));
                        strcpy(automate[*nb_lignes - 1], etat_poubelle);
                        for (int i = 0; i < nb_colonnes - 1; i++) {
                            automate[*nb_lignes - 1][i + 1] = (alphabet[i] == 'a' || alphabet[i] == 'b') ? 'P' : ' ';
                        }
                        automate[*nb_lignes - 1][nb_colonnes] = '\0';
                    }
                    // Remplacement de la transition vide par l'état poubelle
                    automate[row_index][col_index] = 'P';
                } else if (isspace(automate[row_index][col_index])) {
                    // Supprimer l'espace qui précède les autres transitions
                    automate[row_index][col_index] = '\0';
                }
            }
        } else if (strlen(automate[row_index]) > 0 && !etat_poubelle_ajoute) {
            // Compléter les lignes courtes avec des transitions "P"
            automate[row_index] = realloc(automate[row_index], (nb_colonnes + 1) * sizeof(char));
            for (int i = strlen(automate[row_index]); i < nb_colonnes; i++) {
                automate[row_index][i] = 'P';
            }
            automate[row_index][nb_colonnes] = '\0';
        } else {
            printf("Erreur: Ligne mal formatée dans le fichier CSV.\n");
        }
    }

    // Supprimer les "P" de la dernière colonne et ajuster la longueur des lignes si nécessaire
    for (int i = 0; i < *nb_lignes; i++) {
        if (automate[i][nb_colonnes - 1] == 'P') {
            automate[i][nb_colonnes - 1] = ' ';
        }
        if (strlen(automate[i]) > nb_colonnes) {
            automate[i] = realloc(automate[i], (nb_colonnes + 1) * sizeof(char));
            automate[i][nb_colonnes] = '\0';
        }
    }

    return automate;
}

// Fonction pour vérifier si un automate est déterministe
int test_deterministe(char **automate, int nb_lignes, int nb_colonnes) {
    for (int i = 1; i < nb_lignes; i++) {
        if (strlen(automate[i]) > 2) {
            int transitions[nb_colonnes - 1];
            memset(transitions, 0, sizeof(transitions));
            for (int j = 1; j < nb_colonnes - 1; j++) {
                if (automate[i][j] != '\0') {
                    transitions[automate[i][j] - 'A']++;
                    if (transitions[automate[i][j] - 'A'] > 1) {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

// Fonction pour vérifier si un automate est complet
int test_complet(char **automate, int nb_lignes, int nb_colonnes) {
    for (int i = 1; i < nb_lignes; i++) {
        if (strlen(automate[i]) > 2) {
            for (int j = 1; j < nb_colonnes - 1; j++) {
                if (automate[i][j] == '\0' || isspace(automate[i][j])) {
                    return 0;
                }
            }
        } else {
            return 0;
        }
    }
    return 1;
}

// Fonction pour vérifier si un automate est standard
int test_standard(char **automate, int nb_lignes, int nb_colonnes) {
    int etat_initial = -1;
    // Recherche de l'état initial
    for (int i = 1; i < nb_lignes; i++) {
        if (strchr(automate[i], 'S') != NULL) {
            if (etat_initial != -1) {
                return 0;
            }
            etat_initial = i - 1;
        }
    }

    // Vérification si l'état initial est unique
    if (etat_initial == -1) {
        return 0;
    }

    // Vérification si l'état initial n'a pas de transitions entrantes
    for (int i = 1; i < nb_lignes; i++) {
        if (strlen(automate[i]) > 2) {
            for (int j = 1; j < nb_colonnes - 1; j++) {
                if (automate[i][j] - 'A' == etat_initial) {
                    return 0;
                }
            }
        }
    }
    return 1;
}

int test() {
    char ligne[MAX_LINE_LENGTH];
    char *token;
    int nb_lignes = 0;
    int nb_colonnes = 0;
    char **automate = NULL;

    // Ouverture du fichier CSV en mode lecture ('r' pour 'read')
    FILE *fichier_automate = fopen("Lecture.csv", "r");
    if (fichier_automate == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return 1;
    }

    // Lecture du fichier CSV et stockage dans un tableau 2D
    while (fgets(ligne, MAX_LINE_LENGTH, fichier_automate) != NULL) {
        nb_lignes++;
        automate = realloc(automate, nb_lignes * sizeof(char *));
        token = strtok(ligne, ",");
        nb_colonnes = 0;
        while (token != NULL) {
            nb_colonnes++;
            automate[nb_lignes - 1] = realloc(automate[nb_lignes - 1], (nb_colonnes + 1) * sizeof(char));
            strcpy(automate[nb_lignes - 1] + nb_colonnes - 1, token);
            token = strtok(NULL, ",");
        }
        automate[nb_lignes - 1][nb_colonnes] = '\0';
    }

    fclose(fichier_automate);

    // Ajout de l'état poubelle
    automate = ajouter_etat_poubelle(automate, &nb_lignes, nb_colonnes);


    // Vérification des propriétés de l'automate
    printf("L'automate est %sdéterministe.\n", test_deterministe(automate, nb_lignes, nb_colonnes) ? "" : "non ");
    printf("L'automate est %scomplet.\n", test_complet(automate, nb_lignes, nb_colonnes) ? "" : "non ");
    printf("L'automate est %sstandard.\n", test_standard(automate, nb_lignes, nb_colonnes) ? "" : "non ");

    // Libération de la mémoire
    for (int i = 0; i < nb_lignes; i++) {
        free(automate[i]);
    }
    free(automate);

    return 0;
}

