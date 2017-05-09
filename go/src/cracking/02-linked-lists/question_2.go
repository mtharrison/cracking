package chapter2

import (
	"cracking/datastructures"
)

// Implement an algorithm to find the kth to last element of a singly linked list

func kthToLastElement(l *datastructures.LinkedList, kth int) int {

	runnerLeft := l
	runnerRight := l

	// Move the right runner to be kth-1 steps away from left runner
	// If you reach the end of the list first, return -1

	for i := 0; i < kth-1; i++ {
		if runnerRight.Next == nil {
			return -1
		}
		runnerRight = runnerRight.Next
	}

	// Now progress both pointers simultaneously until the end of the
	// List is reached. runnerLeft now points at kth to last element
	// so just return it :)

	for runnerRight.Next != nil {
		runnerLeft = runnerLeft.Next
		runnerRight = runnerRight.Next
	}

	return runnerLeft.Val
}
