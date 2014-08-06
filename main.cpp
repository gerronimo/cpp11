#include <iostream>
#include <thread>
using namespace std;
static const int thread_num = 10;

void call_from_thread()
{
    cout << "hello from thread" << endl;    
}
int main()
{
    thread t[thread_num];
    for(int i=0; i<thread_num; ++i)
    {
        //t[i] = thread(call_from_thread);
        t[i] = thread([]()
        {
            cout << "hello from thread" << endl;
        });
    }
    for(int i=0; i<thread_num; ++i) { t[i].join(); }
    return 0;
}
