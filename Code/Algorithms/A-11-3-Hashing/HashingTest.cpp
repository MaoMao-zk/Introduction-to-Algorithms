// Copyright [2017] <MaoMao>

#include "HashingTest.h"
#include "Hashing.h"
#include "../A-10-2-DoublyLinkedList/DoublyLinkedList.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>

ICollection* HashingTest::CreatCollection()
{
    std::cout << "Chose the hash method(Default is 1):\n"
              << "[1] Division Hash Method \n"
              << "[2] Multiplication Hash Method\n";
    int choice;
    std::cin >> choice;

    if (choice == 2)
    {
        int r, a, w;
        std::cout << "Please input r a w(input 0 as default):\n"
                  << "\th(k) = [(a · k) mod 2^w] >> (w − r)\n";
        std::cin >> r >> a >> w;
        return new MultiplicationHashing(r, a, w);
    }
    else
    {
        int m;
        std::cout << "Please input m:\n"
                  << "\th(k) = k mod m\n";
        std::cin >> m;
        return new DivisionHashing(m);
    }
}

Element* HashingTest::CreatElement()
{
    return new DoublyLinkedElement();
}

void HashingTest::Print()
{
    Hashing* hash = static_cast<Hashing*>(m_pCollection);
    for (int i = 0; i < hash->table_size; i++)
    {
        printf("list_size:%d ... ", hash->table[i].size);
        DoublyLinkedElement* p = hash->table[i].head;
        while (p != nullptr)
        {
            printf("%d, ", p->key);
            p = p->next;
        }
        printf("\n");
    }
}

/*
void HashingTest::m_BuildInput()
{
    // random input some data
    printf("Please input inital data size:");
    int size;
    std::cin >> size;
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        DoublyLinkedElement* elm = new DoublyLinkedElement();
        elm->key = rand();
        elm->data = rand();
        if (elm->key < 0)
            elm->key = -elm->key;
        hash->Insert(elm);
    }
}*/
