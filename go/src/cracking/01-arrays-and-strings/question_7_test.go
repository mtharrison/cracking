package chapter1

import (
	"cracking/datastructures"
	"testing"
)

func TestZeroRowAndCol(t *testing.T) {

	type testCase struct {
		input       datastructures.NMMatrix
		expectation datastructures.NMMatrix
	}

	cases := []testCase{
		{
			datastructures.NMMatrix{
				{1, 2, 3, 4},
				{5, 0, 7, 8},
				{9, 10, 11, 12},
				{13, 14, 0, 16},
			},
			datastructures.NMMatrix{
				{1, 0, 0, 4},
				{0, 0, 0, 0},
				{9, 0, 0, 12},
				{0, 0, 0, 0},
			},
		},
	}

	for _, c := range cases {
		zeroRowAndCol(c.input)
		if c.input.Equals(c.expectation) != true {
			t.Errorf("Error calling ZeroRowAndCol()")
		}
	}
}
