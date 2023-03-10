#include <iostream>
#include <unordered_map>

using namespace std;
// Example 1:
// Input: list = {3, 4, 5, 6, 7} , a = 2, b = 4
// Output: 3 6 5 4 7

// Example 2:
// Input: list = {8, 9, 10}, a = 1, b = 3
// Output: 10 9 8
struct ListNode
{
  int val;
  ListNode *left;
  ListNode *right;
  ListNode(int x = 0, ListNode *l = nullptr, ListNode *r = nullptr) : val(x), left(l), right(r) {}
};
ListNode *init(int *arr, int size, unordered_map<ListNode *, int> &nodeValue)
{
  if (size == 0)
  {
    return nullptr;
  }

  ListNode *head = new ListNode(arr[0]);
  nodeValue[head] = arr[0];
  ListNode *prev = head;
  for (int i = 1; i < size; i++)
  {
    ListNode *node = new ListNode(arr[i], prev, nullptr);
    nodeValue[node] = arr[i];
    prev->right = node;
    prev = node;
  }

  return head;
}

ListNode *reverse(ListNode *head, int a, int b)
{
  if (head == nullptr || a == b)
  {
    return head;
  }

  // B1: Traverse the list until we reach the node at position a. Let's call this node start.
  ListNode *start = head;
  // B2: Keep a reference to the node that precedes start. Let's call this node prev.
  ListNode *prev = nullptr;
  // B3: Traverse the list until we reach the node at position a. 
  for (int i = 1; i < a && start != nullptr; i++)
  {
    prev = start;
    start = start->right;
  }

  if (start == nullptr)
  {
    return head;
  }

  // Reverse the links between start and end
  ListNode *end = start;
  ListNode *next = nullptr;
  for (int i = a; i <= b && end != nullptr; i++)
  {
    next = end->right;
    end->right = end->left;
    end->left = next;
    end = next;
  }

  // Update the links between prev and start, and between end and next
  if (prev != nullptr)
  {
    prev->right = end;
  }
  if (end != nullptr)
  {
    end->left = prev;
  }
  if (a == 1)
  {
    head = end;
  }
  start->right = next;
  if (next != nullptr)
  {
    next->left = start;
  }

  return head;
}

void freeMem(ListNode *head)
{
  ListNode *curr = head;
  while (curr)
  {
    ListNode *temp = curr;
    curr = curr->right;
    delete temp;
  }
}

void printList(ListNode *head, unordered_map<ListNode *, int> &nodeValue)
{
  if (head == nullptr)
  {
    throw "List is empty!";
  }

  ListNode *current = head;
  while (current != nullptr)
  {
    cout << nodeValue[current] << " <-> ";
    current = current->right;
  }
  cout << "NULL" << endl;
}

int main()
{
  int size;
  cin >> size;
  int *list = new int[size];
  for (int i = 0; i < size; i++)
  {
    cin >> list[i];
  }
  // input
  // 5
  // 3 4 5 6 7
  // 2 4
  int a, b;
  cin >> a >> b;
  unordered_map<ListNode *, int> nodeValue;
  ListNode *head = init(list, size, nodeValue);
  ListNode *reversed = reverse(head, a, b);
  try
  {
    printList(reversed, nodeValue);
  }
  catch (char const *err)
  {
    cout << err << '\n';
  }
  // output 3 6 5 4 7
  freeMem(head);
  delete[] list;
  return 0;
}
