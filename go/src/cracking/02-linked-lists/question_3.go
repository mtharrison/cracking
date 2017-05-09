package chapter2

import (
	"cracking/datastructures"
)

func deleteSameNode(l *datastructures.LinkedList) {

	if l.Next == nil {
		l.Val = -1
		return
	}

	l.Val = l.Next.Val
	l.Next = l.Next.Next
}
