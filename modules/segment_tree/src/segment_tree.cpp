// Copyright 2019 Savkin Yuriy

#include "include/segment_tree.h"

segment_tree::node::node(int _v, node* _l, node* _r):
    left_n(_l), right_n(_r), value(_v), push_value(_v)
{

}

segment_tree::segment_tree(const int lg, const int rg, const
        std::function<int(int, int, int)>& fu, const int be):
            base_elem(be), left_barr(lg), right_barr(rg), operation(fu)
{
    if (left_barr > right_barr)
        throw -2;
    root = nullptr;
}

segment_tree::segment_tree(const segment_tree& st):
    base_elem(st.base_elem), left_barr(st.left_barr),
        right_barr(st.right_barr), operation(st.operation)
{
    std::stack<node*> s;
    if (st.root)
    {
        s.push(st.root);
        root = new node(st.base_elem);
        root->value = st.root->value;
        root->push_value = st.root->push_value;
        s.push(root);
    }
    while (s.size())
    {
        node* p = s.top();
        s.pop();
        node* q = s.top();
        s.pop();
        if (q->left_n)
        {
            s.push(q->left_n);
            p->left_n = new node(st.base_elem);
            p->left_n->value = q->left_n->value;
            p->left_n->push_value = q->left_n->push_value;
            s.push(p->left_n);
        }
        if (q->right_n)
        {
            s.push(q->right_n);
            p->right_n = new node(st.base_elem);
            p->right_n->value = q->right_n->value;
            p->right_n->push_value = q->right_n->push_value;
            s.push(p->right_n);
        }
    }
}

segment_tree::~segment_tree()
{
    std::stack<node*> s;
    s.push(root);
    while(s.size())
    {
        node* p = s.top();
        s.pop();
        if (p)
        {
            s.push(p->left_n);
            s.push(p->right_n);
            delete p;
        }
    }
}

