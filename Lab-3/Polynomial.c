#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coef;
    int exp;
    struct Node* next;
};


struct Node* newNode(int coef, int exp) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->coef = coef;
    temp->exp = exp;
    temp->next = NULL;
    return temp;
}


void append(struct Node** head, int coef, int exp) {
    struct Node* temp = newNode(coef, exp);
    if (*head == NULL) {
        *head = temp;
    } else {
        struct Node* curr = *head;
        while (curr->next != NULL)
            curr = curr->next;
        curr->next = temp;
    }
}


void printPoly(struct Node* poly) {
    while (poly != NULL) {
        printf("%dx^%d", poly->coef, poly->exp);
        poly = poly->next;
        if (poly != NULL)
            printf(" + ");
    }
    printf("\n");
}


struct Node* polyAdd(struct Node* poly1, struct Node* poly2) {
    struct Node *ptr1 = poly1, *ptr2 = poly2;
    struct Node *ptr = newNode(0, 0);
    struct Node *poly = ptr;

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->exp > ptr2->exp) {
            ptr->coef = ptr1->coef;
            ptr->exp = ptr1->exp;
            ptr1 = ptr1->next;
        } else if (ptr1->exp < ptr2->exp) {
            ptr->coef = ptr2->coef;
            ptr->exp = ptr2->exp;
            ptr2 = ptr2->next;
        } else {
            ptr->coef = ptr1->coef + ptr2->coef;
            ptr->exp = ptr1->exp;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        if (ptr1 != NULL || ptr2 != NULL) {
            ptr->next = newNode(0, 0);
            ptr = ptr->next;
        }
    }

    struct Node* ptrr = (ptr1 != NULL) ? ptr1 : ptr2;

    while (ptrr != NULL) {
        ptr->coef = ptrr->coef;
        ptr->exp = ptrr->exp;
        ptrr = ptrr->next;
        if (ptrr != NULL) {
            ptr->next = newNode(0, 0);
            ptr = ptr->next;
        }
    }

    ptr->next = NULL;
    return poly;
}


int main() {
    struct Node* poly1 = NULL;
    struct Node* poly2 = NULL;

    // Example: Polynomial 1 = 5x^3 + 4x^2 + 2
    append(&poly1, 5, 3);
    append(&poly1, 4, 2);
    append(&poly1, 2, 0);

    // Example: Polynomial 2 = 5x^2 + 5x + 5
    append(&poly2, 5, 2);
    append(&poly2, 5, 1);
    append(&poly2, 5, 0);

    printf("Polynomial 1: ");
    printPoly(poly1);

    printf("Polynomial 2: ");
    printPoly(poly2);

    struct Node* result = polyAdd(poly1, poly2);

    printf("Sum: ");
    printPoly(result);

    return 0;
}
