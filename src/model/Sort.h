#pragma once

#include "array/ArraySequence.h"
#include "list/LinkedListSequence.h"

template <class T>
class Sort {
private:
    static void quickSort_p(ArraySequence<T> *arr, int low, int high) {
        int i = low;
        int j = high;
        T pivot = arr->get((i + j) / 2);
        int temp;

        while (i <= j) {
            while (arr->get(i) < pivot)
                i++;
            while (arr->get(j) > pivot)
                j--;
            if (i <= j) {
                arr->swap(i,j);
                i++;
                j--;
            }
        }
        if (j > low)
            quickSort_p(arr, low, j);
        if (i < high)
            quickSort_p(arr, i, high);
    }

    static void quickSort_p(LinkedListSequence<T> *arr, int low, int high) {
        int i = low;
        int j = high;
        T pivot = arr->get((i + j) / 2);
        int temp;

        while (i <= j) {
            while (arr->get(i) < pivot)
                i++;
            while (arr->get(j) > pivot)
                j--;
            if (i <= j) {
                arr->swap(i,j);
                i++;
                j--;
            }
        }
        if (j > low)
            quickSort_p(arr, low, j);
        if (i < high)
            quickSort_p(arr, i, high);
    }

public:
    static void shackerSort(ArraySequence<T> *arr) {
        bool sort_or_not = true;

        do {
            sort_or_not = true;
            for (int i = 0; i < arr->getLength() - 1; i++) {
                if (arr->get(i) > arr->get(i + 1)) {
                    arr->swap(i, i + 1);
                    sort_or_not = false;
                }
            }
            for (int i = arr->getLength() - 1; i >= 1; i--) {
                if (arr->get(i) < arr->get(i - 1)) {
                    arr->swap(i - 1, i);
                    sort_or_not = false;
                }
            }
        } while (!sort_or_not);
    }

    static void shackerSort(LinkedListSequence<T> *arr) {
        bool sort_or_not = true;

        do {
            sort_or_not = true;
            for (int i = 0; i < arr->getLength() - 1; i++) {
                if (arr->get(i) > arr->get(i + 1)) {
                    arr->swap(i, i + 1);
                    sort_or_not = false;
                }
            }
            for (int i = arr->getLength() - 1; i >= 1; i--) {
                if (arr->get(i) < arr->get(i - 1)) {
                    arr->swap(i - 1, i);
                    sort_or_not = false;
                }
            }
        } while (!sort_or_not);
    }

    static void shellSort(ArraySequence<T> *arr) {
        int n = arr->getLength();
        int d = n;
        d = d/2;
        while (d>0) {
            for (int i = 0; i < n - d; i++) {
                int j=i;
                while (j >= 0 && arr->get(j) > arr->get(j+d)){
                    arr->swap(j,j+d);
                    j--;
                }
            }
            d=d/2;
        }
    }

    static void shellSort(LinkedListSequence<T> *arr) {
        int n = arr->getLength();
        int d = n;
        d = d/2;
        while (d>0) {
            for (int i = 0; i < n - d; i++) {
                int j=i;
                while (j >= 0 && arr->get(j) > arr->get(j+d)){
                    arr->swap(j,j+d);
                    j--;
                }
            }
            d=d/2;
        }
    }

    static void quickSort(ArraySequence<T> *arr) {
        quickSort_p(arr, 0, arr->getLength()-1);
    }

    static void quickSort(LinkedListSequence<T> *arr) {
        quickSort_p(arr, 0, arr->getLength()-1);
    }

};
