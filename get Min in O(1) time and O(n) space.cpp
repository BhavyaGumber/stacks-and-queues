class MinStack {
public:
    MinStack() {}

    void push(int x) {
        main_stack.push(x);
        if (min_stack.empty() || x <= min_stack.top()) {
            min_stack.push(x);
        }
    }

    void pop() {
        if (!main_stack.empty()) {
            if (main_stack.top() == min_stack.top()) {
                min_stack.pop();
            }
            main_stack.pop();
        }
    }

    int top() {
        if (!main_stack.empty()) {
            return main_stack.top();
        }
        return -1;
    }

    int getMin() {
        if (!min_stack.empty()) {
            return min_stack.top();
        }
        return -1;
    }

private:
    stack<int> main_stack;
    stack<int> min_stack;
};
