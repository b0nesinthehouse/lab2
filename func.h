typedef struct Aircraft {
    char model[50];
    float range;
    int capacity;
}Aircraft;

void createAircraftBase(Aircraft **arr, int *n);
void readAircraftBase(Aircraft **arr, int *n);
void writeAircraftBase(Aircraft *arr, int n);
void searchAircraftBase(Aircraft *arr, int n);