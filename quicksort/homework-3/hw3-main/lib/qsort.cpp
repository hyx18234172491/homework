#ifndef QSORT_CPP
#define QSORT_CPP

#include "qsort.hpp"
#include "iostream"

using namespace std;

template<typename RandomAccessIter, typename Comparator>
void quick_sort(RandomAccessIter first, RandomAccessIter last, Comparator comparator) {
    if (first >= last - 1) {
        return;
    }
    RandomAccessIter pivot = first;
    RandomAccessIter i = first + 1;
    RandomAccessIter j = last - 1;
    while (i <= j) {
        while (i <= j && !comparator(*j, *pivot)) {
            j--;
        }
        while (i <= j && comparator(*i, *pivot)) {
            i++;
        }
        if (i < j) {
            std::iter_swap(i, j);
        }
    }
    std::iter_swap(pivot, j);
    quick_sort(first, j, comparator);
    quick_sort(j + 1, last, comparator);

}

template<typename RandomAccessIter, typename Comparator>
void quick_sort2(RandomAccessIter first, RandomAccessIter last, Comparator comparator) {
    // [first, last)
    if (first >= last - 1) {
        return;
    }
    RandomAccessIter pivot = first;
    RandomAccessIter i = first + 1;
    RandomAccessIter j = last - 1;

    while (i<=j){
        // 先移动j
        while (i <=j && comparator(*j,*pivot)){ //
            j--;
        }
        while (i<=j && !comparator(*i,pivot)){
            i++;
        }
        if(i<j){
            std::iter_swap(i, j);
        }
    }
    std::iter_swap(pivot, j);
    quick_sort2(first,j, comparator);
    quick_sort2(j+1,last, comparator);
}

#endif
