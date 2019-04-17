// Copyright 2019 Savkin Yuriy

#ifndef __SEGMENT_TREE_H__
#define __SEGMENT_TREE_H__

#include <functional>

class segment_tree {
    private:
    struct node {
        node* left_n;
        node* right_n;
        node* pre_n;
        int value;
        int push_value;
        node(node* _l = nullptr, node* _r = nullptr, node* _p = nullptr);
    };

    const int base_elem;
    const int left_barr;
    const int right_barr;
    std::function<void(int* const, int* const)> operation;
    node* root;

    public:
    segment_tree(const int lg, const int rg, const
        std::function<void(int* const, int* const)>& fu =
                [&](int* const a, int* const b) { *a += *b; },
                    const int be = 0);
    segment_tree(const segment_tree& st);
    ~segment_tree();
    segment_tree& operator=(const segment_tree& st);

    void add_value(int pos, int value);
    void add_value(int l_pos, int r_pos, int value);
    void set_value(int pos, int value);
    void set_value(int l_pos, int r_pos, int value);
    int get_value(int pos);
    int get_value(int l_pos, int r_pos);

    const int get_base_elem();
    const int get_left_barr();
    const int get_right_barr();
};

#endif  // __SEGMENT_TREE_H__
