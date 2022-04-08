#pragma once

#include <vector>
#include <ostream>
#include <optional>

namespace assignment {

  struct Node final {
    // поля
    int key;
    Node* next;

    // конструктор
    explicit Node(int key, Node* next = nullptr) : key{key}, next{next} {}
  };

  struct LinkedList final {
   protected:
    // поля
    Node* front_{nullptr};
    Node* back_{nullptr};
    int size_{0};

   public:
    // конструктор
    explicit LinkedList(const std::vector<int>& keys) : size_{static_cast<int>(keys.size())} {

      if (keys.empty()) {
        return;
      }

      front_ = new Node(keys.front());

      Node* curr_node = front_;

      for (int index = 1; index < keys.size(); index++) {
        curr_node->next = new Node(keys[index]);
        curr_node = curr_node->next;
      }

      back_ = curr_node;
    }

    // деструктор
    ~LinkedList() {
      for (Node* curr_node = front_; curr_node != nullptr; /* ... */) {
        Node* node_to_remove = curr_node;
        curr_node = curr_node->next;
        delete node_to_remove;
      }

      front_ = nullptr;
    }

    bool IsEmpty() const {
      return front_ == nullptr;
    }

    std::optional<int> front() {
      if (front_ == nullptr) {
        return std::nullopt;
      }
      return front_->key;
    }

    std::optional<int> back() {
      if (back_ == nullptr) {
        return std::nullopt;
      }
      return back_->key;
    }

    // методы переворачивания списка
    void ReverseIterative();

    void ReverseRecursive();

    void reverse_recursive_helper(Node*& curr, Node* prev);

    // вывод связного списка в поток вывода
    friend std::ostream& operator<<(std::ostream& os, const LinkedList& list);
  };

  inline std::ostream& operator<<(std::ostream& os, const LinkedList& list) {
    constexpr char delim = ' ';

    for (Node* curr_node = list.front_; curr_node != nullptr; curr_node = curr_node->next) {
      os << curr_node->key << delim;
    }

    return os;
  }

}  // namespace assignment