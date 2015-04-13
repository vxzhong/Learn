package main

import "fmt"

const (
	x = 42
	a = iota
	b
	c string = "zz"
)

func main() {
	fmt.Println("Hello world, 世界!", "How many university?")
	fmt.Println(x, a, b, c)

	var s1 = "hello"
	s2 := "baby"
	fmt.Println(s1, s2)

	c2 := []rune(s2)
	c2[0] = 'B'
	s3 := string(c2)
	fmt.Println(s3)

	if x > 0 {
		fmt.Println("OK!")
	} else {
		fmt.Println("Err!")
	}

	sum := 0

	for i := 0; i < 1000; i++ {
		sum += (i + 1)
	}

	fmt.Printf("%v", sum)
	var a1 []int

J:
	for i := 0; i < 5; i++ {
		for j := 0; j < 10; j++ {
			if j >= 5 {
				break J
			}
			a1 = append(a1, i+j)
		}
	}

	fmt.Println(a1)

	list := []string{"a", "b", "c", "d"}

	for k, v := range list {
		fmt.Println(k, v)
	}

	for k, v := range "中国" {
		fmt.Printf("%d, %c\n", k, v)
	}

}
