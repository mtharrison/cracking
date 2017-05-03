package Chapter_1

import "testing"

func TestRotateNNMatrix(t *testing.T) {

	m := NNMatrix{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9},
	}

	m.Print()
	m.Rotate90()
	m.Print()
	// type testCase struct {
	// 	input       string
	// 	expectation string
	// }
	//
	// cases := []testCase{
	// 	{"aabcccccaaa", "a2b1c5a3"},
	// 	{"abcccccaaa", "a1b1c5a3"},
	// 	{"aabbcc", "aabbcc"},
	// 	{"aaaaaaaaaaaabbbbbbbbbbbb", "a12b12"},
	// 	{"abc", "abc"},
	// 	{"a", "a"},
	// }
	//
	// for _, c := range cases {
	// 	result := StringCompress(c.input)
	// 	if result != c.expectation {
	// 		t.Errorf("Error calling StringCompress() on input \"%s\". Expected \"%s\" but got \"%s\".", c.input, c.expectation, result)
	// 	}
	// }
}
