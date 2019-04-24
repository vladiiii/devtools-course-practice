// Copyright 2019 Andronov Maxim

#include "include/priority_queue.h"

PriorityQueue::Link * PriorityQueue::create(int prior, int val) {
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

void PriorityQueue::push(int prior, int val) {
    Link *element = create(prior, val);
    if (first == nullptr) first = last = element;
    else if (first->priority >= prior) {
        element->next = first;
        first = element;
    } else if (last->priority < prior) {
        last->next = element;
        last = element;
    } else {
        Link *tmp = first;
        while ( (tmp->next != nullptr) && (tmp->next->priority < prior))
            tmp = tmp->next;
        element->next = tmp->next;
        tmp->next = element;
    }
}

void PriorityQueue::pop() {
    if (last == nullptr)
        throw "No elements";
    if (first == last) {
        delete last;
        first = last = nullptr;
    } else {
        Link *tmp = first;
        while (tmp->next != last)
            tmp = tmp->next;
        delete last;
        last = tmp;
        last->next = nullptr;
    }
}

int PriorityQueue::top() {
    if (last == nullptr)
        throw "No elements";
    return last->value;
}

bool PriorityQueue::empty() {
    return first == nullptr;
}

int PriorityQueue::size() {
    Link *tmp = first;
    int count = 0;
    while (tmp != nullptr) {
        count++;
        tmp = tmp->next;
    }
    return count;
}
