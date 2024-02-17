#include<bits/stdc++.h>
using namespace std;
class MinStack {
public:
    stack<long long> s;
    long long minElem;
    MinStack() {}

    void push(int num) {
        if (s.empty()) {
            s.push(num);
            minElem = num;
        } else {
            if (num >= minElem) {
                s.push(num);
            } else {
                // store the flag in the stack
                s.push(2LL * num - minElem);
                minElem = num;
            }
        }
    }

    void pop() {
        if (s.empty()) {
            return;
        } else {
            if (s.top() >= minElem) {
                s.pop();
            } else {
                minElem = 2 * minElem - s.top();
                s.pop();
            }
        }
    }

    int top() {
        if (s.empty()) {
            return -1;
        } else {
            if (s.top() >= minElem) {
                return s.top();
            } else {
                return minElem;
            }
        }
    }

    int getMin() {
        if (s.size() == 0) {
            return -1;
        }
        return minElem;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */