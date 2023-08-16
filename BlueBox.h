#pragma once
#include "Box.h"

class BlueBox :public Box {
    using Box::Box;

    double smallest_weight_;
    double largest_weight_;

    double getCantoorValue();
public:
    BlueBox(double d);
    void absorbToken(double token_weight) override;
    double outputScore() override;
};