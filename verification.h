#ifndef AUTOMATES_VERIFICATION_H
#define AUTOMATES_VERIFICATION_H

#include <stdbool.h>

#define MAX_SIZE 100


char **ajouter_etat_poubelle(char **automate, int *nb_lignes, int nb_colonnes);
int test();
int test_complet(char **automate, int nb_lignes, int nb_colonnes);
int test_standard(char **automate, int nb_lignes, int nb_colonnes);
int test_deterministe(char **automate, int nb_lignes, int nb_colonnes);
void afficher_automate(char automate[MAX_SIZE][MAX_SIZE], int nb_alphabet);
void ecrire_automate(char automate[MAX_SIZE][MAX_SIZE], int nb_alphabet);
void standardiser_automate(char automate[MAX_SIZE][MAX_SIZE], int nb_alphabet);
void determiniser_automate(char automate[MAX_SIZE][MAX_SIZE], int nb_alphabet);
void completer_automate(char automate[MAX_SIZE][MAX_SIZE], int nb_alphabet);
void complementariser_automate(char automate[MAX_SIZE][MAX_SIZE], int nb_alphabet);
#endif //AUTOMATES_VERIFICATION_H
