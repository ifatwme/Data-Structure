#include <iostream>
using namespace std;
#define N 10

////////// definitions ///////////
struct binarytree {
    char data;
    struct binarytree *rchild, *lchild;
} *mother;

struct tree {
    int data;
    struct tree *lchild, *rchild;
    int lthread, rthread;
}*start, *tail, *temp;

class Tree {
public:
    int data;
    tree *lchild;
    tree *rchild;
    int rthread, lthread;

    Tree(int value) {
        data = value;

        lchild = NULL;
        rchild = NULL;

        // when thread=0 -> false | thread=1 -> true
        rthread = 0;
        lthread = 0;
    }
};

// if found = 0 -> false | if found = 1 -> true
// each node indicated as right(R) or left(L) or mother(M) node.
////////////// trees //////////////
// inorder -> LMR
void inorder(struct binarytree *node) {
    if (node -> lchild != NULL)
        inorder(node -> lchild);

    cout << node -> data;

    if (node -> rchild != NULL)
        inorder(node -> rchild);
}

// preorder -> MLR
void preorder(struct binarytree *node) {
    cout << node -> data;

    if (node -> lchild != NULL)
        preorder(node -> lchild);
    
    if (node -> rchild != NULL)
        preorder(node -> rchild);
}

// postorder -> LRM
void postorder(struct binarytree *node) {
    if (node -> lchild != NULL)
        postorder(node -> lchild);

    if (node -> rchild != NULL)
        postorder(node -> rchild);

    cout << node -> data;        
}

// inverted inorder -> RML
void invinorder(struct binarytree *node) {
    if (node -> rchild != NULL)
        invinorder(node -> rchild);
    
    cout << node -> data;

    if (node -> lchild != NULL)
        invinorder(node -> lchild);
}

// inverted preorder -> MRL
void invpreorder(struct binarytree *node) {
    cout << node -> data;

    if (node -> rchild != NULL)
        invpreorder(node -> rchild);

    if (node -> lchild != NULL)
        invpreorder(node -> lchild);
}

// inverted postorder -> RLM
void invpostorder(struct binarytree *node) {
    if (node -> rchild != NULL)
        invpostorder(node -> rchild);
    
    if (node -> lchild != NULL)
        invpostorder(node -> lchild);

    cout << node -> data;
}

//////// implementations using trees /////////

// sorting N nums using a tree and inorder iteration.
void CreateUpsortedTree(struct binarytree *mother)
{
    struct binarytree *p, *q, *r;
    mother = new struct binarytree; // great mother
    mother -> lchild = NULL;
    mother -> rchild = NULL;
    
    cout << "Enter a num: " << endl;
    cin >> mother -> data;

    for (int i = 1; i < N; i++) {
        q = new struct binarytree; // random child
        q -> rchild = NULL;
        q -> lchild = NULL;

        cout << "Enter a num: " << endl;
        cin >> q -> data;

        p = mother;
        do {
            if (q -> data > p -> data)
                {r = p -> rchild;} // iteration
            else 
                {r = p -> lchild;} // iteration

            if (r != NULL)
                p = r; // change mother to iterate deeper
        } while (r != NULL); // when there is no remaining child to asign as mother

        if (q -> data > p -> data)
            {p -> rchild = q;} // if bigger then assign as right child
        else
            {p -> lchild = q;} // if smaller then assign as left child
    }
    inorder(mother);
}

// implementing infix expression using tree
struct binarytree *CreateBTformula(int i, char* pre) {
    struct binarytree *s;
    
    if (pre[i] != '\0') {
        switch(pre[i]) {
            case '+':
                s = new struct binarytree;
                s -> data = pre[i];
                s -> lchild = CreateBTformula(i + 1, pre);
                s -> rchild = CreateBTformula(i + 1, pre);
                return s;
                break;
            case '*':
                s = new struct binarytree;
                s -> data = pre[i];
                s -> lchild = CreateBTformula(i + 1, pre);
                s -> rchild = CreateBTformula(i + 1, pre);
                return s;
                break;
            case '-':
                s = new struct binarytree;
                s -> data = pre[i];
                s -> lchild = CreateBTformula(i + 1, pre);
                s -> rchild = CreateBTformula(i + 1, pre);
                return s;
                break;
            case '/':
                s = new struct binarytree;
                s -> data = pre[i];
                s -> lchild = CreateBTformula(i + 1, pre);
                s -> rchild = CreateBTformula(i + 1, pre);
                return s;
                break;
            case '%':
                s = new struct binarytree;
                s -> data = pre[i];
                s -> lchild = CreateBTformula(i + 1, pre);
                s -> rchild = CreateBTformula(i + 1, pre);
                return s;
                break;
            default: 
                s = new struct binarytree;
                s -> data = pre[i];
                s -> lchild = NULL;
                s -> rchild = NULL;
                return s;
        }
    }
}

// assign a real number instead of letters
float evaltree (struct binarytree *mother) {
    switch (mother -> data) {
        case '+':
            return evaltree(mother -> lchild) + evaltree(mother -> rchild);
            break;
        case '-':
            return evaltree(mother -> lchild) - evaltree(mother -> rchild);
            break;
        case '*':
            return evaltree(mother -> lchild) * evaltree(mother -> rchild);
            break;
        case '/':
            return evaltree(mother -> lchild) / evaltree(mother -> rchild);
            break;
        default:
            return (mother -> data - 48); //ASCI code
    }
}

