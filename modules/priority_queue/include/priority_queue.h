// Copyright 2019 Andronov Maxim

#ifndef MODULES_PRIORITY_QUEUE_INCLUDE_PRIORITY_QUEUE_H_
#define MODULES_PRIORITY_QUEUE_INCLUDE_PRIORITY_QUEUE_H_

class PriorityQueue {
    private:
        struct Link {
            int priority;
            int value;
            Link *next;
        };
        Link *first, *last;
        Link *create(int prior, int val);
    public:
        PriorityQueue();
        ~PriorityQueue();
        void push(int prior, int val);
        void pop();
        int top();
        bool empty();
        int size();
};

#endif  // MODULES_PRIORITY_QUEUE_INCLUDE_PRIORITY_QUEUE_H_