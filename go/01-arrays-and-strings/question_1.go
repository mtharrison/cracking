package Chapter_1

func IsUniqueChars(input string) bool {

	m := make(map[rune]bool)

	for _, char := range input {
		_, exists := m[char]
		if exists {
			return false
		}
		m[char] = true
	}

	return true
}

func IsUniqueCharsNoSpace(input string) bool {

	for i, char1 := range input {
		for j, char2 := range input {
			if i != j && char1 == char2 {
				return false
			}
		}
	}

	return true
}
