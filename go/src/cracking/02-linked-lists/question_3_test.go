package chapter2

import (
	"cracking/datastructures"
	"testing"
)

func TestDeleteSameNode(t *testing.T) {

	type testCase struct {
		input       *datastructures.LinkedList
		removeAt    int
		expectation *datastructures.LinkedList
	}

	cases := []testCase{
		{
			datastructures.LinkedListCreate([]int{3, 4, 5, 3, 4, 5, 7, 8, 9}),
			2,
			datastructures.LinkedListCreate([]int{3, 4, 3, 4, 5, 7, 8, 9}),
		},
		{
			datastructures.LinkedListCreate([]int{3, 4, 5, 3, 4, 5, 7, 8, 9}),
			8,
			datastructures.LinkedListCreate([]int{3, 4, 5, 3, 4, 5, 7, 8, -1}),
		},
	}

	for _, c := range cases {
		deleteSameNode(c.input.ElementAtIndex(c.removeAt))
		if !c.input.Equals(c.expectation) {
			t.Errorf("Error calling deleteSameNode()")
			c.input.Print()
			c.expectation.Print()
		}
	}
}
