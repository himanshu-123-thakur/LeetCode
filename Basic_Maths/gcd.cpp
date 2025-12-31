#include <iostream>
#include <cstdlib>
using namespace std;

int gcd_bruteforce(int a, int b) {
    a = abs(a);
    b = abs(b);

    if (a == 0) return b;
    if (b == 0) return a;

    int m = min(a, b);
    for (int i = m; i >= 2; --i) {
        if (a % i == 0 && b % i == 0) return i;
    }
    return 1;
}

int euclidean_sub(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;

    if (a > b)
        return euclidean_sub(a - b, b);
    else
        return euclidean_sub(a, b - a);
}

int even_better(int a, int b){       // Complexity is O(log (min of a,b))
    while(a>0 && b>0){
        if(a>b){
            a=a%b;
        }
        else
        b=b%a;
    }
    if(a==0)
    return b;
    else
    return a;
}


int main() {
    int a = 13, b = 29;
    cout << "Brute-force GCD = " << gcd_bruteforce(a, b) << "\n";
    cout << "Euclid GCD = " << euclidean_sub(a, b) << "\n";
    cout << "Better GCD = "<< even_better(a,b)<<endl;
}
