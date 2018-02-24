// Copyright [2017] <MaoMao>

#include "Algorithms.h"
#include <assert.h>
#include <map>
#include <vector>

using namespace std;

#include "InsertionSort.h"
#include "MergeSort.h"
#include "Inversion.h"
#include "MaxSubArray.h"
#include "MatrixMultiply.h"
#include "HeapSort.h"
#include "YoungTableau.h"
#include "QuickSort.h"
#include "CountingSort.h"
#include "RadixSort.h"
#include "RandomizedSelect.h"
#include "DoublyLinkedListTest.h"
#include "HashingTest.h"
#include "BinarySearchTreeTest.h"
#include "RedBlackTreeTest.h"
#include "AVLTreeTest.h"
#include "RodCutting.h"

class AlgorithmsList
{
 public:
    AlgorithmsList()
    {
        m_AddAlorithms(new InsertionSort());
        m_AddAlorithms(new MergeSort());
        m_AddAlorithms(new Inversion());
        m_AddAlorithms(new MaxSubArray());
        m_AddAlorithms(new MatrixMultiply());
        m_AddAlorithms(new HeapSort());
        m_AddAlorithms(new YoungTableau());
        m_AddAlorithms(new QuickSort());
        m_AddAlorithms(new CountingSort());
        m_AddAlorithms(new RadixSort());
        m_AddAlorithms(new RandomizedSelect());
        m_AddAlorithms(new DoublyLinkedListTest());
        m_AddAlorithms(new HashingTest());
        m_AddAlorithms(new BinarySearchTreeTest());
        m_AddAlorithms(new RedBlackTreeTest());
        m_AddAlorithms(new AVLTreeTest());
        m_AddAlorithms(new RodCutting());
    }

    ~AlgorithmsList()
    {
        m_list.clear();

        for (map<string, Algorithms*>::iterator itor = m_map.begin();
            itor != m_map.end(); itor++)
        {
            delete itor->second;
            itor->second = NULL;
        }
        m_map.clear();
    }

    vector<AlgorithmsInfo>* GetList()
    {
        return &m_list;
    }

    bool RunAlgorithmsByIndex(unsigned int index)
    {
        if (index < m_list.size())
            return RunAlgorithmsByID(m_list[index].id);
        else
            return false;
    }

    bool RunAlgorithmsByID(string id)
    {
        Algorithms* p = NULL;
        try
        {
            p = m_map.at(id);
        }
        catch (...)
        {
            p = NULL;
        }

        if (p == NULL)
        {
            perror("Can't find Algorithms\n");
            return false;
        }
        else
        {
            printf("[%s]%s run:\n", p->GetInfo().id.c_str(), p->GetInfo().name.c_str());
            p->Run();
            return true;
        }
    }

 private:
    void m_AddAlorithms(Algorithms* alg)
    {
        assert(alg != NULL);

        m_list.push_back(alg->GetInfo());
        m_map.insert(pair<string, Algorithms*>(alg->GetInfo().id, alg));
    }

 private:
    vector<AlgorithmsInfo> m_list;
    map<string, Algorithms*> m_map;
};
