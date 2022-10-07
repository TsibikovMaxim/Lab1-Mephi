#pragma once
#include "vector"

#include "ArraySequence.h"
#include "LinkedListSequence.h"
#include "Sort.h"

#define arrType ArraySequence<int>

class Presenter {
private:
    arrType* arr;
    int size;
public:
    void createArr(int size);
    string sortArr(string s); // возвращает время выполнения
    string getArr();
    vector<double> getPointForGraph(string s);
};
