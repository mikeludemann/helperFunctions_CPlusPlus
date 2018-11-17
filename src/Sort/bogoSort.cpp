#include <algorithm>
#include <iostream>
#include <iterator>
#include <random>

template <typename RandomAccessIterator, typename Predicate>

void bogoSort(RandomAccessIterator begin, RandomAccessIterator end, Predicate p)
{
    std::random_device rd;
    std::mt19937 generator(rd());
    while (!std::is_sorted(begin, end, p))
    {
        std::shuffle(begin, end, generator);
    }
}

template <typename RandomAccessIterator>

void bogoSort(RandomAccessIterator begin, RandomAccessIterator end)
{
    bogoSort(begin, end, std::less<typename std::iterator_traits<RandomAccessIterator>::value_type>());
}