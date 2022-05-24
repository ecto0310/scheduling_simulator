#pragma once
#include <string>
#include <vector>
#include <queue>
#include <functional>

enum Status
{
    running,
    finished,

    none,
};

struct Process
{
    std::string name;
    int arrival_time;
    int cost;
    int progress;
    int finish_time;
    Status status;
};

class Scheduler
{
public:
    Scheduler();
    virtual ~Scheduler() {}
    virtual void setup();
    void run();
    void result();

protected:
    int time;
    int limit_time;

    std::priority_queue<Process, std::vector<Process>, std::function<bool(const Process &, const Process &)>> wait;
    Process running;
    std::vector<Process> finished;

    virtual void create_process(Process) = 0;
    virtual void switch_process() = 0;
    virtual void do_process();
};