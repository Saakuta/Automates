#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SIZE 100

bool verif_deterministe(char automate[MAX_SIZE][MAX_SIZE], int nb_alphabet) {
    // Code for verifying if the automate is deterministic
}

bool verif_complet(char automate[MAX_SIZE][MAX_SIZE], int nb_alphabet) {
    // Code for verifying if the automate is complete
}

bool verif_standard(char automate[MAX_SIZE][MAX_SIZE], int nb_alphabet) {
    // Code for verifying if the automate is standard
}

bool test_complet_transition(char automate[MAX_SIZE][MAX_SIZE], int nb_alphabet) {
    // Code for testing if the transition is complete
}

void afficher_automate(char automate[MAX_SIZE][MAX_SIZE], int nb_alphabet) {
    // Code for displaying the automate
}

void lire_automate(char automate[MAX_SIZE][MAX_SIZE], int nb_alphabet) {
    // Code for reading the automate from a file
}

void ecrire_automate(char automate[MAX_SIZE][MAX_SIZE], int nb_alphabet) {
    // Code for writing the automate to a file
}

void standartiser_automate(char automate[MAX_SIZE][MAX_SIZE], int nb_alphabet) {
    // Code for standardizing the automate
}

void determiniser_automate(char automate[MAX_SIZE][MAX_SIZE], int nb_alphabet) {
    // Code for determinizing the automate
}

void completer_automate(char automate[MAX_SIZE][MAX_SIZE], int nb_alphabet) {
    // Code for completing the automate
}

void complementariser_automate(char automate[MAX_SIZE][MAX_SIZE], int nb_alphabet) {
    // Code for complementarizing the automate
}

int menu_automate() {
    int choix = -1;
    while (choix < 0 || choix > 44) {
        printf("---Bonjour---\n0-Quitter\nChoisissez un automate : Entre 1 et 44\n");
        printf("\nQue voulez vous faire ?\n");
        scanf("%d", &choix);
    }
    return choix;
}

int menu_choix() {
    int choix = -1;
    while (choix < 0 || choix > 6) {
        printf("\n0-Quitter\n1-Lire un autre automate\n2-Afficher un automate\n"
               "3-Standartiser un automate\n4-Determiniser un automate\n5-Completer un automate\n"
               "6-Complementariser un automate\n");
        printf("Que voulez vous faire ?\n");
        scanf("%d", &choix);
    }
    return choix;
}

int main() {
    char automate[MAX_SIZE][MAX_SIZE];
    int nb_alphabet;

    while (1) {
        if (remove("transition.csv") == 0) {
            printf("File transition.csv deleted successfully\n");
        }

        int choix_automate = menu_automate();
        if (choix_automate == 0) {
            printf("Au revoir !\n");
            exit(0);
        } else {
            while (1) {
                int choix_menu = menu_choix();
                char automate_debut[MAX_SIZE][MAX_SIZE];
                lire_automate(automate_debut, nb_alphabet);

                if (choix_menu == 0) {
                    printf("Au revoir !\n");
                    exit(0);
                } else if (choix_menu == 1) {
                    break;
                } else if (choix_menu == 2) {
                    char automate_modifier[MAX_SIZE][MAX_SIZE];
                    ecrire_automate(automate_modifier, nb_alphabet);
                    printf("Automate changer :\n");
                    afficher_automate(automate_modifier, nb_alphabet);
                } else if (choix_menu == 3) {
                    standartiser_automate(automate, nb_alphabet);
                    afficher_automate(automate, nb_alphabet);
                } else if (choix_menu == 4) {
                    determiniser_automate(automate, nb_alphabet);
                    afficher_automate(automate, nb_alphabet);
                } else if (choix_menu == 5) {
                    completer_automate(automate, nb_alphabet);
                    afficher_automate(automate, nb_alphabet);
                } else if (choix_menu == 6) {
                    complementariser_automate(automate, nb_alphabet);
                    afficher_automate(automate, nb_alphabet);
                }
            }
        }
    }

    return 0;
}


