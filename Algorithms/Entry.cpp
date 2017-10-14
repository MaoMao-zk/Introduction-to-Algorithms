#include <iostream>
#include "AlgorithmsList.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    AlgorithmsList algorithmsList;

    list<AlgorithmsInfo>* infos = algorithmsList.GetList();

    for(list<AlgorithmsInfo>::iterator itor = infos->begin();
        itor!=infos->end(); itor++)
    {
        cout << itor->id << "\t[" << itor->name << "]" << endl;
    }

    cout << "\nPlease enter a id to run" << endl;

    string id;
    cin >> id;

    cout << id << " run:" << endl;

    algorithmsList.RunAlgorithmsByID(id);

    return 0;
}