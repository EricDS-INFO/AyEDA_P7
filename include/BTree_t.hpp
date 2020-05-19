#pragma once
#include "./BNode_t.hpp"
#include <queue>


template <class KEY>
class BTree_t
{
       public:
 
        BNode_t<KEY>    *root_;

        BTree_t(void) { root_ = NULL; }
        
        ~BTree_t(void);
        
        BNode_t<KEY>* root(void) { return root_; }

        const int size(void);
        const int height(void);

        void level_ride(void);
        void level_print(void);
    

        void inorder(void);
        void postorder(void);
        void preorder(void);        

        bool empty(void);
        const bool balanced(void);

        void balanced_insert(const KEY data );

        template <class T>
        friend std::ostream& operator<< (std::ostream& os, BTree_t<T>& tree);

        void write(std::ostream& os, BNode_t<KEY>* node, int space);    

    protected:
        void trim(BNode_t<KEY>* node);
        bool is_empty(BNode_t<KEY> *node) { return node == NULL; }
        bool is_leaf(BNode_t<KEY> *node) { return (!node->left() && !node->right()); }
        const bool balanced(BNode_t<KEY> *node);

        const int n_size(BNode_t<KEY>* node);
        const int height(BNode_t<KEY>* node);

        void inorder(BNode_t<KEY> *node);
        void postorder(BNode_t<KEY> *node);
        void preorder(BNode_t<KEY> *node);


        void balanced_insert(const KEY data, BNode_t<KEY>* node);

};

template <class KEY>
BTree_t<KEY>::~BTree_t(void)
{
    trim(root_);
}


// EMPTY METHOD 
template <class KEY>
bool BTree_t<KEY>::empty(void)
{ 
    return is_empty(root_); 
}


// BALANCE STATUS METHOD
template <class KEY>
const bool BTree_t<KEY>::balanced(void)
{
    return balanced(root_);
}

template <class KEY>
const bool BTree_t<KEY>::balanced(BNode_t<KEY>* node)
{
    if (node == NULL)
        return true;
    int eq = n_size(node->left()) - n_size(node->right());

    switch (eq)
    {
    case -1:
    case  0:
    case  1:
        return balanced(node->left()) && balanced(node->right());
        break;
    default:
        return false;
        break;
    }
}


// SIZE METHOD 
template <class KEY>
const int BTree_t<KEY>::size(void)
{
    return n_size(root_);
}


template <class KEY>
const int BTree_t<KEY>::n_size(BNode_t<KEY>* Node)
{
    if (Node == NULL)
        return 0;
    else
        return (1 + n_size(Node->left()) 
                  + n_size(Node->right()) );
}

// SIZE METHOD 
template <class KEY>
const int BTree_t<KEY>::height(void)
{
    return height(root_);
}


template <class KEY>
const int BTree_t<KEY>::height(BNode_t<KEY>* Node)
{
    if (Node == NULL)
        return 0;
    
    int left = height(Node->left());
    int right = height(Node->right());

    return 1 + std::max(left, right);
}


// TRIM METHOD
template <class KEY>
void BTree_t<KEY>::trim(BNode_t<KEY>* Node)
{
    if (Node == NULL) return;
    trim(Node->left());
    trim(Node->right());
    delete Node;
    Node = NULL;
}


// RIDE METHODS

template <class KEY>
void BTree_t<KEY>::level_ride(void)
{
    if (root_ == NULL) return;

    std::queue<BNode_t<KEY>* > Q;
    Q.push(root_);

    while (!Q.empty())
    {
        BNode_t<KEY>* node = Q.front();
        Q.pop();


        std::cout << node << " ";

        if(node->left() != NULL)
        {
            Q.push(node->left());
            
        }
        
        if(node->right() != NULL)
        {
            Q.push(node->right());
            
        }
            
    }
    std::cout << "\n";

}



// TREE ORDERED RIDES

template<class KEY>
void BTree_t<KEY>::inorder()
{
    inorder(root_); 
    std::cout << "\n";  
}


template<class KEY>
void BTree_t<KEY>::inorder(BNode_t<KEY>* node)
{
    if (node)
    {
        inorder(node->left());
        std::cout << node;
        inorder(node->right());
    }   
}

template<class KEY>
void BTree_t<KEY>::postorder()
{
    postorder(root_);
    std::cout << "\n";
}


template<class KEY>
void BTree_t<KEY>::postorder(BNode_t<KEY>* node)
{
    if(node)
    {
        postorder(node->left());
        postorder(node->right());
        std::cout << node;
    }
}

template<class KEY>
void BTree_t<KEY>::preorder()
{
    preorder(root_);
    std::cout << "\n";
}

template<class KEY>
void BTree_t<KEY>::preorder(BNode_t<KEY>* node)
{
    if(node)
    {
        std::cout << node;
        preorder(node->left());
        preorder(node->right());
    }
}


//Balaced insertion
template <class KEY>
void BTree_t<KEY>::balanced_insert(const KEY data )
{
    if (root_ == NULL)
        root_ = new BNode_t<KEY>(data);
    else 
        balanced_insert(data, root_);
}


