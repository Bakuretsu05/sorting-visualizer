#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <cstdlib>
using namespace std;

const int nArr = 50;

void draw(vector<int> arr, int c1, int c2){ // c = comparison index
    system("cls");
    for(int i = 0; i < arr.size(); i++){
        string oChar = " O ";
        if(i == c1 || i == c2)  oChar = " # ";

        for(int j = 0; j < arr[i]; j++){
            cout << oChar;
        }
        cout << endl;
    }
}

int main(){
    vector<int> nums;
    for(int i = 0; i < nArr; i++){
        nums.push_back(rand() % nArr + 1);
    }
    
    // sorting algorithm
    int temp, minNI; // min num's index
    for(int i = 0; i < nums.size(); i++){
        minNI = i;
        for(int j = i + 1; j < nums.size(); j++){
            Sleep(20);
            draw(nums, j, minNI);
            if(nums[j] < nums[minNI]) minNI = j;
        }
        temp = nums[i];
        nums[i] = nums[minNI];
        nums[minNI] = temp;
        draw(nums, -1, -1);
    }
    
    return 0;
}