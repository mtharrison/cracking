package chapter2

import (
	"cracking/datastructures"
)

func addLists(l *datastructures.LinkedList, r *datastructures.LinkedList) *datastructures.LinkedList {

	result := &datastructures.LinkedList{Val: 0, Next: nil}
	resultTail := result

	for {

		resultTail.Val += l.Val
		resultTail.Val += r.Val
		l = l.Next
		r = r.Next

		if l == nil {
			break
		}

		node := &datastructures.LinkedList{Val: 0, Next: nil}
		resultTail.Next = node
		resultTail = node
	}

	return result
}
