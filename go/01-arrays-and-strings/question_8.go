package Chapter_1

import "strings"

func IsRotation(input string, compare string) bool {

	if len(input) != len(compare) {
		return false
	}

	return strings.Contains(compare+compare, input)
}
