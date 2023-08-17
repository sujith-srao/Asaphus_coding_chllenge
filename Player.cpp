#include "Player.h"
#include<algorithm>
#include<memory>
#include<utility>

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
