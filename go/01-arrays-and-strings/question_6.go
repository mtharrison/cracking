package Chapter_1

import "fmt"

type NNMatrix [][]int

func (m NNMatrix) Rotate90() {

	size := len(m)

	for i := 0; i < size-1; i++ {
		// save top
		top := m[0][i]
		// left to top
		m[0][i] = m[size-1-i][0]
		// bottom to left
		m[size-1-i][0] = m[size-1][size-1-i]
		// right to bottom
		m[size-1][size-1-i] = m[i][size-1]
		// top to right
		m[i][size-1] = top
	}
}

func (m NNMatrix) Print() {
	for _, i := range m {
		fmt.Print("|")
		for _, j := range i {
			fmt.Printf("%2d", j)
		}
		fmt.Print("|")
		fmt.Print("\n")
	}
	fmt.Print("\n")
}
