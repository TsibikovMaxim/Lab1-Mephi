#pragma once

#include <iostream>

#include "../Sequence.h"
#include "LinkedList.h"

using namespace std;

template <class T> 
class LinkedListSequence : public Sequence<T> {
private:
	LinkedList<T>* list;

public:

	LinkedListSequence() {
		list = new LinkedList<T>();
	}

	LinkedListSequence(int size) {
		list = new LinkedList<T>();
	}

	LinkedListSequence(T* items, int count) {
		list = new LinkedList<T>(items, count);
	}

	LinkedListSequence(LinkedListSequence<T>& list) : LinkedListSequence() {
		for (int i = 0; i < list.getLength(); i++)
			this->list->append(list.get(i));
	}

	~LinkedListSequence() {
		list->~LinkedList();
	}

	int getLength() override{
		return list->getLength();
	}

	void append(T item) override {
		list->append(item);
	}

	void prepend(T item) override {
		list->prepend(item);
	}

	T getFirst() override {
		return list->getFirst();
	}

	T getLast() override {
		return list->getLast();
	}

	T get(int index) override {
		return list->get(index);
	}

	void output() override {
		list->output();
	}

	void insertAt(T item, int index) override {
		list->insertAt(item, index);
	}

	void multiplyWythConst(int con) override {
		for (int i = 0; i < getLength(); i++)
			insertAt(get(i), i);
	}

	LinkedListSequence<T> getSubsequence(int startIndex, int endIndex) {
		LinkedListSequence<T> tmpList;
		LinkedList<T> subList = list->getSubList(startIndex, endIndex);
		for (int i = 0; i < subList.getLength(); i++)
			tmpList.append(subList.get(i));
		return tmpList;
	}

	LinkedListSequence<T> concat(LinkedListSequence<T> list) {
		LinkedList<T> tmpList;
		for (int i = 0; i < list.getLength(); i++)
			tmpList.append(list.get(i));
		LinkedList<T> concatedList = this->list->concat(tmpList);
		LinkedListSequence<T> resList;
		for (int i = 0; i < concatedList.getLength(); i++)
			resList.append(concatedList.get(i));
		return resList;
	}

    void swap(int a, int b) override{
        list->swap(a,b);
    }
};
