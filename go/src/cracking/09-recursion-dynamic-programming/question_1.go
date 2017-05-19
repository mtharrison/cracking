package chapter9

func waysToRunUpStairs(n int) int {

	if n < 0 {
		return 0
	}

	if n == 0 {
		return 1
	}

	return waysToRunUpStairs(n-1) +
		waysToRunUpStairs(n-2) +
		waysToRunUpStairs(n-3)
}

func waysToRunUpStairsDP(n int) int {

	cache := make(map[int]int)

	var fn func(n int) int

	fn = func(n int) int {

		val, ok := cache[n]

		if ok {
			return val
		}

		if n < 0 {
			return 0
		}

		if n == 0 {
			return 1
		}

		result := fn(n-1) + fn(n-2) + fn(n-3)
		cache[n] = result

		return result
	}

	return fn(n)
}
