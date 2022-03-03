#include "HW5.h"

  
/*
 * Add your key ideas to this comment.
 * How did you approach the problem?
In this problem, I began by eliminating the easiest base case. If the current node value matches the desired character, we can mass that child as the current root, remove the found character from the string and continue searching for the others. 

Secondly, if we approach a $ sign and the remaining characters == 0 we know we have completed a path and the word exists. In the case that these base cases fail we can return false. 
 * Why does your code work?
My code works because search for a single character at a time and use that node traverse down the tree in hopes of finding the remaining characters to verify that the word exists. 
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
for this problem I used a similar approach, I start by the given word and characters within the dictionary, I continue this process iteratively until, I have checked all characters, if the desired word is found I check to make sure that an $ sign is appended to the end. If so, I know that the word already existed and I can return false. 

If this isn't the case, I begin appending characters and finally appending the $ sign to add the word to the dictionary.
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
  
  if(word.size() > 0){
    dict->getChildren().push_back(new TreeNode<char>(*word.begin()));
    return addWord(dict, word);
  }
  else{
   dict->getChildren().push_back(new TreeNode<char>('$'));
    return true;
  }
  return true;
}