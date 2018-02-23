// Copyright [2017] <MaoMao>

#ifndef _I_HASHING_HPP_
#define _I_HASHING_HPP_

#include "ICollection.h"

#include <stdint.h>

class DoublyLinkedList;

class Hashing : public ICollection
{
 public:
    // size -> hash table size
    explicit Hashing(int size);
    virtual ~Hashing();
 public:
    // Return null if not found
    virtual Element* Search(int key);
    virtual void Insert(Element* elm);
    virtual void Delete(Element* elm);
 protected:
    virtual int m_HashMethod(int key) = 0;
 public:
    DoublyLinkedList* table;
    int table_size;
};

class DivisionHashing : public Hashing
{
 public:
    // size -> hash table size, also is the Dividend in DivisionHashing
    explicit DivisionHashing(int size) : Hashing(size) {}
    virtual ~DivisionHashing() {}
 protected:
    virtual int m_HashMethod(int key)
    {
        return key % this->table_size;
    }
};

class MultiplicationHashing : public Hashing
{
 public:
    // r : the bits of table size, table_size = 2^r
    // a : the multiplier in MultiplicationHashing
    // w : the bits of key(default is the sizeof int * 8)
    MultiplicationHashing(int r, int a, int w = 0) : Hashing(0x01 << r), r(r), a(a)
    {
        if (w == 0)
            this->w = sizeof(int) * 8;
        else
            this->w = w;
    }
    virtual ~MultiplicationHashing() {}
 protected:
    virtual int m_HashMethod(int key)
    {
        return (((uint64_t)key * a) % ((uint64_t)0x01 << w)) >> (w - r);
    }
 protected:
    int w;
    int r;
    int a;
};


#endif
