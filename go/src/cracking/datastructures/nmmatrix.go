package datastructures

import "fmt"

type NMMatrix [][]int

func (m NMMatrix) Equals(n NMMatrix) bool {

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

func (m NMMatrix) Print() {
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
