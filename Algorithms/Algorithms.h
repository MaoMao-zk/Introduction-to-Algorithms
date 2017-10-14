#pragma once
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
    virtual AlgorithmsInfo GetInfo() = 0;
    virtual void Run() = 0;
};