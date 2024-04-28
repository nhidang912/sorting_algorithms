#include <iostream>
#include <vector>
#include <ctime>
#include <tuple>
#include <random>
#include <algorithm>
using namespace std;
#include "myFunctions.h"

int getRandomNumber(int min, int max) {
    random_device rd;
    mt19937 eng(rd());
    uniform_int_distribution<> distr(min, max);
    return distr(eng);
}

vector<int> random_vector(int numElements, int minval, int maxval) {
    vector<int> numbers;
    for (int i = 0; i < numElements; ++i) {
        int randomNum = getRandomNumber(minval, maxval);  // Generate a random number
        numbers.push_back(randomNum);
    }
    return numbers;
}

void print_vector (vector<int>& arr) {
    printf("[");
    int i;
    for (i = 0; i < arr.size()-1;i++) {
       printf("%d   ", arr[i]);
    }
    printf("%d]\n", arr[i]);
}

void printTree(const std::vector<int>& nums) {
    int size = nums.size();
    if (size == 0) {
        return;
    }
    int height = log2(size + 1);
    int level = 0;
    int count = 1;
    int i = 0;
    while (i < size) {
        for (int j = 0; j < count; j++) {
            if (i >= size) {
                break;
            }
            printf("%d  ", nums[i++]);
        }
        printf("\n");
        level++;
        count *= 2;
    }
}

