// Copyright [2017] <MaoMao>

#include "DoublyLinkedListTest.h"
#include "DoublyLinkedList.h"
#include <iostream>

ICollection* DoublyLinkedListTest::CreatCollection()
{
    return new DoublyLinkedList();
}
Element* DoublyLinkedListTest::CreatElement()
{
    return new DoublyLinkedElement();
}
void DoublyLinkedListTest::Print()
{
    DoublyLinkedList* list = static_cast<DoublyLinkedList*>(m_pCollection);
    DoublyLinkedElement* p = list->head;
    while (p != nullptr)
    {
        printf("%d, ", p->key);
        p = p->next;
    }
    printf("\n");
}
