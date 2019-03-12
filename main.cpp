#include <iostream>
#include "ringbufdeq.h"
#include "test_runner.h"
#include "profile.h"
#include "ringbufarr.h"
using namespace std;

int main()
{
    const int N = 65536;

    vector<int> v1,  v2;
    v1.resize(N);
    v2.resize(N);

    RingBufDeq<int> buffer(N);
    LOG_DURATION("Total time"); //deque 26909ms -O,  deque -O3 2815ms, array 8543ms -O, array -O3 2291ms
    for(int i = 0; i < 100; ++i){
        for (int i = 0; i < 20 * N; i++) {
            buffer.push_back(i);
            v1.push_back(buffer[i % N]);
            v2.push_back(buffer.back());
        }
    }

//    for(const auto& item : buffer)
//        cout << item << " ";
//    cout << endl;

    return 0;
}
