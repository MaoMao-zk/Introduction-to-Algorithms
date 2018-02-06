// Copyright [2017] <MaoMao>

#ifndef _I_COLLECTION_H_
#define _I_COLLECTION_H_

struct Element
{
    int key;
};

class ICollection
{
 public:
    // Return null if not found
    virtual Element* Search(int key) = 0;
    virtual void Insert(Element* elm) = 0;
    virtual void Delete(Element* elm) = 0;
};

class IAdvancedCollection : public ICollection
{
 public:
    // Return null if empty
    virtual Element* Minimum() = 0;
    // Return null if empty
    virtual Element* Maximum() = 0;
    // Return null if elm is the biggest
    virtual Element* Successor(Element* elm) = 0;
    // Return null if elm is the smallest
    virtual Element* Predecessor(Element* elm) = 0;
};

#endif
