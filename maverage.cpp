#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

vector<double> get_moving_average(const vector<double> & sequence, const int window=4){
    int sequence_length = sequence.size();

    if (window < 1){
        string msg = "Window should be positive but passed " + to_string(window) + ".\n";
        throw invalid_argument(msg);
    }

    if (sequence_length < window){
        string msg = "Unable to compute a moving average of a sequence of length " 
                     + to_string(sequence_length) + " with window " 
                     + to_string(window) + ".\n";

        throw length_error(msg);
    }

    vector<double> result(sequence_length - window + 1);

    // first average
    for(int i=0; i<window; i++){
        result[0] += sequence[i] / window;
    }

    // iterative recalculation of next averages
    for (int i=window; i<sequence_length; i++){
        int curr_average_number = i - window + 1;
        result[curr_average_number] = result[curr_average_number - 1] + 
                                      (sequence[i] - sequence[i - window]) / window;
    }

    return result;
}

void show_vector(const vector<double> & sequence){
    for (int i=0; i<sequence.size(); i++){
        cout << sequence[i] << " ";
    }
    cout << endl;
}
