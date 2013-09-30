#include <stdio.h>

#define BUFFER_SIZE     1024
#define DEFAULT_OUTPUT  10
#define MINIMUM_OUTPUT  1
#define MAXIMUM_OUTPUT  65536
#define NUMBER_LENGTH   9

// self-explanatory
unsigned int sq(unsigned int x) {
    return x*x;
}

// self-explanatory
unsigned int pow10(unsigned int n) {

    // the end
    if(n == 1)
        return 10;

    // even power
    if(!(n%2))
        return sq(pow10(n/2));

    // odd power
    return 10*sq(pow10((n-1)/2));
}

int main(int argc, char *argv[]) {

    // counter variable
    int i;

    // number of random bytes to pull
    int n;

    // number of digits
    int d;

    // randomness goes here
    unsigned int random[BUFFER_SIZE];

    // if the argument is missing
    if(argc <= 1)
        // revert to default
        n = DEFAULT_OUTPUT;
    // otherwise attempt to read it
    else {
        // convert the string to an integer
        sscanf(argv[1], "%d", &n);

        // save the requested digit count
        d = (unsigned int)n;

        // divide by 9 (each random "number" is 9 digits long)
        n = n / NUMBER_LENGTH + 1;

        // make sure it makes sense
        if(n < MINIMUM_OUTPUT || n > MAXIMUM_OUTPUT)
            // else use the default again
            n = DEFAULT_OUTPUT;
    }

    // tap into the randomness
    FILE *rnd = fopen("/dev/urandom","r");

    // loop until the requested byte count has been achieved
    while(n > 0) {
        // read some random bytes
        fread(&random, BUFFER_SIZE, sizeof(unsigned int), rnd);

        // convert them to alphanumeric characters and dump to STDOUT
        for(i=0; i < (n > BUFFER_SIZE ? BUFFER_SIZE : n); i++)
            // if the number is in [0, 3999999999], use it
            if(random[i] < (unsigned int)4000000000) {
                
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
                    printf(format, random[i] % pow10(d));
                }
                // otherwise just print out the usual
                else
                    printf("%09u", random[i] % ((unsigned int)1000000000));

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
