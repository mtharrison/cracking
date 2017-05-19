package chapter9

//
// Imagine a robot sitting on the upper left corner of an X by Y grid. The robot can only move in two directions: right and down. How many possible paths are there fortherobottogofrom (0,0) to (X,Y)?
// FOLLOW UP
// Imagine certain spots are "off limits," such that the robot cannot step on them. Design an algorithm to find a path for the robot from the top left to the bottom right.

type point struct{ x, y int }
type grid struct {
	m, n    int
	blocked []point
}

func pathsForRobot(g grid, p point) int {

	if p.x == g.m && p.y == g.n {
		return 1
	}

	if p.x > g.m || p.y > g.n {
		return 0
	}

	for _, b := range g.blocked {
		if b.x == p.x && b.y == p.y {
			return 0
		}
	}

	return pathsForRobot(g, point{p.x + 1, p.y}) + pathsForRobot(g, point{p.x, p.y + 1})
}
