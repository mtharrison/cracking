package chapter9

import (
	"testing"
)

func TestMagicIndexFinder(t *testing.T) {

	type testCase struct {
		arr []int
		m   int
	}

	cases := []testCase{
		{[]int{-1, 0, 2, 4, 7, 8}, 2},
		{[]int{-1, 0, 1, 4, 7, 8}, -1},
		{[]int{1, 2, 3, 4, 5, 6, 7, 8, 9, 19}, -1},
		{[]int{-50, -25, -20, -5, 1, 3, 5, 7, 9, 19}, 7},
		{[]int{-50, -25, -20, -5, 1, 3, 6, 8, 9, 19}, 6},
	}

	for _, c := range cases {
		result := findMagicIndex(c.arr)
		if result != c.m {
			t.Errorf("Error calling findMagicIndex(%v). Expected %d but got %d", c.arr, c.m, result)
		}
	}
}
