// Copyright [2017] <MaoMao>

// O(m+n)
// 1. Remove first data as the min value
// 2. Move last data to first position
// 3. Do MIN-HEAPIFY to first value, right node and down node as it's child node
int young_tableau_extract_min(int** tableau, int m, int n, int* current_size)
{
    if (*current_size <= 0)
        return -1;

    int min = tableau[0][0];

    (*current_size)--;

    // no data left
    if (*current_size == 0)
    {
        tableau[0][0] = -1;
        return min;
    }

    // 1. exchange last data to first position
    int last_r = *current_size / n;
    int last_c = *current_size % n;
    tableau[0][0] = tableau[last_r][last_c];
    tableau[last_r][last_c] = -1;

    // printf("m=%d, n=%d, *current_size=%d, last_r=%d, last_c=%d \n", m, n, *current_size, last_r, last_c);

    // m_Print();

    // 2. move data in first postion to right positon
    int i = 0;
    int j = 0;
    do
    {
        // exchange current data with min data in right data and down data
        int exchange_r = i, exchange_c = j;
        // check right
        if (j+1 < n && tableau[i][j+1] != -1 && tableau[i][j+1] < tableau[i][j])
        {
            exchange_r = i;
            exchange_c = j+1;
        }
        // chack down
        if (i+1 < n && tableau[i+1][j] != -1 && tableau[i+1][j] < tableau[exchange_r][exchange_c])
        {
            exchange_r = i+1;
            exchange_c = j;
        }

        // have in right positon
        if (exchange_r == i && exchange_c == j)
            break;
        else
        {
            // exchange
            int tmp = tableau[i][j];
            tableau[i][j] = tableau[exchange_r][exchange_c];
            tableau[exchange_r][exchange_c] = tmp;
            i = exchange_r;
            j = exchange_c;
        }
    }while(1);

    return min;
}

// O(m+n)
// 1. Set insert value to last position
// 2. Do MIN-HEAP-INSERT, left node and up node as it's parent
bool young_tableau_insert(int** tableau, int m, int n, int* current_size, int a)
{
    // Fule
    if (*current_size == m*n)
        return false;

    (*current_size)++;

    if (*current_size == 1)
    {
        tableau[0][0] = a;
        return true;
    }

    // 1. set 'a' to last positon
    int last_r = (*current_size-1) / n;
    int last_c = (*current_size-1) % n;
    tableau[last_r][last_c] = a;

    // printf("m=%d, n=%d, current_size=%d, a=%d, last_r=%d, last_c=%d \n", m, n, *current_size, a, last_r, last_c);

    // m_Print();

    // move 'a' n to right positon
    int i = last_r;
    int j = last_c;
    do
    {
        // exchange current data with max data in left data and up data
        int exchange_r = i, exchange_c = j;
        // check left
        if (j > 0 && tableau[i][j-1] > tableau[i][j])
        {
            exchange_r = i;
            exchange_c = j-1;
        }
        // chack up
        if (i > 0 && tableau[i-1][j] > tableau[exchange_r][exchange_c])
        {
            exchange_r = i-1;
            exchange_c = j;
        }

        // have in right positon
        if ( exchange_r == i && exchange_c == j)
            break;
        else
        {
            // exchange
            int tmp = tableau[i][j];
            tableau[i][j] = tableau[exchange_r][exchange_c];
            tableau[exchange_r][exchange_c] = tmp;
            i = exchange_r;
            j = exchange_c;
        }
    }while(1);

    return true;
}

// O(n^3)
// 1. Copy tableau
// 2. Do m_ExtractMin to extract all data
int* young_tableau_sort(int** tableau, int m, int n, int current_size)
{
    int current_size_copy = current_size;
    int** tableau_copy = new int* [m];
    for (int i = 0; i < m; i++)
    {
        tableau_copy[i] = new int[n];
        for (int j = 0; j < n; j++)
            tableau_copy[i][j] = tableau[i][j];
    }

    int* array = new int[current_size];

    for (int i = 0; current_size_copy > 0; i++)
    {
        array[i] = young_tableau_extract_min(tableau_copy, m, n, &current_size_copy);
    }

    return array;
}

// O(m+n)
// 1. Check from left-down node
// 2. If bigger than checked value, check to up node
// 3. If smaller than checked value, check to right node
// 4. If same with checked value, found!
bool young_tableau_check_exist(int** tableau, int m, int n, int current_size, int a)
{
    bool result = false;

    if (current_size <= 0)
        return false;

    // Check from left-down node
    // Ref: https://www.cnblogs.com/shuaiwhu/archive/2011/03/21/2065075.html
    int i = (current_size-1) / n;
    int j = 0;
    do
    {
        if (tableau[i][j] == a)
        {
            result = true;
            break;
        }
        else if (tableau[i][j] > a)
        {
            i--;
        }
        else if (tableau[i][j] < a)
        {
            j++;
        }
    }while(i >= 0 && j < n);

    return result;
}
