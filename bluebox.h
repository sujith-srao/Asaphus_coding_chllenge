#pragma once
#include "Box.h"

class BlueBox :public Box {
    using Box::Box;

    double smallest_weight_;
    double largest_weight_;

    double getCantoorValue() const;
public:
    BlueBox(double d);
    BlueBox(const BlueBox& rhs) : smallest_weight_(rhs.smallest_weight_), largest_weight_(rhs.largest_weight_),Box(rhs.weight_) {};
    ~BlueBox(){};
    void absorbToken(const double token_weight) override;
    double outputScore() const override;
};
