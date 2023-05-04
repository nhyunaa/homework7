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


typedef struct Node { // Node 구조체 정의
	int key; // 정수형 변수 key 선언
	struct Node* llink; // 구조체 포인터 변수 llink 선언
	struct Node* rlink; // 구조체 포인터 변수 rlink 선언
} listNode;



typedef struct Head { // Head 구조체 정의
	struct Node* first; // 구조체 포인터 변수 first선언
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
	char command; // char 형 변수 command 선언
	int key; // 정수형 변수 key 선언
	headNode* headnode=NULL; // head 구조체 포인터 변수 headnode NULL로 초기화

    printf("[----- [노현아] [2022041065] -----]\n");

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
		scanf(" %c", &command); // command입력받기 

		switch(command) {
		case 'z': case 'Z':// 입력받은 command가 z나 Z일때
			initialize(&headnode); // initialize 함수 호출
			break;
		case 'p': case 'P': // 입력받은 command가 p나 P일때
			printList(headnode); // printList 함수 호출
			break;
		case 'i': case 'I':// 입력받은 command가 i나 I일때
			printf("Your Key = ");
			scanf("%d", &key); // key입력받기
			insertNode(headnode, key);// insertNode함수호출
			break;
		case 'd': case 'D':// 입력받은 command가 d나 D일때
			printf("Your Key = ");
			scanf("%d", &key);// key입력받기
			deleteNode(headnode, key); // deleteNode 함수 호출
			break;
		case 'n': case 'N':// 입력받은 command가 n나 N일때
			printf("Your Key = ");
			scanf("%d", &key);// key입력받기
			insertLast(headnode, key); // insertLast함수 호출
			break;
		case 'e': case 'E':// 입력받은 command가 e나 E일때
			deleteLast(headnode); //deleteLast함수 호출
			break;
		case 'f': case 'F':// 입력받은 command가 f나 F일때
			printf("Your Key = ");
			scanf("%d", &key);// key입력받기
			insertFirst(headnode, key); // insertFirst함수 호출
			break;
		case 't': case 'T':// 입력받은 command가 t나 T일때
			deleteFirst(headnode);// deleteFirst함수 호출
			break;
		case 'r': case 'R':// 입력받은 command가 r나 R일때
			invertList(headnode);// invertList함수 호출
			break;
		case 'q': case 'Q':// 입력받은 command가 q나 Q일때
			freeList(headnode); // freeList함수 호출
			break;
		default://입력받은 command가 위의 경우들이 아닐때
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');// 입력받은 command가 q나Q가 아니라면 반복

	return 1;
}


int initialize(headNode** h) {

	
	if(*h != NULL)
		freeList(*h); 
        // headNode가 NULL이 아니라면 freeList함수를 호출하여 할당된 메모리를 해제한다.

	*h = (headNode*)malloc(sizeof(headNode)); // headNode에 대한 포인터 변수 h메모리를 동적할당 
	(*h)->first = NULL; //새로운 공백리스트를 생성
	return 1;
}

int freeList(headNode* h){

	listNode* p = h->first; // 구조체 listNode의 포인터 변수 p에 리스트의 시작 주소 대입

	listNode* prev = NULL;// 구조체 listNode의 포인터 변수 prev를 NULL로 초기화 시켜 새로운 공백 리스트 생성
	while(p != NULL) { // p의 값이 NULL값이 아닐때 실행
		prev = p;// prev에 p 대입
		p = p->rlink;//p값에 p의rlink값을 대입
		free(prev);//할당된 prev메모리를 해제한다
	}
	free(h);//할당된 h메모리 해제
	return 0;
}


void printList(headNode* h) {
	int i = 0; // 정수형 변수 i 선언 후 초기화 
	listNode* p;//구조체 포인터 변수 p선언

	printf("\n---PRINT\n");

	if(h == NULL) { // h값이 NULL이라면 실행
		printf("Nothing to print....\n");
		return;
	}

	p = h->first; //p에 h의 first값 대입

	while(p != NULL) { // p가 NULL값이 아니라면 실행
		printf("[ [%d]=%d ] ", i, p->key); // i와 p의 key 값을 출력한다
		p = p->rlink; //p에 p의 rlink 값을 대입
		i++;//i증가
	}

	printf("  items = %d\n", i);//i출력
}





int insertLast(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode)); 
    //listNode 구조체 포인터 node를 동적할당시킨다.
	node->key = key; //key값을 node의 key값에 대입
	node->rlink = NULL; // node의 rlink값을 NULL값으로 대입
	node->llink = NULL; // node의 llink값을 NULL값으로 대입

	if (h->first == NULL) // h의 first값이 NULL값이라면
	{
		h->first = node; // h의 first값을 node값으로 대입
		return 0;
	}

	listNode* n = h->first; // listNode 구조체 포인터 n의 값을 h의first값으로 대입
	while(n->rlink != NULL) { // n의 rlink값이 NULL값이 아니면 실행
		n = n->rlink; // n의 값을 n의 rlink값으로 대입
	}
	n->rlink = node;// n의 rlink 값을 node값으로 대입
	node->llink = n; // node의 llink값을 n으로 대입
	return 0;
}




