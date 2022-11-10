#include <iostream>
#include <vector>

using namespace std;
//parses a string into a vector of ints
vector<int> parseString(const string& s){
    int counter = 0;
    int prev = 0;
    vector<int> v;
    cout << s.size();
    while (counter < s.size()){
        cout << s[counter] << endl;
        if(s[counter] == ' '){
            v.push_back(stoi(s.substr(prev,counter)));
            prev = counter + 1;
        }
        counter++;
    }
    return v;
}
void printVector(const vector<int>& v){
    for(int i: v) {
        cout << "here" << endl;
        cout << i << ' ';
    }
}

int main() {
    string input1, input2;
    cin >> input1;
    vector<int> v1 = parseString(input1);
    cout << v1.size() << " END ME" << endl;
    printVector(v1);
    cin >> input2;
    vector<int> v2 = parseString(input2);
    return 0;
}
