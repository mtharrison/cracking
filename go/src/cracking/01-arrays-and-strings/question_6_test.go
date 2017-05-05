package chapter1

import (
	"cracking/datastructures"
	"testing"
)

func TestRotateNMMatrix(t *testing.T) {

	type testCase struct {
		input       datastructures.NMMatrix
		expectation datastructures.NMMatrix
	}

	cases := []testCase{
		{
			datastructures.NMMatrix{
				{1, 2, 3, 4},
				{5, 6, 7, 8},
				{9, 10, 11, 12},
				{13, 14, 15, 16},
			},
			datastructures.NMMatrix{
				{13, 9, 5, 1},
				{14, 10, 6, 2},
				{15, 11, 7, 3},
				{16, 12, 8, 4},
			},
		},
	}

	for _, c := range cases {
		rotate90(c.input)
		if c.input.Equals(c.expectation) != true {
			t.Errorf("Error calling Rotate90()")
		}
	}
}
