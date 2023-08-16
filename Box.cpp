#include "Box.h"
#include<iostream>
#include "GreenBox.h"
#include "BlueBox.h"
using namespace std;

Box::Box(double initial_weight) :weight_(initial_weight) {

}


std::unique_ptr<Box> Box::makeGreenBox(double initial_weight) {
    std::unique_ptr<Box> greenbox = std::make_unique<GreenBox>(initial_weight);
    return greenbox;
}

std::unique_ptr<Box> Box::makeBlueBox(double initial_weight) {
    std::unique_ptr<Box> bluebox = std::make_unique<BlueBox>(initial_weight);
    return bluebox;
}

bool Box::operator<(const Box& rhs) const {
    cout << "lhs weight::" << weight_ << endl;
    cout << "rhs weight::" << rhs.weight_ << endl;
    return weight_ < rhs.weight_;
}

