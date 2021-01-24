#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "maverage.h"

using namespace std;


int main() {
    int sequence_size = 1e6;
    int iteration = 50;

    srand(unsigned(time(nullptr)));

    vector<int> windows = {4, 8, 16, 32, 64, 128};

    for (auto window: windows){
        cout << "Window: " << window << "\n";
        vector<float> sequence(sequence_size);
        
        double cumulative_time = 0.0;
        for(int i=0;i<iteration; i++){
            generate(sequence.begin(), sequence.end(), rand);
            clock_t tStart = clock();
            vector<float> result = get_moving_average(sequence, window);
            cumulative_time += (double)(clock() - tStart)/CLOCKS_PER_SEC;
        }
        printf("\tAverage time: %.8fs\n", cumulative_time / iteration);
    }
}
