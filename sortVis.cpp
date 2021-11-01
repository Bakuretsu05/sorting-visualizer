#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <cstdlib>
using namespace std;

const int nArr = 50;

void draw(vector<int> arr, int c1 = -1, int c2 = -1, int sorted = -1){ // c = comparison index
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
    Sleep(10);
}

void selectionSort(vector<int> arr){
    int temp, min; // min num's index
    for(int i = 0; i < arr.size(); i++){
        min = i;
        for(int j = i + 1; j < arr.size(); j++){
            draw(arr, j, min, i);
            if(arr[j] < arr[min]) min = j;
        }
        swap(arr[i], arr[min]);
    }
    draw(arr, -1, -1, arr.size());
}

void bubbleSort(vector<int> arr){
    int nSorted;
    while(nSorted != arr.size()){
        for(int j = 0; j < arr.size()-1; j++){
            if(arr[j] > arr[j+1]){
                draw(arr, j, j+1);
                swap(arr[j], arr[j+1]);
            }
        }
        nSorted++;
    }
    draw(arr);
}

int main(){
    // generates {nArr} number of random array
    vector<int> nums;
    for(int i = 0; i < nArr; i++){
        nums.push_back(rand() % nArr + 1);
    }

    int choice;
    cout << "1. Selection Sort" << endl;
    cout << "2. Bubble Sort" << endl;
    cout << ": "; cin >> choice;

    switch(choice){
        case 1:
            selectionSort(nums);
            break;
        case 2:
            bubbleSort(nums);
            break;
        default:
            cout << "Invalid input..." << endl;
    }
    
    return 0;
}