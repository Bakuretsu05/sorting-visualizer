#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <cstdlib>
using namespace std;

const int nArr = 50;

void draw(vector<int> arr, int c1, int c2, int sorted){ // c = comparison index
    system("cls");
    for(int i = 0; i < arr.size(); i++){
        string oChar = " O ";
        if(i == c1 || i == c2)  oChar = " X ";
        if(i < sorted) oChar = " # ";

        for(int j = 0; j < arr[i]; j++){
            cout << oChar;
        }
        cout << endl;
    }
}

void selectionSort(vector<int> arr){
    int temp, min; // min num's index
    for(int i = 0; i < arr.size(); i++){
        min = i;
        for(int j = i + 1; j < arr.size(); j++){
            Sleep(20);
            draw(arr, j, min, i);
            if(arr[j] < arr[min]) min = j;
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    draw(arr, -1, -1, arr.size());
}

void bubbleSort(vector<int> arr){
    int nSorted;
    while(nSorted != arr.size()){
        for(int j = 0; j < arr.size()-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                draw(arr, j, j+1, -1);
            }
        }
        nSorted++;
    }
    draw(arr, -1, -1, -1);
}

int main(){
    vector<int> nums;
    for(int i = 0; i < nArr; i++){
        nums.push_back(rand() % nArr + 1);
    }

    selectionSort(nums);
    
    return 0;
}