// Copyright 2019 Savkin Yuriy

#ifndef __SEGMENT_TREE_H__
#define __SEGMENT_TREE_H__

#include <functional>
#include <stack>

class segment_tree {
    private:
    struct node {
        node* left_n;
        node* right_n;
        int value;
        int push_value;
        bool is_changed;
        node(int _v, node* _l = nullptr, node* _r = nullptr);
    };

    struct position {
        int l, r;
        node* p;
    };

    int base_elem;
    int left_barr;
    int right_barr;
    std::function<int(int, int, int)> operation;
    node* root;

    void correct_node(node*& p);
    bool is_correct_node(const node* const p) const;

    public:
    segment_tree(const int lg, const int rg, const
        std::function<int(int, int, int)>& fu =
                [](int a, int b, int c) { return a + b * c; },
                    const int be = 0);
    segment_tree(const segment_tree& st);
    ~segment_tree();
    segment_tree& operator=(const segment_tree& st);

    void add_value(int pos, int value);
    void add_value(int l_pos, int r_pos, int value);
    void set_value(int pos, int value);
    void set_value(int l_pos, int r_pos, int value);
    int get_value(int pos) const;
    int get_value(int l_pos, int r_pos) const;

    const int get_base_elem() const;
    const int get_left_barr() const;
    const int get_right_barr() const;
};

#endif  // __SEGMENT_TREE_H__
