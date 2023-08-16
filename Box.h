#pragma once
#include <memory>




class Box {
public:
    explicit Box(double i);
    static std::unique_ptr<Box> makeGreenBox(double initial_weight);
    static std::unique_ptr<Box> makeBlueBox(double initial_weight);

    bool operator<(const Box& rhs) const;

    virtual void absorbToken(double token_weight) = 0;
    virtual double outputScore() = 0;

protected:
    double weight_;
};
