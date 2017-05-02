package Chapter_1

import "sort"

type runeSlice []rune

func (p runeSlice) Len() int {
	return len(p)
}

func (p runeSlice) Less(i, j int) bool {
	return p[i] < p[j]
}

func (p runeSlice) Swap(i, j int) {
	p[i], p[j] = p[j], p[i]
}

func sortStringByRunes(s string) string {
	runes := []rune(s)
	sort.Sort(runeSlice(runes))
	return string(runes)
}

func IsPermutation(input string, compare string) bool {
	return sortStringByRunes(input) == sortStringByRunes(compare)
}
