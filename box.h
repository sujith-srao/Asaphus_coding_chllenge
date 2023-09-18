#pragma once
#include <memory>

class Box {

public:
    explicit Box(double i);
    Box(const Box& rhs);
    Box& operator=(const Box& rhs);
    
    virtual ~Box();

    static std::unique_ptr<Box> makeGreenBox(double initial_weight);
    static std::unique_ptr<Box> makeBlueBox(double initial_weight);
    bool operator<(const Box& rhs) const;

    virtual void absorbToken(const double token_weight) = 0;
    virtual double outputScore() const = 0;

protected:
    double weight_;
};
