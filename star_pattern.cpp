#include <iostream>
using namespace std;

class Pattern{

public:
    void print_pat (char c){
        for (int i =0 ; i<4; i++){
            for (int j = 0; j<4; j++){
                cout<<c;
            }
            cout<<endl;
        }
    }
    void print_pat2(char l);
    void numPatt1(char c);
    void star_1(char c);
};

void Pattern::print_pat2(char c){
    for (int i =0 ; i<5 ;i++){
        for (int j=0;j<=i; j++){
            cout <<c;
        }
        cout<<endl;
    }
}

// void Pattern::numPatt1(char c){
//     for(int i = 5;i>=1;i--){
//         for(int j = 1;j<=i;j++){
//             // cout<<j;
//             cout<<j;
//         }
//         cout<<endl;
//     }
// }


void Pattern::star_1(char c){
    int i = 1;
    int l = 9;
    int o = 0;
    for (int m = 0;m<5;m++){
    for(int j = (9-i)/2; j>0 ; j--){
        cout<<" ";
    }
    for (int k = i;k>0;k--){
        cout <<c;
    }
    for(int j = (9-i)/2; j>0 ; j--){
        cout<<" ";
    }
    cout<<endl;
    i = i+2;
}

for (int m = 0;m<5;m++){
    for (int n = 0; n<o ; n++){
        cout<<" ";
    }
    for (int m = 0 ; m<l;m++){
        cout <<c;
    }
    for (int n = 0; n<o ; n++){
        cout<<" ";
    }
    cout<<endl;
    o=o+1;
    l=l-2;
}


}

struct pattern{
    void diff1();
    int j;
    int l =1;
    void struct_pattern(){
        int a=0;
        //Lets go row wise
        for(int i =1;i<=5;i++){
            if (i%2==0)
            a=1;
            else 
            a=0;

            for(int j = 1 ; j<=i ; j++){
                cout <<a;
                a=1-a;
            }
            cout<<endl;
        }
    }
};




void pattern:: diff1 (){
    int l =1;
    for(int i = 1 ; i<=4; i++){
        for(int j = 1; j<=i;j++){
            cout <<j;
        }
        for(int k=0 ; k<(8-(2*i)); k++){
            cout << " ";
        }
        for(int m = i; m>0;m--){
            cout <<m;
        }

        cout <<endl;
    }

}

int main(){
    char c;
    cin >> c;
    Pattern square, pattern2, pattern3, pattern4;
    square.print_pat(c);
    pattern2.print_pat2(c);
    // pattern3.numPatt1(c);
    pattern4.star_1(c);

    pattern pat;
    pat.struct_pattern();

    int m=1;
    
    for (int i = 0; i < 4; i++) {
        int l =0;
        for (int j = 5; j >i; j--) {
            cout << char('A' + l);
            l++;
        }
        cout << endl;
    }


    for(int i = 0 ;i < 5 ; i++){
        int l = 0;
        char c = 'A';
        for(int j = i ; j>=0 ;j--){
            cout <<char(c+i);
        }
        cout<<endl;
    }


    pattern diff;
    diff.diff1();


    for (int i =1 ; i<=4; i++){
        for (int j=1;j<=((7-1)/2);j++){
            cout <<" ";            
        }
        for(int k = 0 ; k<i ; k++){
            cout<<char('A'+k);
        }
        for (int l=1;l<=((7-1)/2);l++){
            cout <<" ";            
        }
        cout<<endl;

    }





    for(int i= 0 ;i<10;i++){
        int j,k,l;
        for(j = i;j<5;j++){
            cout<<'*';
        }
        for (k =0;k<2*i;k++){
            cout<<" ";
        }
        for(l= i;l<5;l++){
            cout<<'*';
        }

// cout<<endl;
//         for(l= i;l<5;l++){
//             cout<<'*';
//         }
//         for (k =0;k<2*i;k++){
//             cout<<" ";
//         }
//         for(j = i;j<5;j++){
//             cout<<'*';
//         }

        cout<<endl;
        
    }
    // for(int i= 0 ;i<10;i++){
    //     int j,k,l,m;
    //     m=1;
    //     cout<<endl;
    //     for(l= i;l<=0;l++){
    //         cout<<'*';
    //     }
    //     for (k =0;k<=(10-2*m);k++){
    //         cout<<" ";
    //         m++;
    //     }
    //     for(j = i;j<=0;j++){
    //         cout<<'*';
    //     }
    //     cout<<endl;
    // }



cout <<"NNNNNNNNNNNNNNNNNNNNEEEEEEEEEEEEEEEEEEWWWWWWWWWWWWWWWWW"<<endl;
cout<<endl;

    






    for (int i = 1 ; i<=5;i++){
        for(int j = 1;j<=i;j++){
            cout<<'*';
        }
        for(int j = 1 ;j<= (10-2*i); j++){
            cout<<" ";
        }
        for(int j = 1;j<=i;j++){
            cout<<'*';
        }
        cout<<endl;
    }
    for(int i = 1;i<=4;i++){
        for(int j = 4; j>=i;j--){
            cout<<'*';
        }
        for(int j = 1;j<=2*i;j++){
            cout<<" ";
        }
        for(int j = 4; j>=i;j--){
            cout<<'*';
        }
        cout <<endl;
    }
    







    return 0;




}