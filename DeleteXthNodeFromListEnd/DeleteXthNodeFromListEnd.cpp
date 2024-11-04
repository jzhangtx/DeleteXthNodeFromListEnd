// DeleteXthNodeFromListEnd.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class ListNode
{
public:
    int data;
    ListNode* next;
    ListNode(int data)
        : data(data)
        , next(nullptr)
    {}
};

ListNode* GetListFromInput(ListNode** ppHead, int count)
{
    if (count == 0)
        return nullptr;

    std::cout << "Enter " << count << " numbers of the list: ";
    ListNode* pTail = *ppHead;
    for (int i = 0; i < count; ++i)
    {
        int data = 0;
        std::cin >> data;
        if (*ppHead == nullptr)
        {
            *ppHead = new ListNode(data);
            pTail = *ppHead;
        }
        else
        {
            pTail->next = new ListNode(data);
            pTail = pTail->next;
        }
    }

    return pTail;
}

void PrintList(ListNode* pHead)
{
    if (!pHead)
        return;
    std::cout << pHead->data;
    pHead = pHead->next;

    while (pHead != nullptr)
    {
        std::cout << ", " << pHead->data;
        pHead = pHead->next;
    }

    std::cout << std::endl;
}

void FreeList(ListNode* pNode)
{
    if (pNode == nullptr)
        return;

    FreeList(pNode->next);
    delete pNode;
}

ListNode* GetNodeByIndex(ListNode* pHead, int index)
{
    if (index == -1)
        return nullptr;

    for (int i = 0; i < index; ++i)
    {
        pHead = pHead->next;
    }

    return pHead;
}

int CountLinkedList(ListNode* pHead)
{
    int count = 0;
    while (pHead != nullptr)
    {
        pHead = pHead->next;
        ++count;
    }

    return count;
}

ListNode* RemoveXthNodeFromEnd(ListNode** head, int& x)
{
    if (x == 0)
        return nullptr;

    int count = CountLinkedList(*head);
    if (count < x)
        return nullptr;

    ListNode* pNode = nullptr;
    if (x == count)
    {
        pNode = *head;
        *head = (*head)->next;
        return pNode;
    }

    ListNode* pPrevious = GetNodeByIndex(*head, count - x - 1);
    pNode = pPrevious->next;
    pPrevious->next = pNode->next;
    return pNode;
}

int main()
{
    while (true)
    {
        int count = 0;
        std::cout << "Number of nodes in list: ";
        std::cin >> count;
        if (count == 0)
            break;

        ListNode* pHead = nullptr;
        ListNode* pTail = GetListFromInput(&pHead, count);

        std::cout << "Which node from the end should be deleted? ";
        int xTh = 0;
        std::cin >> xTh;

        ListNode* pDeleted = RemoveXthNodeFromEnd(&pHead, xTh);
        if (pDeleted)
            delete pDeleted;

        std::cout << "After node removed: ";
        PrintList(pHead);
        FreeList(pHead);
    }
}
