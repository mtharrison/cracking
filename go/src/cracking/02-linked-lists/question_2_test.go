package chapter2

import (
	"cracking/datastructures"
	"testing"
)

func TestKthToLastElement(t *testing.T) {

	type testCase struct {
		input       *datastructures.LinkedList
		kth         int
		expectation int
	}

	cases := []testCase{
		{
			datastructures.LinkedListCreate([]int{3, 4, 5, 3, 4, 5, 7, 8, 9}),
			2,
			8,
		},
		{
			datastructures.LinkedListCreate([]int{3, 4, 5, 3, 4, 5, 7, 8, 9}),
			3,
			7,
		},
		{
			datastructures.LinkedListCreate([]int{3, 4}),
			3,
			-1,
		},
	}

	for _, c := range cases {
		element := kthToLastElement(c.input, c.kth)
		if element != c.expectation {
			t.Errorf("Error calling kthToLastElement(%v, %d). Expected %d but got %d", c.input, c.kth, c.expectation, element)
		}
	}
}
