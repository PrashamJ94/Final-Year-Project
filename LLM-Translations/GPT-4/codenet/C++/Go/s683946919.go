
package main

import (
	"fmt"
	"sort"
	"strings"
)

type Event struct {
	ID      int
	Time    int
	IsStart bool
}

func time2min(month, day, hour, min int) int {
	totalDayOfMonth := []int{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	total := 0
	for i := 1; i < month; i++ {
		total += totalDayOfMonth[i] * 24 * 60
	}
	for i := 1; i < day; i++ {
		total += 24 * 60
	}
	total += hour*60 + min

	return total
}

func main() {
	var N int
	for {
		fmt.Scan(&N)
		if N == 0 {
			break
		}

		events := make([]Event, 0, N)
		for i := 0; i < N; i++ {
			var month, day, hour, min, id int
			var action string
			fmt.Scanf("%d/%d %d:%d %s %d", &month, &day, &hour, &min, &action, &id)

			t := time2min(month, day, hour, min)
			isStart := strings.HasPrefix(action, "S")
			events = append(events, Event{ID: id, Time: t, IsStart: isStart})
		}

		sort.Slice(events, func(i, j int) bool { return events[i].Time < events[j].Time })

		total := make([]int, 1000)
		godStart := 0
		for _, event := range events {
			if event.ID == 0 {
				if event.IsStart {
					godStart = event.Time
				} else {
					for id, totalTime := range total {
						if id == 0 {
							continue
						}
						for i := 0; i < len(events); i += 2 {
							pplStart := events[i].Time
							pplEnd := events[i+1].Time
							start := max(godStart, pplStart)
							end := min(event.Time, pplEnd)
							total[id] += max(0, end-start)
						}
					}
				}
			}
		}

		maxV := 0
		for _, totalTime := range total {
			maxV = max(maxV, totalTime)
		}
		fmt.Println(maxV)
	}
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// 
