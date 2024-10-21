#include <stdio.h>
#include <stdlib.h>

// 트리 노드 구조체
typedef struct TreeNode {
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
} TreeNode;
// 스택 노드 구조체
typedef struct stackNode {
	TreeNode* tNode;
	struct stackNode* next;
} stackNode;
stackNode* createStack() {
	return NULL;
}
int isEmptyStack(stackNode* top) {
	return (top == NULL); // 스택이 비었으면 1 을 반환, 그렇지 않으면 0 을 반환
}
void push(stackNode** top, TreeNode* tNode) {
	stackNode* newNode = (stackNode*)malloc(sizeof(stackNode));
	if (!newNode) {
		printf("메모리 할당 실패\n");
		return;
	}
	newNode->tNode = tNode;
	newNode->next = *top;
	*top = newNode;
}
TreeNode* pop(stackNode** top) {
	if (isEmptyStack(*top)) {
		printf("스택이 비어 있습니다\n");
		return NULL;
	}
	stackNode* temp = *top;
	TreeNode* poppedNode = temp->tNode;
	*top = temp->next;
	free(temp);
	return poppedNode;
}

void deleteStack(stackNode** top) {
	stackNode* temp;
	while (*top) {
		temp = *top;
		*top = (*top)->next;
		free(temp);
	}
}
// 큐 노드 구조체
typedef struct queueNode {
	TreeNode* tNode;
	struct queueNode* next;
} queueNode;

typedef struct Queue {
	queueNode* front, * rear;
} Queue;

Queue* createQueue() {
	Queue* q = (Queue*)malloc(sizeof(Queue));
	if (!q) {
		printf("메모리 할당 실패\n");
		return NULL;
	}
	q->front = q->rear = NULL;
	return q;
}

queueNode* createQueueNode(TreeNode* tNode) {
	queueNode* newNode = (queueNode*)malloc(sizeof(queueNode));
	if (!newNode) {
		printf("메모리 할당 실패\n");
		return NULL;
	}
	newNode->tNode = tNode;
	newNode->next = NULL;
	return newNode;
}

int isEmptyQueue(Queue* q) {
	return (q->front == NULL);
}

void enqueue(Queue* q, TreeNode* tNode) {
	queueNode* newNode = createQueueNode(tNode);
	if (!newNode) return;

	if (q->rear) {
		q->rear->next = newNode;
	}
	q->rear = newNode;

	if (q->front == NULL) {
		q->front = newNode;
	}
}

TreeNode* dequeue(Queue* q) {
	if (isEmptyQueue(q)) {
		printf("큐가 비어 있습니다\n");
		return NULL;
	}
	queueNode* temp = q->front;
	TreeNode* tNode = temp->tNode;
	q->front = q->front->next;
	if (q->front == NULL) {
		q->rear = NULL;
	}
	free(temp);
	return tNode;
}

void deleteQueue(Queue* q) {
	queueNode* temp;
	while (q->front) {
		temp = q->front;
		q->front = q->front->next;
		free(temp);
	}
	free(q);
}
void Postorder_iter(TreeNode* root);
void Inorder_iter(TreeNode* root);
void Preorder_iter(TreeNode* root);
void Postorder_rec(TreeNode* root);
void Inorder_rec(TreeNode* root);
void Preorder_rec(TreeNode* root);

