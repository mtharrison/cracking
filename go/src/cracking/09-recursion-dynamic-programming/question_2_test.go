package chapter9

import (
	"testing"
)

func TestPathsForRobot(t *testing.T) {

	type testCase struct {
		x, y, n int
	}

	cases := []testCase{
		{3, 3, 20},
		{5, 5, 252},
		{10, 5, 3003},
	}

	for _, c := range cases {
		result := pathsForRobot(c.x, c.y, 0, 0)
		if result != c.n {
			t.Errorf("Error calling pathsForRobot(%d, %d). Expected %d but got %d", c.x, c.y, c.n, result)
		}
	}
}

func TestPathsForRobotWithObstructions(t *testing.T) {

	type testCase struct {
		x, y, n int
	}

	cases := []testCase{
		{3, 3, 20},
		{5, 5, 252},
		{10, 5, 3003},
	}

	for _, c := range cases {
		result := pathsForRobot(c.x, c.y, 0, 0)
		if result != c.n {
			t.Errorf("Error calling pathsForRobot(%d, %d). Expected %d but got %d", c.x, c.y, c.n, result)
		}
	}
}
