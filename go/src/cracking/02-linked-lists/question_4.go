package chapter2

import (
	"cracking/datastructures"
)

func paritionList(l *datastructures.LinkedList, at int) *datastructures.LinkedList {

	// Create placeholders to avoid branching logic in the
	// main loop. The placeholder nodes are dropped later

	left := &datastructures.LinkedList{Val: 0, Next: nil}
	middle := &datastructures.LinkedList{Val: 0, Next: nil}
	right := &datastructures.LinkedList{Val: 0, Next: nil}

	leftTail := left
	middleTail := middle
	rightTail := right

	cursor := l

	for cursor != nil {
		val := cursor.Val
		node := &datastructures.LinkedList{Val: val, Next: nil}

		if val == at {
			middleTail.Next = node
			middleTail = node
		} else if val < at {
			leftTail.Next = node
			leftTail = node
		} else {
			rightTail.Next = node
			rightTail = node
		}

		cursor = cursor.Next
	}

	// Attach the three lists, skipping placeholders

	middleTail.Next = right.Next
	leftTail.Next = middle.Next

	// Return left, skipping placeholder

	return left.Next
}
