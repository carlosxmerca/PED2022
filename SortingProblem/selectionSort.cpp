#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int> &nums);
void selectionSort2(vector<int> &nums);
void changeMinimunPosition(vector<int> &nums, int currentPosition, int *min);
void printArray(vector<int> nums);

int main()
{
    cout << "Selection sort\n";
    vector<int> nums = {5, 4, 3, 1, 2};
    
    cout << "Arreglo inicial:\n";
    printArray(nums);
    
    cout << "Ordenando valores...\n";
    // selectionSort(nums);
    selectionSort2(nums);
    
    cout << "\nArreglo ordenado:\n";
    printArray(nums);

    return 0;
}

void selectionSort(vector<int> &nums) {
    int min, aux;
    for (int i = 0; i < nums.size(); i++) {
        min = i; // position
        for (int j = i+1; j < nums.size(); j++) {
            if (nums[j] < nums[min])
                min = j; // change position
        }
        
        aux = nums[i];
        nums[i] = nums[min];
        nums[min] = aux;
    }
}

void selectionSort2(vector<int> &nums) {
    int min, aux;
    for (int i = 0; i < nums.size(); i++) {
        min = i; // position
        changeMinimunPosition(nums, i, &min); // this will change min
        
        aux = nums[i];
        nums[i] = nums[min];
        nums[min] = aux;
    }
}

void changeMinimunPosition(vector<int> &nums, int currentPosition, int *min) {
    for (int j = currentPosition+1; j < nums.size(); j++) {
        if (nums[j] < nums[*min])
            *min = j; // change position
    }
}

void printArray(vector<int> nums) {
    cout << "[";
    for(int i = 0; i < nums.size(); i++)
        cout << " " << nums[i] << " ";
    cout << "]\n";
}

// https://visualgo.net/en/sorting?slide=6-5