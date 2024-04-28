// myFunctions.h
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <vector>
using namespace std;

#define RESET_COLOR "\033[0m"
#define RED_COLOR "\033[31m"
#define GREEN_COLOR "\033[32m"
#define YELLOW_COLOR "\033[33m"

int getRandomNumber(int min, int max);
vector<int> random_vector(int numElements, int minval, int maxval);
void print_vector (vector<int>& arr);
void printTree(const std::vector<int>& nums);

#endif