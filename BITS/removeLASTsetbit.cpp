#include <iostream>
using namespace std;

int main(){
    int n = 81;
    int x = 0;


    //Using BitWISE
    //simple n -1 // after righmost all are set 
    n = (n-1)&n;
    cout<<n<<endl;





    // int temp = n;   // don't destroy original n

    // // Step 1: find rightmost set bit index
    // while(temp != 0){
    //     if((temp & 1) == 1){   // check LSB directly
    //         break;
    //     }
    //     temp = temp >> 1;
    //     x++;
    // }

    // // Step 2: clear that bit
    // int result = n & ~(1 << x);

    // cout << "Rightmost set bit index = " << x << endl;
    // cout << "After clearing = " << result << endl;

    return 0;
}