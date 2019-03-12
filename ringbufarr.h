#ifndef RINGBUFFER2_H
#define RINGBUFFER2_H
#include <array>

template<typename T, std::size_t N>
class RingBufArr
{
private:
    std::size_t buffer_capacity;
    std::array<T, N> adapted_array;
    std::size_t current_idx = 0;
    std::size_t current_size = 0;
    T* data;
public:
    RingBufArr(): buffer_capacity(N)
    {
    }

    void push_back(T element)
    {
        static std::size_t counter = 0;
        current_idx %= buffer_capacity;

        if (counter != buffer_capacity) {
            adapted_array[current_idx++] = element;
            counter++;
            current_size++;
        } else {
            adapted_array[current_idx++] = element;
        }
    }

    std::size_t size()
    {
        return current_size;
    }
    bool empty()
    {
        return current_size == 0;
    }
    bool full(){
        return current_size == buffer_capacity ? true : false;
    }

    T& operator[](size_t idx)
    {
        return adapted_array[idx];
    }

    T& operator[](size_t idx) const
    {
        return adapted_array[idx];
    }

    T& front()
    {
        return adapted_array.front();
    }
    T& back()
    {
        return adapted_array.back();
    }

    const T& front() const
    {
        return adapted_array.front();
    }
    const T& back() const
    {
        return adapted_array.back();
    }

    std::size_t capacity(){
        return this->buffer_capacity;
    }

    typename std::array<T, N>::iterator begin()
    {
        return adapted_array.begin();
    }
    typename std::array<T, N>::iterator end()
    {
        return adapted_array.begin() + current_size;
    }
    typename std::array<T, N>::const_iterator begin() const
    {
        return adapted_array.begin();
    }
    typename std::array<T, N>::const_iterator end() const
    {
        return adapted_array.begin() + current_size;
    }
};

#endif // RINGBUFFER2_H
