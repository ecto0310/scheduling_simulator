#pragma once

#include <queue>
#include <vector>

#include "scheduler.hpp"

class RoundRobin : public Scheduler
{
public:
    void setup() override;

private:
    int time_slice;
    int duration;
    std::queue<Process> queue;

    void create_process(Process) override;
    void switch_process() override;
    void do_process() override;
};
