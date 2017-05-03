package Chapter_1

import "testing"

func TestZeroRowAndCol(t *testing.T) {

	type testCase struct {
		input       NMMatrix
		expectation NMMatrix
	}

	cases := []testCase{
		{
			NMMatrix{
				{1, 2, 3, 4},
				{5, 0, 7, 8},
				{9, 10, 11, 12},
				{13, 14, 0, 16},
			},
			NMMatrix{
				{1, 0, 0, 4},
				{0, 0, 0, 0},
				{9, 0, 0, 12},
				{0, 0, 0, 0},
			},
		},
	}

	for _, c := range cases {
		c.input.ZeroRowAndCol()
		if c.input.Equals(c.expectation) != true {
			t.Errorf("Error calling ZeroRowAndCol()")
		}
	}
}
