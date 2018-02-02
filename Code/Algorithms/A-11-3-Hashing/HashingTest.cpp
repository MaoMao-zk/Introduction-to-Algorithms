// Copyright [2017] <MaoMao>

#include "HashingTest.h"
#include "Hashing.hpp"
#include "../A-10-2-DoublyLinkedList/DoublyLinkedList.hpp"

#include <iostream>
#include <stdlib.h>
#include <time.h>

ICollection<int>* HashingTest::CreatCollection()
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
        return new MultiplicationHashing<int>(r, a, w);
    }
    else
    {
        int m;
        std::cout << "Please input m:\n"
                  << "\th(k) = k mod m\n";
        std::cin >> m;
        return new DivisionHashing<int>(m);
    }
}

Element<int>* HashingTest::CreatElement()
{
    return new DoublyLinkedElement<int>();
}

void HashingTest::Print()
{
    Hashing<int>* hash = static_cast<Hashing<int>*>(m_pCollection);
    for (int i = 0; i < hash->table_size; i++)
    {
        printf("list_size:%d ... ", hash->table[i].size);
        DoublyLinkedElement<int>* p = hash->table[i].head;
        while (p != nullptr)
        {
            printf("[%d,%d] ", p->key, p->data);
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
        DoublyLinkedElement<int>* elm = new DoublyLinkedElement<int>();
        elm->key = rand();
        elm->data = rand();
        if (elm->key < 0)
            elm->key = -elm->key;
        hash->Insert(elm);
    }
}*/
