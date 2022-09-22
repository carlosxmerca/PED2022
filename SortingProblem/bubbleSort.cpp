
#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &nums);
void bubbleSortDetail(vector<int> &nums);
void printArray(vector<int> nums);

int main()
{
    cout << "Bubble sort\n";
    vector<int> nums = {5, 4, 3, 1, 2};
    
    cout << "Arreglo inicial:\n";
    printArray(nums);
    
    cout << "Ordenando valores...\n";
    // bubbleSort(nums);
    bubbleSortDetail(nums);
    
    cout << "\nArreglo ordenado:\n";
    printArray(nums);

    return 0;
}

void bubbleSort(vector<int> &nums) {
    for (int i = 1; i < nums.size(); i++) {
        bool exchange = false;
        
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j - 1] > nums[j]) {
                exchange = true;
                swap(nums[j - 1], nums[j]);
            }
        }
        
        if (exchange == false)
            break;
    }
}

void bubbleSortDetail(vector<int> &nums) {
    for (int i = 1; i < nums.size(); i++) {
        cout << "\n-- Iteracion i: " << i;
        bool exchange = false;
        
        for (int j = 1; j < nums.size(); j++) {
            cout << "\nIteracion j: " << j << "\n";
            if (nums[j - 1] > nums[j]) {
                printArray(nums);
                cout << "\nIntercambiando -> " << nums[j - 1] << " y " << nums[j] << "\n";
                
                exchange = true;
                swap(nums[j - 1], nums[j]);
                printArray(nums);
            }
        }
        
        if (exchange == false) {
            cout << "\nArreglo ordenado, deteniendo bucle...";
            break;
        }
    }
}

void printArray(vector<int> nums) {
    cout << "[";
    for(int i = 0; i < nums.size(); i++)
        cout << " " << nums[i] << " ";
    cout << "]\n";
}
