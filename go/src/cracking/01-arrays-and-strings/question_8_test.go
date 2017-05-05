package chapter1

import "testing"

func TestIsRotation(t *testing.T) {

	type testCase struct {
		input       string
		compare     string
		expectation bool
	}

	cases := []testCase{
		{"waterbottle", "erbottlewat", true},
		{"waterbottle", "erbottleeat", false},
		{"manchester", "chesterman", true},
		{"abc", "x", false},
	}

	for _, c := range cases {
		result := isRotation(c.input, c.compare)
		if result != c.expectation {
			t.Errorf("Error calling IsRotation() on inputs [\"%s\", \"%s\"]. Expected \"%t\" but got \"%t\".", c.input, c.compare, c.expectation, result)
		}
	}
}
