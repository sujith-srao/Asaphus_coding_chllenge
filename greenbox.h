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

    QueueOfThree(const QueueOfThree& rhs):last_3_weights_(rhs.last_3_weights_){
        
    };
    
    ~QueueOfThree() {

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
    GreenBox(const GreenBox& rhs):weight_queue_(rhs.weight_queue_),Box(rhs.weight_) {
        
    };
    ~GreenBox() {};
    void absorbToken(const double token_weight) override;
    double outputScore() const override;
};
