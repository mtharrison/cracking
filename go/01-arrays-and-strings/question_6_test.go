package Chapter_1

import "testing"

func TestRotateNMMatrix(t *testing.T) {

	type testCase struct {
		input       NMMatrix
		expectation NMMatrix
	}

	cases := []testCase{
		{
			NMMatrix{
				{1, 2, 3, 4},
				{5, 6, 7, 8},
				{9, 10, 11, 12},
				{13, 14, 15, 16},
			},
			NMMatrix{
				{13, 9, 5, 1},
				{14, 10, 6, 2},
				{15, 11, 7, 3},
				{16, 12, 8, 4},
			},
		},
	}

	for _, c := range cases {
		c.input.Rotate90()
		if c.input.Equals(c.expectation) != true {
			t.Errorf("Error calling Rotate90()")
		}
	}
}
