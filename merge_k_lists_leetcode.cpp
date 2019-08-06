/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
  
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode *temp = new ListNode(0),*head;
    int k = lists.size(), t, n = 0;
    
    head = temp;

    // Calculate total number of nodes in final list
    for(int i=0;i<k;i++) {
      ListNode *list = lists[i];
      while(list != NULL) {
        n += 1;
        list = list->next;
      }
    }
    
    // Insert the initial k values in heap
    for(int i=0;i<k;i++) {
      if(lists[i] != NULL) {
        pq.push(make_pair(lists[i]->val,i));
      }
    }
    
    // Main solution
    for(int i=0;i<n;i++) {
      t = pq.top().second;
      temp->next = lists[t];
      temp = temp->next;
      lists[t] = lists[t]->next;
      
      pq.pop();
      if(lists[t] != NULL)
        pq.push(make_pair(lists[t]->val,t));
    }
    
    return head->next;
  }
};