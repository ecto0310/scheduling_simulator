#pragma once

#include <queue>
#include <vector>

#include "scheduler.hpp"

class FirstComeFirstService : public Scheduler
{
public:
    void create_process(Process) override;
    void switch_process() override;
    void do_process() override;

private:
    std::queue<Process> queue;
};
