//
// Created by 채민균 on 2017. 6. 29..
//

#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int num;
    vector<Node *> childs;
};

struct Root {
    Node *rootNode;
};

vector<Node> v;
int ans = 0, m;
Root root;

void traversal(int num) {
    if (num == m) {
        return;
    }
    int size = v[num].childs.size();
    if (size == 0) {
        ++ans;
        return;
    }
    if (size == 1) {
        if (v[num].childs[0]->num == m) {
            ++ans;
            return;
        }
    }
    for (int i = 0; i < size; ++i) {
        traversal(v[num].childs[i]->num);
    }
}

int main() {
    int num;
    scanf("%d", &num);
    v.resize(num);
    for (int i = 0; i < num; ++i) {
        int parent;
        scanf("%d", &parent);
        v[i].num = i;
        if (parent != -1) {
            v[parent].childs.push_back(&v[i]);
        } else {
            root.rootNode = &v[i];
        }
    }
    scanf("%d", &m);
    traversal(root.rootNode->num);
    printf("%d", ans);
    return 0;
}
