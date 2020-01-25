#include <iostream>
#include <algorithm>

/**
 * Provides fixed-size static array with type T.
 * It is better to use this instead of traditional static array.
 * This implementation does much safer and has a lot useful function.
 **/
template <typename T, std::size_t size>
class Array {
    T arr[size];

public:
    // iterator class (forward declaration)
    class iterator;

    // member function
    iterator begin() {return iterator(arr);}
    iterator end() {return iterator(arr + size);}

    T& at(std::size_t idx) {
        if (idx >= size) return arr[size-1];
        else if (idx < 0) return arr[0];
        else return arr[idx];
    }

    void reverse() {
        for (std::size_t i = 0; i < size/2; ++i) {
            std::swap<T>(arr[i], arr[size-1-i]);
        }
    }

    // operator overloading for array class
    T& operator[](std::size_t idx) {
        if (idx >= size) return arr[size-1];
        else if (idx < 0) return arr[0];
        else return arr[idx];
    }

    // iterator class
    class iterator {
        T *curr;
        
    public:
        iterator(): curr(nullptr) {}
        iterator(T *ptr): curr(ptr) {}

        iterator& operator=(T *ptr) {
            this->curr = ptr;
            return *this;
        }

        iterator& operator++() {
            if (curr) ++curr;
            return *this;
        }

        iterator operator++(int) {
            iterator it = *this;
            ++*this;
            return it;
        }

        bool operator!=(const iterator &other) {
            return curr != other.curr;
        }

        T& operator*() {
            return *curr;
        }
    };
};

int main(int argc, char const *argv[])
{
    Array<int, 11> arr;
    for (int i=1; i<=11; ++i) arr.at(i-1) = i;
    arr.reverse();
    return 0;
}
