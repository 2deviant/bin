#include <stdio.h>

#define BUFFER_SIZE     1024
#define DEFAULT_OUTPUT  10
#define MINIMUM_OUTPUT  1
#define MAXIMUM_OUTPUT  65536
#define TEXT_CHAR_COUNT 62

int main(int argc, char *argv[]) {

    // counter variable
    int i;

    // number of random bytes to pull
    int n;

    // randomness goes here
    unsigned char random[BUFFER_SIZE];

    // acceptable output characters
    unsigned char text[] = "0123456789qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";

    // if the argument is missing
    if(argc <= 1)
        // revert to default
        n = DEFAULT_OUTPUT;
    // otherwise attempt to read it
    else {
        // convert the string to an integer
        sscanf(argv[1], "%d", &n);

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
        fread(&random, BUFFER_SIZE, 1, rnd);

        // convert them to alphanumeric characters and dump to STDOUT
        for(i=0; i < (n > BUFFER_SIZE ? BUFFER_SIZE : n); i++)
            // chop off random numbers after 248 to ensure uniform distribution
            if(random[i] < 4*TEXT_CHAR_COUNT)
                printf("%c", text[random[i] % TEXT_CHAR_COUNT]);
            else
                // account for the ignored random number
                n++;

        // decrement the counter and continue
        n -= BUFFER_SIZE;
    }

    fclose(rnd);
    return 0;
}
