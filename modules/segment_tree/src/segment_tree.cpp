// Copyright 2019 Savkin Yuriy

#include "include/segment_tree.h"

segment_tree::node::node(int _v, node* _l, node* _r): left_n(_l),
    right_n(_r), value(_v), push_value(_v) {
    is_changed = false;
}

segment_tree::segment_tree(const int lg, const int rg, const
        std::function<int(int, int, int)>& fu, const int be):
            base_elem(be), left_barr(lg), right_barr(rg), operation(fu) {
    if (left_barr > right_barr)
        throw -2;
    root = nullptr;
}

segment_tree::segment_tree(const segment_tree& st): base_elem(st.base_elem),
    left_barr(st.left_barr), right_barr(st.right_barr),
        operation(st.operation) {
    std::stack<node*> s;
    root = nullptr;
    if (is_correct_node(st.root)) {
        s.push(st.root);
        root = new node(st.base_elem);
        root->value = st.root->value;
        root->push_value = st.root->push_value;
        s.push(root);
    }
    while (s.size()) {
        node* p = s.top();
        s.pop();
        node* q = s.top();
        s.pop();
        if (is_correct_node(q->left_n)) {
            s.push(q->left_n);
            p->left_n = new node(st.base_elem);
            p->left_n->value = q->left_n->value;
            p->left_n->push_value = q->left_n->push_value;
            s.push(p->left_n);
        }
        if (is_correct_node(q->right_n)) {
            s.push(q->right_n);
            p->right_n = new node(st.base_elem);
            p->right_n->value = q->right_n->value;
            p->right_n->push_value = q->right_n->push_value;
            s.push(p->right_n);
        }
    }
}

segment_tree::~segment_tree() {
    std::stack<node*> s;
    s.push(root);
    while (s.size()) {
        node* p = s.top();
        s.pop();
        if (p) {
            s.push(p->left_n);
            s.push(p->right_n);
            delete p;
        }
    }
}

segment_tree& segment_tree::operator=(const segment_tree& st) {
    if (&st == this)
        return *this;
    std::stack<node*> s;
    s.push(root);
    while (s.size()) {
        node* p = s.top();
        s.pop();
        if (p) {
            s.push(p->left_n);
            s.push(p->right_n);
            delete p;
        }
    }
    root = nullptr;
    base_elem = st.base_elem;
    left_barr = st.left_barr;
    right_barr = st.right_barr;
    operation = st.operation;
    if (is_correct_node(st.root)) {
        s.push(st.root);
        root = new node(st.base_elem);
        root->value = st.root->value;
        root->push_value = st.root->push_value;
        s.push(root);
    }
    while (s.size()) {
        node* p = s.top();
        s.pop();
        node* q = s.top();
        s.pop();
        if (is_correct_node(q->left_n)) {
            s.push(q->left_n);
            p->left_n = new node(st.base_elem);
            p->left_n->value = q->left_n->value;
            p->left_n->push_value = q->left_n->push_value;
            s.push(p->left_n);
        }
        if (is_correct_node(q->right_n)) {
            s.push(q->right_n);
            p->right_n = new node(st.base_elem);
            p->right_n->value = q->right_n->value;
            p->right_n->push_value = q->right_n->push_value;
            s.push(p->right_n);
        }
    }
    return *this;
}

void segment_tree::correct_node(node** p) {
    if (*p == nullptr)
        *p = new node(base_elem);
    else if ((*p)->is_changed) {
        (*p)->value = base_elem;
        (*p)->push_value = base_elem;
        if ((*p)->left_n != nullptr)
            (*p)->left_n->is_changed = true;
        if ((*p)->right_n != nullptr)
            (*p)->right_n->is_changed = true;
    }
}

bool segment_tree::is_correct_node(const node* const p) const {
    if (p == nullptr)
        return false;
    if (p->is_changed)
        return false;
    return true;
}

const int segment_tree::get_base_elem() const {
    return base_elem;
}

const int segment_tree::get_left_barr() const {
    return left_barr;
}

const int segment_tree::get_right_barr() const {
    return right_barr;
}

