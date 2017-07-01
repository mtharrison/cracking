package chapter2

import (
	"cracking/datastructures"
)

func addLists(l *datastructures.LinkedList, r *datastructures.LinkedList) *datastructures.LinkedList {

	result := &datastructures.LinkedList{Val: 0, Next: nil}
	resultTail := result

	for {

		carry := 0

		if l != nil {
			resultTail.Val += l.Val
			l = l.Next
		}

		if r != nil {
			sum := resultTail.Val + r.Val
			if sum >= 10 {
				carry = 1
				resultTail.Val = sum % 10
			} else {
				resultTail.Val = sum
			}
			r = r.Next
		}

		if l == nil && r == nil && carry == 0 {
			break
		}

		node := &datastructures.LinkedList{Val: carry, Next: nil}
		resultTail.Next = node
		resultTail = node
	}

	return result
}
