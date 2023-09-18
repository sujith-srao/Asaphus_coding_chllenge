#include "bluebox.h"
#include<stdexcept>
#include<iostream>
using namespace std;

BlueBox::BlueBox(double initial_weight): smallest_weight_(-1),largest_weight_(-1),Box(initial_weight) {

}

BlueBox::BlueBox(const BlueBox& rhs) : smallest_weight_(rhs.smallest_weight_), largest_weight_(rhs.largest_weight_), Box(rhs.weight_) {

}

BlueBox& BlueBox::operator=(const BlueBox& rhs) {
    if (this != &rhs) {
        Box::operator=(rhs);
        smallest_weight_ = rhs.smallest_weight_;
        largest_weight_ = rhs.largest_weight_;
    }
    return *this;
}

BlueBox& BlueBox::operator=(BlueBox&& rhs) noexcept {
    Box::operator=(rhs);
    smallest_weight_ = rhs.smallest_weight_;
    largest_weight_ = rhs.largest_weight_;
    rhs.smallest_weight_ = -1;
    rhs.largest_weight_ = -1;
    return *this;
}

BlueBox::BlueBox(BlueBox&& rhs) noexcept:Box(rhs.weight_) {
    smallest_weight_ = rhs.smallest_weight_;
    largest_weight_ = rhs.largest_weight_;
    rhs.smallest_weight_ = -1;
    rhs.largest_weight_ = -1;
}

void BlueBox::absorbToken(const double token_weight) {
    try {
        if (token_weight < 0)
            throw std::invalid_argument("received negative value for weight");

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
    catch (std::invalid_argument& e) {
        cout << e.what();
    }
    
}

double BlueBox::getCantoorValue() const{
    //Cantoor_val(x,y) = ((x+y)*(x+y+1)/2)+y;
    double out_val = ((smallest_weight_ + largest_weight_) * (smallest_weight_ + largest_weight_ + 1)) / 2 + largest_weight_;
    return out_val;
}

double BlueBox::outputScore() const{    
    return getCantoorValue();
}
