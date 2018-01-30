// Copyright [2017] <MaoMao>

#ifndef _I_DOUBLY_LINKED_LIST_HPP_
#define _I_DOUBLY_LINKED_LIST_HPP_

#include "ICollection.h"

template <class T>
struct DoublyLinkedElement : public Element<T>
{
    DoublyLinkedElement* next;
    DoublyLinkedElement* prev;
};


template <class T>
class DoublyLinkedList : public ICollection<T>
{
 public:
    DoublyLinkedList()
    {
        head = nullptr;
    }
    virtual ~DoublyLinkedList() {}
 public:
    // Return null if not found
    virtual Element<T>* Search(int key)
    {
        DoublyLinkedElement<T>* p = head;
        while (p != nullptr && p->key != key)
            p = p->next;
        return p;
    }
    virtual void Insert(Element<T>* elm)
    {
        DoublyLinkedElement<T>* pElm = static_cast<DoublyLinkedElement<T>*>(elm);
        pElm->prev = nullptr;
        pElm->next = head;
        head = pElm;
        if (pElm->next != nullptr)
            pElm->next->prev = pElm;
    }
    virtual void Delete(Element<T>* elm)
    {
        DoublyLinkedElement<T>* pElm = static_cast<DoublyLinkedElement<T>*>(elm);
        if (pElm->prev != nullptr)
            pElm->prev->next = pElm->next;
        else
            head = pElm->next;
        if (pElm->next != nullptr)
            pElm->next->prev = pElm->prev;
    }
 public:
    DoublyLinkedElement<T>* head;
};

#endif
