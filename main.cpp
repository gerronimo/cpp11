#include <iostream>
#include <thread>
#include <vector>
#include <algorithm> //for_each
using namespace std;
static const int thread_num = 10;

void thFun(int i)
{
      cout << "hello from thread " << i << endl;
}
int main()
{
    vector<thread> workers;
    for(int i=0; i<thread_num; ++i)
    {
        auto th = thread(&thFun, i);
        workers.push_back(move(th));
        
        
    }
    for_each(workers.begin(), workers.end(),[](thread& th)
    {
        th.join();
    });
    return 0;
}
