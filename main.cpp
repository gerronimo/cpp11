#include <iostream>
#include <thread>
using namespace std;

 class ppm {
        bool flag_alloc;
        void init();
        //info about the PPM file (height and width)
        unsigned int nr_lines;
        unsigned int nr_columns;

    public:
        //arrays for storing the R,G,B values
        unsigned char *r;
        unsigned char *g;
        unsigned char *b;
        //
        unsigned int height;
        unsigned int width;
        unsigned int max_col_val;
        //total number of elements (pixels)
        unsigned int size;

        ppm();
        //create a PPM object and fill it with data stored in fname 
        ppm(const std::string &fname);
        //create an "empty" PPM image with a given width and height;the R,G,B arrays are filled with zeros
        ppm(const unsigned int _width, const unsigned int _height);
        //free the memory used by the R,G,B vectors when the object is destroyed
        ~ppm();
        //read the PPM image from fname
        void read(const std::string &fname);
        //write the PPM image in fname
        void write(const std::string &fname);
    };

static const int thread_num = 10;

void call_from_thread(int tid)
{
    cout << "hello from thread" << tid <<  endl;    
}
int main()
{
    thread t[thread_num];
    for(int i=0; i<thread_num; ++i)
    {
        t[i] = thread(call_from_thread, i);
    }
    for(int i=0; i<thread_num; ++i) { t[i].join(); }
    return 0;
}
