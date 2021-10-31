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

void selectionSort(vector<int> arr){
    int temp, minNI; // min num's index
    for(int i = 0; i < arr.size(); i++){
        minNI = i;
        for(int j = i + 1; j < arr.size(); j++){
            Sleep(20);
            draw(arr, j, minNI);
            if(arr[j] < arr[minNI]) minNI = j;
        }
        temp = arr[i];
        arr[i] = arr[minNI];
        arr[minNI] = temp;
        draw(arr, -1, -1);
    }
}

int main(){
    vector<int> nums;
    for(int i = 0; i < nArr; i++){
        nums.push_back(rand() % nArr + 1);
    }

    selectionSort(nums);
    
    return 0;
}