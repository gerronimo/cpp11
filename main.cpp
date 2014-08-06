#include <iostream>
#include <thread>
#include <vector>
#include <algorithm> //for_each
using namespace std;
static const int thread_num = 10;

int main()
{
    vector<thread> workers;
    for(int i=0; i<thread_num; ++i)
    {
        workers.push_back(thread([]()
        {
            cout << "hello from thread" << endl;
        }));
        
    }
    //for(int i=0; i<thread_num; ++i) { workers[i].join(); }
    for_each(workers.begin(), workers.end(),[](thread& th)
    {
        th.join();
    });
    return 0;
}
