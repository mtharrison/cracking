package Chapter_1

import (
	"fmt"
	"math"
)

type NNMatrix [][]int
type bounds struct {
	left, right int
}

func (m NNMatrix) Rotate90() {

	size := len(m)
	layers := int(math.Floor(float64(size / 2)))

	for i := 0; i < layers; i++ {
		b := bounds{i, size - i - 1}
		for j := 0; j < b.right-b.left; j++ {
			top := m[b.left][b.left+j]
			m[b.left][b.left+j] = m[b.right-j][b.left]
			m[b.right-j][b.left] = m[b.right][b.right-j]
			m[b.right][b.right-j] = m[b.left+j][b.right]
			m[b.left+j][b.right] = top
		}
	}
}

func (m NNMatrix) Equals(n NNMatrix) bool {

	if len(m) != len(n) {
		return false
	}

	for i, x := range m {
		if len(x) != len(n[i]) {
			return false
		}
		for j, y := range x {
			if y != n[i][j] {
				return false
			}
		}
	}

	return true
}

func (m NNMatrix) Print() {
	for _, i := range m {
		fmt.Print("|")
		for _, j := range i {
			fmt.Printf("%3d", j)
		}
		fmt.Print("|")
		fmt.Print("\n")
	}
	fmt.Print("\n")
}
