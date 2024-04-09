#include <stdio.h>
#include <stdlib.h>
#define N 20

int main(){

    int i;
    double vt[N];
    double *ptn = &vt;

    for(i = 0;i<N; i++)
    {
    *ptn=1+rand()%100;

    printf(" %.1f ", *ptn);
    ptn++;
    }

    return 0;
}