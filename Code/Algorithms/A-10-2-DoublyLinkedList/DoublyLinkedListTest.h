// Copyright [2017] <MaoMao>

#ifndef _I_DOUBLY_LINKED_LIST_TEST_H_
#define _I_DOUBLY_LINKED_LIST_TEST_H_

#include "Algorithms.h"

class DoublyLinkedListTest : public Algorithms
{
 public:
    DoublyLinkedListTest()
    {
        m_info.id = "A-10-2";
        m_info.name = "DoublyLinkedList";
    }
    virtual ~DoublyLinkedListTest() {}
 protected:
    virtual void m_BuildInput() {}
    virtual void m_Execute();
    virtual bool m_CheckOutput() {return true;}
};

#endif
