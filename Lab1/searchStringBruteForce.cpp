//String Searching with brute force
#include<bits/stdc++.h>
using namespace std;

bool isEqual(string a, string b){
    if(a.length() != b.length())
        return false;
    
    for(int i=0; i<a.length(); i++){
        if(a[i] != b[i])
            return false;
    }
    return true;
}

vector<int> getStringIndices(string a, string b){
    vector<int> indices;
    int l = a.length();
    bool found = false;
    indices.push_back(-1);
    for(int i = 0; i < a.length(); i++){
        if(b.length() > l){
            break;
        }
        string s = a.substr(i, b.length());
        if(isEqual(s,b)){
            if(!found){
                found = true;
                indices.pop_back();
            }
            indices.push_back(i);
        }
        l--;
    }
    return indices;
}

void showVector(vector<int> s){
    for(int i = 0; i < s.size(); i++){
        cout<<s[i]<<" ";
    }
}

int main(){
    string s1, s2;
    
    cout<<"First String: ";
    cin>>s1;
    
    cout<<"String to be Search: ";
    cin>>s2;
    
    cout<<"Found at indices: ";
    showVector(getStringIndices(s1, s2));
    return 0;
}