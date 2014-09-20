/****************************************************************
   FILE:      binTree.h
   AUTHOR:    Andrew Bihner
   LOGON ID:  Z156501
   DUE DATE:  October 11, 2010

   PURPOSE:   Header file for a binary tree class
****************************************************************/

#ifndef BINTREE_H
#define BINTREE_H

#include "treeNode.h"

template <class T>
class binTree
{
   public:
   
      binTree();                                    // default constructor
      binTree(const binTree<T>&);                   // copy constructor
      binTree& operator=(const binTree<T>&);     // assignment operator
      virtual ~binTree();                           // destructor
      
      bool empty() const;                           // checks if tree empty
      int size() const;                             // finds no of nodes
      int height() const;                           // finds height of tree
      int leaves() const;                           // finds no of leaves
      virtual void insert(const T&);                // inserts a node in shortest subtree
      void clear();                                 // destroys tree
      
      void inOrder(void (*)(T&));                   // inorder traversal of a tree
      void preOrder(void (*)(T&));                  // preorder traversal of a tree
      void postOrder(void (*)(T&));                 // postorder traversal of a tree
      
   protected:
   
      treeNode<T>* root;                            // root of tree
      
   private:
   
      int size(treeNode<T>*) const;                 // private version of size()
      int height(treeNode<T>*) const;               // private version of height()
      int leaves(treeNode<T>*) const;               // private version of leaves()
      void insert(treeNode<T>*&, const T&);         // private version of insert()
      void clear(treeNode<T>*);                     // private version of clear()
      
      void inOrder(treeNode<T>*, void (*)(T&));     // private version of inOrder()
      void preOrder(treeNode<T>*, void (*)(T&));    // private version of preOrder()
      void postOrder(treeNode<T>*, void (*)(T&));   // private version of postOrder()
      
      treeNode<T>* copy(const treeNode<T>*);        // creates clone of tree
};

/***************************************************************
   FUNCTION: binTree()
 
   USE: Initializes a binTree object 

   ARGUMENTS: NONE.
   
   RETURN:	NONE.
***************************************************************/
template <class T>
binTree<T>::binTree()
{
	root = NULL;
}
/***************************************************************
   FUNCTION: binTree(const binTree<T>& temp)
 
   USE: Initializes a treeNode object 

   ARGUMENTS: 1. Const reference to a binTree object
   
   RETURN:	NONE.
***************************************************************/
template <class T>
binTree<T>::binTree(const binTree<T>& temp)
{
	root = copy(temp.root);
}

/***************************************************************
   FUNCTION: binTree<T>& operator=(const binTree<T>& ptr)
 
   USE: Operator= overload

   ARGUMENTS: 1. Const reference to a binTree object
   
   RETURN:	the call object
***************************************************************/
template <class T>
binTree<T>& binTree<T>:: operator=(const binTree<T>& ptr)
{
   if(this != &ptr)
   {
      clear(root); // Deletes current tree
   
      root = copy(ptr.root); // Copies in the arguments tree
   }      
      return *this;
}

/***************************************************************
   FUNCTION: ~binTree()
 
   USE: Destructor

   ARGUMENTS: NONE.
   
   RETURN:	NONE.
***************************************************************/
template <class T>
binTree<T>::~binTree()
{
   clear();
}

/***************************************************************
   FUNCTION: empty() const
 
   USE: checks to see if the tree is empty or not

   ARGUMENTS: NONE.
   
   RETURN:	True if tree empty, False it tree has objects
***************************************************************/
template<class T>
bool binTree<T>::empty() const
{
   if(root == NULL)
      return true;
   else
      return false;   
}

/***************************************************************
   FUNCTION: size() const
 
   USE: calls the recursive size method 

   ARGUMENTS: NONE.
   
   RETURN:	the size of the binTree
***************************************************************/
template<class T>
int binTree<T>::size() const
{
   return size(root); // Calls the recursive size method.
}

