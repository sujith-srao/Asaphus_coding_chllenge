/**
 * @file asaphus_coding_challenge.cpp
 * @version 1.1
 * @copyright Copyright (c) 2022 Asaphus Vision GmbH
 *
 * The goal is to implement the mechanics of a simple game and write test cases for them.
 * The rules of the game are:
 * - There are two types of boxes, green and blue. 
 * - Both can absorb tokens of a given weight, which they add to their own total weight. 
 * - Both are initialized with a given initial weight.
 * - After a box absorbs a token weight, it outputs a score. 
 * - Green and blue boxes calculate the score in different ways:
 * - A green box calculates the score as the square of the mean of the 3 weights that it most recently absorbed (square of mean of all absorbed weights if there are fewer than 3).
 * - A blue box calculates the score as Cantor's pairing function of the smallest and largest weight that it has absorbed so far, i.e. pairing(smallest, largest), where pairing(0, 1) = 2
 * - The game is played with two green boxes with initial weights 0.0 and 0.1, and two blue boxes with initial weights 0.2 and 0.3.
 * - There is a list of input token weights. Each gets used in one turn.
 * - There are two players, A and B. Both start with a score of 0. 
 * - The players take turns alternatingly. Player A starts.
 * - In each turn, the current player selects one of the boxes with the currently smallest weight, and lets it absorb the next input token weight. Each input weight gets only used once.
 * - The result of the absorption gets added to the current player's score.
 * - When all input token weights have been used up, the game ends, and the player with highest score wins.
 *
 * Task:
 * - Create a git repo for the implementation. Use the git repository to have a commit history.
 * - Implement all missing parts, marked with "TODO", including the test cases.
 * - Split the work in reasonable commits (not just one commit).
 * - Make sure the test cases succeed.
 * - Produce clean, readable code.
 *
 * Notes:
 * - Building and running the executable: g++ --std=c++14 asaphus_coding_challenge.cpp -o challenge && ./challenge
 * - Feel free to add a build system like CMake, meson, etc.
 * - Feel free to add more test cases, if you would like to test more.
 * - This file includes the header-only test framework Catch v2.13.9.
 * - A main function is not required, as it is provided by the test framework.
 */

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <limits>
#include <list>
#include <memory>
#include <numeric>
#include <vector>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Player.h"
#include "Box.h"

bool AreDoubleSame(double dFirstVal, double dSecondVal);

std::pair<double, double> play(const std::vector<uint32_t>& input_weights) {
	std::vector<std::unique_ptr<Box> > boxes;
	boxes.emplace_back(Box::makeGreenBox(0.0));
	boxes.emplace_back(Box::makeGreenBox(0.1));
	boxes.emplace_back(Box::makeBlueBox(0.2));
	boxes.emplace_back(Box::makeBlueBox(0.3));

  // TODO
	Player player_A;
	Player player_B;

	for (int i = 0; i < input_weights.size(); i++) {

		if (i % 2 == 0) {
			player_A.takeTurn(input_weights[i], boxes);
		}
		else {
			player_B.takeTurn(input_weights[i], boxes);
		}
	}

	std::cout << "Scores: player A " << player_A.getScore() << ", player B "
			<< player_B.getScore() << std::endl;
	return std::make_pair(player_A.getScore(), player_B.getScore());
}

TEST_CASE("Final scores for first 4 Fibonacci numbers", "[fibonacci4]") {
	//Arrange
	std::vector<uint32_t> inputs{1, 1, 2, 3};

	//Act
	auto result = play(inputs);
	
	//Assert
	REQUIRE(result.first == 13.0);
	REQUIRE(result.second == 25.0);
}

TEST_CASE("Final scores for first 8 Fibonacci numbers", "[fibonacci8]") {
	//Arrange
	std::vector<uint32_t> inputs{1, 1, 2, 3, 5, 8, 13, 21};

	//Act
	auto result = play(inputs);
	
	//Assert
	REQUIRE(result.first == 155.0);
	REQUIRE(result.second == 366.25);
}

TEST_CASE("Final scores for first 13 Fibonacci numbers", "[fibonacci13]") {
	//Arrange
	std::vector<uint32_t> inputs{1, 1, 2, 3, 5, 8, 13, 21,34,55,89,144};

	//Act
	auto result = play(inputs);

	//Assert
	REQUIRE(AreDoubleSame(result.first,4607.77));
	REQUIRE(AreDoubleSame(result.second,11843.36));
}

bool AreDoubleSame(double dFirstVal, double dSecondVal)
{
	return std::fabs(dFirstVal - dSecondVal) < 0.01;
}

TEST_CASE("Test absorption of green box", "[green]") {
  	
	//Arrange
	double initial_weight = 0.0;
	std::unique_ptr<Box> greenBox = Box::makeGreenBox(initial_weight);
	
	//Act
	greenBox->absorbToken(1);
	
	//Assert
	REQUIRE(1==greenBox->outputScore());
	
	//Act
	greenBox->absorbToken(5);

	//Assert
	REQUIRE(9==greenBox->outputScore());

}

TEST_CASE("Test absorption of blue box", "[blue]") {
	
	//Arrange
	double initial_weight = 0.1;
	std::unique_ptr<Box> blueBox = Box::makeBlueBox(initial_weight);

	//Act
	blueBox->absorbToken(2);

	//Assert
	REQUIRE(12==blueBox->outputScore());

	//Act
	blueBox->absorbToken(13);
	
	//Assert
	REQUIRE(133==blueBox->outputScore());
}

TEST_CASE("Test getSmallestBoxIndex", "[Player]"){
	
	//Arrange
	std::vector<std::unique_ptr<Box> > boxes;
	boxes.emplace_back(Box::makeGreenBox(10));
	boxes.emplace_back(Box::makeGreenBox(5));
    boxes.emplace_back(Box::makeBlueBox(2));
    boxes.emplace_back(Box::makeBlueBox(4));
	Player player;

	//Act and Assert
	REQUIRE(2==player.getSmallestBoxIndex(boxes));
}

TEST_CASE("Test Mean for Queue of 3", "[Queue_Of_3]") {

	//Arrange
	QueueOfThree queue_of_three;
	queue_of_three.add(10);
	queue_of_three.add(12);
	queue_of_three.add(11);

	Player player;

	//Act and Assert
	REQUIRE(11 == queue_of_three.get_mean());
}