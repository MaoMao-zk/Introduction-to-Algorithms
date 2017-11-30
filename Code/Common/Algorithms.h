#ifndef _ALGORITHMS_H_
#define _ALGORITHMS_H_

#include <string>

using namespace std;

struct AlgorithmsInfo
{
    string id;
    string name;
};

class Algorithms
{
public:
    virtual ~Algorithms(){}
    AlgorithmsInfo& GetInfo();
    void Run();
protected:
    virtual void m_BuildInput() = 0;
    virtual void m_Execute() = 0;
    virtual bool m_CheckOutput() = 0;
protected:
    AlgorithmsInfo m_info;
};

#endif