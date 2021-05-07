#include <iostream>
#include "GameManager.h"
#include "GameObject.h"

#include<vector>

using namespace std;


int main(int argc, char* argv[]) {
    GameManager theApp;

    vector<int> vectorEnteros;
    vector<int> vectorEnterosAux;

    cout << "max_size() = " << vectorEnteros.max_size() << endl;
    cout << "size() = " << vectorEnteros.size() << endl;
    vectorEnteros.push_back(5);
    //vectorEnteros.resize(100000);
    cout << "size() = " << vectorEnteros.size() << endl;
    vectorEnteros.push_back(10);
    cout << "size() = " << vectorEnteros.size() << endl;
    vectorEnteros.push_back(15);
    cout << "size() = " << vectorEnteros.size() << endl;
    vectorEnteros.push_back(20);
    cout << "size() = " << vectorEnteros.size() << endl;
    cout << "max_size() = " << vectorEnteros.max_size() << endl;
    vectorEnterosAux.push_back(3);
    vectorEnterosAux.push_back(6);
    vectorEnterosAux.push_back(9);
    vectorEnterosAux.push_back(12);

    vectorEnteros.swap(vectorEnterosAux);

    for (int i = 0; i < vectorEnteros.size(); i++) {
        cout << vectorEnteros[i] << " -- " << vectorEnterosAux[i] << endl;
    }

    if (vectorEnteros > vectorEnterosAux) {
        cout << "vectorEnteros es mayor" << endl;
    }
    else {
        cout << "vectorEnterosAux es mayor" << endl;
    }
 
    //auto ive = vectorEnteros.begin();
    
    for (auto ive = vectorEnteros.begin(); ive != vectorEnteros.end(); ++ive) {
        cout << *ive << endl;
    }


    system("pause");
    return theApp.onExecute();
}