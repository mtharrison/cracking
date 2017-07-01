package datastructures

type Stack struct {
	head *LinkedList
}

func (s *Stack) Push(v int) {
	newHead := &LinkedList{v, s.head}
	s.head = newHead
}

func (s *Stack) Pop() int {
	val := s.head.Val
	s.head = s.head.Next
	return val
}

func (s *Stack) Peek() int {
	return s.head.Val
}

func (s *Stack) AsList() *LinkedList {

	return s.head
}

func (s *Stack) Print() {
	s.head.Print()
}
