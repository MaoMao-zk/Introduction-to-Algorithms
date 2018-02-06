// Copyright [2017] <MaoMao>

#include "DoublyLinkedList.h"


DoublyLinkedList::DoublyLinkedList()
{
    head = nullptr;
    size = 0;
}

Element* DoublyLinkedList::Search(int key)
{
    DoublyLinkedElement* p = head;
    while (p != nullptr && p->key != key)
        p = p->next;
    return p;
}

void DoublyLinkedList::Insert(Element* elm)
{
    DoublyLinkedElement* pElm = static_cast<DoublyLinkedElement*>(elm);
    pElm->prev = nullptr;
    pElm->next = head;
    head = pElm;
    if (pElm->next != nullptr)
        pElm->next->prev = pElm;
    size++;
}

void DoublyLinkedList::Delete(Element* elm)
{
    DoublyLinkedElement* pElm = static_cast<DoublyLinkedElement*>(elm);
    if (pElm->prev != nullptr)
        pElm->prev->next = pElm->next;
    else
        head = pElm->next;
    if (pElm->next != nullptr)
        pElm->next->prev = pElm->prev;
    size--;
}
