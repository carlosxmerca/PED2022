/******************************************************************************

Consider the problem of adding two n-bit binary integers, stored in two n-element arrays A
and B. The sum of the two integers should be stored in binary form in an (n + 1)-element
array C. State the problem formally and write pseudocode for adding the two integers.

*******************************************************************************/
#include <iostream>

using namespace std;

void binarySum(int *A, int *B, int *C, int n);
void printArray(int nums[], int n);

int main()
{
    cout << "Binary sum\n";
    
    int A[] =    {1, 1, 1, 0};
    int B[] =    {1, 1, 0, 1}; // 4
    int C[] = {0, 0, 0, 0, 0}; // 5
    int n = sizeof(C) / sizeof(C[0]);
    
    // Expected output:
    // C = [1, 1, 0, 1, 1]
    
    cout << "Sum A and B -> C\n";
    cout << "A:\n";
    printArray(A, n-1);
    cout << "B:\n";
    printArray(B, n-1);
    
    binarySum(A, B, C, n);
    
    cout << "C:\n";
    printArray(C, n);

    return 0;
}

void binarySum(int *A, int *B, int *C, int n) {
    int acc = 0;
    int sum = 0;
    
    for (int i = n-2; i >= 0; i--) {
        sum = A[i] + B[i] + acc;
        
        switch(sum) {
            case 3:
                C[i+1] = 1;
                acc = 1;
            break;
            case 2:
                C[i+1] = 0;
                acc = 1;
            break;
            case 1:
                if (acc == 1)
                    acc = 0; 
                C[i+1] = 1;
            break;
            default:
                C[i+1] = 0;
            break;
        }
    }
    C[0] = acc;
}

void printArray(int nums[], int n) {
    cout << "[";
    for(int i = 0; i < n; i++)
        cout << " " << nums[i] << " ";
    cout << "]\n";
}
