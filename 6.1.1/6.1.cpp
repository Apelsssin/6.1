#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
void incr (size_t &n, size_t max, bool& work) {
    for (size_t i = 0; i < max; ++i) {
        this_thread::sleep_for(1s);
        n += 1;
    }
    work = false;
}
void decr(size_t &n, bool& work) {
    while (work || n > 0) {
        this_thread::sleep_for(2s);
        n -= 1;
    }
}
int main()
{
    size_t n = 0;
    size_t max = 20;
    bool work = true;
    thread t1(incr, std::ref(n), max, ref(work));
    thread t2(decr, std::ref(n), ref(work));
    t1.join();
    t2.join();
}