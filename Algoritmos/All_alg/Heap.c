#include <stdio.h>

void HeapBottomUp(int H[], int n) {
    for (int i = n/2; i >= 1; i--) {
        int k = i;
        int v = H[k];
        int heap = 0;

        while (!heap && 2*k <= n) {
            int j = 2*k;

            if (j < n) {
                if (H[j] < H[j + 1]) {
                    j = j + 1;
                }
            }

            if (v >= H[j]) {
                heap = 1;
            } else {
                H[k] = H[j];
                k = j;
            }
        }

        H[k] = v;
    }
}

