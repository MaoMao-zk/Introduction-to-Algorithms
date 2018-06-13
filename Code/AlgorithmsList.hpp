// Copyright [2017] <MaoMao>

#include "Algorithms.h"
#include <assert.h>
#include <map>
#include <vector>

using namespace std;

#include "Algorithms/A-02-1-InsertionSort/InsertionSort.h"
#include "Algorithms/A-02-3-MergeSort/MergeSort.h"
#include "Thinkings/T-02-4-Inversion/Inversion.h"
#include "Algorithms/A-04-1-MaxSubArray/MaxSubArray.h"
#include "Algorithms/A-04-2-MatrixMultiply/MatrixMultiply.h"
#include "Algorithms/A-06-4-HeapSort/HeapSort.h"
#include "Algorithms/A-06-5-PriorityQueue/PriorityQueueTest.h"
#include "Thinkings/T-06-3-YoungTableau/YoungTableau.h"
#include "Algorithms/A-07-1-QuickSort/QuickSort.h"
#include "Algorithms/A-08-2-CountingSort/CountingSort.h"
#include "Algorithms/A-08-3-RadixSort/RadixSort.h"
#include "Algorithms/A-09-2-RandomizedSelect/RandomizedSelect.h"
#include "Algorithms/A-10-2-DoublyLinkedList/DoublyLinkedListTest.h"
#include "Algorithms/A-11-3-Hashing/HashingTest.h"
#include "Algorithms/A-12-0-BinarySearchTree/BinarySearchTreeTest.h"
#include "Algorithms/A-13-0-RedBlackTree/RedBlackTreeTest.h"
#include "Thinkings/T-13-3-AVLTree/AVLTreeTest.h"
#include "Algorithms/A-15-1-RodCutting/RodCutting.h"
#include "Algorithms/A-15-2-MatrixChainX/MatrixChainX.h"
#include "Algorithms/A-15-4-LCS/LCS.h"

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
        m_AddAlorithms(new PriorityQueueTest());
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
        m_AddAlorithms(new MatrixChainX());
        m_AddAlorithms(new LCS());
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
