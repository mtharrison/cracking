package Chapter_1

import "testing"

func TestPercentEncode(t *testing.T) {

	type testCase struct {
		input       []rune
		length      int
		expectation string
	}

	cases := []testCase{
		{[]rune("Mr John Smith    "), 13, "Mr%20John%20Smith"},
	}

	for _, c := range cases {
		before := string(c.input)
		PercentEncode(c.input, c.length)
		result := string(c.input)
		if result != c.expectation {
			t.Errorf("Error calling PercentEncode() on input \"%s\". Expected \"%s\" but got \"%s\".", before, c.expectation, result)
		}
	}
}
