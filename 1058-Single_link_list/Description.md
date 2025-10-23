# 1058 单链表

## 1058-题目描述

需要实现以下六种操作，分别标号为操作0~5：（注意这里的 $i$ 都为 **0-base**）

- 0 返回链表长度；
- 1 在位置 $i$ 插入一个数。注意这里是指插入的数在插入后处于位置 $i$，即插入在现在位置 $i$ 数字的前面；
- 2 输出位置 $i$ 的数。如果 $i$ 超出链表长度，输出 $-1$；
- 3 删除位置 $i$ 的数，整个链表长度减 $1$；
- 4 删除位置 $i$ 的数并插入至链表的尾端；
- 5 输出链表中最大的数。如果表为空，输出 $-1$；

注意：为防止内存泄漏，需要在程序最后删除整个列表。

链表的要求如下：

- 必须使用指针和结构体；
- 在单链表中，每个结点由一个数据元素、一个后继指针组成，后继指针指向存储该元素直接后继的结点；
- 存储一个单链表只需要一个指向头结点的指针；
- 可以使用单独的变量记录链表长度；

## 1058-输入格式

第一行一个数 $n$ 表示操作的个数。

之后 $n$ 行，每行第一个数 $op$ ($op=0,1,2,3,4,5$)代表操作编号，分别对应前文中的编号。

- 如果 $op$ 为1，其后会输入两个整数 $p,x$，表示在 $p$ 位置插入的数值为 $x$；
- 如果 $op$ 为2，其后会输入一个整数 $p$，表示需要输出链表中 $p$ 位置结点的值；
- 如果 $op$ 为3或4，其后会输入一个整数 $p$，表示你需要删除链表中 $p$ 位置的值。

数据保证插入删除操作不会操作无效位置。

## 1058-输出格式

- 对于操作1,3,4，不需要输出任何内容；
- 对于操作0，输出一个整数，表示链表长度；
- 对于操作2，输出一个整数，表示第 $i$ 个数；
- 对于操作5，输出一个整数，表示链表中最大的数；

每一个操作输出后要求换行。

### 1058-程序模板

```cpp
//sample.cpp

#include <iostream>
#include <cstdio>
using namespace std;

namespace LIST
{

    struct NODE {
        // TODO
    };

    NODE *head = nullptr;
    int len = 0;

    void init() {
        // TODO
    }
    NODE* move(int i) {
        // TODO
    }
    void insert(int i, int x) {
        // TODO
    }
    void remove(int i) {
        // TODO
    }
    void remove_insert(int i) {
        //TODO
    }
    void get_length() {
        // TODO
    }
    void query(int i) {
        // TODO
    }
    void get_max() {
        // TODO
    }
    void clear() {
        // TODO
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
```
