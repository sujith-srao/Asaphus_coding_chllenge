#include "GreenBox.h"
#include<stdexcept>
#include<iostream>

using namespace std;

QueueOfThree::QueueOfThree() {

};

QueueOfThree::QueueOfThree(const QueueOfThree& rhs) :last_3_weights_(rhs.last_3_weights_) {

};

QueueOfThree::QueueOfThree(QueueOfThree&& rhs) noexcept{
    last_3_weights_ = rhs.last_3_weights_;
    rhs.last_3_weights_.clear();
}

QueueOfThree& QueueOfThree::operator=(const QueueOfThree& rhs) {
    if (this != &rhs) {
        last_3_weights_ = rhs.last_3_weights_;
    }
    return *this;
}

QueueOfThree& QueueOfThree::operator=(QueueOfThree&& rhs) noexcept{
    last_3_weights_ = rhs.last_3_weights_;
    rhs.last_3_weights_.clear();
    return *this;
}

void QueueOfThree::add(double weight) {
    int size = last_3_weights_.size();

    if (last_3_weights_.size() >= SIZE_OF_QUEUE) {
        last_3_weights_.pop_front();
    }
    last_3_weights_.push_back(weight);
}

double QueueOfThree::get_mean() const {
    assert(last_3_weights_.size() > 0 && "no elements to calculate mean");
    int count = last_3_weights_.size();
    double sum = 0;

    for (auto i : last_3_weights_)
        sum += i;

    return (sum / count);
}

GreenBox::GreenBox(double initial_weight) : Box(initial_weight) {

}

GreenBox::GreenBox(const GreenBox& rhs) :weight_queue_(rhs.weight_queue_), Box(rhs.weight_) {

}

GreenBox::GreenBox(GreenBox&& rhs) noexcept:Box(rhs.weight_) {
    swap(weight_queue_, rhs.weight_queue_);
}

GreenBox& GreenBox::operator=(const GreenBox& rhs) {
    if (this != &rhs) {
        Box::operator=(rhs);
        weight_queue_ = rhs.weight_queue_;
    }
    return *this;
}

GreenBox& GreenBox::operator=(GreenBox&& rhs) noexcept{
    if (this != &rhs) {
        Box::operator=(rhs);
        weight_queue_ = std::move(rhs.weight_queue_);
    }
    return *this;
}

double GreenBox::outputScore() const {
    double mean = weight_queue_.get_mean();
    return (mean * mean);
}

void GreenBox::absorbToken(const double token_weight) {
    try {
        if(token_weight < 0)
            throw std::invalid_argument("received negative value for weight");
        weight_ += token_weight;
        weight_queue_.add(token_weight);
    }
    catch (std::invalid_argument& e) {
        cout << e.what();
    }
}
