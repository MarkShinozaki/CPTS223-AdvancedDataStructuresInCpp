#include "OpenMP.h"
#include "Heap.h"

void runOpenMP() {
    hello_world();
    cal_sum();
    cal_max();
}

void runHeap() {
    printf("\nStart runHeap()\n");
    int data_size = 10000;
    int* data = new int[data_size];

    std::vector<int> dupCheck(data_size, 0);

    for (int i = 0; i < data_size; ++i) {
        data[i] = rand() % data_size;
        //-
        dupCheck[data[i]] = data[i];
    }
    auto *hp = new Heap<int>();
    for (int i = 0; i < data_size; ++i) {
        dupCheck[0]=0;
        //hp->push(data[i]);
        //-
        if( dupCheck[i] > 0 ) {
            hp->push(i);
            dupCheck[i] = 0;
        }
    }

    // Sort these values using stl
    std::vector<int> vect(data, data + data_size);
    std::sort(vect.begin(), vect.end());
    //-
    vect.erase( std::unique( vect.begin(), vect.end() ), vect.end());

    for (int i = 0; i < data_size; ++i) {
        // Compare the pop result with the value sorted by stl
        // If the two required functions are correct, the assertion should pass
        if ( hp->size() == 1) {
            std::cout << "All elements have been deleted from the Heap besides the place holder ( size = " << hp->size() << "  )" << std::endl;
            assert(vect[i] == hp->pop());
            
        }  
        
    }
    printf("\nStart runHeap(): assert pass!\n");
}
int main(int argc, char* argv[])
{
    runOpenMP();
    runHeap();
}