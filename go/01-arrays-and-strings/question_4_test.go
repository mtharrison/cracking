package Chapter_1

import "testing"

func TestPercentEncode(t *testing.T) {

	type testCase struct {
		input       string
		expectation string
	}

	cases := []testCase{
		{"Mr John Smith", "Mr%20John%20Smith"},
	}

	for _, c := range cases {
		result := PercentEncode(c.input)
		if result != c.expectation {
			t.Errorf("Error calling PercentEncode() on input \"%s\". Expected \"%s\" but got \"%s\".", c.input, c.expectation, result)
		}
	}
}
