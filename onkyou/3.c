#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define F 440 //周波数
#define LEN 2
#define A 20000 //振幅
#define SAMPLE_RATE 44100

int main(int argc, const char * argv[]) {
    double x, y, t;
    int i = 0;
    
    for (t = 0; t < LEN; t += 1.0 / SAMPLE_RATE) {
        i = 10000 * t;
        if((A * sin(2.0 * M_PI * F * t)) > 0)
            y = A - i;
        else
            y = -A + i;
        
        printf("%d\n%d\n",  (short)x, (short)y);
    }
    
    return 0;
}
