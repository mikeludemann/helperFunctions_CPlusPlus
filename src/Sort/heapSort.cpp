#include <algorithm>
#include <iterator>
#include <iostream>

template <typename RandomAccessIterator>
void heapSort(RandomAccessIterator begin, RandomAccessIterator end)
{
    std::make_heap(begin, end);
    std::sort_heap(begin, end);
}