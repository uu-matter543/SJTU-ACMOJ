#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct node{
    int cnt;
    int gid;
    node* next;
};

int main()
{
    int n;
    cin >> n;
    vector<int> gid(n);
    for (int i=0; i<n; i++) cin >> gid[i];
    
    int q;
    cin >> q;

    node *head = nullptr, *tail = nullptr;
    unordered_map<int, node*> last_pos;

    int cur = 0;
    for (int i=0; i<q; i++)
    {
        int op;
        cin >> op;
        if (op == 0)
        {
            if (cur >= n) continue;
            node* new_person = new node{cur+1, gid[cur], nullptr};
            if (last_pos.find(gid[cur])!=last_pos.end() && last_pos[gid[cur]] != nullptr)
            {
                node *tmp = last_pos[gid[cur]];
                new_person->next = tmp->next;
                tmp->next = new_person;
                if (tmp == tail) tail = new_person;
            }
            else
            {
                if (head == nullptr) head = tail = new_person;
                else
                {
                    tail->next = new_person;
                    tail = new_person;
                }
            }
            last_pos[gid[cur++]] = new_person;
        }
        else
        {
            if (head == nullptr) cout << -1 << endl;
            else
            {
                cout << head->cnt << endl;
                int gid_out = head->gid;
                if (last_pos[gid_out] == head) last_pos[gid_out] = nullptr;
                node* del = head;
                head = head->next;
                delete del;
                if (head == nullptr) tail = nullptr;
            }
        }
    }
    while (head != nullptr)
    {
        node* del = head;
        head = head->next;
        delete del;
    }
    return 0;
}
