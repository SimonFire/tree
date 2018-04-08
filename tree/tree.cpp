#include <iostream>
using namespace std;

/****************/
/*�������������ݽṹ*/
typedef struct BiTNode
{
	int data;
	struct BiTNode *lchild, *rchild;

}BiTNode, *BiTree;
/****************/
/*��������������*/
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
		return;//�����ظ�
	else if (num < (T)->data)
		CreateBiTree((T)->lchild, num);
	else
		CreateBiTree((T)->rchild, num);
}

/****************/
/*���Ҷ���������*/
/******find key******/
/*f��T��˫��*,��ʼֵ��NULL */
/*****����p*******/
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
/*ɾ�������������Ľڵ�*/
bool Delet(BiTree *p)
{
	BiTree q, s;
	if ((*p)->rchild == NULL)//û��������
	{
		q = *p;
		*p = (*p)->lchild;
		free(q);
	}
	else if ((*p)->lchild == NULL)//û��������
	{
		q = *p;
		*p = (*p)->rchild;
		delete q;
	}
	else
	{//�������������ҵ���ڵ������Ҷ��
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
	cout << "\n�������н���,ʹ�ûس�����" << endl;
	cin.get(); cin.get();*/
	return 0;
}

