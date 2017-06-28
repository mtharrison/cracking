package chapter2

import (
	"cracking/datastructures"
)

func addLists(l *datastructures.LinkedList, r *datastructures.LinkedList) *datastructures.LinkedList {

	result := &datastructures.LinkedList{Val: 0, Next: nil}
	resultTail := result

	for {

		if l != nil {
			resultTail.Val += l.Val
			l = l.Next
		}

		if r != nil {
			resultTail.Val += r.Val
			r = r.Next
		}

		if l == nil && r == nil {
			break
		}

		node := &datastructures.LinkedList{Val: 0, Next: nil}
		resultTail.Next = node
		resultTail = node
	}

	return result
}
