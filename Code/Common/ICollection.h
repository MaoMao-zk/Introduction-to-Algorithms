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

#endif
