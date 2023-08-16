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

using namespace std;




class BlueBox;
class GreenBox;

class Box {
public:
    explicit Box(double i);
    
    static std::unique_ptr<Box> makeGreenBox(double initial_weight);
    static std::unique_ptr<Box> makeBlueBox(double initial_weight);
    
    bool operator<(const Box& rhs) const;
    
    virtual void absorbToken(double token_weight)=0;
    virtual double outputScore() = 0;

protected:
    double weight_;
};


class GreenBox :public Box {
    using Box::Box;
public:
    void absorbToken(double token_weight) override;
    double outputScore() override;
};

class BlueBox :public Box {
    using Box::Box;
public:
    void absorbToken(double token_weight) override;
    double outputScore() override;
};

Box::Box(double initial_weight):weight_(initial_weight) {

}

std::unique_ptr<Box> Box::makeGreenBox(double initial_weight) {
    std::unique_ptr<Box> greenbox = std::make_unique<GreenBox>(initial_weight);
    return greenbox;
}

std::unique_ptr<Box> Box::makeBlueBox(double initial_weight) {
    std::unique_ptr<Box> bluebox = std::make_unique<BlueBox>(initial_weight);
    return bluebox;
}

bool Box::operator<(const Box& rhs) const {
    return weight_ < rhs.weight_;
}

void GreenBox::absorbToken(double token_weight) {

}

void BlueBox::absorbToken(double token_weight) {

}

double GreenBox::outputScore() {
    return 0;
}

double BlueBox::outputScore() {
    return 0;
}

int main()
{
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
