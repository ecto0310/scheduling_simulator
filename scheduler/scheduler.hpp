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
    std::string name = "";
    int arrival_time = 0;
    int cost = 0;
    int progress = 0;
    int finish_time = -1;
    Status status = running;

    int priority = 0;
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
    int process_count;
    int time;

    std::deque<Process> wait;
    Process running;
    std::vector<Process> finished;

    virtual void create_process(Process) = 0;
    virtual void switch_process() = 0;
    virtual void do_process();
    bool finish() const;
};
