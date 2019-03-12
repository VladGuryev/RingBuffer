#include <iostream>
#include "ringbuffer.h"
#include "test_runner.h"
using namespace std;

int main()
{
    const int N = 5;
    RingBuffer<int> buffer(N);
    for (int i = 0; i < 20 * N; i++) {
        buffer.push_back(i);
    }

    for(const auto& item : buffer)
        cout << item << " ";
    cout << endl;

    return 0;
}
