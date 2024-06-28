#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createList(struct Node *start);
struct Node *insertInBeginning(struct Node *start, int data);
struct Node *insertAtEnd(struct Node *start, int data);
void displayList(struct Node *start);
void sortByExchangingData(struct Node *start);
struct Node *sortByExchangingLinks(struct Node *start);

int main() {
    struct Node *start = NULL;
    start = createList(start);
    displayList(start);
    start = sortByExchangingLinks(start);
    displayList(start);
}

struct Node *createList(struct Node *start) {
    int n, num;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n == 0) {
        printf("No elements!\n");
        return start;
    }

    printf("Enter the first element: ");
    scanf("%d", &num);

    start = insertInBeginning(start, num);

    for (int i=2; i<=n; i++) {
        printf("Enter the next element: ");
        scanf("%d", &num);
        start = insertAtEnd(start, num);
    }

    return start;
}

struct Node *insertInBeginning(struct Node *start, int data) {
    struct Node *temp;
    temp = (struct Node *) malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = start;

    start = temp;

    return start;
}

struct Node *insertAtEnd(struct Node *start, int data) {
    struct Node *temp, *p;
    temp = (struct Node *) malloc(sizeof(struct Node));

    temp->data = data;
    p = start;

    if (p == NULL) {
        start = temp;
        return start;
    }

    while (p->next!= NULL) {
        p = p->next;
    }

    p->next = temp;
    temp->next = NULL;

    return start;
}

void displayList(struct Node *start) {
    struct Node *p = start;

    if (p == NULL) {
        printf("Empty List!\n");
        return;
    }

    while (p != NULL) {
        printf("%d, ", p->data);
        p = p->next;
    }
    printf("\n");
}

void sortByExchangingData(struct Node *start) {
    struct Node *p, *q, *end;
    int temp;

    if (start->next == NULL) {
        printf("There is nothing to sort!\n");
        return;
    }

    for (end = NULL; end != start->next; end=p) {
        for (p = start; p->next != end; p = p->next) {
            q = p->next;
            if (p->data > q->data) {
                temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
        }
    }
}

struct Node *sortByExchangingLinks(struct Node *start)
{
	struct Node *end, *r, *p, *q, *temp;
		
	for(end = NULL; end != start->next; end = p)
	{
  		for(r = p = start; p->next != end; r = p, p = p->next)
		{
			q=p->next;
			if(p->data > q->data)
			{
				p->next=q->next;
				q->next=p;
				if(p!=start) {
                    r->next=q;
                }
				else {
					start=q;
                }

				// temp=p;
				p=q;
				// q=temp;
			}
		}
		
	}
	return start;
}