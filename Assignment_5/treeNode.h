/****************************************************************
   FILE:      treeNode.h
   AUTHOR:    Andrew Bihner
   LOGON ID:  Z156501
   DUE DATE:  October 11, 2010

   PURPOSE:   Header file for a tree node class
****************************************************************/
#ifndef TREENODE_H
#define TREENODE_H

#include "/home/turing/onyuksel/courses/340/common/340.h"

using namespace std;

template <class T> class binTree;

template <class T>
class treeNode
{
   friend class binTree<T>;
   
   public:
   
      treeNode(const T& = T(), treeNode<T>* = NULL, treeNode<T>* = NULL);
      
   private:
   
      T value;
      treeNode<T>* left,
                 * right;
};

/***************************************************************
   FUNCTION: treeNode(const T& newValue, treeNode<T>* newLeft, 
                      treeNode<T>* newRight)
 
   USE: Initializes a treeNode object 

   ARGUMENTS: 1. Const reference to a template T item.
			  2. treeNode * newLeft
			  3. treeNode * newRight
   
   RETURN:	NONE.
***************************************************************/
template<class T>
treeNode<T>:: treeNode(const T& newValue, treeNode<T>* newLeft, treeNode<T>* newRight)
{
   value = newValue;
   left = newLeft;
   right = newRight;
}

#endif

