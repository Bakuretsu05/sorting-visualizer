#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <cstdlib>
#include <time.h>
using namespace std;

const int nArr = 50;
vector<int> nums;
int comparisons, swaps;

void setup(){
    // generates {nArr} number of random array
    srand(time(NULL)); // seed the time
    for(int i = 0; i < nArr; i++){
        nums.push_back(rand() % nArr + 1);
    }

    comparisons = 0;
    swaps = 0;
}

void draw(vector<int> arr, int c1 = -1, int c2 = -1){ // c = comparison index
    system("cls");
    cout << "Comparisons: " << comparisons << "  /   swaps: " << swaps << endl;
    cout << endl;
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
            comparisons++;
        }
        swap(arr[i], arr[min]);
        swaps++;
    }
    draw(arr, -1, -1);
}

void bubbleSort(vector<int> arr){
    for(int i = arr.size(); i > 0; i--){
        for(int j = 0; j < i; j++){
            if(arr[j] > arr[j+1]){
                draw(arr, j, j+1);
                swap(arr[j], arr[j+1]);
                swaps++;
            }
            comparisons++;
        }
    }
    draw(arr);
}

int main(){
    setup();

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