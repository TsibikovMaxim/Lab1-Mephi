#include <iostream>
#include <string>
#include <vector>
#include "src/libs/array/ArraySequence.h"
#include "src/libs/list/LinkedListSequence.h"
#include "src/libs/Vector.h"
#include "src/libs/Sort.h"
using namespace std;

void arraySequenceTest();
void linkedListSequenceTest();
void sortTest();

void startAllTests() {
	cout << "\nArraySequence:\n";
	arraySequenceTest();
	cout << "\nLinkedListSequence:\n";
	linkedListSequenceTest();
    cout << "\nSorts:\n";
    sortTest();
}

void check(int flag, string msg) {
	if (flag)
		cout << "\t" << msg << " - OK\n";
	else
		cout << "\t" << msg << " - NO\n";
}

void arraySequenceTest_getLength(ArraySequence<int> arraySequence, ArraySequence<char> arraySequence_c) { check(arraySequence.getLength() == 3, "getLength"); }

void arraySequenceTest_getFirst(ArraySequence<int> arraySequence, ArraySequence<char> arraySequence_c) { check((arraySequence.getFirst() == 1) * (arraySequence_c.getFirst() == 'a'), "getFirst"); }

void arraySequenceTest_getLast(ArraySequence<int> arraySequence, ArraySequence<char> arraySequence_c) { check(arraySequence.getLast() == 3 * (arraySequence_c.getLast() == 'c'), "getLast"); }

void arraySequenceTest_get(ArraySequence<int> arraySequence, ArraySequence<char> arraySequence_c) { check(arraySequence.get(1) == 2 * (arraySequence_c.get(1) == 'b'), "get"); }

void arraySequenceTest_prepend(ArraySequence<int> arraySequence, ArraySequence<char> arraySequence_c) { check((arraySequence.getFirst() == 0) * (arraySequence_c.getFirst() == 'x'), "prepend"); }

void arraySequenceTest_append(ArraySequence<int> arraySequence, ArraySequence<char> arraySequence_c) { check((arraySequence.getLast() == 4) * (arraySequence_c.getLast() == 'd'), "append"); }

void arraySequenceTest_insertAt(ArraySequence<int> arraySequence, ArraySequence<char> arraySequence_c) { check((arraySequence.get(2) == 125) * (arraySequence_c.get(2) == 'y'), "insertAt"); }

void arraySequenceTest() {
	int arr[3] = {1,2,3};
	char arr_c[3] = {'a','b','c'};
	ArraySequence<int> arraySequence(arr, 3);
	ArraySequence<char> arraySequence_c(arr_c, 3);
	arraySequenceTest_getLength(arraySequence, arraySequence_c);
	arraySequenceTest_getFirst(arraySequence, arraySequence_c);
	arraySequenceTest_getLast(arraySequence, arraySequence_c);
	arraySequenceTest_get(arraySequence, arraySequence_c);
	arraySequence.append(4);
	arraySequence.prepend(0);
	arraySequence_c.append('d');
	arraySequence_c.prepend('x');
	arraySequenceTest_prepend(arraySequence, arraySequence_c);
	arraySequenceTest_append(arraySequence, arraySequence_c);
	arraySequence.insertAt(125, 2);
	arraySequence_c.insertAt('y', 2);
	arraySequenceTest_insertAt(arraySequence, arraySequence_c);
}

void linkedListSequenceTest_getFirst(LinkedListSequence<int> linkedListSequence, LinkedListSequence<char> linkedListSequence_c) { check((linkedListSequence.getFirst() == 1) * (linkedListSequence_c.getFirst() == 'a'), "getFirst"); }

void linkedListSequenceTest_getLast(LinkedListSequence<int> linkedListSequence, LinkedListSequence<char> linkedListSequence_c) { check((linkedListSequence.getLast() == 3) * (linkedListSequence_c.getLast() == 'c'), "getLast"); }

void linkedListSequenceTest_get(LinkedListSequence<int> linkedListSequence, LinkedListSequence<char> linkedListSequence_c) { check((linkedListSequence.get(1) == 2) * (linkedListSequence_c.get(1) == 'b'), "get"); }

