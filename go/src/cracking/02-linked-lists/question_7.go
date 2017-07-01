package chapter2

import (
	"cracking/datastructures"
)

func isPallindrome(l *datastructures.LinkedList) bool {

	stack := datastructures.Stack{}

	slow := l
	fast := l

	for {
		if slow.Next != nil {
			stack.Push(slow.Val)
			slow = slow.Next
		}

		if fast.Next != nil && fast.Next.Next != nil {
			fast = fast.Next.Next
		} else {
			if fast.Next == nil {
				stack.Pop() // don't want middle value
			}
			break
		}
	}

	return stack.AsList().Equals(slow)
}
