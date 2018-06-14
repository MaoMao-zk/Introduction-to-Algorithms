// Copyright [2017] <MaoMao>

#include "HuffmanCode.h"
#include "Utils.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <iostream>

extern int huffman_code(char* org_str, int length, char*& code_str);
extern int huffman_decode(char* code_str, int bits, char*& org_str);

//char* test = "ASDKJRFHNNICQOJHRW7N4CTQ9843GM448TNGR780GZQM7834RJUHGNFY8M4BHFUIXBJAKHKSLJDHFPJN389VN0YGR78CNGWYUGNFCUYNASHDUFCKNGSYD";

char* test = "aaaaaaaaaaeaaaaaaaaadddaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbbbbccc";

HuffmanCode::HuffmanCode()
{
    m_info.id = "A-16-3";
    m_info.name = "HuffmanCode";


    str = nullptr;
    len = 0;
    result_str = nullptr;
	code_bits = 0;
    result_len = 0;
}

HuffmanCode::~HuffmanCode()
{
    if (result_str)
        delete[]result_str;
}

void HuffmanCode::m_BuildInput()
{
    str = test;
    len = strlen(str);
}

void HuffmanCode::m_Execute()
{
    char* code_str = nullptr;
    code_bits = huffman_code(str, len, code_str);

	result_len = huffman_decode(code_str, code_bits, result_str);
}

bool HuffmanCode::m_CheckOutput()
{
	if (strcmp(result_str, str) == 0)
	{
		printf("Compression ratio is %.2f%%\n", ((float)code_bits / (result_len * 8)) * 100);
		return true;
	}
    else
    {
        printf("decode/code failed. result_str(%s) != str(%s)\n", result_str, str);
        return false;
    }
}
