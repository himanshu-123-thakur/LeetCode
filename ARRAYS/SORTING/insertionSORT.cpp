//Code - INSERSTION SORT
//Each elemnet in it's correct position - like first 2 then 3 then 4 then 5 sort this way

#include <iostream>
using namespace std;

int main() {
    int arr[7] = {14,9,15,12,6,8,13};
    int n = 7;
            for (int i = 1; i < n; i++) {
                int j = i;
                while (j > 0 && arr[j - 1] > arr[j]) {
                    swap(arr[j - 1], arr[j]);
                    j--;
                }
            }
        

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
