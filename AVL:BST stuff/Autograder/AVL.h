#include <memory>
#include <string>
//#include "BST.cpp"
class AVL;

class AVLNode {
 public:
 	AVLNode(int key);
 	AVLNode(int key, std::weak_ptr<AVLNode> parent);
 	bool IsLeaf() const;
 	bool IsMissingChild() const;
 	bool HasLeftChild() const;
 	bool HasRightChild() const;
 	void DeleteChild(std::shared_ptr<AVLNode> v);
 	void ReplaceChild(std::shared_ptr<AVLNode> v, std::shared_ptr<AVLNode> u);


    int height;
    int balance;
    friend AVL;

    int key_;
    std::weak_ptr<AVLNode> parent_;
    std::shared_ptr<AVLNode> left_;
    std::shared_ptr<AVLNode> right_;

  friend AVL;
}; // class BSTNode

class AVL {
 public:
 	AVL();
    void updateHeight(std::shared_ptr<AVLNode> node);
    void rightright (std::shared_ptr<AVLNode> lastNode);
    void leftleft (std::shared_ptr<AVLNode> lastNode);

    void leftright(std::shared_ptr<AVLNode> lastNode);
    void rightleft(std::shared_ptr<AVLNode> lastNode);

 	void Insert(int key);
 	bool Delete(int key);
 	bool Find(int key) const;
 	std::string JSON() const;
 	size_t size() const;
 	bool empty() const;
 	int DeleteMin();


	void DeleteLeaf(std::shared_ptr<AVLNode> currentNode);
	int DeleteMin(std::shared_ptr<AVLNode> currentNode);

 	std::shared_ptr<AVLNode> root_;
 	size_t size_;

}; // class BST


