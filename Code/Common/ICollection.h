// Copyright [2017] <MaoMao>

#ifndef _I_COLLECTION_H_
#define _I_COLLECTION_H_

template <class T>
struct Element
{
    int key;
    T data;
};

template <class T>
class ICollection
{
 public:
    // Return null if not found
    virtual Element<T>* Search(int key) = 0;
    virtual void Insert(Element<T>* elm) = 0;
    virtual void Delete(Element<T>* elm) = 0;
};

template <class T>
class IAdvancedCollection : public ICollection<T>
{
 public:
    // Return null if empty
    virtual Element<T>* Minimum() = 0;
    // Return null if empty
    virtual Element<T>* Maximum() = 0;
    // Return null if elm is the biggest
    virtual Element<T>* Successor(Element<T>* elm) = 0;
    // Return null if elm is the smallest
    virtual Element<T>* Predecessor(Element<T>* elm) = 0;
};

#endif