void segment_tree::add_value(int pos, int value) {
    if ((pos > right_barr) || (pos < left_barr))
        throw -1;
    int l = left_barr, r = right_barr, c;
    correct_node(&root);
    root->value = operation(root->value, value, 1);
    node* p = root;
    while (l < r) {
        c = l + (r - l) / 2;
        if (pos <= c) {
            correct_node(&p->left_n);
            p = p->left_n;
            p->value = operation(p->value, value, 1);
            r = c;
        } else {
            correct_node(&p->right_n);
            p = p->right_n;
            p->value = operation(p->value, value, 1);
            l = c + 1;
        }
    }
}

void segment_tree::add_value(int l_pos, int r_pos, int value) {
    if ((l_pos < left_barr) || (r_pos > right_barr))
        throw -1;
    if (l_pos > r_pos)
        throw -3;
    int c;
    std::stack<position> s;
    correct_node(&root);
    if ((left_barr >= l_pos) && (right_barr <= r_pos)) {
        root->value = operation(root->value, value, right_barr - left_barr + 1);
        root->push_value = operation(root->push_value, value, 1);
    } else {
        c = left_barr + (right_barr - left_barr) / 2;
        if (l_pos <= c) {
            root->value = operation(root->value, value, c - l_pos + 1);
            correct_node(&root->left_n);
            s.push({left_barr, c, root->left_n});
        }
        if (r_pos > c) {
            root->value = operation(root->value, value, r_pos - c);
            correct_node(&root->right_n);
            s.push({c + 1, right_barr, root->right_n});
        }
    }
    while (s.size()) {
        position t = s.top();
        s.pop();
        if ((t.l > r_pos) || (t.r < l_pos))
            continue;
        if ((t.l >= l_pos) && (t.r <= r_pos)) {
            t.p->value = operation(t.p->value, value, t.r - t.l + 1);
            t.p->push_value = operation(t.p->push_value, value, 1);
        } else {
            c = t.l + (t.r - t.l) / 2;
            if (l_pos <= c) {
                t.p->value = operation(t.p->value, value, c - l_pos + 1);
                correct_node(&t.p->left_n);
                s.push({t.l, c, t.p->left_n});
            }
            if (r_pos > c) {
                t.p->value = operation(t.p->value, value, r_pos - c);
                correct_node(&t.p->right_n);
                s.push({c + 1, t.r, t.p->right_n});
            }
        }
    }
}

int segment_tree::get_value(int pos) const {
    if ((pos > right_barr) || (pos < left_barr))
        throw -1;
    int l = left_barr, r = right_barr, c;
    int value = base_elem;
    if (!is_correct_node(root))
        return value;
    if (left_barr == right_barr) {
        value = operation(value, root->value, 1);
        return value;
    }
    value = operation(value, root->push_value, 1);
    node* t = root;
    while (l < r) {
        c = l + (r - l) / 2;
        if (pos <= c) {
            r = c;
            if (!is_correct_node(t->left_n))
                break;
            t = t->left_n;
            if (l == r) {
                value = operation(value, t->value, 1);
                break;
            }
            value = operation(value, t->push_value, 1);
        } else {
            l = c + 1;
            if (!is_correct_node(t->right_n))
                break;
            t = t->right_n;
            if (l == r) {
                value = operation(value, t->value, 1);
                break;
            }
            value = operation(value, t->push_value, 1);
        }
    }
    return value;
}

int segment_tree::get_value(int l_pos, int r_pos) const {
    if ((l_pos < left_barr) || (r_pos > right_barr))
        throw -1;
    if (l_pos > r_pos)
        throw -3;
    int c, value = base_elem, l, r;
    std::stack<position> s;
    if (!is_correct_node(root))
        return value;
    if ((left_barr >= l_pos) && (right_barr <= r_pos)) {
        value = operation(value, root->value, 1);
    } else {
        c = left_barr + (right_barr - left_barr) / 2;
        if (l_pos <= c) {
            l = std::max(l_pos, left_barr);
            r = std::min(r_pos, c);
            value = operation(value, root->push_value, r - l + 1);
            if (is_correct_node(root->left_n))
                s.push({left_barr, c, root->left_n});
        }
        if (r_pos > c) {
            l = std::max(l_pos, c + 1);
            r = std::min(r_pos, right_barr);
            value = operation(value, root->push_value, r - l + 1);
            if (is_correct_node(root->right_n))
                s.push({c + 1, right_barr, root->right_n});
        }
    }
    while (s.size()) {
        position t = s.top();
        s.pop();
        if ((t.l > r_pos) || (t.r < l_pos))
            continue;
        if ((t.l >= l_pos) && (t.r <= r_pos)) {
            value = operation(value, t.p->value, 1);
        } else {
            c = t.l + (t.r - t.l) / 2;
            if (l_pos <= c) {
                l = std::max(l_pos, t.l);
                r = std::min(r_pos, c);
                value = operation(value, t.p->push_value, r - l + 1);
                if (is_correct_node(t.p->left_n))
                    s.push({t.l, c, t.p->left_n});
            }
            if (r_pos > c) {
                l = std::max(l_pos, c + 1);
                r = std::min(r_pos, t.r);
                value = operation(value, t.p->push_value, r - l + 1);
                if (is_correct_node(t.p->right_n))
                    s.push({c + 1, t.r, t.p->right_n});
            }
        }
    }
    return value;
}

