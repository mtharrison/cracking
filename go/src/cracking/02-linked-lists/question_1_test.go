package chapter2

import (
	"cracking/datastructures"
	"testing"
)

func TestRemoveDuplicates(t *testing.T) {

	type testCase struct {
		input   *datastructures.LinkedList
		compare *datastructures.LinkedList
	}

	cases := []testCase{
		{
			datastructures.LinkedListCreate([]int{1, 2, 2, 3, 4}),
			datastructures.LinkedListCreate([]int{1, 2, 3, 4}),
		},
		{
			datastructures.LinkedListCreate([]int{1, 2, 3}),
			datastructures.LinkedListCreate([]int{1, 2, 3}),
		},
		{
			datastructures.LinkedListCreate([]int{3, 4, 5, 3, 4, 5, 7, 8, 9}),
			datastructures.LinkedListCreate([]int{3, 4, 5, 7, 8, 9}),
		},
	}

	for _, c := range cases {
		RemoveDuplicates(c.input)
		if !c.input.Equals(c.compare) {
			t.Error("Error calling RemoveDuplicates() on input")
			c.input.Print()
			c.compare.Print()
		}
	}
}