void linkedListSequenceTest_prepend(LinkedListSequence<int> linkedListSequence, LinkedListSequence<char> linkedListSequence_c) { check((linkedListSequence.getFirst() == 0) * (linkedListSequence_c.getFirst() == 'x'), "prepend"); }

void linkedListSequenceTest_append(LinkedListSequence<int> linkedListSequence, LinkedListSequence<char> linkedListSequence_c) { check((linkedListSequence.getLast() == 4) * (linkedListSequence_c.getLast() == 'd'), "append"); }

void linkedListSequenceTest_insertAt(LinkedListSequence<int> linkedListSequence, LinkedListSequence<char> linkedListSequence_c) { check((linkedListSequence.get(2) == 125) * (linkedListSequence_c.get(2) == 'y'), "insertAt"); }

void linkedListSequenceTest_concat(LinkedListSequence<int> linkedListSequence, LinkedListSequence<char> linkedListSequence_c) { check(linkedListSequence.getLast() == 4, "concat"); }

void linkedListSequenceTest_getSubsequence(LinkedListSequence<int> linkedListSequence, LinkedListSequence<char> linkedListSequence_c) { check(linkedListSequence.getSubsequence(1, 3).get(0) == 1 && linkedListSequence.getSubsequence(1, 3).get(1) == 125 && linkedListSequence.getSubsequence(1, 3).get(2) == 2, "getSubsequence"); }

void linkedListSequenceTest() {
	int arr[3] = { 1,2,3 };
	char arr_c[3] = { 'a', 'b', 'c' };
	LinkedListSequence<int> linkedListSequence(arr, 3);
	LinkedListSequence<char> linkedListSequence_c(arr_c, 3);
	linkedListSequenceTest_getFirst(linkedListSequence, linkedListSequence_c);
	linkedListSequenceTest_getLast(linkedListSequence, linkedListSequence_c);
	linkedListSequenceTest_get(linkedListSequence, linkedListSequence_c);
	linkedListSequence.append(4);
	linkedListSequence.prepend(0);
	linkedListSequence_c.append('d');
	linkedListSequence_c.prepend('x');
	linkedListSequenceTest_prepend(linkedListSequence, linkedListSequence_c);
	linkedListSequenceTest_append(linkedListSequence, linkedListSequence_c);
	linkedListSequence.insertAt(125, 2);
	linkedListSequence_c.insertAt('y', 2);
	linkedListSequenceTest_insertAt(linkedListSequence, linkedListSequence_c);
	linkedListSequenceTest_concat(linkedListSequence, linkedListSequence_c);
	linkedListSequenceTest_getSubsequence(linkedListSequence, linkedListSequence_c);
}

bool sortTest_shackerSort(ArraySequence<int> arr, vector<int> vec) {
    Sort<int>::shackerSort(&arr);
    sort(vec.begin(), vec.end());
    for(int i = 0; i < arr.getLength(); i++)
        if(arr[i] != vec[i])
            return false;
    return true;
}

bool sortTest_shellSort(ArraySequence<int> arr, vector<int> vec) {
    Sort<int>::shellSort(&arr);
    sort(vec.begin(), vec.end());
    for(int i = 0; i < arr.getLength(); i++)
        if(arr[i] != vec[i])
            return false;
    return true;
}

bool sortTest_quickSort(ArraySequence<int> arr, vector<int> vec) {
    Sort<int>::quickSort(&arr);
    sort(vec.begin(), vec.end());
    for(int i = 0; i < arr.getLength(); i++)
        if(arr[i] != vec[i])
            return false;
    return true;
}

void sortTest() {
    int arr_5[5];
    for (int & i : arr_5)
        i = 1 + rand() % 5;

    ArraySequence<int> arrSeq_5(arr_5, 5);
    vector<int> vec_5(arr_5, arr_5 + sizeof arr_5 / sizeof arr_5[0]);

    check(sortTest_shackerSort(arrSeq_5, vec_5), "shackerSort");
    check(sortTest_shellSort(arrSeq_5, vec_5), "shellSort");
    check(sortTest_quickSort(arrSeq_5, vec_5), "quickSort");
}