/***************************************************************
   FUNCTION: size(treeNode<T>* ptr) const
 
   USE: counts the number of objects in the tree

   ARGUMENTS: 1. Const reference to a binTree object
   
   RETURN:	0 if a object does not exist at a given spot
            1 if an object exists at a spot
***************************************************************/
template<class T>
int binTree<T>::size(treeNode<T>* ptr) const
{
   if(ptr != NULL)
   {
      return 1 + size(ptr -> left) // counts left side
	           + size(ptr -> right); // counts right side
   }
   else
      return 0; // emtpy tree
} 

/***************************************************************
   FUNCTION: height() const
 
   USE: calls the recursive height method 

   ARGUMENTS: NONE.
   
   RETURN:	Height of the tree.
***************************************************************/
template<class T>
int binTree<T>:: height() const
{
   return height(root); // Calls the recursive height method.
}

/***************************************************************
   FUNCTION: height(treeNode<T>* ptr) const
 
   USE: counts the height of a given tree

   ARGUMENTS: 1. Const reference to a binTree object
   
   RETURN:	0 if object does not exists
            1 if object exists
***************************************************************/
template <class T>
int binTree<T>:: height(treeNode<T>* ptr) const
{
   if(ptr == NULL)
      return 0;
   else
   {
      int lHeight = height(ptr -> left); // counts left side
	  int rHeight = height(ptr -> right); // counts right side
	  
	  if(lHeight > rHeight)
	     return 1 + lHeight;
	  else 
	     return 1 + rHeight;
   }
}

/***************************************************************
   FUNCTION: leaves() const
 
   USE: calls the leaves recursive method

   ARGUMENTS: NONE.
   
   RETURN:	number of leaves in the tree
***************************************************************/
// Non-Recursive method that will call leaves
template<class T>
int binTree<T>::leaves() const
{
   return leaves(root);
}

/***************************************************************
   FUNCTION: leaves(treeNode<T>* ptr) const
 
   USE: counts the number of leaves in a given tree

   ARGUMENTS: 1. Const reference to a binTree object
   
   RETURN:	0 if object does not exists
            1 if object exists
***************************************************************/
//Recursive method called leaves
template<class T>
int binTree<T>::leaves(treeNode<T>* ptr) const
{
   int lCount = 0;
   if(ptr == NULL)
      return 0;
   else if(ptr -> left == NULL && ptr -> right == NULL) 
      return 1;
   else
   {
      if(ptr -> left != NULL)
         lCount += leaves(ptr -> left);
	  if(ptr -> right != NULL)
	     lCount += leaves(ptr -> right);	  
   }
   return lCount;
}

/***************************************************************
   FUNCTION: insert(const T& newValue)
 
   USE: calls the insert recursive method

   ARGUMENTS: 1. const T& value
   
   RETURN:	NONE.
***************************************************************/
// inserts a node in shortest subtree
template <class T>
void binTree<T>::insert(const T& newValue)
{
   insert(root, newValue);
}

/***************************************************************
   FUNCTION: insert(treeNode<T>*& ptr, const T& newValue)
 
   USE: Inserts an object into the tree

   ARGUMENTS: 1. Const reference to a binTree object
              2. Const type T& newValue
   
   RETURN:	NONE.
***************************************************************/
//recurisive insert method
template<class T>
void binTree<T>::insert(treeNode<T>*& ptr, const T& newValue)
{
   if(ptr == NULL)
   {
      // Need to make a call to TreeNode constructor
	  treeNode<T>* newNode;
	  newNode = new treeNode<T>(newValue);
      ptr = newNode;
   }	   
   else 
   {
      int lHeight = height(ptr->left);
	  int rHeight = height(ptr->right);
	  
	  if(lHeight <= rHeight)
	     insert(ptr->left, newValue);
	  else
	     insert(ptr->right, newValue);
   }
   
}

/***************************************************************
   FUNCTION: clear
 
   USE: calls clear recursive method

   ARGUMENTS: NONE.
   
   RETURN:	NONE.
***************************************************************/
// nonrecursive clear method
template <class T>
void binTree<T>::clear()
{
  clear(this -> root);
  root = NULL;  
}

