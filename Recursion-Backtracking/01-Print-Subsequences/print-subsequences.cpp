#include <bits/stdc++.h>
using namespace std;

void findAllSubsequences(string str, int index, string& current){
  if(index == str.length()){
    cout << current << endl;
    return;
  }
  findAllSubsequences(str, index + 1, current);
  current.push_back(str[index]);
  findAllSubsequences(str, index + 1, current);
  current.pop_back();
}

int main() 
{
  string str = "abc";
  string current = "";
  findAllSubsequences(str, 0, current);
  return 0;
}