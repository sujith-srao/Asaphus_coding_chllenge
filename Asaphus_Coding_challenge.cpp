// Asaphus_Coding_challenge.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <cstdint>
#include <limits>
#include <list>
#include <memory>
#include <numeric>
#include <vector>
#include "Box.h"
#include "Player.h"
using namespace std;


std::pair<double, double> play(const std::vector<uint32_t>& input_weights) {
    std::vector<std::unique_ptr<Box> > boxes;
    boxes.emplace_back(Box::makeGreenBox(0.0));
    boxes.emplace_back(Box::makeGreenBox(0.1));
    boxes.emplace_back(Box::makeBlueBox(0.2));
    boxes.emplace_back(Box::makeBlueBox(0.3));

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

int main()
{
    std::vector<uint32_t> inputs{ 1, 1, 2, 3 };
    auto result = play(inputs);
    return 0;

    double initial_weight = 0.0;
    std::unique_ptr<Box> greenBox = Box::makeGreenBox(initial_weight);
    
    greenBox->absorbToken(1);
    cout << "Output Score after pushing 1 " << greenBox->outputScore() << endl;;

    greenBox->absorbToken(5);
    cout<<"Output Score after pushing 5 "<<greenBox->outputScore() << endl;;
    
    initial_weight = 0.2;
    std::unique_ptr<Box> blueBox = Box::makeBlueBox(initial_weight);

    blueBox->absorbToken(2);
    cout << "Output Score after pushing 2 " << blueBox->outputScore() << endl;;

    blueBox->absorbToken(13);
    cout << "Output Score after pushing 13 " << blueBox->outputScore() << endl;;

    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
