package chapter9

func findMagicIndexInternal(arr []int, start int) int {

	length := len(arr)
	midPoint := length / 2
	midValue := arr[midPoint]

	if midValue == (midPoint + start) {
		return midValue
	}

	if length == 1 {
		return -1
	}

	if midValue > (midPoint + start) {
		return findMagicIndexInternal(arr[0:midPoint], 0+start)
	}

	return findMagicIndexInternal(arr[midPoint+1:], midPoint+1+start)
}

func findMagicIndex(arr []int) int {

	return findMagicIndexInternal(arr, 0)
}
