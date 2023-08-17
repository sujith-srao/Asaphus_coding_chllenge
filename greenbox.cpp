#include "GreenBox.h"

double GreenBox::outputScore() const {
    double mean = weight_queue_.get_mean();
    return (mean * mean);
}

void GreenBox::absorbToken(double token_weight) {
    weight_ += token_weight;
    weight_queue_.add(token_weight);
}

GreenBox::GreenBox(double initial_weight) : Box(initial_weight) {
    
}
