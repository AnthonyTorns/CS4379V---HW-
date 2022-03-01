#include "HW5.h"

  
/*
 * Add your key ideas to this comment.
 * How did you approach the problem?
 * Why does your code work?
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
  throw std::logic_error("not implemented");
}
