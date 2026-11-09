/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return head;

        unordered_map<Node*, int> nodes;
        unordered_map<int, Node*> newNodes;
        Node* curr = head;

        int pos = 0;
        while(curr != nullptr) {
            nodes[curr] = pos;
            newNodes[pos++] = new Node(curr->val);
            curr = curr->next;
        }
        
        for(auto &[node, nodePos] : nodes) {
            if(nodes.find(node->next) != nodes.end()) {
                int nextPos = nodes[node->next];
                newNodes[nodePos]->next = newNodes[nextPos];
            }

            if(nodes.find(node->random) != nodes.end()) {
                int randomPos = nodes[node->random];
                newNodes[nodePos]->random = newNodes[randomPos];
            }
        }

        return newNodes[0];
    }
};
