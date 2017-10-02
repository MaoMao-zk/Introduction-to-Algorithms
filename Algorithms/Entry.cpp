#include <iostream>
#include <windows.h>
#include "AlgorithmsList.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    AlgorithmsList algorithmsList;

    list<AlgorithmsInfo>* infos = algorithmsList.GetList();

    for each (AlgorithmsInfo var in *infos)
    {
        cout << var.id << "\t[" << var.name << "]" << endl;
    }

    cout << "\nPlease enter a id to run" << endl;

    string id;
    cin >> id;

    cout << id << " run:" << endl;

    algorithmsList.RunAlgorithmsByID(id);

    Sleep(1000);
    
    return 0;
}