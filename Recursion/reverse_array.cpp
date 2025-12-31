//CODE 
#include <iostream>
using namespace std;
class recursion{
    public:
    int a=0;
    void reverse_array(int arr[], int size){
        if(a>=size/2)
        return;
        else{
        swap(arr[a],arr[size-a-1]);
        a++;
        reverse_array(arr,size);
        }

    }

};
int main(){
    int size;
    cout<<"Size = ";
    cin>>size;
    int arr[size];
    cout<<"Enter Array of "<<size<<" = ";
    for(int &i:arr){
        cin>>i;
    }
    recursion r1 ;
    r1.reverse_array(arr,size);
    cout << "Reversed: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";
    return 0;
}