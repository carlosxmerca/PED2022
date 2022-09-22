#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int> &nums);
void insertionSortDetail(vector<int> &nums);
void printArray(vector<int> nums);

int main()
{
    cout << "Insertion sort\n";
    vector<int> nums = {5, 4, 3, 1, 2};
    
    cout << "Arreglo inicial:\n";
    printArray(nums);
    
    cout << "Ordenando valores...\n";
    // insertionSort(nums);
    insertionSortDetail(nums);
    
    cout << "\nArreglo ordenado:\n";
    printArray(nums);
    
    return 0;
}

void insertionSort(vector<int> &nums) {
    for(int i = 1; i < nums.size(); i++) {
        int position = i;
        int tmp = nums[i];
        
        // tmp -> valor actual
        // nums[position - 1] -> valor a la izq del valor actual
        while(position > 0 && tmp < nums[position - 1]) {
            nums[position] = nums[position - 1];
            position--;
        }
        
        nums[position] = tmp;
    }
}


void insertionSortDetail(vector<int> &nums) {
    for(int i = 1; i < nums.size(); i++) {
        int position = i;
        int tmp = nums[i];
        
        cout << "\nIteracion i: " << position;
        cout << "\nValor a comparar: " << tmp;
        cout << "\n";
        printArray(nums);
        
        while(position > 0 && tmp < nums[position - 1]) {
            nums[position] = nums[position - 1];
            position--;
        }
        
        nums[position] = tmp;
        printArray(nums);
    }
}

void printArray(vector<int> nums) {
    cout << "[";
    for(int i = 0; i < nums.size(); i++)
        cout << " " << nums[i] << " ";
    cout << "]\n";
}

// https://visualgo.net/en/sorting?slide=6-5