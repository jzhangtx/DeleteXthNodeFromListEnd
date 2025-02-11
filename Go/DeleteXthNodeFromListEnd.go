package main

import "fmt"

type ListNode struct {
	data int
	next *ListNode
}

func GetArrayFromInput(count int, prompt string) []int {
	if count == 0 {
		return []int{}
	}

	fmt.Print(prompt)

	v := make([]int, count)
	for i := 0; i < count; i++ {
		fmt.Scan(&v[i])
	}

	return v
}

func GetListFromArray(v []int) *ListNode {
	if len(v) == 0 {
		return nil
	}

	if len(v) == 1 {
		return &ListNode{v[0], nil}
	}

	pHead := &ListNode{v[0], nil}
	pCur := pHead
	for i := 1; i < len(v); i++ {
		pCur.next = &ListNode{v[i], nil}
		pCur = pCur.next
	}

	return pHead
}

func (pNode *ListNode) Print() {
	fmt.Print(pNode.data)
	if pNode.next != nil {
		fmt.Print(", ")
		pNode.next.Print()
	} else {
		fmt.Println("")
	}
}

func CountList(pNode *ListNode) int {
	count := 0
	for ; pNode != nil; pNode = pNode.next {
		count++
	}

	return count
}

func RemoveXthNodeFromEnd(head *ListNode, x int) *ListNode {
	if head == nil {
		return head
	}

	count := CountList(head)
	if x == count {
		return head.next
	}

	pSaved := head
	for i := 0; i < count-x-1; i++ {
		head = head.next
	}

	head.next = head.next.next
	return pSaved
}

func main() {
	for {
		fmt.Print("Number elements in list: ")
		var count int
		fmt.Scan(&count)
		if count == 0 {
			break
		}

		vec := GetArrayFromInput(count, "Please enter the nodes in list: ")
		pHead := GetListFromArray(vec)

		fmt.Print("Which node from the end should be removed: ")
		var x int
		fmt.Scan(&x)

		pHead = RemoveXthNodeFromEnd(pHead, x)
		fmt.Print("The resule list: ")
		pHead.Print()
	}
}
