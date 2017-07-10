// https://leetcode.com/problems/implement-stack-using-queues/#/description
class MyStack {
public:
    /** Initialize your data structure here. */
    struct stackType
    {
        int val;
        stackType *next;
    };
    stackType *root = NULL;
    
    /** Push element x onto stack. */
    void push(int x) {
        if(root == NULL)
        {
            root = new stackType();
            root->val = x;
            root->next = NULL;
        }
        else
        {
            stackType *pik;
            pik = new stackType();
            pik->val = x;
            pik->next = root;
            root = pik;
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        stackType *pik = root;
        root = root->next;
        int ret = pik->val;
        delete(pik);
        return ret;
    }
    
    /** Get the top element. */
    int top() {
        return root->val;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return root == NULL;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
