package datastructures

import "fmt"

type LinkedList struct {
	Val  int
	Next *LinkedList
}

func (l1 *LinkedList) Equals(l2 *LinkedList) bool {

	for {

		// If both pointers are nil then either:
		// 1. they were both nil to start with and this equal
		// 2. Every element was iterated and matched thus equal

		if l1 == nil && l2 == nil {
			return true
		}

		// If both pointers are not nil but at least one is nil
		// that means they're of unequal length, thus not equal

		if l1 == nil || l2 == nil {
			return false
		}

		// If the currently pointed to Values don't match
		// then they're not equal

		if l1.Val != l2.Val {
			return false
		}

		// Move along the pointers by one more step

		l1 = l1.Next
		l2 = l2.Next
	}
}

func (l1 *LinkedList) Print() {

	for l1 != nil {
		fmt.Printf("%d -> ", l1.Val)
		l1 = l1.Next
	}

	fmt.Print("nil\n")
}

func (l *LinkedList) ElementAtIndex(index int) *LinkedList {

	for i := 0; i < index; i++ {
		if l.Next == nil {
			return nil
		}
		l = l.Next
	}

	return l
}

func LinkedListCreate(vals []int) *LinkedList {

	if len(vals) < 1 {
		return nil
	}

	// Build a head

	head := &LinkedList{vals[0], nil}
	last := head

	// Attach the rest of the Values

	for _, val := range vals[1:] {
		node := &LinkedList{val, nil}
		last.Next = node
		last = node
	}

	return head
}
