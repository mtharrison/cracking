package chapter2

import (
	"cracking/datastructures"
	"fmt"
	"testing"
)

func TestPartitionList(t *testing.T) {

	type testCase struct {
		input       *datastructures.LinkedList
		partitionAt int
		expectation *datastructures.LinkedList
	}

	cases := []testCase{
		{
			datastructures.LinkedListCreate([]int{3, 6, 4, 2, 5, 6, 7, 3, 2}),
			5,
			datastructures.LinkedListCreate([]int{3, 4, 2, 3, 2, 5, 6, 6, 7}),
		},
		{
			datastructures.LinkedListCreate([]int{3, 4, 4, 4, 4, 2, 3, 2, 5, 6, 6, 7}),
			4,
			datastructures.LinkedListCreate([]int{3, 2, 3, 2, 4, 4, 4, 4, 5, 6, 6, 7}),
		},
	}

	for _, c := range cases {
		result := paritionList(c.input, c.partitionAt)
		if !c.expectation.Equals(result) {
			t.Errorf("Error calling paritionList(%v, %d)", c.input, c.partitionAt)
			fmt.Print("Input:\n")
			c.input.Print()
			fmt.Print("Expectation:\n")
			c.expectation.Print()
			fmt.Print("Result:\n")
			result.Print()
		}
	}
}
