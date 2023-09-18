#include "Player.h"

Player::Player() {

}

Player::Player(const Player& rhs) : score_(rhs.score_) {

}

Player::Player(Player&& rhs) noexcept{
    score_ = rhs.score_;
    rhs.score_ = 0.0;
}

Player& Player::operator=(const Player& rhs) {
    if (this != &rhs) {
        score_ = rhs.score_;
    }
    return *this;
}

Player& Player::operator=(Player&& rhs) noexcept{
    score_ = rhs.score_;
    rhs.score_ = 0.0;
    return *this;
}

int Player::getSmallestBoxIndex(const std::vector<std::unique_ptr<Box> >& boxes) {
    int index = 0;
    for (int i = 1; i < boxes.size(); i++) {		
        if (*(boxes[i]) < *(boxes[index]))
            index = i;
    }
    return index;
}

void Player::takeTurn(uint32_t input_weight, const std::vector<std::unique_ptr<Box> >& boxes) {
    int index = getSmallestBoxIndex(boxes);
    boxes[index]->absorbToken(input_weight);
    double cur_score = boxes[index]->outputScore();
    score_ += cur_score;
}

double Player::getScore() const{ 
    return score_; 
}