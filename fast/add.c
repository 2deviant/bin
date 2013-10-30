#include <stdio.h>

int main(int argc, char *argv[]) {

    FILE *f;
    long double sum = 0, x = 0;

    // if the file name is not specified, attempt to read from the standard
    // input
    if(!(f = argc <= 1 ? stdin : fopen(argv[1], "r"))) {
        printf("Unable to open stream for reading.\n");
        return 1;
    }

    while(!feof(f)) {

        // increment the sum
        sum += x;

        // read the number
        fscanf(f, "%Lf", &x);

    }

    printf("%.10Lg\n", sum);

    return 0;
}
