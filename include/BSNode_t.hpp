#pragma once
#include "./BNode_t.hpp"


template <class KEY>
class BSNode_t: public BNode_t<KEY>
{
public:

    BSNode_t(KEY data): BNode_t<KEY> (data) 
    {}

    virtual ~BSNode_t();
};

template <class KEY>
BSNode_t<KEY>::~BSNode_t()
{
}
