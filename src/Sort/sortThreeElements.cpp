#include <iostream>
#include <string>
#include <vector>

template <class T>

void sortThreeElements(T &x, T &y, T &z)
{
    std::vector<T> v;
    v.push_back(x);
    v.push_back(y);
    v.push_back(z);
    bool b = true;
    while (b)
    {
        b = false;
        for (size_t i = 0; i < v.size() - 1; i++)
        {
            if (v[i] > v[i + 1])
            {
                T t = v[i];
                v[i] = v[i + 1];
                v[i + 1] = t;
                b = true;
            }
        }
    }
    x = v[0];
    y = v[1];
    z = v[2];
}