template <class KEY>
void BTree_t<KEY>::balanced_insert(const KEY data, BNode_t<KEY>* node)
{
    if (n_size(node->left()) < n_size(node->right()))
    {
        if (node->left() != NULL)
            balanced_insert(data, node->left());
        else
            node->left(new BNode_t<KEY>(data));
    }
    else
    {
        if (node->right() != NULL)
            balanced_insert(data, node->right());
        else
            node->right(new BNode_t<KEY>(data));
        
    }

}


//Write operator


template <class KEY>
std::ostream& operator<< (std::ostream& os, BTree_t<KEY>& tree)
{
    for (int i = 0; i <= tree.height(); i++)
        os << "Nivel" << i <<"    ";
    os << "\n";

    tree.write(os, tree.root(), 0);

    return os;
}


template <class KEY>
void BTree_t<KEY>::write(std::ostream& os, BNode_t<KEY>* node, int space) {
  if (node == NULL) {
    space += 10;
    for (int i = 10; i < space ; i++)
      os<< " ";
    os << "[*]" << std::endl;
    return;
  }
  space += 10;

  write(os, node->right(), space);

    os << std::endl;
    for (int i = 10; i < space ; i++)
      os<< " ";
    os  << node << "\n";

  write(os, node->left(), space); 



}



//////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// Binary Search Tree ///////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

template <class KEY>
class BSTree_t : public BTree_t<KEY>
{
       public:
 
        BSTree_t(void): BTree_t<KEY>() {}
        
        ~BSTree_t(void) {}
        
        void insert(KEY data);
        BNode_t<KEY>* search(KEY data);
        BNode_t<KEY>* extract(KEY data); 
    

        void inorder(void);
        void postorder(void);
        void preorder(void);        

    protected:


        void insert(KEY data, BNode_t<KEY>* node);
        BNode_t<KEY>* search( KEY data, BNode_t<KEY>* node);
        BNode_t<KEY>* extract(KEY data, BNode_t<KEY>* node);
        BNode_t<KEY>* min_value(BNode_t<KEY>* node);        

};


/////// Search Tree Methods



// INSERT METHOD
template <class KEY>
void BSTree_t<KEY>::insert(KEY data)
{
    
    if (this->root_ != NULL)
    {
        insert(data, this->root_);
    }
    else
    {
        this->root_ = new BNode_t<KEY>;
        this->root_->data(data);
        this->root_->left(NULL);
        this->root_->right(NULL);
    }
    
}

template <class KEY>
void BSTree_t<KEY>::insert(KEY data, BNode_t<KEY> *leaf)
{
    if (data < leaf->data())
    {
        if (leaf->left() != NULL )
        {
            insert(data, leaf->left());
        }
        else
        {
            leaf->left(new BNode_t<KEY>);
            leaf->left()->data(data);
            leaf->left()->left(NULL);
            leaf->left()->right(NULL);
        }
    }
    else if (data >= leaf->data())
    {
        if (leaf->right() != NULL )
        {
            insert(data, leaf->right());
        }
        else
        {
            leaf->right(new BNode_t<KEY>);
            leaf->right()->data(data);
            leaf->right()->right(NULL);
            leaf->right()->left(NULL);
        }
    }
    

}


//SEARCH METHOD
template <class KEY>
BNode_t<KEY>* BSTree_t<KEY>::search(KEY data)
{
    return search(data, this->root_);
}

template <class KEY>
BNode_t<KEY>* BSTree_t<KEY>::search(KEY data, BNode_t<KEY>* leaf)
{
    if(leaf != NULL)
    {
        if (data == leaf->data())
        {
            return leaf;
        }
        if (data < leaf->data())
        {
            return search(data, leaf->left());
        }
        else
        {
            return search(data, leaf->right());
        }
        
    } 
    else
    {
        return NULL;
    }
}


// EXTRACT

template<class KEY>
BNode_t<KEY>* BSTree_t<KEY>::extract(KEY data)
{
    extract(data, this->root_);
} 


template<class KEY>
BNode_t<KEY>* BSTree_t<KEY>::extract(KEY data, BNode_t<KEY>* node)
{
    if (node == NULL) 
        return node;
    if (data < node->data())
        node->left( extract(data, node->left()) );
    else if (data > node->data())
        node->right( extract(data, node->right()) );
    else
    {
        if (node->left() == NULL)
        {
            BNode_t<KEY>* aux( node->right() );
            free(node);
            return aux;
        }
        else if (node->right() == NULL)
        {
            BNode_t<KEY>* aux( node->left() );
            free(node);
            return aux;
        }
        BNode_t<KEY>* aux( min_value(node->right()) );

        KEY value = aux->data();
        node->data( value );

        node->right( extract(aux->data(), node->right()));
    }
    
}


template<class KEY>
BNode_t<KEY>* BSTree_t<KEY>::min_value(BNode_t<KEY>* node)
{
    BNode_t<KEY>* current(node);

    while (current && current->left() != NULL)
    {
        current = current->left();
    }
    return current;
}




//// AVL Tree

template <class KEY>
class AVL_t: public BTree_t<KEY> 
{
    public:

    AVL_t(void): BTree_t<KEY>(){}
    ~AVL_t(){}
};