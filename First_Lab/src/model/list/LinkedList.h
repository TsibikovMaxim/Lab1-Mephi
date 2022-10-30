#pragma once

#include <iostream>

using namespace std;

template <class T >
class LinkedList {
    struct Node {
        T field;
        Node* next;
    };
private:
    Node* head;
    Node* getAt(int index) {
        int count = 0;
        if (head == NULL)
            return head;
        Node* p = head;
        while (index != count){
            count++;
            p = p->next;
        }
        return p;
    }
    LinkedList(Node* head) {
        this->head = head;
    }
public:
    LinkedList() {
        head = NULL;
    }

    LinkedList(T* items, int count) : LinkedList() {
        for (int i = 0; i < count; i++)
            append(items[i]);
    }

    LinkedList(const LinkedList& v){
        Node* p1 = 0;
        Node* p2 = 0;
        if (v.head == 0) {
            head = 0;
            return;
        } else {
            head = new Node;
            head->field = v.head->field;

            p1 = head;
            p2 = v.head->next;
        }

        while (p2) {
            p1->next = new Node;
            p1 = p1->next;
            p1->field = p2->field;
            p2 = p2->next;
        }
        p1->next = 0;
    }
    ~LinkedList() {
        Node* next = head;
        while (next) {             
            Node* deleteMe = next;
            next = next->next;    
            delete deleteMe;     
        }
    }

    void prepend(T val) {
        Node* n = new Node();   
        n->field = val;             
        n->next = head;         
                              
        head = n;               
    }

    void append(T val) {
        if (head == NULL) {
            prepend(val);
        }
        else {
            Node* p = head;
            while (p->next != NULL)
                p = p->next;
            p->next = new Node();
            p->next->field = val;
        }
    }
     
    void insertAt(T val, int index) {
        if (index == 0) {
            prepend(val); return;
        }
        if (index > getLength() || index < 0) {
            throw exception(); return;
        }
        Node* tmp = new Node();
        tmp->field = val;
        tmp->next = getAt(index - 1)->next;
        getAt(index - 1)->next = tmp;
    }

    T getLast() {
        if (head == NULL) {
            throw exception();
        } else {
            Node *p = head;
            while (p->next != NULL)
                p = p->next;
            return p->field;
        }
    }

    T getFirst() {
        if (head == NULL)
            throw exception();
        Node* p = head;
        return p->field;
    }

    T get(int index) {
        if (index < 0 || index >= getLength())
            throw exception();
        return getAt(index)->field;
    }

    int getLength() {
        int count = 0;
        if (head == NULL) 
            return count;
        Node* p = head;
        do {
            count++;
            p = p->next;
        } while (p != NULL);
        return count;
    }

    LinkedList<T> getSubList(int startIndex, int endIndex) {
        if (startIndex < 0 || endIndex > getLength() || endIndex < startIndex)
            throw exception();

        LinkedList<T> newList;
        for (int i = 0; i < endIndex - startIndex + 1; i++)
            newList.append(getAt(i + startIndex)->field);
        return newList;
    }

    LinkedList<T> concat(LinkedList<T> list) {
        LinkedList<T> resList;
        Node* p = head;
        do {
            resList.append(p->field);
            p = p->next;
        } while (p != NULL);
        Node* p1 = list.head;
        do {
            resList.append(p1->field);
            p1 = p1->next;
        } while (p1 != NULL);
        return resList;
    }

    void output() {
        if (head == NULL) { cout << "Список пуст" << endl; return; }
        Node* p = head;
        do {
            cout << p->field << " ";
            p = p->next;
        } while (p != NULL);
        cout << endl;
    }

    void swap(int index1, int index2){
        Node* tmp = head;
        int count=0;
        int min, max;
        if(index1<index2){
            min = index1;
            max = index2;
        }
        else{
            min = index2;
            max = index1;
        }
        int diff = max - min;
        while(min!=count){
            tmp=  tmp->next;
            count++;
        }
        int minValue = tmp->field;
        while(max!=count){
            tmp=  tmp->next;
            count++;
        }
        int maxValue = tmp->field;
        tmp->field = minValue;
        tmp = head;
        count =0;
        while(min!=count){
            tmp=  tmp->next;
            count++;
        }
        tmp->field = maxValue;
    }
};
