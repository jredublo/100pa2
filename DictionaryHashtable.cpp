#include "util.h"
#include "DictionaryHashtable.h"

/* Create a new Dictionary that uses a Hashset back end */
DictionaryHashtable::DictionaryHashtable(){
}

/* Insert a word into the dictionary. */
bool DictionaryHashtable::insert(std::string word)
{
  std::unordered_set<std::string>::const_iterator iter = hashie.find(word);
  
  if ( iter == hashie.end() ) {
    hashie.insert(word);
    return true;
  }
  return false;
}


/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryHashtable::find(std::string word) const
{
  std::unordered_set<std::string>::const_iterator iter = hashie.find(word);
  
  if ( iter == hashie.end() ) {
    return false;
  }
  return true;

}

/* Destructor */
DictionaryHashtable::~DictionaryHashtable(){}
