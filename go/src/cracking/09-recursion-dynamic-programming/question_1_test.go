package chapter9

import (
	"testing"
)

func TestWaysToRunUpStairs(t *testing.T) {

	type testCase struct {
		n int
		w int
	}

	cases := []testCase{
		{1, 1},
		{2, 2},
		{3, 4},
		{10, 274},
	}

	for _, c := range cases {
		result := waysToRunUpStairs(c.n)
		if result != c.w {
			t.Errorf("Error calling WaysToRunUpStairs(%d). Expected %d but got %d", c.n, c.w, result)
		}
	}

	for _, c := range cases {
		result := waysToRunUpStairsDP(c.n)
		if result != c.w {
			t.Errorf("Error calling WaysToRunUpStairs(%d). Expected %d but got %d", c.n, c.w, result)
		}
	}
}
