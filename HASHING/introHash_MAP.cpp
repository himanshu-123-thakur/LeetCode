//CODE 
//map<int,int> name_name ;   (key/Number , value/frequency)
//unordered_map <> name
//Array hashing is only safe when the value range is known and bounded. Otherwise, use map or unordered_map.
//MAP STORES KEY/NUMBER IN INCREASING ORDER

#include <iostream>
#include <map>
using namespace std;


int main(){
    int arr[10]={2,23,2,2,3,3,4,2,5,53};
    int hash[53]={0};
    string s;
    cin>>s;
    map <int, int> hash_map{};
    for(int i=0;i<s.size();i++){
        hash_map[s[i]]++;
    }
    cout<<"From the stringgg "<<s<<" want to check how many times the folowing things gets repeated : ";
    char c;
    cin>>c;
    cout <<c<<" gets repeated "<<hash_map[c]<<endl;

    for(int i =0;i<10;i++){
        hash[arr[i]]++;
    }

    cout <<"The number 2 is repeated "<<hash[1]<<" times "<<endl;
    cout <<"The number 53 is repeated "<<hash[52]<<endl;

    for(auto it:hash_map){
        cout<<it.first<<" --> "<<it.second<<endl;
    }
    return 0;
}