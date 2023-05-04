/*
 *  doubly-linked-list.c
 *
 *  Doubly Linked List
 *
 *  Data Structures
 *  School of Computer Science 
 *  at Chungbuk National University
 *
 */



#include<stdio.h>
#include<stdlib.h>


typedef struct Node { // Node ����ü ����
	int key; // ������ ���� key ����
	struct Node* llink; // ����ü ������ ���� llink ����
	struct Node* rlink; // ����ü ������ ���� rlink ����
} listNode;



typedef struct Head { // Head ����ü ����
	struct Node* first; // ����ü ������ ���� first����
}headNode;




int initialize(headNode** h);


int freeList(headNode* h);

int insertNode(headNode* h, int key);
int insertLast(headNode* h, int key);
int insertFirst(headNode* h, int key);
int deleteNode(headNode* h, int key);
int deleteLast(headNode* h);
int deleteFirst(headNode* h);
int invertList(headNode* h);

void printList(headNode* h);


int main()
{
	char command; // char �� ���� command ����
	int key; // ������ ���� key ����
	headNode* headnode=NULL; // head ����ü ������ ���� headnode NULL�� �ʱ�ȭ

    printf("[----- [������] [2022041065] -----]\n");

	do{
		printf("----------------------------------------------------------------\n");
		printf("                     Doubly Linked  List                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command); // command�Է¹ޱ� 

		switch(command) {
		case 'z': case 'Z':// �Է¹��� command�� z�� Z�϶�
			initialize(&headnode); // initialize �Լ� ȣ��
			break;
		case 'p': case 'P': // �Է¹��� command�� p�� P�϶�
			printList(headnode); // printList �Լ� ȣ��
			break;
		case 'i': case 'I':// �Է¹��� command�� i�� I�϶�
			printf("Your Key = ");
			scanf("%d", &key); // key�Է¹ޱ�
			insertNode(headnode, key);// insertNode�Լ�ȣ��
			break;
		case 'd': case 'D':// �Է¹��� command�� d�� D�϶�
			printf("Your Key = ");
			scanf("%d", &key);// key�Է¹ޱ�
			deleteNode(headnode, key); // deleteNode �Լ� ȣ��
			break;
		case 'n': case 'N':// �Է¹��� command�� n�� N�϶�
			printf("Your Key = ");
			scanf("%d", &key);// key�Է¹ޱ�
			insertLast(headnode, key); // insertLast�Լ� ȣ��
			break;
		case 'e': case 'E':// �Է¹��� command�� e�� E�϶�
			deleteLast(headnode); //deleteLast�Լ� ȣ��
			break;
		case 'f': case 'F':// �Է¹��� command�� f�� F�϶�
			printf("Your Key = ");
			scanf("%d", &key);// key�Է¹ޱ�
			insertFirst(headnode, key); // insertFirst�Լ� ȣ��
			break;
		case 't': case 'T':// �Է¹��� command�� t�� T�϶�
			deleteFirst(headnode);// deleteFirst�Լ� ȣ��
			break;
		case 'r': case 'R':// �Է¹��� command�� r�� R�϶�
			invertList(headnode);// invertList�Լ� ȣ��
			break;
		case 'q': case 'Q':// �Է¹��� command�� q�� Q�϶�
			freeList(headnode); // freeList�Լ� ȣ��
			break;
		default://�Է¹��� command�� ���� ������ �ƴҶ�
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');// �Է¹��� command�� q��Q�� �ƴ϶�� �ݺ�

	return 1;
}


int initialize(headNode** h) {

	
	if(*h != NULL)
		freeList(*h); 
        // headNode�� NULL�� �ƴ϶�� freeList�Լ��� ȣ���Ͽ� �Ҵ�� �޸𸮸� �����Ѵ�.

	*h = (headNode*)malloc(sizeof(headNode)); // headNode�� ���� ������ ���� h�޸𸮸� �����Ҵ� 
	(*h)->first = NULL; //���ο� ���鸮��Ʈ�� ����
	return 1;
}

int freeList(headNode* h){

	listNode* p = h->first; // ����ü listNode�� ������ ���� p�� ����Ʈ�� ���� �ּ� ����

	listNode* prev = NULL;// ����ü listNode�� ������ ���� prev�� NULL�� �ʱ�ȭ ���� ���ο� ���� ����Ʈ ����
	while(p != NULL) { // p�� ���� NULL���� �ƴҶ� ����
		prev = p;// prev�� p ����
		p = p->rlink;//p���� p��rlink���� ����
		free(prev);//�Ҵ�� prev�޸𸮸� �����Ѵ�
	}
	free(h);//�Ҵ�� h�޸� ����
	return 0;
}


void printList(headNode* h) {
	int i = 0; // ������ ���� i ���� �� �ʱ�ȭ 
	listNode* p;//����ü ������ ���� p����

	printf("\n---PRINT\n");

	if(h == NULL) { // h���� NULL�̶�� ����
		printf("Nothing to print....\n");
		return;
	}

	p = h->first; //p�� h�� first�� ����

	while(p != NULL) { // p�� NULL���� �ƴ϶�� ����
		printf("[ [%d]=%d ] ", i, p->key); // i�� p�� key ���� ����Ѵ�
		p = p->rlink; //p�� p�� rlink ���� ����
		i++;//i����
	}

	printf("  items = %d\n", i);//i���
}





int insertLast(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode)); 
    //listNode ����ü ������ node�� �����Ҵ��Ų��.
	node->key = key; //key���� node�� key���� ����
	node->rlink = NULL; // node�� rlink���� NULL������ ����
	node->llink = NULL; // node�� llink���� NULL������ ����

	if (h->first == NULL) // h�� first���� NULL���̶��
	{
		h->first = node; // h�� first���� node������ ����
		return 0;
	}

	listNode* n = h->first; // listNode ����ü ������ n�� ���� h��first������ ����
	while(n->rlink != NULL) { // n�� rlink���� NULL���� �ƴϸ� ����
		n = n->rlink; // n�� ���� n�� rlink������ ����
	}
	n->rlink = node;// n�� rlink ���� node������ ����
	node->llink = n; // node�� llink���� n���� ����
	return 0;
}




int deleteLast(headNode* h) {

	if (h->first == NULL) // h�� first���� NULL�϶�
	{
		printf("nothing to delete.\n");
		return 0;
	}

	listNode* n = h->first; // listNode ����ü ������ n�� ���� h�� first������ ����
	listNode* trail = NULL; // listNode ����ü ������ trail���� NULL������ ����

	
	if(n->rlink == NULL) { // n�� rlink���� NULL���� �����Ҷ� ����
		h->first = NULL; // h�� first�� NULL�� ����
		free(n); // n�� �޸� �����Ҵ� ����
		return 0;
	}

	
	while(n->rlink != NULL) { // n�� rlink ���� NULL���� �������� ������ ����
		trail = n;//trail���� n���� ����
		n = n->rlink;//n�� n�� rlink���� ����
	}


	trail->rlink = NULL; // trail�� rlink ���� NULL������ ����
	free(n);//n�� �޸� �����Ҵ� ����

	return 0;
}




int insertFirst(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));
    //listNode����ü ������ node�� �޸𸮸� �����Ҵ��Ŵ
	node->key = key;//node�� key ���� key ������ �ٲ�
	node->rlink = node->llink = NULL;//node�� rlink���� node�� llink���� NULL������ 

	if(h->first == NULL) // h�� first���� NULL���϶�
	{
		h->first = node; // h�� first���� node������ ����
		return 1;
	}

	node->rlink = h->first; // node�� rlink���� h�� first������ ����
	node->llink = NULL; // node�� llink ���� NULL������ �ٲ۴�

	listNode *p = h->first; // listNode����ü ������ p�� ���� h�� first������ ����
	p->llink = node;//p�� llink���� node������ ����
	h->first = node;//h�� first���� node������ ����

	return 0;
}


