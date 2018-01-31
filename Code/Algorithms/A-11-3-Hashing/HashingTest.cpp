// Copyright [2017] <MaoMao>

#include "HashingTest.h"
#include "../A-10-2-DoublyLinkedList/DoublyLinkedList.hpp"

#include <iostream>
#include <stdlib.h>
#include <time.h>

void HashingTest::m_BuildInput()
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
        hash = new MultiplicationHashing<int>(r, a, w);
    }
    else
    {
        int m;
        std::cout << "Please input m:\n"
                  << "\th(k) = k mod m\n";
        std::cin >> m;
        hash = new DivisionHashing<int>(m);
    }

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
}

void HashingTest::m_Execute()
{
    int choice = -1;
    do
    {
        printf("1. Search.\n");
        printf("2. Insert.\n");
        printf("3. Delect.\n");
        printf("4. Print.\n");
        printf("-1. Exit.\n");
        std::cin >> choice;
        switch (choice)
        {
            case 1:
            {
                printf("Input key to search :\n");
                int key;
                std::cin >> key;
                Element<int>* elm = hash->Search(key);
                if (elm == nullptr)
                    printf("Not found key=%d\n", key);
                else
                    printf("Found key=%d, data=%d\n", key, elm->data);
                break;
            }
            case 2:
            {
                printf("Input key & data to insert :\n");
                DoublyLinkedElement<int>* elm = new DoublyLinkedElement<int>();
                std::cin >> elm->key >> elm->data;
                hash->Insert(elm);
                break;
            }
            case 3:
            {
                printf("Input key to delete :\n");
                int key;
                std::cin >> key;
                Element<int>* elm = hash->Search(key);
                if (elm == nullptr)
                    printf("Not found key=%d\n", key);
                else
                {
                    hash->Delete(elm);
                    delete elm;
                }
                break;
            }
            case 4:
            {
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
                break;
            }
        }
    }while(choice > 0);
}
