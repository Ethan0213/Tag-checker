#include <iostream>
#include <fstream>
#include <stack>
using namespace std;

int main(){
ifstream inFile("html file");
char c;
stack<string> myStack;
while(inFile >> c){
    string tag = "";
    if(c == '<'){
        while(inFile >> c){
            if(c == '>') break;
            tag += c;
        }
        if(tag[0] != '/') myStack.push(tag);
        else{
            if(tag.substr(1).compare(myStack.top()) == 0){
            myStack.pop();
            }
            else{
            cout << "HTML file has non matching tags" << endl;
            return 0;
            }
        }
    } 
}
if(myStack.empty()) cout << "HTML file has all matching tags" << endl;
else cout << "HTML file has non matching tags" << endl;
return 0;
}
