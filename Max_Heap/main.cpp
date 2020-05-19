#include <iostream>
#include "Heap.h"
using namespace std;

int main() {
    Heap h;
    h.insert(30);
    h.insert(20);
    h.insert(15);
    h.insert(5);
    h.insert(10);
    h.insert(12);
    h.insert(6);
    h.insert(40);
    h.erase();
    h.print();


    return 0;
}
