// Copyright [2017] <MaoMao>

#include "DoublyLinkedListTest.h"
#include "DoublyLinkedList.hpp"
#include <iostream>

void DoublyLinkedListTest::m_Execute()
{
    int choice = -1;
    DoublyLinkedList<int> list;
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
                Element<int>* elm = list.Search(key);
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
                list.Insert(elm);
                break;
            }
            case 3:
            {
                printf("Input key to delete :\n");
                int key;
                std::cin >> key;
                Element<int>* elm = list.Search(key);
                if (elm == nullptr)
                    printf("Not found key=%d\n", key);
                else
                    list.Delete(elm);
                break;
            }
            case 4:
            {
                DoublyLinkedElement<int>* p = list.head;
                while (p != nullptr)
                {
                    printf("[%d,%d] ", p->key, p->data);
                    p = p->next;
                }
                printf("\n");
                break;
            }
        }
    }while(choice > 0);
}