segment_tree& segment_tree::operator=(const segment_tree& st)
{
    std::stack<node*> s;
    s.push(root);
    while(s.size())
    {
        node* p = s.top();
        s.pop();
        if (p)
        {
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
    if (st.root)
    {
        s.push(st.root);
        root = new node(st.base_elem);
        root->value = st.root->value;
        root->push_value = st.root->push_value;
        s.push(root);
    }
    while (s.size())
    {
        node* p = s.top();
        s.pop();
        node* q = s.top();
        s.pop();
        if (q->left_n)
        {
            s.push(q->left_n);
            p->left_n = new node(st.base_elem);
            p->left_n->value = q->left_n->value;
            p->left_n->push_value = q->left_n->push_value;
            s.push(p->left_n);
        }
        if (q->right_n)
        {
            s.push(q->right_n);
            p->right_n = new node(st.base_elem);
            p->right_n->value = q->right_n->value;
            p->right_n->push_value = q->right_n->push_value;
            s.push(p->right_n);
        }
    }
    return *this;
}

const int segment_tree::get_base_elem() const
{
    return base_elem;
}

const int segment_tree::get_left_barr() const
{
    return left_barr;
}

const int segment_tree::get_right_barr() const
{
    return right_barr;
}

void segment_tree::add_value(int pos, int value)
{
    if ((pos > right_barr) || (pos < left_barr))
        throw -1;
    int l = left_barr, r = right_barr, c;
    if (root == nullptr)
        root = new node(base_elem);
    root->value = operation(root->value, value, 1);
    node* p = root;
    while(l < r)
    {
        c = (l + r) / 2;
        if (pos <= c)
        {
            if (p->left_n == nullptr)
                p->left_n = new node(base_elem);
            p->value = operation(p->value, value, 1);
            p = p->left_n;
            r = c;
        }
        else
        {
            if (p->right_n == nullptr)
                p->right_n = new node(base_elem);
            p->value = operation(p->value, value, 1);
            p = p->right_n;
            l = c + 1;
        }
    }
}

void segment_tree::add_value(int l_pos, int r_pos, int value)
{
    if ((l_pos > right_barr) || (r_pos < left_barr))
        throw -1;
    if (l_pos > r_pos)
        throw -3;
    int c;

    struct position
    {
        int l, r;
        node* p;
    };

    std::stack<position> s;
    if (root == nullptr)
        root = new node(base_elem);
    if ((left_barr >= l_pos) && (right_barr <= r_pos))
    {
        root->value = operation(root->value, value, right_barr - left_barr + 1);
        root->push_value = operation(root->push_value, value, 1);
    }
    else
    {
        c = (left_barr + right_barr) / 2;
        if (l_pos <= c)
        {
            root->value = operation(root->value, value, c - l_pos + 1);
            if (root->left_n == nullptr)
                root->left_n = new node(base_elem);
            s.push({left_barr, c, root->left_n});
        }
        if (r_pos > c)
        {
            root->value = operation(root->value, value, r_pos - c);
            if (root->right_n == nullptr)
                root->right_n = new node(base_elem);
            s.push({c + 1, right_barr, root->right_n});
        }
    }
    while (s.size())
    {
        position t = s.top();
        s.pop();
        if ((t.l > r_pos) || (t.r < l_pos))
            continue;
        if ((t.l >= l_pos) && (t.r <= r_pos))
        {
            t.p->value = operation(t.p->value, value, t.r - t.l + 1);
            t.p->push_value = operation(t.p->push_value, value, 1);
        }
        else
        {
            c = (t.l + t.r) / 2;
            if (l_pos <= c)
            {
                t.p->value = operation(t.p->value, value, c - l_pos + 1);
                if (t.p->left_n == nullptr)
                    t.p->left_n = new node(base_elem);
                s.push({t.l, c, t.p->left_n});
            }
            if (r_pos > c)
            {
                t.p->value = operation(t.p->value, value, r_pos - c);
                if (t.p->right_n == nullptr)
                    t.p->right_n = new node(base_elem);
                s.push({c + 1, t.r, t.p->right_n});
            }
        }
    }
}

int segment_tree::get_value(int pos)
{
    if ((pos > right_barr) || (pos < left_barr))
        throw -1;
    int l = left_barr, r = right_barr, c;
    int value = base_elem;
    if (root == nullptr)
        return value;
    if (left_barr == right_barr)
    {
        value = operation(value, root->value, 1);
        return value;
    }
    value = operation(value, root->push_value, 1);
    node* t = root;
    while(l < r)
    {
        c = (l + r) / 2;
        if (pos <= c)
        {
            r = c;
            if (t->left_n == nullptr)
                break;
            t = t->left_n;
            if (l == r)
            {
                value = operation(value, t->value, 1);
                break;
            }
            value = operation(value, t->push_value, 1);
        }
        else
        {
            l = c + 1;
            if (t->right_n == nullptr)
                break;
            t = t->right_n;
            if (l == r)
            {
                value = operation(value, t->value, 1);
                break;
            }
            value = operation(value, t->push_value, 1);
        }
    }
    return value;
}

int segment_tree::get_value(int l_pos, int r_pos)
{
    if ((l_pos > right_barr) || (r_pos < left_barr))
        throw -1;
    if (l_pos > r_pos)
        throw -3;
    int c, value = base_elem;

    struct position
    {
        int l, r;
        node* p;
    };

    std::stack<position> s;
    if (root == nullptr)
        return value;
    if ((left_barr >= l_pos) && (right_barr <= r_pos))
        value = operation(value, root->value, 1);
    else
    {
        c = (left_barr + right_barr) / 2;
        if (l_pos <= c)
        {
            value = operation(value, root->push_value, c - l_pos + 1);
            if (root->left_n != nullptr)
                s.push({left_barr, c, root->left_n});
        }
        if (r_pos > c)
        {
            value = operation(value, root->push_value, r_pos - c);
            if (root->right_n != nullptr)
                s.push({c + 1, right_barr, root->right_n});
        }
    }
    while (s.size())
    {
        position t = s.top();
        s.pop();
        if ((t.l > r_pos) || (t.r < l_pos))
            continue;
        if ((t.l >= l_pos) && (t.r <= r_pos))
            value = operation(value, t.p->value, 1);
        else
        {
            c = (t.l + t.r) / 2;
            if (l_pos <= c)
            {
                value = operation(value, t.p->push_value, c - l_pos + 1);
                if (t.p->left_n != nullptr)
                    s.push({t.l, c, t.p->left_n});
            }
            if (r_pos > c)
            {
                value = operation(value, t.p->push_value, r_pos - c);
                if (t.p->right_n != nullptr)
                    s.push({c + 1, t.r, t.p->right_n});
            }
        }
    }
    return value;
}

void segment_tree::set_value(int pos, int value)
{
    if ((pos > right_barr) || (pos < left_barr))
        throw -1;
    int l = left_barr, r = right_barr, c;
    std::stack<node*> s;
    if (root == nullptr)
        root = new node(base_elem);
    if (l == r)
    {
        root->value = value;
        return;
    }
    node* t = root;
    s.push(root);
    while (l < r)
    {
        c = (l + r) / 2;
        if (t->left_n == nullptr)
            t->left_n = new node(base_elem);
        if (t->right_n == nullptr)
            t->right_n = new node(base_elem);
        t->left_n->value = operation(t->left_n->value, t->push_value, c - l + 1);
        t->left_n->push_value = operation(t->left_n->push_value, t->push_value, 1);
        t->right_n->value = operation(t->right_n->value, t->push_value, r - c);
        t->right_n->push_value = operation(t->right_n->push_value, t->push_value, 1);
        t->push_value = base_elem;
        if (pos <= c)
        {
            s.push(t->left_n);
            t = t->left_n;
            r = c;
        }
        else
        {
            s.push(t->right_n);
            t = t->right_n;
            l = c + 1;
        }
    }
    t = s.top();
    s.pop();
    t->value = value;
    t->push_value = base_elem;
    while(s.size())
    {
        t = s.top();
        s.pop();
        t->value = base_elem;
        t->value = operation(t->value, t->left_n->value, 1);
        t->value = operation(t->value, t->right_n->value, 1);
    }
}

void segment_tree::set_value(int l_pos, int r_pos, int value)
{
//    if ((l_pos > right_barr) || (r_pos < left_barr))
//        throw -1;
//    if (l_pos > r_pos)
//        throw -3;
//    int c;
//
//    struct position
//    {
//        int l, r;
//        node* p;
//    };
//
//    std::stack<position> s;
}
