#include "assignment/linked_list.hpp"

namespace assignment {

  // Используя три указателя на предыдущий, текущий и следующий узлы.
  void LinkedList::ReverseIterative() {
    Node* previous = nullptr;
    Node* curr = front_;
    back_ = front_;

    while (curr != nullptr) {
      Node* next = curr->next;
      (*curr).next = previous;

      previous = curr;
      curr = next;
    }
    front_ = previous;
  }

  void LinkedList::ReverseRecursive() {
    reverse_recursive_helper(front_, nullptr);
  }

  // Вспомогательный метод для реализации рекурсивного переворачивания списка.
  void LinkedList::reverse_recursive_helper(Node*& curr, Node* prev) {
    if (curr == nullptr) {
      back_ = front_;
      front_ = prev;
      return;
    }
    Node* cur = curr->next;
    curr->next = prev;
    reverse_recursive_helper(cur, curr);
  }

}  // namespace assignment