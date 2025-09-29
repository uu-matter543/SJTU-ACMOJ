#include <iostream>
#include <cstdio>
using namespace std;

namespace LIST
{

    struct NODE {
        int val;
        NODE *next;
    };

    NODE *head = nullptr;
    int len = 0;

    void init() {
        head = new NODE();
        head->next = nullptr;
        len = 0;
    }
    NODE* move(int i) {
        NODE* p = head;
        for (int j = 0; j < i; ++j) {
            p = p->next;
        }
        return p;
    }
    void insert(int i, int x) {
        NODE* p = move(i);
        NODE* newNode = new NODE();
        newNode->val = x;
        newNode->next = p->next;
        p->next = newNode;
        len++;
    }
    void remove(int i) {
        NODE* p = move(i);
        NODE* toDelete = p->next;
        p->next = toDelete->next;
        delete toDelete;
        len--;
    }
    void remove_insert(int i) {
        NODE* p = move(i);
        NODE* toMove = p->next;
        p->next = toMove->next;
        NODE* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
        }
        tail->next = toMove;
        toMove->next = nullptr;
    }
    void get_length() {
        cout << len << endl;
    }
    void query(int i) {
        if (i >= len) {
            cout << "-1" << endl;
            return;
        }
        NODE* p = move(i);
        cout << p->next->val << endl;
    }
    void get_max() {
        if (len == 0) {
            cout << "-1" << endl;
            return;
        }
        NODE* p = head->next;
        int maxVal = p->val;
        while (p != nullptr) {
            if (p->val > maxVal) {
                maxVal = p->val;
            }
            p = p->next;
        }
        cout << maxVal << endl;
    }
    void clear() {
        NODE* p = head;
        while (p != nullptr) {
            NODE* toDelete = p;
            p = p->next;
            delete toDelete;
        }
        head = nullptr;
        len = 0;
    }

}
int n;
int main()
{
    cin >> n;
    int op, x, p;
    LIST::init();
    for (int _ = 0; _ < n; ++_)
    {
        cin >> op;
        switch(op) {
            case 0:
                LIST::get_length();
                break;
            case 1:
                cin >> p >> x;
                LIST::insert(p,x);
                break;
            case 2:
                cin >> p;
                LIST::query(p);
                break;
            case 3:
                cin >> p;
                LIST::remove(p);
                break;
            case 4:
                cin >> p;
                LIST::remove_insert(p);
                break;
            case 5:
                LIST::get_max();
                break;
        }
    }
    LIST::clear();
    return 0;
}