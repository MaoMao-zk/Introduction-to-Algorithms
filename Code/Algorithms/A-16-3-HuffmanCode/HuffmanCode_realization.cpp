// Copyright [2017] <MaoMao>

#include <string.h>
#include <stdio.h>

struct Node
{
    float freq;
    char  c;
    char  code;
    int   code_len;

    Node* parent;
    Node* left;
    Node* right;

    Node()
    {
        freq = 0.0;
        c = 0;
        code = 0;
        code_len = 0;

        parent = nullptr;
        left = nullptr;
        right = nullptr;
    }
};

Node* root = nullptr;

Node* heap[256];
int heap_size = 0;;

void heap_init()
{
    heap_size = 0;
}

void heap_insert(Node* p)
{
    heap[heap_size] = p;

    int cur = heap_size;
    int parent;
    while (cur)
    {
        parent = (cur - 1) / 2;
        if (heap[cur]->freq < heap[parent]->freq)
        {
            Node* tmp = heap[cur];
            heap[cur] = heap[parent];
            heap[parent] = tmp;
            cur = parent;
        }
        else
            break;
    }

    heap_size++;
}

Node* heap_extract_min()
{
    if (heap_size == 0)
        return nullptr;
    
    heap_size--;

    Node* p = heap[0];
    heap[0] = heap[heap_size];
    int cur = 0;
    while (cur < (heap_size + 1) / 2)
    {
        int min = cur;
        // left
        if (heap[min * 2 + 1] < heap[min])
        {
            min = min * 2 + 1;
        }
        // right
        if ((min * 2 + 2) < heap_size && heap[min * 2 + 2] < heap[min])
        {
            min = min * 2 + 2;
        }
        if (min == cur)
            break;
        else
        {
            Node* tmp = heap[cur];
            heap[cur] = heap[min];
            heap[min] = tmp;
            cur = min;
        }
    }

    return p;
}

int char_count[256];
int char_num;
Node* char_nodes[256];
int bits;

void DFS(Node* p, char code, int code_len)
{
    p->code = code;
    p->code_len = code_len;
    bits += code_len * char_count[p->c + 128];

    if (p->left)
        DFS(p->left, code<<1, code_len+1);
    if(p->right)
        DFS(p->right, (code << 1) + 1, code_len + 1);
}

int huffman_code(char* org_str, int length, char*& code_str)
{
    heap_init();
    char_num = 0;
    bits = 0;
    for (int i = 0; i < 256; i++)
    {
        char_count[i] = 0;
        char_nodes[i] = nullptr;
    }

    int num = 0;

    // 1. counting
    for (int i = 0; i < length; i++)
        char_count[org_str[i] + 128]++;

    // 2. build heap
    for (int i = 0; i < 256; i++)
    {
        if (char_count[i])
        {
            Node* p = new Node();
            p->c = i - 128;
            p->freq = (float)char_count[i] / (float)length;
            heap_insert(p);
            char_nodes[i] = p;
            char_num++;
        }
    }

    // 3. build tree
    for (int i = 1; i < char_num; i++)
    {
        Node* p = new Node();
        p->left = heap_extract_min();
        p->right = heap_extract_min();
        p->left->parent = p;
        p->right->parent = p;

        p->freq = p->left->freq + p->right->freq;
        heap_insert(p);
    }
    root = heap[0];

    // 4. get code
    DFS(root, 0, 0);

    // 5. coding
    num = bits / 8 + 1;
    code_str = new char[num];
    memset(code_str, 0, num);

    int cur_char = 0;
    int cur_bits = 0;
    for (int i = 0; i < length; i++)
    {
		Node* p = char_nodes[org_str[i] + 128];

        if (p->code_len + cur_bits >= 8)
        {
			code_str[cur_char] += p->code >> (p->code_len - (8 -cur_bits));
			cur_char++;
			cur_bits = p->code_len + cur_bits - 8;
			code_str[cur_char] = (p->code << (8 - cur_bits)) & 0xFF;
        }
        else
        {
            code_str[cur_char] += p->code << (8 - p->code_len - cur_bits);
			cur_bits += p->code_len;
        }

    }

	return bits;
}

int huffman_decode(char* code_str, int bits, char*& org_str)
{
    int len = 0;

	int cur_bits = 0;
	int cur_index = 0;
	int cur_bit = 0;
	Node*p = root;
	// 1. Check length
	while (cur_bits < bits)
	{
		if (code_str[cur_index] & 1 << (7 - cur_bit))
			p = p->right;
		else
			p = p->left;

		if (p->left == nullptr)
		{
			len++;
			p = root;
		}
		cur_bit++;
		cur_bits++;
		if (cur_bit >= 8)
		{
			cur_bit = 0;
			cur_index++;
		}
	}

	// 2. Get str
	org_str = new char[len+1];
	memset(org_str, 0, len + 1);
	len = 0;
	cur_bits = 0;
	cur_index = 0;
	cur_bit = 0;
	p = root;
	while (cur_bits < bits)
	{
		if (code_str[cur_index] & 1 << (7 - cur_bit))
			p = p->right;
		else
			p = p->left;

		if (p->left == nullptr)
		{
			org_str[len] = p->c;
			len++;
			p = root;
		}
		cur_bit++;
		cur_bits++;
		if (cur_bit >= 8)
		{
			cur_bit = 0;
			cur_index++;
		}
	}

	return len;
}
