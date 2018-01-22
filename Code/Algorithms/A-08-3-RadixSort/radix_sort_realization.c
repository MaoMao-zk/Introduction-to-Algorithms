// Copyright [2017] <MaoMao>
#include <stdint.h>

int bit_n(int32_t x, int n)
{
    return ((x >> (n*8)) & 0x00FF);
}

// data is 'int32_t', this radix_sort will sort as 256 hex
void radix_sort(int32_t* array, int size)
{
    int* counting_array = new int[256];
    int* tmp_array = new int32_t[size];

    for (int bits = 0; bits < 4; bits++)
    {
        // initial
        for (int i = 0; i  < 256; i++)
            counting_array[i] = 0;

        // counting
        for (int i = 0; i < size; i++)
            counting_array[bit_n(array[i], bits)]++;

        // counting_array[i] will be the right position of i
        for (int i  = 1; i  < 256; i++)
            counting_array[i] += counting_array[i-1];

        // sorting
        for (int i  = size-1; i  >= 0; i--)
        {
            tmp_array[counting_array[bit_n(array[i], bits)]-1] = array[i];
            counting_array[bit_n(array[i], bits)]--;
        }

        // copy to array
        for (int i  = 0; i  < size; i++)
            array[i] = tmp_array[i];
    }
}
