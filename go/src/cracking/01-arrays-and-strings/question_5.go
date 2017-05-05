package chapter1

import "strconv"

// Version that uses additional storage up
// Space O(n)
// Time O(n)

func stringCompress(input string) string {

	runes := make([]rune, len(input))

	var currentRune rune
	currentRunLength := 0
	idx := 0

	flush := func() bool {
		if currentRunLength > 0 {
			runes[idx] = currentRune
			lengthRunes := []rune(strconv.Itoa(currentRunLength))
			if (idx + 1 + len(lengthRunes)) > (len(input) - 1) {
				return false
			}
			idx++
			for _, r := range lengthRunes {
				runes[idx] = r
				idx++
			}
			currentRunLength = 0
		}
		return true
	}

	for _, r := range input {
		if r != currentRune {
			if flush() != true {
				return input
			}
		}
		currentRunLength++
		currentRune = r
	}

	if flush() != true {
		return input
	}

	return string(runes[0:idx])
}
