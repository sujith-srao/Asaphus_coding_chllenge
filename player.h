#pragma once
#include<vector>
#include<memory>
#include"Box.h"
#include"BlueBox.h"
#include"GreenBox.h"

class Player {
public:
    Player() {};
    Player(const Player& rhs) : score_(rhs.score_) {};
    ~Player() {};

    void takeTurn(uint32_t input_weight, const std::vector<std::unique_ptr<Box> >& boxes);
    double getScore() const { return score_; }
    //made public for it to be unit tested
    int getSmallestBoxIndex(const std::vector<std::unique_ptr<Box> >& boxes);

private:
    double score_{ 0.0 };
};
