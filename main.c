#include "verification.h"
#include "lecture.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SIZE 100

void ecrire_automate(char automate[MAX_SIZE][MAX_SIZE], int nb_alphabet) {
    // Implémentation ici...
}

void standardiser_automate(char automate[MAX_SIZE][MAX_SIZE], int nb_alphabet) {
    // Implémentation ici...
}

void determiniser_automate(char automate[MAX_SIZE][MAX_SIZE], int nb_alphabet) {
    // Implémentation ici...
}

void completer_automate(char automate[MAX_SIZE][MAX_SIZE], int nb_alphabet) {
    // Implémentation ici...
}

void complementariser_automate(char automate[MAX_SIZE][MAX_SIZE], int nb_alphabet) {
    // Implémentation ici...
}

int menu_automate() {
    int choix1 = -1;


    if (choix1 ==0){
        printf("Au revoir !\n");
        return 0;
    }
    do {
        printf("---Bienvenue---\n0-Quitter\nChoisissez un automate : Entre 1 et 44\n");
        scanf("%d", &choix1);
    } while (choix1 < 1 || choix1 > 44);
    return choix1;
}

int menu_choix() {
    int choix2 = -1;
    printf("\n0-Quitter\n1-Determiniser un automate\n2-Standardiser un automate\n");
    printf("3-Compléter un automate\n4-Complémentariser un automate\n5-Lire un automate\n");
    printf("6-Écrire un automate\nQue voulez vous faire ?\n");
    scanf("%d", &choix2);
    return choix2;
}

int main() {
    char automate[MAX_SIZE][MAX_SIZE];
    int nb_alphabet = 0; // Initialiser avec une valeur appropriée

    while (1) {


        int choix_automate = menu_automate();
        if (choix_automate == 0) {
            printf("Au revoir !\n");
            break;  // Sortie de la boucle principale
        }


        int choix_menu = menu_choix();
        if (choix_menu == 0) {
            printf("Au revoir !\n");
            break;  // Sortie de la boucle principale
        }

        switch (choix_menu) {
            case 1:
                test();
                determiniser_automate(automate, nb_alphabet);
                afficher_automate(automate, nb_alphabet);
                break;
            case 2:
                //test_standard();
                standardiser_automate(automate, nb_alphabet);
                afficher_automate(automate, nb_alphabet);
                break;
            case 3:
                //test_complet();
                completer_automate(automate, nb_alphabet);
                afficher_automate(automate, nb_alphabet);
                break;
            case 4:

                complementariser_automate(automate, nb_alphabet);
                afficher_automate(automate, nb_alphabet);
                break;
            case 5:
                lecture("PLUS2-1.txt","output.csv");
                break;
            case 6:
                ecrire_automate(automate, nb_alphabet);
                break;
        }
    }
}