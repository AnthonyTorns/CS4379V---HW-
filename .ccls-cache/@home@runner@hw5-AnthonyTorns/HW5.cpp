#include "HW5.h"

  
/*
 * Add your key ideas to this comment.
 * How did you approach the problem?
In this problem, I began by eliminating the easisest base case. If the current node value matches the desired character, we can mass that child as the current root, and remove the found character from the string and continue searching for the others. 

Secondly, if we approach a $ sign and the remaining characters == 0 we know we have completed a path and the word exists. In the case that these base cases fail we can return false. 
 * Why does your code work?
My code works beacuse, search for a single character at a time and use thar node traverse down 
 *
 */
bool isValidWord(TreeNode<char>* dict, std::string word) {
 // throw std::logic_error("not implemented");
    for(auto node : dict->getChildren()) {
      
      if(node->getValue() == *word.begin() ) {
        return true && isValidWord(node, word.erase(0,1));
      }

      if(node->getValue() == '$' && word.size() < 1) {
        return true;
      }
    }
  
  return false;
}


/*
 * Add your key ideas to this comment.
 * How did you approach the problem?
 * Why does your code work?
 *
 */
bool addWord(TreeNode<char>* dict, std::string word) {
  //throw std::logic_error("not implemented");
  for (auto child: dict->getChildren()) {
    if(child->getValue() == *word.begin()){
      return addWord(child, word.erase(0,1));
    }
    if(word.size() ==0) {
      if(child->getValue() == '$'){
        return false;
      }
    }
  }
  
  if(word.size() == 0){
    dict->getChildren().push_back(new TreeNode<char>('$'));
    return true;
  }
  else{
    dict->getChildren().push_back(new TreeNode<char>(*word.begin()));
    return addWord(dict, word);
  }
  return false;
}