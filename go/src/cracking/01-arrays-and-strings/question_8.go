package chapter1

import "strings"

func isRotation(input string, compare string) bool {

	if len(input) != len(compare) {
		return false
	}

	return strings.Contains(compare+compare, input)
}
