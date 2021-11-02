#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <cstdlib>
using namespace std;

const int nArr = 50;

void draw(vector<int> arr, int c1 = -1, int c2 = -1){ // c = comparison index
    system("cls");
    for(int i = 0; i < arr.size(); i++){
        string oChar = "___";
        if(i == c1 || i == c2)  oChar = "XXX";

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
            draw(arr, j, min);
            if(arr[j] < arr[min]) min = j;
        }
        swap(arr[i], arr[min]);
    }
    draw(arr, -1, -1);
}

void bubbleSort(vector<int> arr){
    for(int i = arr.size(); i > 0; i--){
        for(int j = 0; j < i; j++){
            if(arr[j] > arr[j+1]){
                draw(arr, j, j+1);
                swap(arr[j], arr[j+1]);
            }
        }
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