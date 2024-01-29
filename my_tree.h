#ifndef MY_TREE_H
#define MY_TREE_H

#include <vector>
#include <bits/stdc++.h>
#include <stack>
#include <queue>
#include <cmath>

template <class T>
struct Node {
    T data;
    Node *left = nullptr;
    Node *right = nullptr;

    Node(T data) : data(data) {}
    // Add the constructors you want
};

template <class T>
class MyTree{

    private:
    Node<T>* root=nullptr;

    Node<T>* ConvertBST(std::vector<T> v,int start,int end){
        if(start>end){
            return NULL;
        }
        float mid=ceil((start+end)/2.0);
        Node<T>* r=new Node<T>(v[mid]);
        r->left=ConvertBST(v,start,mid-1);
        r->right=ConvertBST(v,mid+1,end);
        root=r;
        return root;
    }
    Node<T>* insertKey(Node<T>* r,T key){
        if(!r){
            return new Node<T>(key);
        }
        if(key>r->data){
            r->right=insertKey(r->right,key);
        }
        else if(key<r->data){
            r->left=insertKey(r->left,key);
        }
        return r;
    }
    Node<T>* InsertNode(Node<T>* r,Node<T> node){
        if(r==NULL){
            return new Node<T>(node.data);
        }
        if(node.data > r->data){
            r->right=InsertNode(r->right,node);
        }
        else if(node.data < r->data){
            r->left=InsertNode(r->left,node);
        }
        return r;
    }
    Node<T>* Search(Node<T>* r,T key){
        if(r==nullptr || r->data==key){
            return r;
        }
        if(key > r->data){
            return Search(r->right,key);
        }
        if(key<r->data){
            return Search(r->left,key);
        }
    }
    Node<T>* DeleteKey(Node<T>* r,T key){
    if (r == NULL)
        return r;
        if(r->data >key){
            r->left=DeleteKey(r->left,key);
            return r;
        }
        else if(r->data < key){
            r->right=DeleteKey(r->right,key);
            return r;
        }
        if(r->left==NULL){
            Node<T>* temp=r->right;
            delete r;
            return temp;
        }
        else if(r->right==NULL){
            Node<T>* temp=r->left;
            delete r;
            return temp;
        }
        else{
            Node<T>* succParent=r;
            Node<T>* succ=r->right;
            while(succ->left != NULL){
                succParent=succ;
                succ=succ->left;
            }
            if(succParent != r)
            succParent->left=succ->right;
            else
            succParent->right=succ->right;
            r->data=succ->data;
            delete succ;
            return r;
        }
    }
    Node<T>* DeleteNode(Node<T>* r,Node<T> node){
    if (r == NULL)
        return r;
        if(r->data >node.data){
            r->left=DeleteNode(r->left,node.data);
            return r;
        }
        else if(r->data < node.data){
            r->right=DeleteNode(r->right,node.data);
            return r;
        }
        if(r->left==NULL){
            Node<T>* temp=r->right;
            delete r;
            return temp;
        }
        else if(r->right==NULL){
            Node<T>* temp=r->left;
            delete r;
            return temp;
        }
        else{
            Node<T>* succParent=r;
            Node<T>* succ=r->right;
            while(succ->left != NULL){
                succParent=succ;
                succ=succ->left;
            }
            if(succParent != r)
            succParent->left=succ->right;
            else
            succParent->right=succ->right;
            r->data=succ->data;
            delete succ;
            return r;
        }
    }
    void InorderRec(Node<T>* r,std::vector<T>& v){
        if(r!=NULL){
            InorderRec(r->left,v);
            v.push_back(r->data);
            InorderRec(r->right,v);
        }
    }
    void PreorderRec(Node<T>* r,std::vector<T>& v){
        if(r!=NULL){
            v.push_back(r->data);
            PreorderRec(r->left,v);
            PreorderRec(r->right,v);
        }
    }
    void PostorderRec(Node<T>* r,std::vector<T>& v){
        if(r!=NULL){
            PostorderRec(r->left,v);
            PostorderRec(r->right,v);
            v.push_back(r->data);
        }
    }
    int Height(Node<T>* r){
        if(r==NULL){
            return 0;
        }
        else{
            int lHeight=Height(r->left);
            int RHeight=Height(r->right);
            if(lHeight>RHeight)
            return (lHeight+1);
            else
            return (RHeight+1);
        }
    }
    void ClearTree(Node<T>* r){
        if(r==NULL) return;
        //Delete the subtrees.
        ClearTree(r->left);
        ClearTree(r->right);
        delete r;
    }
    void Breadth_Traversal(Node<T>* r,std::vector<T>& v){
        if(r==NULL)
        return;
        std::queue<Node<T>*> q;
        q.push(r);
        while(q.empty()==false){
            Node<T>* node=q.front();
            v.push_back(node->data);
            q.pop();
            if(node->left!=NULL)
            q.push(node->left);
            if(node->right!=NULL)
            q.push(node->right);
        }
    }
    void InOrder_it(Node<T>* r,std::vector<T>& v){
        std::stack<Node<T>*> s;
        Node<T>* curr=r;
        while(curr !=NULL || s.empty()==false){
            while(curr!=NULL){
                s.push(curr);
                curr=curr->left;
            }
            curr=s.top();
            s.pop();
            v.push_back(curr->data);
            curr=curr->right;
        }
    }
    void PreOrder_it(Node<T>* r,std::vector<T>& v){
        if(r==NULL)
        return;
        std::stack<Node<T>*> S;
        S.push(r);
        while(S.empty()==false){
            Node<T>* node=S.top();
            v.push_back(node->data);
            S.pop();
            if(node->right)
            S.push(node->right);
            if(node->left)
            S.push(node->left);
        }
    }
    void PostOrder_it(Node<T>* root,std::vector<T>& vec){
        std::stack<Node<T>*> st;
        Node<T>* curr = root;
        while (true)
        {
            if (curr != nullptr)
            {
                st.push(curr);
                curr = curr->left;
            }
            else
            {
                if (st.empty())
                {
                    break;
                }
                curr = st.top()->right;
                if (curr == nullptr)
                {
                    Node<T>* last = nullptr;
                    while (!st.empty() && st.top()->right == last)
                    {
                        last = st.top();
                        st.pop();
                        vec.push_back(last->data);
                    }
                }
            }
        }
        }
    public:
        MyTree(){}
        
