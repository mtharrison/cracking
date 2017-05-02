package Chapter_1

func PercentEncode(input string) string {

	spaces := 0
	runes := []rune(input)

	// one pass through string to identify spaces

	for _, r := range runes {
		if r == ' ' {
			spaces++
		}
	}

	result := make([]rune, len(input)+spaces*2)

	// another pass to populate result slice

	index := 0

	for _, r := range runes {
		if r == ' ' {
			result[index] = '%'
			result[index+1] = '2'
			result[index+2] = '0'
			index += 2
		} else {
			result[index] = r
		}
		index++
	}

	return string(result)
}