///////////// threaded binary tree ////////////// 
// if link is: real -> thread=0, threaded -> thread=1 
void th_inorder(struct tree *mother) {
    struct tree *q;
    q = mother;
    if (mother -> lchild != NULL)
        th_inorder(mother -> lchild);
    else {
        mother -> lchild = q;
        mother -> lthread = 1;
    }
    if (mother -> rchild != NULL) {
        mother -> rchild = q;
        mother -> rthread = 1;
    } else {
        th_inorder(mother -> rchild);
    }
}

// iteration of threaded tree and then print data: left -> mother -> right
void i_th_inorder(struct tree *mother) {
    temp = mother;
    do {
        for (;temp -> lthread == 1; temp = temp -> lchild) {
            cout << temp -> data;
            temp = temp -> rchild; // reach mother
            cout << temp -> data;
            temp = temp -> rchild; // reach mother of mother
        }
    } while (temp != mother); // iterate until reach great mother
}

// copying threaded tree
struct binarytree copy_th_tree(struct binarytree *mother) {
    struct binarytree *q;
    q = new struct binarytree;
    q -> data = mother -> data;

    if (mother -> lchild != NULL) {
        q -> lchild = mother -> lchild;
        copy_th_tree(q -> lchild);
    } else {
        q -> lchild = NULL;
    }

    if (mother -> rchild != NULL) {
        q -> rchild = mother -> rchild;
        copy_th_tree(q -> rchild);
    } else {
        q -> rchild = NULL;
    }
}

// comparing threaded trees if similar -> 1 if not 0
int comp_th_tree(struct binarytree *mother1, struct binarytree *mother2) {
    if (mother1 -> data != mother2 -> data) {
        return 0;
    } else {
        return (comp_th_tree(mother1 -> lchild, mother2 -> lchild) && comp_th_tree(mother1 -> rchild, mother2 -> lchild));
    }

    if((mother1 == NULL) && (mother2 == NULL)) {
        return 1;
    }
}

// inorder non-recursive iteration of threaded tree -> LMR
void i_th_nrec_inorder(struct binarytree *mother) { // to be compatible with type of mystack
    Stack mystack = Stack();
    int top = -1;
    for (; ;) {
        for (; mother != NULL; mother -> lchild) {
            mystack.push(mother -> data);
            top++;
        }
        if (top > -1) {
            mother -> data = mystack.pop();
            top--;
        }
        else
            break;
        cout << mother -> data;
        mother = mother -> rchild;
    }
}

//  preorer non-recursive iteration of threaded tree -> MLR
void i_th_nrec_preorder(struct binarytree *mother) {
    int top = -1;
    Stack mystack = Stack();
    do {
        do {
            cout << mother -> data;
            mystack.push(mother -> data);
            mother = mother -> lchild;
        } while (mother != NULL);
        do {
            mother -> data = mystack.pop();
        } while (mother -> rchild == NULL && top > -1);
        
        mother = mother -> rchild;
    } while (mother != NULL);
}

// postorder non-recursive iteration of threaded tree -> LRM
void i_th_nrec_postorder() {
    int top = -1;
    Stack mystack = Stack();
    do {
        do{
            mystack.push(mother -> data);
            if (mother -> rchild != NULL) {
                mystack.push((mother -> rchild) -> data);
                mother = mother -> lchild;
            }
        } while (mother != NULL);
        mother -> data = mystack.pop();
        while (mother != NULL) {
            cout << mother -> data;
            mother -> data = mystack.pop();
        }
    }while (mother != NULL);
}

// push and pop from stack flag=0 -> child, flag=1 -> parent
struct stack2{
    int top;
    struct tree *p;
    int flag;
}mystack2[N];

void push(struct tree *m, char &thread) {
    Stack mystack = Stack();
    int top = -1;
    if (top == N-1) {
        cout << "stack is full" << endl;
    } else {
        top++;
        mystack2[top].p = m;
        mystack2[top].flag = thread;
    }
}

struct tree *pop(char &thread) {
    int top = -1;
    if (top == -1) {
        cout << "stack is empty!";
    } else {
        thread = mystack2->flag;
        return mystack2[top--].p;
    }
}

/////////// stack //////////////
struct stack
{
    int data;
    struct stack *left, *right;
};

class Stack
{
public:
    struct stack *start, *top, *temp;
    int top2;

    Stack();
    void push(int val);
    int pop();
    void freeStack();
};

Stack::Stack()
{
    start = new struct stack;
    start -> right = NULL;
    start -> left = NULL;
    top = start;
    top2 = -1;
}

void Stack::push(int value)
{
    if (top2 == N) {
        cout << "stack is full" << endl;
        return;
    }
    
    temp = new struct stack;
    temp -> data = value;

    temp -> left = top;
    temp -> right = NULL;
    
    top -> right = temp;
    top = temp;

    top2++;
}

int Stack::pop()
{
    int value;
    if (top == start || top2 == -1)
    {
        cout << "the stack is empty!" << endl;
        return;
    }
        temp = top -> left;
        temp -> right = NULL;
        top -> left = NULL;

        value = top -> data;

        free(top);
        top = temp;
        return value;
}

// if start == top then it's empty
void Stack::freeStack()
{
    while(start != top)
    {
        temp = start;
        start = start -> right;
        free(temp);
    }
    top2 = -1;
}

int main()
{
    int length, i;
    cout << "enter a length for stack: " << endl;
    cin >> length;

    Stack mystack = Stack();

    for (i = 0; i < length; i++)
    {
        mystack.push(i);
    }

    for(i = 0; i < length; i++)
    {
        mystack.pop();
    }

    mystack.freeStack();
    mystack.pop();

    return 0;
}