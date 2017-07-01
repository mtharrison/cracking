package chapter2

import (
	"cracking/datastructures"
	"testing"
)

func TestFindLoopStart(t *testing.T) {

	type testCase struct {
		list         *datastructures.LinkedList
		loopStartVal int
	}

	list1 := datastructures.LinkedListCreate([]int{1, 2, 3, 4, 5, 6, 7, 8, 9})
	list1.ElementAtIndex(8).Next = list1.ElementAtIndex(3)

	list2 := datastructures.LinkedListCreate([]int{1, 2, 3, 4, 5, 6, 7, 8, 9})

	list3 := datastructures.LinkedListCreate([]int{1, 2, 3, 4, 5, 6, 7, 8, 9})
	list3.ElementAtIndex(8).Next = list3.ElementAtIndex(1)

	cases := []testCase{
		{list1, 4},
		{list2, -1},
		{list3, 2},
	}

	for _, c := range cases {
		loopNode := findStartOfLoop(c.list)
		if loopNode.Val != c.loopStartVal {
			t.Errorf("Error calling findStartOfLoop(%v). Expected %d. Got %d", c.list, c.loopStartVal, loopNode.Val)
		}
	}
}
