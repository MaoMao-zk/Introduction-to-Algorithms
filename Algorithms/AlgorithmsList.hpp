#include "Algorithms.h"
#include <map>
#include <list>

class AlgorithmsList
{
public:
    AlgorithmsList()
    {
        m_list = new list<AlgorithmsInfo>();
        m_map = new map<string, Algorithms*>;
    }

    list<AlgorithmsInfo>* GetList()
    {
        return m_list;
    }

    bool RunAlgorithmsByID(string id)
    {
        Algorithms* p = NULL;
        try
        {
            p = m_map->at(id);
        }
        catch (...)
        {
            p = NULL;
        }

        if (p == NULL)
            return false;
        else
        {
            p->Run();
            return true;
        }
    }

private:
    list<AlgorithmsInfo>* m_list;
    map<string, Algorithms*>* m_map;
};