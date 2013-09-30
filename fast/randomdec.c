#include <stdio.h>

#define BUFFER_SIZE     1024
#define DEFAULT_OUTPUT  10
#define MINIMUM_OUTPUT  1
#define MAXIMUM_OUTPUT  65536
#define NUMBER_LENGTH   9
#define integer         unsigned int

// self-explanatory
integer sq(integer x) {
    return x*x;
}

// self-explanatory
integer power10(integer n) {

    // the end
    if(n == 1)
        return 10;

    // odd power
    if(n%2)
        return 10*sq(power10((n-1)/2));

    // even power
    return sq(power10(n/2));
}

int main(int argc, char *argv[]) {

    // counter variable
    int i;

    // number of random [data type] to pull
    int n;

    // number of digits
    int d;

    // randomness goes here
    integer random[BUFFER_SIZE];

    // if the argument is missing
    if(argc <= 1) {
        // revert to default
        d = DEFAULT_OUTPUT;
        n = d / NUMBER_LENGTH + 1;
    }
    // otherwise attempt to read it
    else {
        // convert the string to an integer
        sscanf(argv[1], "%d", &d);

        // divide by NUMBER_LENGTH
        // each random number is NUMBER_LENGTH digits long
        n = d / NUMBER_LENGTH + 1;

        // make sure it makes sense
        if(n < MINIMUM_OUTPUT || n > MAXIMUM_OUTPUT || d < 0) {
            // else use the default again
            d = DEFAULT_OUTPUT;
            n = d / NUMBER_LENGTH + 1;
        }
    }

    // tap into the randomness
    FILE *rnd = fopen("/dev/urandom","r");

    // loop until the requested byte count has been achieved
    while(n > 0) {
        // read some random bytes
        fread(&random, BUFFER_SIZE, sizeof(integer), rnd);

        // convert them to alphanumeric characters and dump to STDOUT
        for(i=0; i < (n > BUFFER_SIZE ? BUFFER_SIZE : n) && d > 0; i++)
            // if the number is in [0, 3999999999], use it
            if(random[i] < 4000000000u) {
                
                /*
                 * effectively, remove the first digit of random[i]
                 * then concatenate it to the random number
                 *
                 */

                // if the digit target is about to be reached, print out the
                // remaining digits and stop
                if (d < NUMBER_LENGTH) {
                    // create the format string
                    char format[8];
                    sprintf((char *)format, "%%0%du", d);
                    // print out th remaining digits
                    printf(format, random[i] % power10(d));
                }
                // otherwise just print out the usual
                else
                    printf("%09u", random[i] % ((integer)1000000000));

                // take account of the length of the number outputted so far
                d -= NUMBER_LENGTH;
            }
            else
                // account for the ignored random number
                n++;

        // decrement the counter and continue
        n -= BUFFER_SIZE;
    }

    fclose(rnd);
    return 0;
}
