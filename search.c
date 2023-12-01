#include "func.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void searchAircraft(const struct Aircraft *arr, int n) {
    int select;

    printf("Search:\n|1. By model\n|2. By range\n|3. By capacity\n");

    scanf("%d", &select);

    system("clear");

    switch (select) {
        case 1: {
            char tag[50];
            int found = 0;
            printf("Enter a model: ");

            scanf("%s", tag);

            for (int i = 0; i < n; i++) {
                if (!strcmp(arr[i].model, tag)) {
                    printf("A match found: %s %.2f %d\n", arr[i].model, arr[i].range, arr[i].capacity);
                    found = 1;
                }
            }
            if (!found) printf("Couldn't find any matches\n\n");
            break;
        }
        case 2: {
            float tag;
            int found = 0;
            printf("Enter a range: ");

            scanf("%f", &tag);

            for (int i = 0; i < n; i++) {
                if (arr[i].range == tag) {
                    printf("A match found: %s %.2f %d\n", arr[i].model, arr[i].range, arr[i].capacity);
                    found = 1;
                }
            }
            if (!found) printf("Couldn't find any matches\n\n");
            break;
        }
        case 3: {
            int tag;
            int found = 0;
            printf("Enter a capacity: ");

            scanf("%d", &tag);

            for (int i = 0; i < n; i++) {
                if (arr[i].capacity == tag) {
                    printf("A match found: %s %.2f %d\n", arr[i].model, arr[i].range, arr[i].capacity);
                    found = 1;
                }
            }
            if (!found) printf("Couldn't find any matches\n\n");
            break;
        }
        default:
            break;
    }
    printf("\n");
}