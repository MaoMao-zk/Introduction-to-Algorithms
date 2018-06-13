// Copyright [2017] <MaoMao>

void rod_cutting(int* p, int n, int* r, int* s)
{
    for (int i = 0; i < n; i++)
    {
        // Record not cutting price
        r[i] = p[i];
        s[i] = i+1;
        for (int j = 0; j < i; j++)
        {
            // tmp is the price that cutting as j and another
            int tmp = p[j] + r[i-j-1];
            if (tmp > r[i])
            {
                r[i] = tmp;
                s[i] = j+1;
            }
        }
    }
}
