package chapter2

import (
	"cracking/datastructures"
)

func findStartOfLoop(l *datastructures.LinkedList) *datastructures.LinkedList {

	slow := l
	fast := l

	for {
		slow = slow.Next
		fast = fast.Next
		if fast == nil { // protect against non-circular lists
			return &datastructures.LinkedList{Val: -1, Next: nil}
		}

		fast = fast.Next

		if fast == slow { // collision occured
			break
		}
	}

	slow = l

	for {
		slow = slow.Next
		fast = fast.Next

		if fast == slow { // collision occured - reached start
			break
		}
	}

	return slow
}
