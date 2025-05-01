
#include <queue>
#include <vector>

struct Task {
    int time;
    int duration;
    int index;

    Task(int time, int duration, int index) : time(time), duration(duration), index(index) {}
};

std::pair<int, std::vector<int>> run_task(std::queue<Task>& remaining, int finish_time, std::vector<int>& result) {
    Task task_to_run = remaining.front();
    remaining.pop();
    finish_time = std::max(finish_time, task_to_run.time) + task_to_run.duration;
    result[task_to_run.index] = finish_time;
    return {finish_time, result};
}

int main() {
    int n, b;
    std::cin >> n >> b;
    std::queue<Task> remaining;
    bool running = false;
    int finish_time = 0;
    std::vector<int> result(n);
    for (int i = 0; i < n; i++) {
        int time, duration;
        std::cin >> time >> duration;
        Task task(time, duration, i);
        if (task.time > finish_time && remaining.empty()) {
            running = true;
            finish_time = task.time + task.duration;
            result[i] = finish_time;
        } else {
            if (task.time >= finish_time && !remaining.empty()) {
                std::tie(finish_time, result) = run_task(remaining, finish_time, result);
            }
            if (remaining.size() < b) {
                remaining.push(task);
            } else {
                result[i] = -1;
            }
        }
    }
    while (!remaining.empty()) {
        std::tie(finish_time, result) = run_task(remaining, finish_time, result);
    }
    for (const auto& res : result) {
        std::cout << res << std::endl;
    }
    return 0;
} //End of Code


