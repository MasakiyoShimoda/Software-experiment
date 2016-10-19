#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define F 440
#define LEN 2
#define A 20000 //振幅
#define SAMPLE_RATE 44100

int main(int argc, const char * argv[]) {
    double y, t;
    
    for (t = 0; t <   t += 1.0 / SAMPLE_RATE) {
        y = A * sin(2.0 * M_PI * F * t);
        printf("%d\n%d\n"  ,  (short)y, (short)y);
    }
    
    return 0;
}
