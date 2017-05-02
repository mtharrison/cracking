package Chapter_1

import "testing"

func TestStringReverse(t *testing.T) {

	type testCase struct {
		input       string
		expectation string
	}

	cases := []testCase{
		{"abc", "cba"},
		{"abca", "acba"},
		{"你好", "好你"},
	}

	for _, c := range cases {
		result := StringReverse(c.input)
		if result != c.expectation {
			t.Errorf("Error calling StringReverse() on input \"%s\". Expected %s but got %s.", c.input, c.expectation, result)
		}
	}
}
