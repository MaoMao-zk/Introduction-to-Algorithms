// Copyright [2017] <MaoMao>

#ifndef _HUFFMAN_CODE_H_
#define _HUFFMAN_CODE_H_

#include "Algorithms.h"

class HuffmanCode : public Algorithms
{
 public:
    HuffmanCode();
    virtual ~HuffmanCode();
 protected:
    virtual void m_BuildInput();
    virtual void m_Execute();
    virtual bool m_CheckOutput();
private:
    char* str;
    int len;
	int code_bits;
    char* result_str;
    int result_len;
};

#endif
