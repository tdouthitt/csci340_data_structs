/****************************************************************
   FILE:      binSTree.h
   AUTHOR:    Andrew Bihner
   LOGON ID:  Z156501
   DUE DATE:  October 21, 2010

   PURPOSE:   Header file for a binary search  tree class
****************************************************************/

#ifndef BINSTREE_H
#define BINSTREE_H
#include "binTree.h"

template <class T>
class binSTree : public binTree<T>
{
   public:
     void insert(const T&); 							// inserts a node with value x
	  void remove(const T&);							// removes a node with value x
	  bool search(const T&, int&) const;                // searches a node with value x

   private:
     void insert(treeNode<T>*&, const T&);             // private version of insert
	  void remove(treeNode<T>*&, const T&);				// private version of remove
	  bool search(treeNode<T>* const&, const T&, int&) const; // private version of search
	  bool remove_root(treeNode<T>*&);					// removes a node
     
};

/***************************************************************
   FUNCTION: insert(const T& newValue)
 
   USE: calls the insert recursive method

   ARGUMENTS: 1. const T& value
   
   RETURN:	NONE.
***************************************************************/
// inserts a node in shortest subtree
template <class T>
void binSTree<T>::insert(const T& newValue)
{
   insert(this -> root, newValue);
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
void binSTree<T>::insert(treeNode<T>*& ptr, const T& newValue)
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
	  
	  if(newValue < ptr -> value)
	     insert(ptr->left, newValue);
	  else if(newValue > ptr -> value)
	     insert(ptr->right, newValue);
	  else 
		 return;
   }
   
}

/***************************************************************
   FUNCTION: remove(const T& newValue)
 
   USE: calls the remove recursive method

   ARGUMENTS: 1. const T& value
   
   RETURN:	NONE.
***************************************************************/
template <class T>
void binSTree<T>::remove(const T& removeValue)
{
   remove(this -> root, removeValue);
}

/***************************************************************
   FUNCTION: remove(treeNode<T>*& ptr, const T& newValue)
 
   USE: Removes an object from the tree

   ARGUMENTS: 1. Const reference to a binTree object
              2. Const type T& newValue
   
   RETURN:	NONE.
***************************************************************/
template<class T>
void binSTree<T>::remove(treeNode<T>*& ptr, const T& removeValue)
{
   if(ptr == NULL || ptr -> value == removeValue)
       remove_root(ptr);
   else
   {
      if(removeValue < ptr -> value)
	     remove(ptr -> left, removeValue);
	  else
	     remove(ptr -> right, removeValue);
   }
}

/***************************************************************
   FUNCTION: bool search(const T&, int&) const
 
   USE: calls the search recursive method

   ARGUMENTS: 1. const T& value
			  2. int&
   
   RETURN:	True if found, False if not found.
***************************************************************/
template<class T>
bool binSTree<T>::search(const T& searchValue, int& len) const
{
   len = 0;
   return search(this -> root, searchValue, len);
}

/***************************************************************
   FUNCTION: bool search(treeNode<T>*& ptr, const T& newValue)
 
   USE: Removes an object from the tree

   ARGUMENTS: 1. Const reference to a treeNode object
              2. Const type T& newValue
   
   RETURN:	NONE.
***************************************************************/
template<class T>
bool binSTree<T>::search(treeNode<T>* const& ptr, const T& searchValue , int& len) const
{
   if(ptr == NULL)
      return false;
   else 
   {
      len++;
	  
	  if(searchValue == ptr -> value)
	     return true;
	  else if(searchValue < ptr -> value)
	     return search(ptr -> left, searchValue, len);
	  else 
	     return search(ptr -> right, searchValue, len);
   }
}

/***************************************************************
   FUNCTION: bool remove_root(treeNode<T>*&)
 
   USE: Removes the root from the tree

   ARGUMENTS: 1. Const reference to a treeNode object
   
   RETURN:	NONE.
***************************************************************/
template<class T>
bool binSTree<T>:: remove_root(treeNode<T>*& ptr)
{
   treeNode<T>* delNode = ptr, * replNode, * replParent;
   
   //Value to remove was not found
   if(delNode == NULL)
      return false;
	  
   // Case 1 && 2 
   if(delNode -> left == NULL)
      replNode = delNode -> right;
   // Case 3	  
   else if(delNode -> right == NULL)
      replNode = delNode -> left;
   else 
   {
      replParent = delNode;
	   replNode = delNode -> left;
	  
	  while(replNode -> right != NULL)
	  {
	     replParent = replNode;
		  replNode = replNode -> right;
	  }
	  
	  //If replNode is not the left child of delNode
	  if(replParent != delNode)
	  {
	     replParent -> right = replNode -> left;
		  replNode -> left = delNode -> left;
	  }
	  replNode -> right = delNode -> right;
   } // end else
   
   delete delNode;
   ptr = replNode; 
   return true;
}
#endif