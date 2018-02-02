// Copyright [2017] <MaoMao>

#include "CollectionTest.h"
#include <iostream>
#include <assert.h>

void CollectionTest::m_BuildInput()
{
    m_pCollection = CreatCollection();
    assert(m_pCollection != nullptr);
}

void CollectionTest::m_Execute()
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
                Element<int>* elm = m_pCollection->Search(key);
                if (elm == nullptr)
                    printf("Not found key=%d\n", key);
                else
                    printf("Found key=%d, data=%d\n", key, elm->data);
                break;
            }
            case 2:
            {
                printf("Input key & data to insert :\n");
                Element<int>* elm = CreatElement();
                std::cin >> elm->key >> elm->data;
                m_pCollection->Insert(elm);
                break;
            }
            case 3:
            {
                printf("Input key to delete :\n");
                int key;
                std::cin >> key;
                Element<int>* elm = m_pCollection->Search(key);
                if (elm == nullptr)
                    printf("Not found key=%d\n", key);
                else
                {
                    m_pCollection->Delete(elm);
                    delete elm;
                }
                break;
            }
            case 4:
            {
                Print();
                break;
            }
        }
    }while(choice > 0);
}

bool CollectionTest::m_CheckOutput()
{
    return true;
}
