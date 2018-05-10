/**
 *  CSE 100 PA3 C++ Autocomplete
 *  Authors: Jor-el Briones, Christine Alvarado, Carlos Mattoso
 */

#ifndef DICTIONARY_TRIE_H
#define DICTIONARY_TRIE_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class TrieNode;


/*  DICTIONARY TRIE DECLARATIONS    */

/**
 *  The class for a dictionary ADT, implemented as a trie
 *  You may implement this class as either a mulit-way trie
 *  or a ternary search trie, but you must use one or the other.
 *
 */
class DictionaryTrie
{
public:

  /* Create a new Dictionary that uses a Trie back end */
  DictionaryTrie();

  /* Insert a word with its frequency into the dictionary.
   * Return true if the word was inserted, and false if it
   * was not (i.e. it was already in the dictionary or it was
   * invalid (empty string) */
  bool insert(std::string word, unsigned int freq);

  /* Return true if word is in the dictionary, and false otherwise */
  bool find(std::string word) const;

  /* Return up to num_completions of the most frequent completions
   * of the prefix, such that the completions are words in the dictionary.
   * These completions should be listed from most frequent to least.
   * If there are fewer than num_completions legal completions, this
   * function returns a vector with as many completions as possible.
   * If no completions exist, then the function returns a vector of size 0.
   * The prefix itself might be included in the returned words if the prefix
   * is a word (and is among the num_completions most frequent completions
   * of the prefix)
   */
  std::vector<std::string>
  predictCompletions(std::string prefix, unsigned int num_completions);

  /* Return the most similar word of equal length to the query, based
   * on their Hamming distance. 
   * In case of ties, return the word with the highest frequency (you may
   * assume there will always be one should a tie happen.)
   * In case there isn't any word of equal length to the query in the
   * trie, return an empty string.
   */
  std::string
  checkSpelling(std::string query);

  TrieNode* findPrefix(string word);

  int findMin(vector<pair<string, int>> v);
  int findHam(string word, string query);

  /* Destructor */
  ~DictionaryTrie();
  
  void deleteAll();

  TrieNode* root;

private:
//  TrieNode* root;
};


// NODE CLASS
class TrieNode
{
public:
  // Members
  //TrieNode* letters[27];  // array of node pointers

  std::vector<TrieNode*> letters; //= std::vector<TrieNode*>(27,nullptr);

  std::string fullWord;   // string to hold the word at the node
  unsigned int freq;      // frequency value, if not 0 then indicates the end of word
  bool isWord;            // bool to indicate is end of a word
  unsigned int lengthOf;

  // Default Constructor: creates blank node with default vals
  TrieNode(){
    fullWord = "";
    lengthOf = 0;
    freq = 0;
    isWord = false;
    // Setting array to null ptr
    for (int i = 0; i < 27; i++) {
      letters.push_back(nullptr);
    }
  }


  // Destructor
//  ~TrieNode();

  // Helper function to check array
  bool hasPointerAt(int place) {
    std::cout << place << std::endl;
    // check place in array
    if (this->letters[place] == nullptr)
      return false;
    else 
      return true;
  }

private:
};


#endif // DICTIONARY_TRIE_H
