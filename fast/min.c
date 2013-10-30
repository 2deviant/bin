#include <stdio.h>

int main(int argc, char *argv[]) {

    FILE *f;
    long double min = 1e100, x;

    // if the file name is not specified, attempt to read from the standard
    // input
    if(!(f = argc <= 1 ? stdin : fopen(argv[1], "r"))) {
        printf("Unable to open stream for reading.\n");
        return 1;
    }

    while(1) {

        // read the next number
        fscanf(f, "%Lf", &x);

        // if the end of the file has been reached, stop
        if(feof(f))
            break;

        if(x < min)
            min = x;
    }

    printf("%.10Lg\n", min);

    return 0;
}
