package chapter2

import (
	"cracking/datastructures"
	"fmt"
	"testing"
)

func TestAddLists(t *testing.T) {

	type testCase struct {
		l           *datastructures.LinkedList
		r           *datastructures.LinkedList
		expectation *datastructures.LinkedList
	}

	cases := []testCase{
		{
			datastructures.LinkedListCreate([]int{3, 2, 1}), // 123+
			datastructures.LinkedListCreate([]int{6, 5, 4}), // 456
			datastructures.LinkedListCreate([]int{9, 7, 5}), // 579=
		},
		{
			datastructures.LinkedListCreate([]int{3, 2, 1, 5}), // 5123+
			datastructures.LinkedListCreate([]int{6, 5, 4}),    //  456
			datastructures.LinkedListCreate([]int{9, 7, 5, 5}), // 5579=
		},
		{
			datastructures.LinkedListCreate([]int{5, 2, 1}), // 125+
			datastructures.LinkedListCreate([]int{6, 5, 4}), // 456
			datastructures.LinkedListCreate([]int{9, 7, 5}), // 581=
		},
	}

	for _, c := range cases {
		result := addLists(c.l, c.r)
		if !c.expectation.Equals(result) {
			t.Errorf("Error calling addLists(%v, %v)", c.l, c.r)
			fmt.Print("Input:\n")
			c.l.Print()
			c.r.Print()
			fmt.Print("Expectation:\n")
			c.expectation.Print()
			fmt.Print("Result:\n")
			result.Print()
		}
	}
}
