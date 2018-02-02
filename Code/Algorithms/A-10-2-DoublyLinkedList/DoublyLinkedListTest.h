// Copyright [2017] <MaoMao>

#ifndef _I_DOUBLY_LINKED_LIST_TEST_H_
#define _I_DOUBLY_LINKED_LIST_TEST_H_

#include "CollectionTest.h"

class DoublyLinkedListTest : public CollectionTest
{
 public:
    DoublyLinkedListTest()
    {
        m_info.id = "A-10-2";
        m_info.name = "DoublyLinkedList";
    }
    virtual ~DoublyLinkedListTest() {}
 protected:
    virtual ICollection<int>* CreatCollection();
    virtual Element<int>* CreatElement();
    virtual void Print();
};

#endif
