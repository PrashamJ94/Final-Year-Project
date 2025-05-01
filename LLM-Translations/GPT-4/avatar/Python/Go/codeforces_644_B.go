
package main

import (
	"fmt"
	"bufio"
	"os"
	"strings"
	"strconv"
	"container/list"
)

type Task struct {
	time, duration, index int
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	nb := strings.Split(scanner.Text(), " ")
	n, _ := strconv.Atoi(nb[0])
	b, _ := strconv.Atoi(nb[1])
	result := make(map[int]int)
	remaining := list.New()
	var finishTime int
	var taskToRun *Task
	for i := 0; i < n; i++ {
		scanner.Scan()
		timeDuration := strings.Split(scanner.Text(), " ")
		time, _ := strconv.Atoi(timeDuration[0])
		duration, _ := strconv.Atoi(timeDuration[1])
		task := &Task{time, duration, i}
		if task.time > finishTime && remaining.Len() == 0 {
			finishTime = task.time + task.duration
			result[i] = finishTime
		} else {
			if task.time >= finishTime && remaining.Len() != 0 {
				taskToRun = remaining.Remove(remaining.Front()).(*Task)
				finishTime = max(finishTime, taskToRun.time) + taskToRun.duration
				result[taskToRun.index] = finishTime
			}
			if remaining.Len() < b {
				remaining.PushBack(task)
			} else {
				result[i] = -1
			}
		}
	}
	for remaining.Len() != 0 {
		taskToRun = remaining.Remove(remaining.Front()).(*Task)
		finishTime = max(finishTime, taskToRun.time) + taskToRun.duration
		result[taskToRun.index] = finishTime
	}
	for key, value := range result {
		fmt.Println(value)
	}
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
// End of Code

This code translates the given Python code into Go. The main difference is that Go does not have a built-in queue, so we use a doubly-linked list from the container/list package. The `max` function is also not built-in in Go, so we define it ourselves.