        MyTree(std::vector<T> elements){
            int size=elements.size();
            std::sort(elements.begin(),elements.end());
            root=ConvertBST(elements,0,(size-1));
        }
   
        void insert(T key){
            root=insertKey(root,key);
        }

        void insert(const Node<T> node){
            root=InsertNode(root,node);
        }

        const Node<T>* search(T key){
            return Search(root,key);
        }
        
        const Node<T>* delete_node(T key){
            return DeleteKey(root,key);
        }

        const Node<T>* delete_node(const Node<T> node){
            return DeleteNode(root,node);
        }

        bool isBST(){
            std::vector<T> v;
            v=inorder_rec();
            return std::is_sorted(v.begin(),v.end());
        }
        
        std::vector<T> inorder_rec(){
            std::vector<T> v;
            InorderRec(root,v);
            return v;
        }
        
        std::vector<T> preorder_rec(){
            std::vector<T> v;
            PreorderRec(root,v);
            return v;
        }
        
        std::vector<T> postorder_rec(){
            std::vector<T> v;
            PostorderRec(root,v);
            return v;
        }
        
        std::vector<T> inorder_it(){
            std::vector<T> v;
            InOrder_it(root,v);
            return v;
        }
        
        std::vector<T> preorder_it(){
            std::vector<T> v;
            PreOrder_it(root,v);
            return v;
        }
        
        std::vector<T> postorder_it(){
            std::vector<T> v;
            PostOrder_it(root,v);
            return v;
        }

        std::vector<T> breadth_traversal(){
            std::vector<T> v;
            Breadth_Traversal(root,v);
            return v;
        }

        int get_size(){
            std::vector<T> v=inorder_rec();
            return v.size();
        }

        int get_height(){
            return (Height(root)-1);
        }

        void clear(){
            ClearTree(root);
            root=nullptr;
        }

        ~MyTree(){
            clear();
        }
};

#endif