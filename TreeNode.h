// DO NOT EDIT THIS FILE

#pragma once

#include <iostream>
#include <vector>

template <typename T>
class TreeNode {
 public:
  TreeNode(const T& value) : value_(value) {}
  TreeNode(const T& value, std::vector<TreeNode<T>*> children)
      : value_(value), children_(std::move(children)) {}

  T getValue() const { return value_; }
  std::vector<TreeNode<T>*>& getChildren() { return children_; }

  // empty children == leaf node
  bool isLeaf() const { return children_.empty(); }

 private:
  T value_;
  std::vector<TreeNode<T>*> children_{};
};


template <typename T>
void freeTree(TreeNode<T>* node) {
  if (node == nullptr) {
    return;
  }
  for (TreeNode<T>* c : node->getChildren()) {
    freeTree(c);
  }
  delete node;
}
