#include <algorithm>
#include <iterator>
#include <iostream>

template <typename ForwardIterator>
void selectionSort(ForwardIterator begin, ForwardIterator end)
{
    for (auto i = begin; i != end; ++i)
    {
        std::iter_swap(i, std::min_element(i, end));
    }
}