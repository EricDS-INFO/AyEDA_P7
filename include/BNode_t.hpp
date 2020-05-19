#pragma once
#include <iostream>

template <class KEY>
class BNode_t
{
protected:
    BNode_t<KEY>        *left_;
    BNode_t<KEY>        *right_;
    KEY                  data_;

public:

    BNode_t(KEY& data):
    left_(NULL),
    right_(NULL)
    {

        data_.value( data.value() );
    }

    BNode_t(BNode_t<KEY>& node)
    {
        left_ = node.left_;
        right_ = node.right_;
        data_ = node.data_;
    }


    BNode_t(void):
    left_(NULL),
    right_(NULL)
    {
        data_ = -1;
    }


    ~BNode_t();

    BNode_t<KEY>* left(void)  { return left_; }
    BNode_t<KEY>* right(void)  { return right_; }
    KEY&           data(void) { return data_; }

    void left(BNode_t<KEY>* NewChild) { left_ = NewChild; }
    void right(BNode_t<KEY>* NewChild) { right_ = NewChild; }
    void data(KEY& data) { data_ = data; }

    bool empty(void) { return data_ == -1; }

    template <class T>
    friend std::ostream& operator<< (std::ostream& os, BNode_t<T>& Node); 
};

template <class KEY>
BNode_t<KEY>::~BNode_t()
{
    left_ = NULL;
    right_ = NULL;
}


template <class KEY>
std::ostream& operator<< (std::ostream& os, BNode_t<KEY>* Node)
{
    os << "[";
    if (Node->empty())
        os << "*";
    else
        os << Node->data();
    os <<"]";
    return os;
}