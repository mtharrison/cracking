package Chapter_1

// [mr john smith    ]
//              ^   ^
//           idx1   idx2

func PercentEncode(input []rune, originalLength int) {

	idx1 := originalLength - 1
	idx2 := len(input) - 1

	for idx1 > 0 {
		if input[idx1] == ' ' {
			input[idx2-2], input[idx2-1], input[idx2] = '%', '2', '0'
			idx2 -= 2
		} else {
			input[idx2] = input[idx1]
		}

		idx1--
		idx2--
	}
}
