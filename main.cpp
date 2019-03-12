#include <iostream>
#include "ringbufdeq.h"
#include "test_runner.h"
#include "profile.h"
#include "ringbufarr.h"
#include <boost/circular_buffer.hpp>

using namespace std;
using namespace boost;

int main()
{
    const int N = 65536;

    vector<int> v1,  v2;
    v1.resize(N);
    v2.resize(N);

    circular_buffer<int> buffer(N);
    LOG_DURATION("Total time");
    // deque: 26909ms -O,  2815ms -O3;
    // array: 8543ms -O,  2291ms -O3;
    // boost::circle_bufer: 7834ms -O, 1575ms -O3;

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
