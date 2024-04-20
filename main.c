#include "verification.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SIZE 100

bool verif_deterministe(char automate[MAX_SIZE][MAX_SIZE], int nb_alphabet) {
    // Code pour vérifier si l'automate est déterministe
    return true; // Remplacez par votre logique
}

bool verif_complet(char automate[MAX_SIZE][MAX_SIZE], int nb_alphabet) {
    // Code pour vérifier si l'automate est complet
    return true; // Remplacez par votre logique
}

bool verif_standard(char automate[MAX_SIZE][MAX_SIZE], int nb_alphabet) {
    // Code pour vérifier si l'automate est standard
    return true; // Remplacez par votre logique
}

bool test_complet_transition(char automate[MAX_SIZE][MAX_SIZE], int nb_alphabet) {
    // Code pour tester si la transition est complète
    return true; // Remplacez par votre logique
}

void afficherAutomate(char automate[MAX_SIZE][MAX_SIZE], int nb_alphabet) {
    // Code pour afficher l'automate
}

void lire_automate(char automate[MAX_SIZE][MAX_SIZE], int nb_alphabet) {
    // Code pour lire l'automate à partir d'un fichier
}

void ecrire_automate(char automate[MAX_SIZE][MAX_SIZE], int nb_alphabet) {
    // Code pour écrire l'automate dans un fichier
}

void standardiser_automate(char automate[MAX_SIZE][MAX_SIZE], int nb_alphabet) {
    // Code pour standardiser l'automate
}

void determiniser_automate(char automate[MAX_SIZE][MAX_SIZE], int nb_alphabet) {
    // Code pour déterminiser l'automate
}

void completer_automate(char automate[MAX_SIZE][MAX_SIZE], int nb_alphabet) {
    // Code pour compléter l'automate
}

void complementariser_automate(char automate[MAX_SIZE][MAX_SIZE], int nb_alphabet) {
    // Code pour complémentariser l'automate
}

int menu_automate() {
    int choix = -1;
    while (choix < 0 || choix > 44) {
        printf("---Bienvenue---\n0-Quitter\nChoisissez un automate : Entre 1 et 44\n");
        printf("\nQue voulez vous faire ?\n");
        scanf("%d", &choix);
    }
    return choix;
}

int menu_choix() {
    int choix = -1;
    while (choix < 0 || choix > 6) {
        printf("\n0-Quitter\n1-Determiniser un automate\n2-Standardiser un automate\n");
        printf("3-Compléter un automate\n4-Complémentariser un automate\n5-Lire un automate\n");
        printf("6-Écrire un automate\nQue voulez vous faire ?\n");
        scanf("%d", &choix);
    }
    return choix;
}

int main() {
    char automate[MAX_SIZE][MAX_SIZE];
    int nb_alphabet = 0; // Initialiser avec une valeur appropriée

    while (1) {
        FILE *file = fopen("transition.csv", "r");
        if (file) {
            fclose(file);
            remove("transition.csv");
            printf("File transition.csv deleted successfully\n");
        }

        int choix_automate = menu_automate();
        if (choix_automate == 0) {
            printf("Au revoir !\n");
            exit(0);
        } else {
            while (1) {
                int choix_menu = menu_choix();
                if (choix_menu == 0) {
                    printf("Au revoir !\n");
                    exit(0);
                } else if (choix_menu == 1) {
                    break;
                } else if (choix_menu == 2) {
                    char automate_modifier[MAX_SIZE][MAX_SIZE];
                    ecrire_automate(automate_modifier, nb_alphabet);
                    printf("Automate changer :\n");
                    afficherAutomate(automate_modifier, nb_alphabet);
                } else if (choix_menu == 3) {
                    standardiser_automate(automate, nb_alphabet);
                    afficherAutomate(automate, nb_alphabet);
                } else if (choix_menu == 4) {
                    determiniser_automate(automate, nb_alphabet);
                    afficherAutomate(automate, nb_alphabet);
                } else if (choix_menu == 5) {
                    completer_automate(automate, nb_alphabet);
                    afficherAutomate(automate, nb_alphabet);
                } else if (choix_menu == 6) {
                    complementariser_automate(automate, nb_alphabet);
                    afficherAutomate(automate, nb_alphabet);
                }
            }
        }
    }

    return 0;
}


