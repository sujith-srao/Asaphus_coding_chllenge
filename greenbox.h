#pragma once

#include "Box.h"
#include<deque>
#include<cassert>

const int SIZE_OF_QUEUE = 3;

class QueueOfThree {
public:
    QueueOfThree();
    QueueOfThree(const QueueOfThree& rhs);
    QueueOfThree(QueueOfThree&& rhs) noexcept;
    QueueOfThree& operator=(const QueueOfThree& rhs);
    QueueOfThree& operator=(QueueOfThree&& rhs) noexcept;
    ~QueueOfThree()=default;
    void add(double weight);
    double get_mean() const;

private:
    std::deque<double> last_3_weights_;
};

class GreenBox :public Box {
public:
    using Box::Box;
    GreenBox(double initial_weight);
    GreenBox(const GreenBox& rhs);
    GreenBox(GreenBox&& rhs) noexcept;
    GreenBox& operator=(const GreenBox& rhs);
    GreenBox& operator=(GreenBox&& rhs) noexcept;
    ~GreenBox()=default;
    void absorbToken(const double token_weight) override;
    double outputScore() const override;

private:
    QueueOfThree weight_queue_;
};
