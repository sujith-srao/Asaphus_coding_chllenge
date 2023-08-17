#include "BlueBox.h"
#include<limits>

BlueBox::BlueBox(double initial_weight): smallest_weight_(-1),largest_weight_(-1),Box(initial_weight) {

}

void BlueBox::absorbToken(double token_weight) {
    if (smallest_weight_ == -1)
        smallest_weight_ = token_weight;

    if (largest_weight_ == -1)
        largest_weight_ = token_weight;

    if (token_weight < smallest_weight_) {
        smallest_weight_ = token_weight;
    }

    if (token_weight > largest_weight_) {
        largest_weight_ = token_weight;
    }
    weight_ += token_weight;
}

double BlueBox::getCantoorValue() const{
    //Cantoor_val(x,y) = ((x+y)*(x+y+1)/2)+y;
    double out_val = ((smallest_weight_ + largest_weight_) * (smallest_weight_ + largest_weight_ + 1)) / 2 + largest_weight_;
    return out_val;
}

double BlueBox::outputScore() const{    
    return getCantoorValue();
}
