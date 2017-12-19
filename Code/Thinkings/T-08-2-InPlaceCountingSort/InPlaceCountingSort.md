Ref: https://stackoverflow.com/questions/15682100/sorting-in-linear-time-and-in-place

nwellnhof has two answer:

1. Use 2 arrays of size k as extra storage.  
    array *start* mark the start position of val x  
    array *end* mark the end position of val x  
``` C
#include <stdlib.h>

void in_place_counting_sort(int *a, int n, int k)
{
    int *start = (int *)calloc(k + 1, sizeof(int));
    int *end   = (int *)malloc(k * sizeof(int));

    // Count.
    for (int i = 0; i < n; ++i) {
        ++start[a[i]];
    }

    // Compute partial sums.
    for (int bin = 0, sum = 0; bin < k; ++bin) {
        int tmp = start[bin];
        start[bin] = sum;
        end[bin]   = sum;
        sum += tmp;
    }
    start[k] = n;

    // Move elements.
    for (int i = 0, cur_bin = 0; i < n; ++i) {
        while (i >= start[cur_bin+1]) { ++cur_bin; }
        if (i < end[cur_bin]) {
            // Element has already been processed.
            continue;
        }

        int bin = a[i];
        while (bin != cur_bin) {
            int j = end[bin]++;
            // Swap bin and a[j]
            int tmp = a[j];
            a[j] = bin;
            bin = tmp;
        }
        a[i] = bin;
        ++end[cur_bin];
    }

    free(start);
    free(end);
}
```

2. Use only 1 arrays of size k as extra storage.  
``` C
#include <stdlib.h>

void in_place_counting_sort(int *a, int n, int k)
{
    int *counts = (int *)calloc(k, sizeof(int));

    // Count.
    for (int i = 0; i < n; ++i) {
        ++counts[a[i]];
    }

    // Compute partial sums.
    for (int val = 0, sum = 0; val < k; ++val) {
        int tmp = counts[val];
        counts[val] = sum;
        sum += tmp;
    }

    // Move elements.
    for (int i = n - 1; i >= 0; --i) {
        int val = a[i];
        int j   = counts[val];

        if (j < i) {
            // Process a fresh cycle. Since the index 'i' moves
            // downward and the counts move upward, it is
            // guaranteed that a value is never moved twice.

            do {
                ++counts[val];

                // Swap val and a[j].
                int tmp = val;
                val  = a[j];
                a[j] = tmp;

                j = counts[val];
            } while (j < i);

            // Move final value into place.
            a[i] = val;
        }
    }

    free(counts);
}
```