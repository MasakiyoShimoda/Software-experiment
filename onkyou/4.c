#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define DO_ 261.63
#define RE 293.66
#define MI 329.63
#define FA 349.23
#define SO 392.00
#define RA 440.00
#define SI 493.88
#define DO 523.25
#define NA 0
#define A 20000 //振幅
#define SAMPLE_RATE 44100

int main(int argc, const char * argv[]) {
    int i, s;
    double y, t;
    double ontei[] = {DO_, RE, MI, FA, MI, RE, DO_, MI, FA, SO, RA, SO, FA, MI};
    double len[] = {0.4, 0.4, 0.4, 0.4, 0.4 ,0.4 ,0.8 ,0.4 ,0.4 ,0.4 ,0.4 ,0.4 ,0.4 ,0.4};
    s = sizeof len/sizeof(double);
    
    if ((sizeof len/sizeof(double)) != (sizeof ontei/sizeof(double))) {
        puts("音程と長さが違います");
        return 0;
    }
    
    for (i = 0; i < s; i++){
        for (t = 0; t < len[i]; t += 1.0 / SAMPLE_RATE) {
            y = A * sin(2.0 * M_PI * ontei[i] * t);
            printf("%d\n%d\n"  ,  (short)y, (short)y);
        }
    }
    return 0;
}