int deleteLast(headNode* h) {

	if (h->first == NULL) // h의 first값이 NULL일때
	{
		printf("nothing to delete.\n");
		return 0;
	}

	listNode* n = h->first; // listNode 구조체 포인터 n의 값을 h의 first값으로 대입
	listNode* trail = NULL; // listNode 구조체 포인터 trail값을 NULL값으로 대입

	
	if(n->rlink == NULL) { // n의 rlink값이 NULL값과 동일할때 실행
		h->first = NULL; // h의 first를 NULL로 대입
		free(n); // n의 메모리 동적할당 해제
		return 0;
	}

	
	while(n->rlink != NULL) { // n의 rlink 값이 NULL값과 동일하지 않을때 실행
		trail = n;//trail값을 n으로 대입
		n = n->rlink;//n에 n의 rlink값을 대입
	}


	trail->rlink = NULL; // trail의 rlink 값을 NULL값으로 대입
	free(n);//n의 메모리 동적할당 해제

	return 0;
}




int insertFirst(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));
    //listNode구조체 포인터 node의 메모리를 동적할당시킴
	node->key = key;//node의 key 값을 key 값으로 바꿈
	node->rlink = node->llink = NULL;//node의 rlink값과 node의 llink값을 NULL값으로 

	if(h->first == NULL) // h의 first값이 NULL값일때
	{
		h->first = node; // h의 first값을 node값으로 대입
		return 1;
	}

	node->rlink = h->first; // node의 rlink값을 h의 first값으로 대입
	node->llink = NULL; // node의 llink 값을 NULL값으로 바꾼다

	listNode *p = h->first; // listNode구조체 포인터 p의 값을 h의 first값으로 대입
	p->llink = node;//p의 llink값을 node값으로 대입
	h->first = node;//h의 first값을 node값으로 대입

	return 0;
}


int deleteFirst(headNode* h) {

	if (h->first == NULL) //h의 first값이 NULL값일 경우
	{
		printf("nothing to delete.\n");
		return 0;
	}
	listNode* n = h->first; //listNode구조체 포인터 n의 값을 h의 first값으로 대입
	h->first = n->rlink;// h의 first값을 n의 rlink값으로 대입

	free(n);//동적할당된 n의 메모리를 해제

	return 0;
}



int invertList(headNode* h) {


	if(h->first == NULL) { // h의 first값이  NULL값일때
		printf("nothing to invert...\n");
		return 0;
	}
	listNode *n = h->first; // listNode구조체 포인터 n의 값을 h의 first값으로 대입
	listNode *trail = NULL; // listNode구조체 포인터 trail값을 NULL값으로 대입
	listNode *middle = NULL; // listNode구조체 푄터 middle 값을 NULL값으로 대입

	while(n != NULL){ // n의 값이 NULL 값이 아닐때 실행
		trail = middle;//middle값을 trail에 대입
		middle = n;//n을 middle에 대입
		n = n->rlink; //n의 rlink값을 n에 대입
		middle->rlink = trail;// trail값을 middle의 rlink값에 대입
		middle->llink = n;// n의 값을 middle의 llink값에 대입
	}

	h->first = middle; //middle값을 h의 first값에 대입

	return 0;
}




int insertNode(headNode* h, int key) {

	listNode* node = (listNode*)malloc(sizeof(listNode));
    // listNode구조체node의 메모리를 동적할당시킨다
	node->key = key;//key값을node의 key값으로 대입
	node->llink = node->rlink = NULL;//node의 llink값과 node의 rlink값을 NULL값으로 바꿈

	if (h->first == NULL) // h의 first값이 NULL값이라면 
	{
		h->first = node; // h의 first값을 node로 바꾼다
		return 0;
	}

	listNode* n = h->first; // h의 first값을 listNode 구조체 포인터n에 대입


	while(n != NULL) { // n이 NULL이 아닐 때 실행
		if(n->key >= key) { // n의 key값이 key값보다 크거나 같을때
			
			if(n == h->first) {//n의 값과 h의 first값이 같다면
				insertFirst(h, key);//insertFisrst함수를 호출
			}
             else {//n의 값과 h의 first값이 같지않다면
				node->rlink = n; // node의rlink에 n대입
				node->llink = n->llink; // node의 llink에 n의 llink값 대입
				n->llink->rlink = node; // n의 llink의 rlink에 node대입
			}
			return 0;
		}

		n = n->rlink;//n에 n의 rlink값 대입
	}


	insertLast(h, key); // insertLast함수 호출 
	return 0;
}



int deleteNode(headNode* h, int key) {

	if (h->first == NULL) // 헤드노드가 NULL값일 경우 실행
	{
		printf("nothing to delete.\n");
		return 1;
	}

	listNode* n = h->first; //listNode구조체 포인터 n에 h의 first값을 대입한다

	while(n != NULL) { // n이 NULL값이 아닐때 실행

		if(n->key == key) { // n의 key 값과 key 값이 동일한 경우 
			if(n == h->first) { //n의 값과 h의 first값이 동일한경우
				deleteFirst(h); //deleteFitst함수 호출 
			}
             else if (n->rlink == NULL){ // n의 rlink값이 NULL값인경우
				deleteLast(h); // deleteLast함수 호출
			} 
            else { 
				n->llink->rlink = n->rlink; // n의 왼쪽 노드의 rlink를 n의 오른쪽 노드로 바꿈
				n->rlink->llink = n->llink; // n의 오른쪽 노드의 llink를 n의 왼쪽 노드로 바꿈
				free(n); // n의 메모리 할당을 해제
			}
			return 1;
		}

		n = n->rlink; //n에 n의 rlink값을 대입
	}


	printf("cannot find the node for key = %d\n", key); // key값 출력
	return 1;
}

