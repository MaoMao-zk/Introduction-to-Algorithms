// Copyright [2017] <MaoMao>

#ifndef _I_HASHING_HPP_
#define _I_HASHING_HPP_

#include "ICollection.h"
#include "../A-10-2-DoublyLinkedList/DoublyLinkedList.hpp"

#include <stdint.h>

template <class T>
class Hashing : public ICollection<T>
{
 public:
    // size -> hash table size
    explicit Hashing(int size)
    {
        table_size = size;
        table = new DoublyLinkedList<T>[size];
    }
    virtual ~Hashing()
    {
        // TODO(MaoMao): delete table data
    }
 public:
    // Return null if not found
    virtual Element<T>* Search(int key)
    {
        int hash_key = m_HashMethod(key);
        return table[hash_key].Search(key);
    }
    virtual void Insert(Element<T>* elm)
    {
        int hash_key = m_HashMethod(elm->key);
        table[hash_key].Insert(elm);
    }
    virtual void Delete(Element<T>* elm)
    {
        int hash_key = m_HashMethod(elm->key);
        table[hash_key].Delete(elm);
    }
 protected:
    virtual int m_HashMethod(int key) = 0;
 public:
    DoublyLinkedList<T>* table;
    int table_size;
};

template <class T>
class DivisionHashing : public Hashing<T>
{
 public:
    // size -> hash table size, also is the Dividend in DivisionHashing
    explicit DivisionHashing(int size) : Hashing<T>(size) {}
    virtual ~DivisionHashing() {}
 protected:
    virtual int m_HashMethod(int key)
    {
        return key % this->table_size;
    }
};

template <class T>
class MultiplicationHashing : public Hashing<T>
{
 public:
    // r : the bits of table size, table_size = x^r
    // a : the multiplier in MultiplicationHashing
    // w : the bits of key(default is the sizeof int)
    MultiplicationHashing(int r, int a, int w = 0) : Hashing<T>(0x01 << r), r(r), a(a)
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
