#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

template <typename BidIt, typename Pred>
void pancakeSort(BidIt first, BidIt last, Pred order)
{
    if (std::distance(first, last) < 2)
        return;

    for (; first != last; --last)
    {
        BidIt mid = std::max_element(first, last, order);
        if (mid == last - 1)
        {
            continue;
        }
        if (first != mid)
        {
            std::reverse(first, mid + 1);
        }
        std::reverse(first, last);
    }
}

template <typename BidIt>
void pancakeSort(BidIt first, BidIt last)
{
    pancakeSort(first, last, std::less<typename std::iterator_traits<BidIt>::value_type>());
}