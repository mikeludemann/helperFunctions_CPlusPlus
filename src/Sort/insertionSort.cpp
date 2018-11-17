#include <algorithm>
#include <iostream>
#include <iterator>

template <typename RandomAccessIterator, typename Predicate>
void insertionSort(RandomAccessIterator begin, RandomAccessIterator end, Predicate p)
{
    for (auto i = begin; i != end; ++i)
    {
        std::rotate(std::upper_bound(begin, i, *i, p), i, i + 1);
    }
}

template <typename RandomAccessIterator>
void insertionSort(RandomAccessIterator begin, RandomAccessIterator end)
{
    insertionSort(begin, end, std::less<typename std::iterator_traits<RandomAccessIterator>::value_type>());
}