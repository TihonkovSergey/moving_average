#include <iostream>
#include <vector>
#include "maverage.h"

using namespace std;


int main() {
    int size = 10;
    int window = 8;
    vector<double> v(size);

    for (int i=0; i<size; i++){
        v[i] = double(i);
    }

    show_vector(v);
    vector<double> result =  get_moving_average(v, window);
    show_vector(result);
}
