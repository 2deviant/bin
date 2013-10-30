#include <stdio.h>

int main(int argc, char *argv[]) {

    FILE *f;
    long double max = -1e100, x = -2e100;

    // if the file name is not specified, attempt to read from the standard
    // input
    if(!(f = argc <= 1 ? stdin : fopen(argv[1], "r"))) {
        printf("Unable to open stream for reading.\n");
        return 1;
    }

    while(!feof(f)) {

        // find the maximum
        if(x > max)
            max = x;

        // read the number
        fscanf(f, "%Lf", &x);
    }

    printf("%.10Lg\n", max);

    return 0;
}
