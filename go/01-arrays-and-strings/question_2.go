package Chapter_1

func StringReverse(input string) string {

	inputRuneArray := []rune(input)
	numChars := len(inputRuneArray)
	resultRuneArray := make([]rune, numChars)

	for i := numChars - 1; i >= 0; i-- {
		resultRuneArray[numChars-i-1] = inputRuneArray[i]
	}

	return string(resultRuneArray)
}
