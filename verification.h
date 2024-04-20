#ifndef AUTOMATES_VERIFICATION_H
#define AUTOMATES_VERIFICATION_H

#include <stdbool.h>

#define MAX_SIZE 100

bool verif_deterministe(char automate[MAX_SIZE][MAX_SIZE], int nb_alphabet);
bool verif_complet(char automate[MAX_SIZE][MAX_SIZE], int nb_alphabet);
bool verif_standard(char automate[MAX_SIZE][MAX_SIZE], int nb_alphabet);
bool test_complet_transition(char automate[MAX_SIZE][MAX_SIZE], int nb_alphabet);
void afficher_automate(char automate[MAX_SIZE][MAX_SIZE], int nb_alphabet);
void lire_automate(char automate[MAX_SIZE][MAX_SIZE], int nb_alphabet);
void ecrire_automate(char automate[MAX_SIZE][MAX_SIZE], int nb_alphabet);
void standardiser_automate(char automate[MAX_SIZE][MAX_SIZE], int nb_alphabet);
void determiniser_automate(char automate[MAX_SIZE][MAX_SIZE], int nb_alphabet);
void completer_automate(char automate[MAX_SIZE][MAX_SIZE], int nb_alphabet);
void complementariser_automate(char automate[MAX_SIZE][MAX_SIZE], int nb_alphabet);
#endif //AUTOMATES_VERIFICATION_H
