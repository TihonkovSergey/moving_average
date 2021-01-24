#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "maverage.h"

using namespace std;


int main() {
    int sequence_size = 1e7;
    int iteration = 20;

    srand(unsigned(time(nullptr)));

    vector<int> windows = {4, 8, 16, 32, 64, 128};

    for (auto window: windows){
        cout << "Window: " << window << "\n";
        vector<double> sequence(sequence_size);
        
        double elems_per_sec = 0.0;
        for(int i=0;i<iteration; i++){
            generate(sequence.begin(), sequence.end(), rand);
            clock_t tStart = clock();
            vector<double> result = get_moving_average(sequence, window);
            elems_per_sec += double(sequence_size) / ((double)(clock() - tStart)/CLOCKS_PER_SEC);
        }
        printf("\tAverage elements per second: %.2f\n", elems_per_sec / iteration);
    }
}
