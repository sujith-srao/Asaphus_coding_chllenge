#pragma once
#include<vector>
#include<memory>
#include"Box.h"
#include"BlueBox.h"
#include"GreenBox.h"

class Player {
public:
    Player();
    Player(const Player& rhs);
    Player(Player&& rhs) noexcept;
    Player& operator=(const Player& rhs);
    Player& operator=(Player&& rhs) noexcept;
    ~Player();

    void takeTurn(uint32_t input_weight, const std::vector<std::unique_ptr<Box> >& boxes);
    double getScore() const; 
    //made public for it to be unit tested
    int getSmallestBoxIndex(const std::vector<std::unique_ptr<Box> >& boxes);

private:
    double score_{ 0.0 };
};
