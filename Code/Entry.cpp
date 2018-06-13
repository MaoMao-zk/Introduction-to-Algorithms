// Copyright [2017] <MaoMao>

#include <iostream>
#include <vector>
#include "AlgorithmsList.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    AlgorithmsList algorithmsList;

    vector<AlgorithmsInfo>* infos = algorithmsList.GetList();

    if (infos->size() <= 0)
        return -1;

    cout << "Index" << "\t"<< "ID" << "\t" << "Name" << endl;
    for (unsigned int i = 0; i < infos->size(); i++)
    {
        cout << i << "\t" \
             << infos->at(i).id << "\t" \
             << infos->at(i).name << endl;
    }

    cout << "\nPlease enter index to run" << endl;

    unsigned int index;
    cin >> index;

    algorithmsList.RunAlgorithmsByIndex(index);

#ifdef WIN32
    system("pause");
#endif

    return 0;
}
