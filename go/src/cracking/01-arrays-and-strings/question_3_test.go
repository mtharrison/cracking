package chapter1

import "testing"

func TestIsPermutation(t *testing.T) {

	type testCase struct {
		input       string
		compare     string
		expectation bool
	}

	cases := []testCase{
		{"this", "shit", true},
		{"irish", "english", false},
	}

	for _, c := range cases {
		result := isPermutation(c.input, c.compare)
		if result != c.expectation {
			t.Errorf("Error calling IsPermutation() on inputs [\"%s\", \"%s\"]. Expected %t but got %t.", c.input, c.compare, c.expectation, result)
		}
	}
}
