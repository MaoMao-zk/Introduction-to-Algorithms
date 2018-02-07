// Copyright [2017] <MaoMao>

#include "AdvancedCollectionTest.h"
#include <iostream>
#include <assert.h>

void AdvancedCollectionTest::m_Execute()
{
    IAdvancedCollection* pCollection = static_cast<IAdvancedCollection*>(m_pCollection);
    int choice = -1;
    do
    {
        printf("1. Search.\n");
        printf("2. Insert.\n");
        printf("3. Delect.\n");
        printf("4. Minimum.\n");
        printf("5. Maximum.\n");
        printf("6. Successor.\n");
        printf("7. Predecessor.\n");
        printf("8. Print.\n");
        printf("-1. Exit.\n");
        std::cin >> choice;
        switch (choice)
        {
            case 1:
            {
                printf("Input key to search :\n");
                int key;
                std::cin >> key;
                Element* elm = pCollection->Search(key);
                if (elm == nullptr)
                    printf("Not found key=%d\n", key);
                else
                    printf("Found key=%d\n", key);
                break;
            }
            case 2:
            {
                printf("Input key to insert :\n");
                Element* elm = CreatElement();
                std::cin >> elm->key;
                pCollection->Insert(elm);
                break;
            }
            case 3:
            {
                printf("Input key to delete :\n");
                int key;
                std::cin >> key;
                Element* elm = pCollection->Search(key);
                if (elm == nullptr)
                    printf("Not found key=%d\n", key);
                else
                {
                    pCollection->Delete(elm);
                    delete elm;
                }
                break;
            }
            case 4:
            {
                Element* elm = pCollection->Minimum();
                if (elm != nullptr)
                    printf("Minimum key=%d\n", elm->key);
                else
                    printf("Collection is emplty.\n");
                break;
            }
            case 5:
            {
                Element* elm = pCollection->Maximum();
                if (elm != nullptr)
                    printf("Maximum key=%d\n", elm->key);
                else
                    printf("Collection is emplty.\n");
                break;
            }
            case 6:
            {
                printf("Input key to find it's Successor :\n");
                int key;
                std::cin >> key;
                Element* elm = pCollection->Search(key);
                if (elm == nullptr)
                    printf("Not found key=%d\n", key);
                else
                {
                    Element* successor = pCollection->Successor(elm);
                    if (successor != nullptr)
                        printf("Successor of %d is %d\n", key, successor->key);
                    else
                        printf("%d is the Maximum key.\n", elm->key);
                }
                break;
            }
            case 7:
            {
                printf("Input key to find it's Predecessor :\n");
                int key;
                std::cin >> key;
                Element* elm = pCollection->Search(key);
                if (elm == nullptr)
                    printf("Not found key=%d\n", key);
                else
                {
                    Element* predecessor = pCollection->Predecessor(elm);
                    if (predecessor != nullptr)
                        printf("Predecessor of %d is %d\n", key, predecessor->key);
                    else
                        printf("%d is the Minimum key.\n", elm->key);
                }
                break;
            }
            case 8:
            {
                Print();
                break;
            }
        }
    }while(choice > 0);
}

bool AdvancedCollectionTest::m_CheckOutput()
{
    IAdvancedCollection* pCollection = static_cast<IAdvancedCollection*>(m_pCollection);
    Element* current = pCollection->Minimum();
    Element* next = nullptr;
    while (current != nullptr)
    {
        next = pCollection->Successor(current);
        if (next != nullptr && next->key < current->key)
        {
            fprintf(stderr, "next->key(%d) < current->key(%d)\n", next->key, current->key);
            return false;
        }
        current = next;
    }
    return true;
}
