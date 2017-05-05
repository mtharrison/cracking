package chapter2

import (
	"cracking/datastructures"
)

func RemoveDuplicates(list *datastructures.LinkedList) {

	// Use a map as a set to record duplicates

	m := make(map[int]int)
	var lastNode *datastructures.LinkedList

	for list != nil {

		m[list.Val]++

		if m[list.Val] > 1 {
			lastNode.Next = list.Next
			list = list.Next
			continue
		}

		lastNode = list
		list = list.Next
	}
}
