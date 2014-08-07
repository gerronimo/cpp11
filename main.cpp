#include <iostream>
#include <thread>
#include <vector>
#include <future>
#include <algorithm> //for_each
#include <exception>
using namespace std;
static const int thread_num = 10;

class myexception : public exception
{
public:
	myexception(const char* message) : message(message){}
	virtual const char* what()
	{
		return message;
	}
private:
	const char* message;
};
void thFun(int i)
{
      cout << "hello from thread " << i << endl;
}
void function_promising(promise<string> && prm)
{
	try
	{
	throw(myexception("future exception"));
	prm.set_value(string("this is the string I promised"));
	}
	catch(...)
	{
		prm.set_exception(std::current_exception());
	}
}
string fun()
{
	string str("hello from async");
	return str;
}
int main()
{
    promise<string> prm; 
    future<string> future = prm.get_future();
    thread thr(&function_promising, std::move(prm));
    try
    {
	    string promised_string = future.get();
	    cout << promised_string;
    }
    catch(myexception& e)
    {
	    cout << e.what() << endl;
    }
    thr.join();
		    


    auto ftr = async(fun);  

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
	    string str = ftr.get();
	    cout << str << endl;

    return 0;
}
