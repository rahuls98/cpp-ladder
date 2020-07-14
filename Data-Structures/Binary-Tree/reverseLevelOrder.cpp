#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

#define br() std::cout<<std::endl;

class Node {
public:
    int data;
    Node* left = NULL;
    Node* right = NULL;

    Node(int data) { this->data = data; }
};

std::unordered_map< int, std::vector<Node*> > map;
std::queue<Node*> q;

int power(int base, int exp) {
    int res = 1;
    if(exp==0) return res;
    if(exp==1) return base;

    for(int i=1; i<=exp; i++) 
        res = res*base;

    return res;
}

void levelOrderTraverse(Node* root_ref) {
    int node=0;
    int level=0;
    Node* temp;
    q.push(root_ref);

    while(!q.empty()) {
        map[level] = std::vector<Node*>();
        do {
            temp = q.front();
            map[level].push_back(temp);
            node++;
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            q.pop();

            if(q.empty()) break;
        } while(node != power(2,level));

        node=0;
        level++;
    }
}

void printMap() {
    for(auto p: map) {
        std::cout<<p.first<<": ";
        for(auto node: p.second) {
            std::cout<<node->data<<" ";
        }
        std::cout<<std::endl;
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    levelOrderTraverse(root);
    printMap();
    /* 
    2: 4 5 6 
    1: 2 3 
    0: 1 
    */

    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}