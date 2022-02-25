/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int get_length(struct ListNode* l1) {
    int length = (l1 == 0) ? 0 : get_length(l1->next) + 1;
    return length;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int length_1 = get_length(l1);
    int length_2 = get_length(l2);

    //做统一处理，保证l1的长度是大于等于l2的
    if (length_1 < length_2) {
        struct ListNode* temp_1 = l1;
        l1 = l2;
        l2 = temp_1;
    }
    length_1 = get_length(l1);
    length_2 = get_length(l2);

    int jin = 0;
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* head1 = head;//head1为临时指针
    for (int i = 0; i < length_2; i++) {
        int temp = l1->val + l2->val + jin;
        if (temp >= 10) {
            jin = 1;
            temp -= 10;
        }
        else {
            jin = 0;
        }

        struct ListNode* temp_l = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp_l->val = temp;
        temp_l->next = NULL;
        head1->next = temp_l;
        head1 = temp_l;

        l1 = l1->next;
        l2 = l2->next;
    }
    for (int i = 0; i < length_1 - length_2; i++) {
        int temp = l1->val + jin;
        if (temp >= 10) {
            jin = 1;
            temp -= 10;
        }
        else {
            jin = 0;
        }
        struct ListNode* temp_l = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp_l->val = temp;
        temp_l->next = NULL;
        head1->next = temp_l;
        head1 = temp_l;

        l1 = l1->next;
    }
    if (jin == 1) {
        struct ListNode* temp_l = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp_l->val = jin;
        temp_l->next = NULL;
        head1->next = temp_l;
        head1 = temp_l;
    }
    return head->next;
}