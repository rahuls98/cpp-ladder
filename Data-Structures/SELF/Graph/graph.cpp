#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <any>
#include <utility>

#define br() {std::cout<<std::endl;}

class Node {
    std::string NAME;

public:
    Node(std::string Name) { NAME = Name; }

    std::string getName() { return this->NAME; }

    ~Node() { std::cout<<"\nDeleting "<<this->NAME; }
};

class Graph {
    std::vector<Node*> GRAPH_NODES;
    int N_NODES;
    std::unordered_map<Node*, std::vector<Node*>> CONNECTIONS;
    
public:
    Graph() { 
        N_NODES = 0;
        GRAPH_NODES = {}; 
        CONNECTIONS = {};
    }

    void insertNode(Node** ref) {
        GRAPH_NODES.push_back(*ref);
        N_NODES++;
        CONNECTIONS[*ref] = {};
    }

    void insertConnection(Node** src, Node** dest) {
        CONNECTIONS[(*src)].push_back(*dest);
    }

    void printGraph() {
        for(auto &p: CONNECTIONS) {
            br();
            std::cout<<p.first->getName()<<std::endl;

            std::cout<<"Connected to: ";
            if(p.second.size() == 0 )
                std::cout<<"NONE";
            else {
                for(auto n: p.second) {
                    std::cout<<n->getName()<<" ";
                }
            }
        }
    }

    void deleteNode(Node** ref) {
        br();
        int n1 = GRAPH_NODES.size();
        int n2 = CONNECTIONS.size();
        int n3 = N_NODES;

        for(auto i=GRAPH_NODES.begin(); i!=GRAPH_NODES.end(); i++) {
            if(*i == *ref) {
                GRAPH_NODES.erase(i);
                break;
            }
        }

        auto toDel = CONNECTIONS.find(*ref);
        if(toDel != CONNECTIONS.end()) 
            CONNECTIONS.erase(toDel);

        for(auto &c: CONNECTIONS) {
            for(auto i=c.second.begin(); i!=c.second.end(); i++) {
                if(*i == *ref) {
                    c.second.erase(i);
                    break;
                }
            }
        }

        N_NODES--;

        if((n1>GRAPH_NODES.size()) && (n2>CONNECTIONS.size()) && (n3>N_NODES)){
            delete *ref;
        }
    }

    void deleteGraph() {
        br();
        for(auto &n: GRAPH_NODES) {
            delete n;
            N_NODES = 0;
            GRAPH_NODES = {}; 
            CONNECTIONS = {};
        }
    }
};

int main() {
    Graph orgs;
    Node* A = new Node("Org A");
    Node* B = new Node("Org B");
    Node* C = new Node("Org C");

    orgs.insertNode(&A);
    orgs.insertNode(&B);
    orgs.insertNode(&C);

    orgs.insertConnection(&A, &B);
    orgs.insertConnection(&A, &C);
    orgs.insertConnection(&C, &A);

    orgs.printGraph(); 
    /*
        Org C
        Connected to: Org A 
        Org B
        Connected to: NONE
        Org A
        Connected to: Org B Org C
    */
    orgs.deleteNode(&C); br(); // Deleting Org C
    orgs.printGraph();
    /* 
        Org B
        Connected to: NONE
        Org A
        Connected to: Org B 
    */

    orgs.deleteGraph(); br();
    /* 
        Deleting Org A
        Deleting Org B   
    */

    br();
    return 0;
}