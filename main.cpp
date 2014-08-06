#include <iostream>
#include <thread>
using namespace std;

void call_from_thread()
{
    cout << "hello from thread" << endl;    
}
int main()
{
    thread t(call_from_thread);
    t.join();
    return 0;
}
