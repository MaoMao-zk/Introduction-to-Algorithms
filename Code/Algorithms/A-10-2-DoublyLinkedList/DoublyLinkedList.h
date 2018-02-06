// Copyright [2017] <MaoMao>

#ifndef _I_DOUBLY_LINKED_LIST_HPP_
#define _I_DOUBLY_LINKED_LIST_HPP_

#include "ICollection.h"

struct DoublyLinkedElement : public Element
{
    DoublyLinkedElement* next;
    DoublyLinkedElement* prev;
};


class DoublyLinkedList : public ICollection
{
 public:
    DoublyLinkedList();
    virtual ~DoublyLinkedList() {}
 public:
    // Return null if not found
    virtual Element* Search(int key);
    virtual void Insert(Element* elm);
    virtual void Delete(Element* elm);
 public:
    DoublyLinkedElement* head;
    int size;
};

#endif
