/***
 *  File: encode.hpp
 *  Author: Tammy Chang 
 */

#ifndef ENCODE_HPP
#define ENCODE_HPP

#include "a6.hpp"
#include <string>

// IMPLEMENT FUNCTION ENCODE BELOW
// THIS FUNCTION IS USED BY EXTRA CHALLENGE PROGRAM a6e
// ONLY IF YOU GET 100 FOR a6 YOU WILL BE TESTED ON a6e
struct value_count{
  char value;
  std::string count;
};

void dfs ( bnode<symbol>* root, std::string seq, std::vector<value_count>& vc){
  if (root->left == nullptr && root->right == nullptr){
    //os << root->value.value << " " << seq ;
    value_count thing;
    thing.value = root->value.value;
    thing.count = seq;
    vc.push_back(thing);
    return; // print entire value
  }
  std::string temp = seq;
  seq = seq + "0";
  dfs( root->left, seq, vc);

  seq = temp;
  seq = seq + "1";
  dfs( root->right, seq, vc);
}

std::string encode(const std::string& M, bnode<symbol>* root){

std::vector<value_count> vc;
std::string str1;
std::string ans;
dfs (root, str1, vc);

for(int i =0; i < M.size(); i++){ // through string
  for(int a = 0; a < vc.size(); a++){ //through vector
    if( M[i] == vc[a].value) {
      ans =ans + vc[a].count;
    }
    //std::cout << ans <<std::endl;
  }
//  std::cout << ans << std::endl;
}
return ans;
std::cout << ans << std::endl;
//return ans;
}
#endif // ENCODE_HPP
