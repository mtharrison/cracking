package chapter1

import (
	"cracking/datastructures"
	"math"
)

type bounds struct {
	left, right int
}

func rotate90(m datastructures.NMMatrix) {

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
