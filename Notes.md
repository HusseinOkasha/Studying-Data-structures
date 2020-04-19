This file will be about my notes on Data structures .

BST (Binary search Tree):
=========================
 -------------------------------------
    Q:what is binary search tree ...?  

    A:binary search tree is a tree where every node in it has 0 ,1 or 2 nodes only where left child is lessthan the parent and the right child is greater than the parent.
   ------------------------------------------------ 
    Q:How we can insert in binary search tree ...?
    
    A:well this is a good question bro, this process has two base cases so starting from the root node.
    first: the inserted value is lessthan th current node then move to the current left child and repeate
    second : the inserted value is greaterthan the current node then move to the current right child .
    stop : when you reach a nullptr to node , then their you should insert your value in this posiotion.
   ----------------------------------------------
    Q:How we delete in binary search tree...?
    
    A:this has 4 cases:
    case #1: the value you want to delete is the root node,so you want to delete the root node then you will traverse the right substree finding the left most node and make it's left child points to the left child of the root node .
    then make the right child of the root node be the root.this only if the the root node has left and right childs. 
    but if it has obly one child then mke root points to it.
    case #2: the value you want to delete has two childs but itsn't the root node.
    let the node the you want to delete be"A"left child "B" right child "C" .
    then you traverse the right subtree finding the left most node make it's leftchild points to "B" and make the parent of "A" points to "C".
    case #3: the value you want to delete has only one child then make the parent points to it .
    case #4: the value you want to delete is leaf (has no childs) just make parent points to null.
              
