package chapter1

import "cracking/datastructures"

func zeroRowAndCol(m datastructures.NMMatrix) {

	rows := make([]bool, len(m))
	cols := make([]bool, len(m))

	// Pass through the whole matrix marking which
	// Cols and rows should be zeroed on second pass

	for i, a := range m {
		for j, b := range a {
			if b == 0 {
				rows[i] = true
				cols[j] = true
				break
			}
		}
	}

	// Make a second pass marking the elements to zero

	for i, a := range m {
		for j := range a {
			if rows[i] == true ||
				cols[j] == true {
				a[j] = 0
			}
		}
	}
}
