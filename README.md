# Scheduling Simulator

It is a scheduler simulator.

- supported algorithm
  - first come first service
  - shortest processing time first
  - round robin
  - priority(deadline scheduling)[^1]

[^1]: Priority can be used as deadline scheduling by assigning high priority to the earliest due date.

## Requirement

- Boost C++ Libraries

## Usage

```bash
git clone https://github.com/ecto0310/scheduling_simulator.git
cd scheduling_simulator
make
./build/main
```
