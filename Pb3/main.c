//
// Created by bbok on 8/18/24.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** readTruthTable(const char* filename, int* rows, int* cols) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    char line[256];
    fgets(line, sizeof(line), file); // 첫 줄 변수 이름 무시

    int** truthTable = (int**)malloc(sizeof(int*) * 256);
    *rows = 0;
    *cols = 0;

    while (fgets(line, sizeof(line), file)) {
        truthTable[*rows] = (int*)malloc(sizeof(int) * 256);
        char* token = strtok(line, " ");
        int col = 0;
        char *endptr;

        while (token != NULL) {
            truthTable[*rows][col++] = strtol(token, &endptr, 10);
            if (*endptr != '\0' && *endptr != '\n') {
                fprintf(stderr, "Conversion error, non-convertible part: %s\n", endptr);
                exit(EXIT_FAILURE);
            }
            token = strtok(NULL, " ");
        }
        *cols = col;
        (*rows)++;
    }

    fclose(file);

    return truthTable;
}

int main() {
    const char* filename1 = "s3.txt";
    onst char* filename2 = "cout.txt";
    int rows, cols;

    int** truthTable1 = readTruthTable(filename1, &rows, &cols);
    int** truthTable2 = readTruthTable(filename2, &rows, &cols);

    //truth table1, truth table2 build BDD
    //share or merge BDDs
    //reduction BDDs
    //visualize BDDs

    return 0;
}


//
