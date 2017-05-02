package Question_1_1

import (
	"testing"
)

type TestCase struct {
	input       string
	expectation bool
}

func TestIsUniqueChars(t *testing.T) {

	cases := []TestCase{
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
