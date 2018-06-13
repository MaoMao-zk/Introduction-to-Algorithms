// Copyright [2017] <MaoMao>

#ifndef _ACTIVITY_CHOICE_H_
#define _ACTIVITY_CHOICE_H_

#include "Algorithms.h"

class ActivityChoice : public Algorithms
{
 public:
    ActivityChoice();
    virtual ~ActivityChoice();
 protected:
    virtual void m_BuildInput();
    virtual void m_Execute();
    virtual bool m_CheckOutput();
private:
    int (*activity)[2];
    int num;
    int *result_activity;
    int result_num;
};

#endif
