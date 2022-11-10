#include <iostream>
#include <vector>

using namespace std;
//parses a string into a vector of ints
vector<int> parseString(const string& s){
    int counter = 0;
    int prev = 0;
    vector<int> v;
    while (counter < s.size()){
        if(s[counter] == ' '){
            v.push_back((int) s.substr(prev,counter));
        }
    }
    return v;
}

int main() {
    string input1, input2;
    cin >> input1;
    vector<int> v1 = parseString(input1);
    cin >> input2;
    vector<int> v2 = parseString(input2);
    return 0;
}
