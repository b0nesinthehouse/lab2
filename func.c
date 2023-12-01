#include <stdio.h>
#include <stdlib.h>
#include "func.h"

void createAircraftBase(Aircraft **arr, int *n) {
    printf("Enter the number of entries: ");
    scanf("%d", n);

    if (*n <= 0) return;

    *arr = (struct Aircraft *)calloc(*n, sizeof(struct Aircraft));

    if (!*arr) return;

    for (int i = 0; i < *n; i++) {
        printf("Entry number %d:\n", i + 1);
        printf("|Enter a model: ");
        scanf("%s", (*arr)[i].model);
        printf("|Enter the range: ");
        scanf("%f", &(*arr)[i].range);
        printf("|Enter the capacity: ");
        scanf("%d", &(*arr)[i].capacity);

        
    }
}

void readAircraftBase(Aircraft **arr, int *n) {
    FILE *file = fopen("AircraftDB.txt", "r");
    if (!file) return;

    if (fscanf(file, "%d", n) != 1) {
        fclose(file);
        return;
    }

    *arr = (struct Aircraft *)calloc(*n, sizeof(struct Aircraft));

    for (int i = 0; i < *n; i++) {
        if (fscanf(file, "%s %f %d", (*arr)[i].model, &(*arr)[i].range, &(*arr)[i].capacity) != 3) break;
    }

    fclose(file);
}

void writeAircraftBase(Aircraft *arr, int n) {
    if (n <= 0) return;
    FILE *file = fopen("AircraftDB.txt", "w");
    if (!file) {
        printf("COULDN'T OPEN FILE");
        return;
    }

    fprintf(file, "%d\n", n);

    for (int i = 0; i < n; i++) {
        fprintf(file, "%s %.2f %d\n", arr[i].model, arr[i].range, arr[i].capacity);
    }

    fclose(file);
}