int deleteFirst(headNode* h) {

	if (h->first == NULL) //h�� first���� NULL���� ���
	{
		printf("nothing to delete.\n");
		return 0;
	}
	listNode* n = h->first; //listNode����ü ������ n�� ���� h�� first������ ����
	h->first = n->rlink;// h�� first���� n�� rlink������ ����

	free(n);//�����Ҵ�� n�� �޸𸮸� ����

	return 0;
}



int invertList(headNode* h) {


	if(h->first == NULL) { // h�� first����  NULL���϶�
		printf("nothing to invert...\n");
		return 0;
	}
	listNode *n = h->first; // listNode����ü ������ n�� ���� h�� first������ ����
	listNode *trail = NULL; // listNode����ü ������ trail���� NULL������ ����
	listNode *middle = NULL; // listNode����ü Ǥ�� middle ���� NULL������ ����

	while(n != NULL){ // n�� ���� NULL ���� �ƴҶ� ����
		trail = middle;//middle���� trail�� ����
		middle = n;//n�� middle�� ����
		n = n->rlink; //n�� rlink���� n�� ����
		middle->rlink = trail;// trail���� middle�� rlink���� ����
		middle->llink = n;// n�� ���� middle�� llink���� ����
	}

	h->first = middle; //middle���� h�� first���� ����

	return 0;
}




