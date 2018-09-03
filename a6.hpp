/***
 *  File: a6.hpp
 *  Author: tammy chang 
 */

#ifndef A6_HPP
#define A6_HPP
#include <iostream>
#include <ostream>
#include "symbol.hpp"
#include <queue>

struct Point {
  int x;
  int y;
};

struct compare_pointers {
  bool operator()(bnode<symbol>* a, bnode<symbol>* b) {
    return ((*b).value < (*a).value);
  }
};

template <typename Iter>
bnode<symbol>* huffman_tree(Iter first, Iter last){ 
  //priority queue holds pointers to bnode objects
  std::priority_queue<bnode<symbol>*, std::vector<bnode<symbol>*>, compare_pointers> bnodeQ;  

  while(first != last){
  bnode<symbol>* node = new bnode<symbol>();
  node->value = *first;               //put symbol into bnode
  bnodeQ.push(node);
  ++first;
  }

  //while(!bnodeQ.empty()){
    //std::cout<< bnodeQ.top()->value.value << std::endl;
  //  bnodeQ.pop();
  //}

  while (bnodeQ.size() > 1 ){
  auto left = bnodeQ.top();
  bnodeQ.pop();
  auto right = bnodeQ.top(); //symbol and count
  bnodeQ.pop();



  bnode<symbol>* parent = new bnode<symbol>();
   parent->value.count = left->value.count + right->value.count;  // frequency
  if(left->value.value > right->value.value){
    parent->value.value = right->value.value; // symbol
  }
  else{
    parent->value.value = left->value.value;
  }
  parent->left= left; //tree
  parent->right= right; //tree
  bnodeQ.push(parent);
  }
  //std::cout<<bnodeQ.top()->left->left->left->value.value<<std::endl;
  //std::cout<<bnodeQ.top()->left->left->right->value.value<<std::endl;
  //std::cout<<bnodeQ.top()->left->right->value.value<<std::endl;
  //std::cout<<bnodeQ.top()->right->value.value<<std::endl;
  return bnodeQ.top();
}

void dfs (std::ostream& os, bnode<symbol>* root, std::string seq){
  if (root->left == nullptr && root->right == nullptr){
    os << root->value.value << " " << seq <<std::endl;
    return; // print entire value
  }
  std::string temp = seq;
  seq = seq + "0";
  dfs(os, root->left, seq);

  seq = temp;
  seq = seq + "1";
  dfs(os, root->right, seq);
}


void print_dictionary(std::ostream& os, bnode<symbol>* root){
std::string seq  = "";
dfs(os, root, seq);
}


void release_tree(bnode<symbol>* root){
if (root == nullptr) return;
release_tree (root->left);
release_tree (root->right);
delete root;
}

#endif // A5_HPP
