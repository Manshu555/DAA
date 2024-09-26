ListNode * vectolistNode(vector <int>& vec){
        ListNode * headptr = new ListNode(0);
        ListNode * dummy = headptr;

        for(auto i : vec){
            dummy->next = new ListNode(i);
            dummy = dummy->next;
        }
        return headptr->next;
    }
