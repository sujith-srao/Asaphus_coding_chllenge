#pragma once

#include "Box.h"
#include<deque>
#include<cassert>

const int SIZE_OF_QUEUE = 3;

class QueueOfThree {
    std::deque<double> last_3_weights_;
    
public:
    
    QueueOfThree()  {

    };

    void add(double weight) {
        int size = last_3_weights_ .size();

        if (last_3_weights_.size() >= SIZE_OF_QUEUE) {
            last_3_weights_.pop_front();
        }
        last_3_weights_.push_back(weight);
    }
    
    double get_mean() const {
	assert(last_3_weights_.size()>0 && "no elements to calculate mean");
        int count = last_3_weights_.size();
        double sum = 0;
        
        for (auto i : last_3_weights_)
            sum += i;

        return (sum / count);
    }
};

class GreenBox :public Box {
    using Box::Box;
private:
    QueueOfThree weight_queue_;
    
public:
    GreenBox(double initial_weight);
    void absorbToken(double token_weight) override;
    double outputScore() const override;
};
