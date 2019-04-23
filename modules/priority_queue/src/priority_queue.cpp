// Copyright 2019 Andronov Maxim

#include "include/priority_queue.h"

Link * PriorityQueue::create(int prior, int val) {
    Link *tmp = new Link;

    tmp->priority = prior;
    tmp->value = val;
    tmp->next = nullptr;

    return tmp;
}

PriorityQueue::PriorityQueue() {
    first = last = nullptr;
}

PriorityQueue::~PriorityQueue() {
    Link *tmp;
    while (first != nullptr) {
        tmp = first;
        first = first->next;
        delete tmp;
    }
}
