#include <bits/stdc++.h>
using namespace std;

template<class T>
class BTreeNode
{
private:
    T Ele;
    BTreeNode *parent, *left, *right;
public:
    BTreeNode *parent, *left, *right;
    BTreeNode() {Ele = 0; parent = left = right = NULL;}
    BTreeNode (T Ele, BTreeNode *parent, BTreeNode *left, BTreeNode *right) {
        Ele = Ele;
        parent = parent;
        right = right;
        left = left;
    }
    void setEle(T ele) Ele = ele;
    T getEle() return Ele;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    BTreeNode *A, *B, *C, *D, *E;
    B = new BTreeNode();
    B->setEle("B");
    B->getEle();
    return 0;
}