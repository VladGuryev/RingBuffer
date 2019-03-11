#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#include <array>

template<typename T, std::size_t N>
class RingBuffer
{
private:
    std::size_t ringBufferCapacity;
    std::array<T, N> adaptedArray;
    std::size_t current_idx = 0;
   // std::size_t current_size = 0;
public:
    RingBuffer(): ringBufferCapacity(N)
    {
        //adaptedArray.fill(T());
    }

    void push_back(T element)
    {
        current_idx %= ringBufferCapacity;
        adaptedArray[current_idx++] = element;
    }

    std::size_t size()
    {
        return adaptedArray.size();
    }
    bool empty()
    {
        return adaptedArray.empty();
    }

    T& operator[](size_t idx)
    {
        return adaptedArray[idx];
    }

    T& operator[](size_t idx) const
    {
        return adaptedArray[idx];
    }

    T& front()
    {
        return adaptedArray.front();
    }
    T& back()
    {
        return adaptedArray.back();
    }

    T* data(){
        return adaptedArray.data();
    }

    const T& front() const
    {
        return adaptedArray.front();
    }
    const T& back() const
    {
        return adaptedArray.back();
    }

    std::size_t capacity(){
        return adaptedArray.max_size();
    }

    typename std::array<T, N>::iterator begin()
    {
        return adaptedArray.begin();
    }
    typename std::array<T, N>::iterator end()
    {
        return adaptedArray.begin() + adaptedArray.size();
    }
    typename std::array<T, N>::const_iterator begin() const
    {
        return adaptedArray.begin();
    }
    typename std::array<T, N>::const_iterator end() const
    {
        return adaptedArray.begin() + adaptedArray.size();
    }
};

#endif // RINGBUFFER_H
