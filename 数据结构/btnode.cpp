#include <iostream>
using namespace std;
//*************************************************************************************
//二叉树结点类的定义 
template<typename T> struct BTNode
{
    T data;
    BTNode <T> * Lchild,*Rchild;
    BTNode(T nodeValue = T(), BTNode<T>* leftNode = NULL, BTNode<T>* rightNode = NULL) : data(nodeValue),Lchild(leftNode),Rchild(rightNode){} //可选择参数的默认构造函数 
};
//**************************************************************************************
//二叉树的建立 
template <typename T>
void createBinTree(BTNode<T>*& root)
{
    BTNode<T>* p = root;
    BTNode<T>* k;
    T nodeValue;
    cin >> nodeValue;
    if(nodeValue == -1)
    {
        root = NULL;
    }
    else
    {
        root = new BTNode<T>();
        root->data = nodeValue;
        createBinTree(root->Lchild);
        createBinTree(root->Rchild); 
    }
}
//************************************************************************************
//二叉树的先序遍历
template <typename T>
void preOrder(BTNode<T>*& p)
{
    if(p)
    {
        cout << p->data << " ";
        preOrder(p->Lchild);
        preOrder(p->Rchild);
    }
}
//**************************************************************************************
//二叉树的中序遍历
template <typename T>
void inOrder(BTNode<T> * & p)
{
    if(p)
    {
        inOrder(p->Lchild); cout << p->data << " ";
        inOrder(p->Rchild);
    }
}
//**************************************************************************************
//二叉树的后序遍历
template <typename T>
void levelOrder(BTNode<T>*& p)
{
    if(p)
    {
        levelOrder(p->Lchild);
        levelOrder(p->Rchild);
        cout << p->data << " ";
    }
}
//*************************************************************************************
//统计二叉树中结点的个数
template<typename T>
int countNode(BTNode<T> * & p)
{
    if(p == NULL)
        return 0;
    return 1 + countNode(p->Lchild) + countNode(p->Rchild);
}
//***********************************************************************************
//求二叉树的深度
template<typename T>
int depth(BTNode<T> *& p)
{
    if(p == NULL)
        return -1;
    int h1 = depth(p->Lchild);
    int h2 = depth(p->Rchild);
    if(h1 > h2)
        return (h1+1);
    return h2 + 1;
}
//***********************************************************************************
//二叉树的消毁操作
template<typename T>
BTNode<T>* destroy(BTNode<T>* p) //消毁函数，用来消毁二叉树中的各个结点 
{
    if(p)
    {
        return destroy(p->Lchild);
        return destroy(p->Rchild);
        delete p;
    }
    return p;
}
//********************************************************************************
//主函数的设计
int main()
{
    BTNode<int> * rootNode = NULL;
    int choiced = 0;
    while(true)
    {
        system("cls");
        cout << "\n\n\n ---主界面---\n\n\n";
        cout << " 1、创建二叉树 2、先序遍历二叉树\n";
        cout << " 3、中序遍历二叉树 4、后序遍历二叉树\n";
        cout << " 5、统计结点总数 6、查看树深度 \n";
        cout << " 7、消毁二叉树 0、退出\n\n";
        cout << " 请选择操作：";
        cin >> choiced;
        if(choiced == 0)
            return 0;
        else if(choiced == 1)
        {
            system("cls");
            cout << "请输入每个结点，回车确认，并以-1结束：\n";
            createBinTree(rootNode );
        }
        else if(choiced == 2)
        {
            system("cls");
            cout << "先序遍历二叉树结果：\n";
            preOrder(rootNode);
            cout << endl;
            system("pause");
        }
        else if(choiced == 3)
        {
            system("cls");
            cout << "中序遍历二叉树结果：\n";
            inOrder(rootNode);
            cout << endl;
            system("pause");
        }
        else if(choiced == 4)
        {
            system("cls");
            cout << "后序遍历二叉树结果：\n";
            levelOrder(rootNode);
            cout << endl;
            system("pause");
        }
        else if(choiced == 5)
        {
            system("cls");
            int count = countNode(rootNode);
            cout << "二叉树中结点总数为" << count << endl;
            system("pause");
        }
        else if(choiced == 6)
        {
            system("cls");
            int dep = depth(rootNode);
            cout << "此二叉树的深度为" << dep << endl;
            system("pause");
        }
        else if(choiced == 7)
        {
            system("cls");
            cout << "二叉树已被消毁！\n";
            destroy(rootNode);
            cout  <<  endl;
            system("pause");
        }
        else
        {
            system("cls");
            cout  <<  "\n\n\n\n\n\t错误选择！\n";
        }
    }
}