int main() {
	TreeNode* root = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* node1 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* node2 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* node3 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* node4 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* node5 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* node6 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* node7 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* node8 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* node9 = (TreeNode*)malloc(sizeof(TreeNode));
	TreeNode* node10 = (TreeNode*)malloc(sizeof(TreeNode));
	root->data = 11;
	root->left = node1;
	root->right = node2;
	node1->data = 5;
	node1->left = node3;
	node1->right = node4;
	node2->data = 10;
	node2->left = node5;
	node2->right = node6;
	node3->data = 3;
	node3->left = node7;
	node3->right = node8;
	node4->data = 4;
	node4->left = NULL;
	node4->right = NULL;
	node5->data = 6;
	node5->left = NULL;
	node5->right = NULL;
	node6->data = 9;
	node6->left = node9;
	node6->right = node10;
	node7->data = 1;
	node7->left = NULL;
	node7->right = NULL;
	node8->data = 2;
	node8->left = NULL;
	node8->right = NULL;
	node9->data = 7;
	node9->left = NULL;
	node9->right = NULL;
	node10->data = 8;
	node10->left = NULL;
	node10->right = NULL;
	printf("Preorder iterative : ");
	Preorder_iter(root);
	printf("\n");
	printf("Preorder recursive: ");
	Preorder_rec(root);
	printf("\n\n");
	printf("Inorder iterative : ");
	Inorder_iter(root);
	printf("\n");
	printf("Inorder recursive: ");
	Inorder_rec(root);
	printf("\n\n");
	printf("Postorder iterative : ");
	Postorder_iter(root);
	printf("\n");
	printf("Postorder recursive: ");
	Postorder_rec(root);
	printf("\n");
	free(root);
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	free(node5);
	free(node6);
	free(node7);
	free(node8);
	free(node9);
	free(node10);
	return 0;
}

void Preorder_iter(TreeNode* root) {
	stackNode* top;
	top = createStack();
	while (1) {
		while (root) {
			printf("%d ", root->data);
			push(&top, root);
			root = root->left;
		}//중간 부터 출력이라서 스택에 넣으면서 출력까지 왼쪽 끝까지
		if (isEmptyStack(top))
			break;
		//왼쪽 끝까지 출력했으니 올라가면서 오른쪽 자식 트리까지 확인
		root = pop(&top);
		root = root->right;
	}
	deleteStack(&top);
}

void Inorder_iter(TreeNode* root) {
	stackNode* top;
	top = createStack();
	while (1) {
		while (root) {
			push(&top, root);
			root = root->left;
		}//왼쪽 끝까지 내려감
		if (isEmptyStack(top))
			break;
		root = pop(&top);//스택 젤 위에 있는걸 꺼내서 출력
		printf("%d ", root->data);
		//왼쪽 중간 했으니 오른쪽 자식 있으면 오른쪽 자식으로
		if (root->right) root = root->right;
		else root = NULL;
	}
	deleteStack(&top);
}

void Postorder_iter(TreeNode* root) {
	stackNode* top;
	top = createStack();
	TreeNode* last = NULL;
	while (1) {
		while (root) {
			push(&top, root);
			root = root->left;
		}//제일 왼쪽 밑까지 내려가기
		if (isEmptyStack(top))
			break;
		root = pop(&top);//왼쪽 자식이 더 이상없으니 다시 위로 한칸
		if (root->right && last != root->right) {//오른쪽 자식 출력하고 올라와서다시 내려갈수도 있으니
				push(&top, root);//오른쪽 자식이 있다면 오른쪽 자식이 먼저출력되야 하니 다시 스택에 넣음
				root = root->right;//오른쪽 자식으로 이동
		}
		else {
			printf("%d ", root->data);
			last = root;
			root = NULL; //출력 후에 while(root)문으로 다시 들어가 이미 출력된게 다시 스택에 들어가는것을 방지
		}
	}
	deleteStack(&top);
}


void Postorder_rec(TreeNode* root) {
	if (root->left) Postorder_rec(root->left);
	if (root->right) Postorder_rec(root->right);
	printf("%d ", root->data);
}
void Inorder_rec(TreeNode* root) {
	if (root->left) Inorder_rec(root->left);
	printf("%d ", root->data);
	if (root->right) Inorder_rec(root->right);
}
void Preorder_rec(TreeNode* root) {
	if (root) {
		printf("%d ", root->data);
		Preorder_rec(root->left);
		Preorder_rec(root->right);
	}
}
void LevelOrder_iter(TreeNode* root) {
	Queue* q = createQueue();
	if (!root)
		return;

	enqueue(q, root);

	while (!isEmptyQueue(q)) {
		root = dequeue(q);
		printf("%d ", root->data);

		if (root->left)
			enqueue(q, root->left);

		if (root->right)
			enqueue(q, root->right);
	}

	deleteQueue(q);
}
