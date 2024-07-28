/**
 * @file Trie.hpp
 * @brief Trie header file
 */
#pragma once
#include <cstddef>
#include <iostream>
#include <memory>
#include <ostream>
#include <optional>
#include <string>
#include <stack>

using namespace std;

#define DEBUG

#define USE_HASH_MAP

#ifdef USE_HASH_MAP
#include "ByteHashMap.hpp"
template <typename Tp>
using Map = ByteHashMap<Tp>;
#else
#include <unordered_map>
template <typename Key, typename Tp>
using Map = unordered_map<Key, Tp>;
#endif

template <typename Value>
class Trie {
 public:
  Trie() : root_(new Node(0)), num_words_(0), num_nodes_(0) {
  }

  ~Trie() {
    // delete all nodes
    // DFS traversal
    /*
    DFS is supposed to traverse and delete child nodes before its parent node.
    however, all we have to do is to delete popped node one by one,
    just to delete all nodes.
    unnecessary to make efforts like keeping pointer to parent node.
     */
    stack<Node*> q;
    q.emplace(root_);
    while (!q.empty()) {
      auto node = q.top();
      q.pop();
      for (const auto& [c, next] : node->children) {
        if (next) {
          q.emplace(next);
        }
      }
      // cerr << "delete node " << node->index << endl;
      delete node;
    }
  }

  class Node {
   public:
    Node(size_t index) : index(index), value(nullopt), children() {}
    ~Node() {}

    friend ostream& operator<<(ostream& os, const Node& node) {
      if (node.value) os << "*";
      os << node.index << ": ";
      os << node.children;
      return os;
    }

    friend ostream& operator<<(ostream& os, const Node* node) {
      if (node->value) os << "*";
      os << node->index;
      return os;
    }

    //! node index, older node has smaller value
    size_t index;

    //! value if this node is end of a certain word
    optional<Value> value;

    //! child nodes
    Map<Node*> children;
  };

  /**
   * @brief Trie size
   * @return number of words stored in Trie
   */
  size_t size(void) const {
    return num_words_;
  }

  /**
   * @brief number of Trie nodes
   * @return number of Trie nodes (includes internal nodes)
   */
  size_t num_nodes(void) const {
    return num_nodes_;
  }

  /**
   * @brief print all nodes in Trie
   */
  void print(void) const {
    // DFS traversal
    stack<Node*> q;
    q.emplace(root_);
    while (!q.empty()) {
      auto node = q.top();
      cerr << *node << endl;
      q.pop();
      for (const auto& [c, next] : node->children) {
        if (next) {
          q.emplace(next);
        }
      }
    }
  }

  /**
   * @brief insert new pair {key, value}
   * @param [in] p pair of key (string), value
   */
  void insert(pair<string, Value>&& p) {
    auto [word, new_value] = p;
    Node* current = root_;
    for (const auto c : word) {
      byte b = static_cast<byte>(c);
      if (!current->children.count(b)) {
        current->children.insert({b, new Node(++num_nodes_)});
      }
      current = current->children.at(b);
    }
    if (!current->value) {
      ++num_words_;
    }

    current->value = move(new_value);
  }

  /**
   * @brief search Trie for word
   * @param [in] word
   * @return 1 if found, else 0
   */
  size_t count(const string& word) const {
    Node* current = root_;
    for (const auto c : word) {
      byte b = static_cast<byte>(c);
      if (!current->children.count(b)) {
        return 0;
      }
      current = current->children.at(b);
    }
    if (current->value) {
      return 1;
    }
    else {
      return 0;
    }
  }

  // /**
  //  * @brief search Trie for word
  //  * @param [in] word
  //  * @return pointer to key-value pair (almost compatible with unordered_map::find()) if found
  //  */
  // pair<string, Value> find(const string& word) const {
  //   Node* current = root_;
  //   for (auto c : word) {
  //     byte b = static_cast<byte>(c);
  //     if (!current->children.count(b)) {
  //       return nullptr;
  //     }
  //     current = current->children.at(b);
  //   }
  //   if (current->value) {
  //     return {word, *(current->value)};
  //   }
  //   else {
  //     return nullptr;
  //   }
  // }

 private:
  //! root node of Trie
  Node* root_;

  //! number of words stored in Trie
  size_t num_words_;

  //! number of nodes (includes internal nodes)
  size_t num_nodes_;
};
