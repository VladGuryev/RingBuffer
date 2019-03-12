#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#include <deque>

template<typename T>
class RingBuffer
{
private:
    std::size_t buffer_capacity = 0;
    std::deque<T> adapted_deque;
    std::size_t current_idx = 0;
    std::size_t current_size = 0;
public:
    RingBuffer(std::size_t capacity): buffer_capacity(capacity)
    {
        adapted_deque.resize(buffer_capacity);
    }

    void push_back(T element)
    {
        static std::size_t counter = 0;
        current_idx %= buffer_capacity;

        if (counter != buffer_capacity) {
            adapted_deque[current_idx++] = element;
            counter++;
            current_size++;
        } else {
            adapted_deque[current_idx++] = element;
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

    T& operator[](std::size_t idx)
    {
        return adapted_deque[idx];
    }

    T& operator[](std::size_t idx) const
    {
        return adapted_deque[idx];
    }

    T& front()
    {
        return adapted_deque.front();
    }
    T& back()
    {
        return adapted_deque.back();
    }

    T* data(){
        return adapted_deque.data();
    }

    const T& front() const
    {
        return adapted_deque.front();
    }
    const T& back() const
    {
        return adapted_deque.back();
    }

    std::size_t capacity(){
        return buffer_capacity;
    }

    typename std::deque<T>::iterator begin()
    {
        return adapted_deque.begin();
    }
    typename std::deque<T>::iterator end()
    {
        return adapted_deque.begin() + current_size;
    }
    typename std::deque<T>::const_iterator begin() const
    {
        return adapted_deque.begin();
    }
    typename std::deque<T>::const_iterator end() const
    {
        return adapted_deque.begin() + current_size;
    }
};

#endif // RINGBUFFER_H