int insertNode(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));
    // listNode����ünode�� �޸𸮸� �����Ҵ��Ų��
	node->key = key;//key����node�� key������ ����
	node->llink = node->rlink = NULL;//node�� llink���� node�� rlink���� NULL������ �ٲ�

	if (h->first == NULL) // h�� first���� NULL���̶�� 
	{
		h->first = node; // h�� first���� node�� �ٲ۴�
		return 0;
	}

	listNode* n = h->first; // h�� first���� listNode ����ü ������n�� ����


	while(n != NULL) { // n�� NULL�� �ƴ� �� ����
		if(n->key >= key) { // n�� key���� key������ ũ�ų� ������
			
			if(n == h->first) {//n�� ���� h�� first���� ���ٸ�
				insertFirst(h, key);//insertFisrst�Լ��� ȣ��
			}
             else {//n�� ���� h�� first���� �����ʴٸ�
				node->rlink = n; // node��rlink�� n����
				node->llink = n->llink; // node�� llink�� n�� llink�� ����
				n->llink->rlink = node; // n�� llink�� rlink�� node����
			}
			return 0;
		}

		n = n->rlink;//n�� n�� rlink�� ����
	}


	insertLast(h, key); // insertLast�Լ� ȣ�� 
	return 0;
}



int deleteNode(headNode* h, int key) {

	if (h->first == NULL) // ����尡 NULL���� ��� ����
	{
		printf("nothing to delete.\n");
		return 1;
	}

	listNode* n = h->first; //listNode����ü ������ n�� h�� first���� �����Ѵ�

	while(n != NULL) { // n�� NULL���� �ƴҶ� ����

		if(n->key == key) { // n�� key ���� key ���� ������ ��� 
			if(n == h->first) { //n�� ���� h�� first���� �����Ѱ��
				deleteFirst(h); //deleteFitst�Լ� ȣ�� 
			}
             else if (n->rlink == NULL){ // n�� rlink���� NULL���ΰ��
				deleteLast(h); // deleteLast�Լ� ȣ��
			} 
            else { 
				n->llink->rlink = n->rlink; // n�� ���� ����� rlink�� n�� ������ ���� �ٲ�
				n->rlink->llink = n->llink; // n�� ������ ����� llink�� n�� ���� ���� �ٲ�
				free(n); // n�� �޸� �Ҵ��� ����
			}
			return 1;
		}

		n = n->rlink; //n�� n�� rlink���� ����
	}


	printf("cannot find the node for key = %d\n", key); // key�� ���
	return 1;
}

