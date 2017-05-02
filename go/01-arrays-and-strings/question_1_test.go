package Chapter_1

import "testing"

func TestIsUniqueChars(t *testing.T) {

	type testCase struct {
		input       string
		expectation bool
	}

	cases := []testCase{
		{"abc", true},
		{"abca", false},
	}

	for _, c := range cases {
		result := IsUniqueChars(c.input)
		if result != c.expectation {
			t.Errorf("Error calling IsUniqueChars() on input \"%s\". Expected %t but got %t.", c.input, c.expectation, result)
		}
	}

	for _, c := range cases {
		result := IsUniqueCharsNoSpace(c.input)
		if result != c.expectation {
			t.Errorf("Error calling IsUniqueChars() on input \"%s\". Expected %t but got %t.", c.input, c.expectation, result)
		}
	}
}
