package chapter9

//
// Imagine a robot sitting on the upper left corner of an X by Y grid. The robot can only move in two directions: right and down. How many possible paths are there fortherobottogofrom (0,0) to (X,Y)?
// FOLLOW UP
// Imagine certain spots are "off limits," such that the robot cannot step on them. Design an algorithm to find a path for the robot from the top left to the bottom right.

func pathsForRobot(x, y, a, b int) int {

	if a == x && b == y {
		return 1
	}

	if a > x || b > y {
		return 0
	}

	return pathsForRobot(x, y, a+1, b) + pathsForRobot(x, y, a, b+1)
}
