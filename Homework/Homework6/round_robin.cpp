#include <iostream>
#include <queue>
#include <fstream>
#include <sstream>
#include <vector>

class Process {
private:
    int id;
    int arrival_time;
    int time_needed;
    int finished_time;

public:
    // constructor
    Process() = default;
    Process(int id, int arrival_time, int time_needed) 
        : id { id }, arrival_time { arrival_time }, time_needed { time_needed }
    {}
    
    // getters
    int get_id() { return id; }
    int get_arrival_time() { return arrival_time; }
    int get_time_needed() { return time_needed; }
    int get_finished_time() { return finished_time; }

    // setters
    void set_id(int id) { this->id = id; }
    void set_arrival_time(int arrival_time) { this->arrival_time = arrival_time; }
    void set_time_needed(int time_needed) { this->time_needed = time_needed; }
    void set_finished_time(int finished_time) { this->finished_time = finished_time; }
};

std::vector<Process> do_work(std::vector<Process>& processes) {
    std::vector<Process> done;
    std::queue<Process> queue;
    Process process_working;
    bool idle = true;

    int time = 0;
    int CPU_time  = 4;
    int time_worked = 0;
    Process temp;
    while (!idle or !processes.empty()) {
        for (auto it = processes.begin(); it != processes.end(); it++) {
            Process p = *it;
            if (p.get_arrival_time() == time) {
                queue.push(p);
                processes.erase(it--);
            }
        } 

        if (process_working.get_time_needed() == 0) {
            process_working.set_finished_time(time);
            done.push_back(process_working);
            time_worked = 0;
            idle = true;
        }
        else if (time_worked == CPU_time) {
            queue.push(process_working);
            time_worked = 0;
            idle = true;
        }

        if (idle and !queue.empty()) {
            process_working = queue.front();
            queue.pop();
            idle = false;
            process_working.set_time_needed(process_working.get_time_needed() - 1);
            time_worked++;
        }
        else if (!idle) {
            process_working.set_time_needed(process_working.get_time_needed() - 1);
            time_worked++;
        } 

        time++;
    }

    return done;
}

int main()
{
    
    std::fstream file("round_robin.txt");

    std::vector<Process> processes;
    std::string line;
    while (std::getline(file,line)) {
        std::stringstream ss(line);
        int id,arrival_time,time_needed;
        ss >> id >> arrival_time >> time_needed;
        processes.push_back(Process { id, arrival_time, time_needed });
    }

    file.close();

    std::vector<Process> finished_processes = do_work(processes);
    for (auto p : finished_processes) {
        std::cout << "p" << p.get_id() << ": finished at time " << p.get_finished_time() << std::endl;
    }

    return 0;
}
