#include <bits/stdc++.h>
using namespace std;

// Hàm cmp1 cho max-heap
bool cmp1(int a, int b) {
    return a > b;
}

// Hàm cmp2 cho min-heap
bool cmp2(int a, int b) {
    return a < b; 
}

template <class T>
class Tree {
private:
    class Node {  
    public:
        T elem;
        int n;
        Node* left;
        Node* right;

        Node(T e, Node* L = nullptr, Node* R = nullptr){
            elem = e;
            left = L;
            right = R;
            n = 1 + (L ? L->n : 0) + (R ? R->n : 0);
        }
    };

    Node* root;
    bool (*cmp)(T, T); // Con trỏ hàm để lưu hàm so sánh

    void push(Node*& H, T x) {
        if (!H || cmp(x, H->elem)) {
            H = new Node(x, H, nullptr);
        } else {
            H->n++;
            if (!H->left) {
                H->left = new Node(x);
            } else if (!H->right) {
                H->right = new Node(x);
            } else {
                push((H->left->n < H->right->n) ? H->left : H->right, x);
            }
        }
    }

     void pop(Node*& H) {
        if (!H) return;
        if (!H->left && !H->right) {
            
            delete H;
            H = nullptr;
        } else if (!H->right || (H->left && cmp(H->left->elem, H->right->elem))) {
            H->elem = H->left->elem;
            pop(H->left);
            H->n--;
        } else {    
            H->elem = H->right->elem;
            pop(H->right);
            H->n--;
        }
    }

public:
    Tree(bool (*compareFunc)(T, T))
    {
        root = nullptr; 
        cmp = compareFunc;
    }

    void push(T x) {
        push(root, x);
    }

    T top() const {
        if (!root){
            cout << "Heap is empty!\n";
            return 0;
        }
        return root->elem;
    }

    void pop() {
        pop(root);
    }

    bool empty() const {
        return root == nullptr;
    }

    int size() const {
        return root ? root->n : 0;
    }

    ~Tree() {
        while (root) {
            pop();
        }
    }
};

int main() {
    // Sử dụng cmp1 cho max-heap
    Tree<int> max_heap(cmp1);
    vector<int> nums = {47, 28, 68, 48, 32, 17, 21, 75, 37, 63, 48};

    for (int x : nums) {
        max_heap.push(x);
    }

    cout << "Max-Heap (cmp1): ";
    while (!max_heap.empty()) {
        cout << max_heap.top() << " ";
        max_heap.pop();
    }
    cout << endl;

    // Sử dụng cmp2 cho min-heap : noi thanh kim loai
    Tree<int> min_heap(cmp2);
    int n; cin >> n;
    for(int i = 0; i< n; i++){
        int x; cin >> x;
        min_heap.push(x);
    }
    // while(min_heap.size()){
    //     cout << min_heap.top() << ' ';
    //     min_heap.pop();
    // }
    int tong = 0;
    while(min_heap.size() > 1){
        int tmp1 = min_heap.top();
        min_heap.pop();
        int tmp2 = min_heap.top();
        min_heap.pop();
        int tmp = tmp1 + tmp2;
        tong += tmp;
        min_heap.push(tmp);
    }
    cout << tong;
}
