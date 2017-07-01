package chapter2

import (
	"cracking/datastructures"
	"testing"
)

func TestIsPallindrome(t *testing.T) {

	type testCase struct {
		list *datastructures.LinkedList
		is   bool
	}

	cases := []testCase{
		{
			datastructures.LinkedListCreate([]int{1, 2, 3, 4, 5, 6, 6, 5, 4, 3, 2, 1}),
			true,
		},
		{
			datastructures.LinkedListCreate([]int{1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1}),
			true,
		},
		{
			datastructures.LinkedListCreate([]int{1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 5}),
			false,
		},
	}

	for _, c := range cases {
		is := isPallindrome(c.list)
		if is != c.is {
			t.Errorf("Error calling isPallindrome(%v). Expected %t. Got %t.", c.list, c.is, is)
		}
	}
}
