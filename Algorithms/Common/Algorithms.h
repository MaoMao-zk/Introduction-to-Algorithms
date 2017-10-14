#ifndef _ALGORITHMS_H_
#define _ALGORITHMS_H_

#include <string>
#include <assert.h>

using namespace std;

struct AlgorithmsInfo
{
    string id;
    string name;
};

class Algorithms
{
public:
    AlgorithmsInfo GetInfo()
    {
        assert(m_info.id != "");
        return m_info;
    }
    virtual void Run() = 0;
protected:
    AlgorithmsInfo m_info;
};

#endif