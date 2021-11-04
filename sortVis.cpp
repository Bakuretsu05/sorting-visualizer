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

void draw(const vector<int> &arr, int c1 = -1, int c2 = -1){ // c = comparison index
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

void selectionSort(vector<int> &arr){
    int temp, min; // min num's index
    for(int i = 0; i < arr.size(); i++){
        min = i;
        for(int j = i + 1; j < arr.size(); j++){
            draw(arr, j, min);
            if(arr[j] < arr[min]) min = j;
            comparisons++;
        }
        draw(arr, min, i);
        swap(arr[i], arr[min]);
        swaps++;
    }
    draw(arr); // final draw
}

void bubbleSort(vector<int> &arr){
    for(int i = arr.size(); i > 0; i--){
        for(int j = 0; j < i-1; j++){
            draw(arr, j, j+1);
            if(arr[j] > arr[j+1]){
                draw(arr, j, j+1);
                swap(arr[j], arr[j+1]);
                swaps++;
            }
            comparisons++;
        }
    }
    draw(arr); // final draw
}

void cocktailSort(vector<int> &arr){
    bool swapped = true;
    int nSorted = 1;

    while(swapped){
        // ascend
        swapped = false;
        for(int i = nSorted-1; i < arr.size() - nSorted; i++){
            draw(arr, i, i+1);
            if(arr[i] > arr[i+1]){
                swap(arr[i], arr[i+1]);
                swapped = true;

                draw(arr, i, i+1);
                swaps++;
            }
            comparisons++;
        }
        if(!swapped) break;

        // descend
        swapped = false;
        for(int i = arr.size()-nSorted; i >= nSorted; i--){
            draw(arr, i, i-1);
            if(arr[i] < arr[i-1]){
                swap(arr[i], arr[i-1]);
                swapped = true;

                draw(arr, i, i+1);
                swaps++;
            }
            comparisons++;
        }
        if(!swapped) break;

        nSorted++;
    }
    draw(arr); // final draw
}

int main(){
    setup();

    int choice;
    cout << "1. Selection Sort" << endl;
    cout << "2. Bubble Sort" << endl;
    cout << "3. Cocktail Sort" << endl;
    cout << ": "; cin >> choice;

    switch(choice){
        case 1:
            selectionSort(nums);
            break;
        case 2:
            bubbleSort(nums);
            break;
        case 3:
            cocktailSort(nums);
            break;
        default:
            cout << "Invalid input..." << endl;
    }
    
    return 0;
}