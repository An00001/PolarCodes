#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "polarCodes.h"

int SUB_BLOCK_INTERLEAVE_PATTERN[] = {0, 1, 2, 4, 3, 5, 6, 7, 8, 16, 9, 17, 10, 18, 11, 19, 12, 20, 13, 21, 14, 22, 15, 23, 24, 25, 26, 28, 27, 29, 30, 31};

int * subBlockInterleaving(int * dataBits, struct PC_CONFIG * pcConfig) {
    int N = pcConfig->N;
    int idx;

    int * intrlvData = (int *)calloc(N, sizeof(int));

    for (int iter_bits = 0; iter_bits < N; iter_bits++) {
        idx = SUB_BLOCK_INTERLEAVE_PATTERN[(int)floor(32 * (double)iter_bits / N)] * N / 32 + (iter_bits % (N / 32));
        *(intrlvData + iter_bits) = *(dataBits + idx);
    }

    return intrlvData;
}

int * bitSelection(int * dataBits, struct PC_CONFIG * pcConfig) {
    int N = pcConfig->N;
    int E = pcConfig->E;
    int K = pcConfig->K;

    int idx;

    int * rateMatchedData = (int *)calloc(E, sizeof(int)); 

    if (E > N) { // Repetition
        for (int iter_bits = 0; iter_bits < E; iter_bits++) {
            *(rateMatchedData + iter_bits) = *(dataBits + (iter_bits % N));
        }
    } else if ((double)K/E <= 7/16) {  // Puncturing
        for (int iter_bits = 0; iter_bits < E; iter_bits++) {
            *(rateMatchedData + iter_bits) = *(dataBits + iter_bits + N - E);
        }
    } else {  // Shortening
        for (int iter_bits = 0; iter_bits < E; iter_bits++) {
            *(rateMatchedData + iter_bits) = *(dataBits + iter_bits);
        }
    }

    return rateMatchedData;
}

