#pragma once

#include <queue>
#include <vector>

#include "scheduler.hpp"

class Priority : public Scheduler
{
public:
    Priority();
    void setup() override;

private:
    std::priority_queue<Process, std::vector<Process>, std::function<bool(const Process &, const Process &)>> queue;

    void create_process(Process) override;
    void switch_process() override;
};
