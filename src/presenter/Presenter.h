#pragma once
#include "vector"

#include "../model/array/ArraySequence.h"
#include "../model/Sort.h"



class Presenter {
private:
	ArraySequence<int>* arr;
	int size;
public:
	void createArr(int size);
	string sortArr(string s); // ���������� ����� ����������
	string getArr();
	vector<double> getPointForGraph(string s);
};
