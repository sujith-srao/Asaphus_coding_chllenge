#include "GreenBox.h"
#include<stdexcept>
#include<iostream>

using namespace std;

double GreenBox::outputScore() const {
    double mean = weight_queue_.get_mean();
    return (mean * mean);
}

void GreenBox::absorbToken(const double token_weight) {
    try {
        if(token_weight < 0)
            throw std::invalid_argument("received negative value for weight");
        weight_ += token_weight;
        weight_queue_.add(token_weight);
    }
    catch (std::invalid_argument& e) {
        cout << e.what();
    }
    
}

GreenBox::GreenBox(double initial_weight) : Box(initial_weight) {
    
}
