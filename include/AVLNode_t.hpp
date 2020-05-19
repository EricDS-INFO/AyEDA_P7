#pragma once
#include "./BSNode_t.hpp"


template <class KEY>
class AVLNode_t: public BSNode_t<KEY>
{
public:

    AVLNode_t(KEY data): BSNode_t<KEY> (data) 
    {
    }

    virtual ~AVLNode_t();
};

template <class KEY>
AVLNode_t<KEY>::~AVLNode_t()
{
}
