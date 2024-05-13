class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    auto compare = [](ListNode* a, ListNode* b) { return a->val > b->val; };
    priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> min_heap(
        compare);

    for (ListNode* list_head : lists) {
      if (list_head) {
        min_heap.push(list_head);
      }
    }
    ListNode* dummy_head = new ListNode();
    ListNode* current_node = dummy_head;

    while (!min_heap.empty()) {
      ListNode* min_node = min_heap.top();
      min_heap.pop();

      if (min_node->next) {
        min_heap.push(min_node->next);
      }
      current_node->next = min_node;
      current_node = current_node->next;
    }
    return dummy_head->next;
  }
};
