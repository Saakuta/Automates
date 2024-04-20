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

void read_automaton_from_file(FILE *fp) {
    fscanf(fp, "%d %d %d %d %d", &num_states, &num_initial_states, &num_final_states, &num_transitions, &num_symbols);

    for (int i = 0; i < num_states; i++) {
        fscanf(fp, "%s", states[i]);
    }

    for (int i = 0; i < num_symbols; i++) {
        fscanf(fp, "%s", symbols[i]);
    }

    for (int i = 0; i < num_transitions; i++) {
        fscanf(fp, "%s", transitions[i]);
    }
}

void write_automaton_to_csv(FILE *fp) {
    fprintf(fp, "etat");
    for (int i = 0; i < num_symbols; i++) {
        fprintf(fp, ",%s", symbols[i]);
    }
    fprintf(fp, "\n");

    for (int i = 0; i < num_states; i++) {
        fprintf(fp, "%s", states[i]);
        for (int j = 0; j < num_symbols; j++) {
            int found = 0;
            for (int k = 0; k < num_transitions; k++) {
                if (strncmp(states[i], transitions[k], 2) == 0 && strcmp(symbols[j], &transitions[k][2]) == 0) {
                    fprintf(fp, ",%s", &transitions[k][4]);
                    found = 1;
                    break;
                }
            }
            if (!found) {
                fprintf(fp, ",-");
            }
        }
        fprintf(fp, "\n");
    }
}

int main() {
    FILE *fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    read_automaton_from_file(fp);
    fclose(fp);

    fp = fopen("output.csv", "w");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    write_automaton_to_csv(fp);
    fclose(fp);

    return 0;
}

