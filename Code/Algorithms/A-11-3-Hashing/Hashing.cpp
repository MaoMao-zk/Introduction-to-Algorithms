// Copyright [2017] <MaoMao>

#include "Hashing.h"
#include "../A-10-2-DoublyLinkedList/DoublyLinkedList.h"

Hashing::Hashing(int size)
{
    table_size = size;
    table = new DoublyLinkedList[size];
}

Hashing::~Hashing()
{
    // TODO(MaoMao): delete table data
}

Element* Hashing::Search(int key)
{
    int hash_key = m_HashMethod(key);
    return table[hash_key].Search(key);
}

void Hashing::Insert(Element* elm)
{
    int hash_key = m_HashMethod(elm->key);
    table[hash_key].Insert(elm);
}

void Hashing::Delete(Element* elm)
{
    int hash_key = m_HashMethod(elm->key);
    table[hash_key].Delete(elm);
}