/***************************************************************
   FUNCTION: clear(treeNode<T>* ptr)
 
   USE: clears out a given tree

   ARGUMENTS: 1. Const reference to a binTree object
   
   RETURN:	NONE.
***************************************************************/
// Recursive clear method
template<class T>
void binTree<T>::clear(treeNode<T>* ptr)
{
      if(ptr != NULL)
   {
      clear(ptr -> left);
	  clear(ptr -> right);
	  delete ptr;
      // Destroys both left and right colomns in tree and deletes
   }
      
}

/***************************************************************
   FUNCTION: inOrder(void (*fn)(T&))
 
   USE: Calls the inOrder recursive method

   ARGUMENTS: 1. void (*fn) (T%)
   
   RETURN:	NONE.
***************************************************************/
template <class T>
void binTree<T>::inOrder(void (*fn)(T&))
{
   inOrder(root, fn);
}

/***************************************************************
   FUNCTION: inOrder(treeNode<T>* p, void (*fn)(T&))
 
   USE: inOrder traversal in a tree

   ARGUMENTS: 1. Const reference to a binTree object
			  2. void (*fn) (T&)
   
   RETURN:	NONE.
***************************************************************/
template <class T>
void binTree<T>::inOrder(treeNode<T>* p, void (*fn)(T&))
{
   if (p != NULL)
   {
      inOrder(p->left, fn);
      fn(p->value);
      inOrder(p->right, fn);
   }
}

/***************************************************************
   FUNCTION: preOrder(void (*fn)(T&))
 
   USE: Calls the preOrder recursive method

   ARGUMENTS: 1. void (*fn) (T%)
   
   RETURN:	NONE.
***************************************************************/
// preorder traversal of a tree
template <class T>
void binTree<T>::preOrder(void (*fn)(T&))
{
   preOrder(root, fn);
}

/***************************************************************
   FUNCTION: preOrder(treeNode<T>* p, void (*fn)(T&))
 
   USE: preOrder traversal in a tree

   ARGUMENTS: 1. Const reference to a binTree object
			  2. void (*fn) (T&)
   
   RETURN:	NONE.
***************************************************************/
// private version of preOrder()
template <class T>
void binTree<T>::preOrder(treeNode<T>* p, void (*fn)(T&))
{
   if (p != NULL)
   {
      fn(p->value); 
      preOrder(p->left, fn);
      preOrder(p->right, fn);
   }
}

// POSTORDER 
/***************************************************************
   FUNCTION: postOrder(void (*fn)(T&))
 
   USE: Calls the postOrder recursive method

   ARGUMENTS: 1. void (*fn) (T%)
   
   RETURN:	NONE.
***************************************************************/
// postorder traversal of a tree
template <class T>
void binTree<T>::postOrder(void (*fn)(T&))
{
   postOrder(root, fn);
}

/***************************************************************
   FUNCTION: postOrder(treeNode<T>* p, void (*fn)(T&))
 
   USE: postOrder traversal in a tree

   ARGUMENTS: 1. Const reference to a binTree object
			  2. void (*fn) (T&)
   
   RETURN:	NONE.
***************************************************************/
// private version of preOrder()
template <class T>
void binTree<T>::postOrder(treeNode<T>* p, void (*fn)(T&))
{
   if (p != NULL)
   {
      postOrder(p->left, fn);
      postOrder(p->right, fn);
      fn(p->value); 
   }
}

/***************************************************************
   FUNCTION: copy(const treeNode<T>* ptr)
 
   USE: preforms a deep copy on the treeNode

   ARGUMENTS: 1. Const reference to a binTree object
   
   RETURN:	returns the root
***************************************************************/
// copy constructor
template<class T>
treeNode<T>* binTree<T>::copy(const treeNode<T>* ptr)
{
   treeNode<T> * newNode;
   
   if(ptr != NULL)
   {
	  newNode = new treeNode<T>(ptr -> value);
	  newNode  -> left = copy(ptr -> left);
	  newNode -> right = copy(ptr -> right);
	  return newNode;
   }
   else
      return NULL;
}
#endif

