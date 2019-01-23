//#include "heapprofiler.h"
#include <iostream>
#include <map>

//int main(int argc, char* argv[]) 
//{
//    const int mega = 1024 * 1024;
// 
//    for (int i = 0; i < 10; ++i)
//	{
//		char * data = new char[1024*mega];
//		char * data2 = new char [1024*mega];
//		char * data3 = new char [1024*mega];
//		delete[] data;
//		delete data2;
//    }
//    return 0;
//}
//
#include <stdlib.h>
 
void* create(unsigned int size) {
    return malloc(size);
}
 
void create_destory(unsigned int size) {
    void *p = create(size);
    free(p);
}
 
int main(void) {
    const int loop = 4;
    char* a[loop];
    unsigned int mega = 1024 * 1024;
 
    for (int i = 0; i < loop; i++) {
        const unsigned int create_size = 1024 * mega;
        create(create_size);
 
        const unsigned int malloc_size = 1024 * mega;
        a[i] = (char*)malloc(malloc_size);
 
        const unsigned int create_destory_size = mega;
        create_destory(create_destory_size);
    }
 
    for (int i = 0; i < loop; i++) {
        free(a[i]);
    }
 
    return 0;
}