void segment_tree::set_value(int pos, int value) {
    if ((pos > right_barr) || (pos < left_barr))
        throw -1;
    int l = left_barr, r = right_barr, c;
    std::stack<node*> s;
    correct_node(&root);
    if (l == r) {
        root->value = value;
        return;
    }
    node* t = root;
    s.push(root);
    while (l < r) {
        c = l + (r - l) / 2;
        correct_node(&t->left_n);
        correct_node(&t->right_n);
        t->left_n->value =
            operation(t->left_n->value, t->push_value, c - l + 1);
        t->left_n->push_value =
            operation(t->left_n->push_value, t->push_value, 1);
        t->right_n->value =
            operation(t->right_n->value, t->push_value, r - c);
        t->right_n->push_value =
            operation(t->right_n->push_value, t->push_value, 1);
        t->push_value = base_elem;
        if (pos <= c) {
            s.push(t->left_n);
            t = t->left_n;
            r = c;
        } else {
            s.push(t->right_n);
            t = t->right_n;
            l = c + 1;
        }
    }
    t = s.top();
    s.pop();
    t->value = operation(base_elem, value, 1);
    t->push_value = operation(base_elem, value, 1);
    while (s.size()) {
        t = s.top();
        s.pop();
        t->value = base_elem;
        t->value = operation(t->value, t->left_n->value, 1);
        t->value = operation(t->value, t->right_n->value, 1);
    }
}

void segment_tree::set_value(int l_pos, int r_pos, int value) {
    if ((l_pos < left_barr) || (r_pos > right_barr))
        throw -1;
    if (l_pos > r_pos)
        throw -3;
    int c;
    std::stack<position> s;
    std::stack<node*> s2;
    correct_node(&root);
    s.push({left_barr, right_barr, root});
    while (s.size()) {
        position t = s.top();
        s.pop();
        if ((t.l > r_pos) || (t.r < l_pos))
            continue;
        if ((t.l >= l_pos) && (t.r <= r_pos)) {
            t.p->value = operation(base_elem, value, t.r - t.l + 1);
            t.p->push_value = operation(base_elem, value, 1);
            if (is_correct_node(t.p->left_n))
                t.p->left_n->is_changed = true;
            if (is_correct_node(t.p->right_n))
                t.p->right_n->is_changed = true;
        } else {
            c = t.l + (t.r - t.l) / 2;
            correct_node(&t.p->left_n);
            correct_node(&t.p->right_n);
            t.p->left_n->value =
                operation(t.p->left_n->value, t.p->push_value, c - t.l + 1);
            t.p->left_n->push_value =
                operation(t.p->left_n->push_value, t.p->push_value, 1);
            t.p->right_n->value =
                operation(t.p->right_n->value, t.p->push_value, t.r - c);
            t.p->right_n->push_value =
                operation(t.p->right_n->push_value, t.p->push_value, 1);
            t.p->push_value = base_elem;
            s2.push(t.p);
            if (l_pos <= c)
                s.push({t.l, c, t.p->left_n});
            if (r_pos > c)
                s.push({c + 1, t.r, t.p->right_n});
        }
    }
    while (s2.size()) {
        node* t = s2.top();
        s2.pop();
        t->value = base_elem;
        t->value = operation(t->value, t->left_n->value, 1);
        t->value = operation(t->value, t->right_n->value, 1);
    }
}
