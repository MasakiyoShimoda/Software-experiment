#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define F 440 //周波数
#define LEN 5
#define A 20000 //振幅
#define SAMPLE_RATE 44100

int main(int argc, const char * argv[]) {
    double x, y, t;
    int i = 0;
    
    for (t = 0; t < LEN; t += 1.0 / SAMPLE_RATE) {
                x  = (A-t*A/LEN) * sin(2.0 * M_PI * F * t);
                y =   (t*A/LEN) * sin(2.0 * M_PI * F * t);
        
        printf("%d\n%d\n",  (short)x, (short)y);
    }
    
    return 0;
}
