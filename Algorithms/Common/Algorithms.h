#ifndef _ALGORITHMS_H_
#define _ALGORITHMS_H_

#include <string>
#include <assert.h>
#include <sys/time.h>

using namespace std;

struct AlgorithmsInfo
{
    string id;
    string name;
};

class Algorithms
{
public:
    AlgorithmsInfo& GetInfo()
    {
        assert(m_info.id != "");
        return m_info;
    }
    void Run()
    {
        m_BuildInput();

        timeval tv1, tv2;
        gettimeofday(&tv1,NULL);

        m_Execute();
        
        gettimeofday(&tv2,NULL);
        long long used_time = (tv2.tv_sec*1000*1000 + tv2.tv_usec) - (tv1.tv_sec*1000*1000 + tv1.tv_usec);
        long long seconds = used_time / (1000*1000);
        used_time = used_time % (1000*1000);
        double mile_seconds = used_time / 1000.0;
        printf("Time used %llds %.3lfms\n", seconds, mile_seconds);

        m_CheckOutput();
    }
protected:
    virtual void m_BuildInput() = 0;
    virtual void m_Execute() = 0;
    virtual void m_CheckOutput() = 0;
protected:
    AlgorithmsInfo m_info;
};

#endif