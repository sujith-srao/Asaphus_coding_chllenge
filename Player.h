#pragma once
#include<vector>
#include<memory>
#include"Box.h"
#include"BlueBox.h"
#include"GreenBox.h"

class Player {
public:
    void takeTurn(uint32_t input_weight,
        const std::vector<std::unique_ptr<Box> >& boxes);
    double getScore() const { return score_; }
    //made public for it to be unit tested
    int getSmallestBoxIndex(const std::vector<std::unique_ptr<Box> >& boxes);

private:
    //int getSmallestBoxIndex(const std::vector<std::unique_ptr<Box> >& boxes);
    double score_{ 0.0 };
};
