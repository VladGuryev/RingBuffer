#include <iostream>
#include "ringbuffer.h"
#include "test_runner.h"
using namespace std;

int main()
{
    const int N = 5;
    RingBuffer<int, N> buffer;
    for (int i = 0; i < 20 * N; i++) {
        buffer.push_back(i);
    }
    ASSERT_EQUAL(buffer[0], 95);
    ASSERT_EQUAL(buffer[1], 96);
    ASSERT_EQUAL(buffer[2], 97);
    ASSERT_EQUAL(buffer[3], 98);
    ASSERT_EQUAL(buffer[4], 99);

    return 0;
}
