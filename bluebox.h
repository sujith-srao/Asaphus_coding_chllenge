#pragma once
#include "Box.h"

class BlueBox :public Box {

public:
    using Box::Box;
    BlueBox(double d);
    BlueBox(const BlueBox& rhs);
    BlueBox& operator=(const BlueBox& rhs);
    BlueBox(BlueBox&& rhs) noexcept;
    ~BlueBox();
    void absorbToken(const double token_weight) override;
    double outputScore() const override;

private:
    double smallest_weight_;
    double largest_weight_;
    double getCantoorValue() const;
};
