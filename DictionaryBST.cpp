#include "util.h"
#include "DictionaryBST.h"
#include <set>
#include <string>

/* Create a new Dictionary that uses a BST back end */
DictionaryBST::DictionaryBST(){
//  std::set<std::string> treeSet;
}

/* Insert a word into the dictionary. */
bool DictionaryBST::insert(std::string word)
{
  std::set<std::string>::iterator iter = treeSet.find(word);
  
  if ( iter == treeSet.end() ) {
    treeSet.insert(word);
    return true;
  }
  
  return false;
/*
  if (treeSet.find(word))
    return false;
  else {
    treeSet.insert(word);
  }
  return true;*/
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryBST::find(std::string word) const
{
  
  std::set<std::string>::iterator iter = treeSet.find(word);
  
  if ( iter == treeSet.end() ) {
    return false;
  }
  
  return true;


/*
  if (treeSet.find(word)){
    return true;
  }
  return false;*/
}

/* Destructor */
DictionaryBST::~DictionaryBST(){}
