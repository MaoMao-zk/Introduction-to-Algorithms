// Copyright [2017] <MaoMao>

#include "DoublyLinkedListTest.h"
#include "DoublyLinkedList.hpp"
#include <iostream>

ICollection<int>* DoublyLinkedListTest::CreatCollection()
{
    return new DoublyLinkedList<int>();
}
Element<int>* DoublyLinkedListTest::CreatElement()
{
    return new DoublyLinkedElement<int>();
}
void DoublyLinkedListTest::Print()
{
    DoublyLinkedList<int>* list = static_cast<DoublyLinkedList<int>*>(m_pCollection);
    DoublyLinkedElement<int>* p = list->head;
    while (p != nullptr)
    {
        printf("[%d,%d] ", p->key, p->data);
        p = p->next;
    }
    printf("\n");
}
