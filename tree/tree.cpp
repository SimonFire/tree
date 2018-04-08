#include <iostream>
using namespace std;

/****************/
/*二叉排序树数据结构*/
typedef struct BiTNode
{
	int data;
	struct BiTNode *lchild, *rchild;

}BiTNode, *BiTree;
/****************/
/*创建二叉排序树*/
void CreateBiTree(BiTNode* &T, int num)
{
	if (!T)
	{
		T = new BiTNode;
		(T)->data = num;
		(T)->lchild = (T)->rchild = NULL;
		return;
	}
	if ((T)->data == num)
		return;//不能重复
	else if (num < (T)->data)
		CreateBiTree((T)->lchild, num);
	else
		CreateBiTree((T)->rchild, num);
}

/****************/
/*查找二叉排序树*/
/******find key******/
/*f是T的双亲*,初始值是NULL */
/*****返回p*******/
/*return yes or no */
/************/
bool SerachBiTree(BiTree T, int key, BiTree f, BiTree *p)
{
	if (!T)
	{
		*p = f;
		return false;
	}
	else if (key == T->data)
	{
		*p = T;
		return true;
	}
	else if (key < T->data)
		SerachBiTree(T->lchild, key, T, p);
	else
		SerachBiTree(T->rchild, key, T, p);

}
/****************/
/*删除二叉排序树的节点*/
bool Delet(BiTree *p)
{
	BiTree q, s;
	if ((*p)->rchild == NULL)//没有右子树
	{
		q = *p;
		*p = (*p)->lchild;
		free(q);
	}
	else if ((*p)->lchild == NULL)//没有左子树
	{
		q = *p;
		*p = (*p)->rchild;
		delete q;
	}
	else
	{//有左右子树，找到左节点的最右叶子
		q = *p; s = (*p)->lchild;
		while (s->rchild)
		{
			q = s;
			s = s->rchild;
		}
		(*p)->data = s->data;
		if (q != *p)
			q->rchild = s->lchild;
		else
			q->lchild = s->lchild;
		delete s;

	}
	return true;
}
bool DeletBST(BiTree *T, int key)
{
	if (!*T)
		return false;
	else
	{
		if ((*T)->data == key)
			return Delet(T);
		else if ((*T)->data > key)
			DeletBST(&(*T)->lchild, key);
		else
			DeletBST(&(*T)->rchild, key);
	}
}

int main()
{

	BiTNode* T = NULL;
	CreateBiTree(T, 2);
	CreateBiTree(T, 1);
	CreateBiTree(T, 3);

	cout << (T)->data << endl;
	cout << (T->rchild)->data << endl;
	cout << (T->lchild)->data << endl;

	BiTree p = NULL;
	cout << SerachBiTree(T, 1, NULL, &p);

	cout << DeletBST(&T, 3);
	if ((T->rchild) == NULL)
		cout << "have delete" << endl;
	/*
	cout << "\n程序运行结束,使用回车返回" << endl;
	cin.get(); cin.get();*/
	return 0;
}

