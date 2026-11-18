# checkoff-comp211
# First-Come, First-Served (FCFS) Scheduling

COMP 211 Checkoff 3 · Agastya Arora

## Topic

A computer runs hundreds of processes, but each CPU core can only run one at a time. The part of the operating system that decides which process runs next is called the **scheduler**. I explored **First-Come, First-Served (FCFS)**, the simplest rule a scheduler can use: whoever gets in line first runs first, and once a job starts, it runs until it's done.

## What I explored

- How FCFS works and the key terms (arrival time, burst time, waiting time, turnaround time)
- How the order jobs arrive in changes the average waiting time
- What happens when a job never finishes
- How FCFS compares to Shortest Job First (SJF) and Round Robin

## Most interesting discoveries

### 1. The convoy effect: order changes everything

I took the same 3 jobs (two 3 ms jobs and one 24 ms job) and ran them in two different orders:

| Order | Waiting times | Average wait |
|---|---|---|
| Short jobs first | 0, 3, 6 | **3 ms** |
| Long job first | 0, 24, 27 | **17 ms** |

Same jobs, same total work, but about 6x the average wait just from changing the order. This is called the **convoy effect**: short jobs get stuck behind one long job, like cars stuck behind a slow truck on a one-lane road. I assumed the waits would be about the same, so this surprised me.

### 2. One infinite loop can freeze FCFS

FCFS never interrupts a running job. So if the first job runs something like:

```c
while (1) { }
```

it never finishes, and every job behind it waits forever. I always assumed the OS could stop a stuck program, but under pure FCFS it can't.

### 3. How FCFS compares

| Scheduler | Rule | Best at | Catch |
|---|---|---|---|
| FCFS | First in line goes first | Simple, predictable, nobody gets skipped | Order of arrival decides the wait |
| Shortest Job First | Shortest job goes first | Lowest average wait | OS has to guess how long jobs take |
| Round Robin | Everyone takes short turns | Feels responsive | Lots of switching between jobs |

FCFS is still used for things like printer queues and batch jobs, where work just needs to get done in order.

## Code

`code/fcfs.c` simulates FCFS for the same 3 jobs in both orders and prints each job's waiting time and the average.

### How to run it

```
cd code
gcc fcfs.c -o fcfs
./fcfs
```

### Output

```
Short jobs first:
  P2 waits 0 ms (burst 3 ms)
  P3 waits 3 ms (burst 3 ms)
  P1 waits 6 ms (burst 24 ms)
  Average wait = 3.0 ms

Long job first:
  P1 waits 0 ms (burst 24 ms)
  P2 waits 24 ms (burst 3 ms)
  P3 waits 27 ms (burst 3 ms)
  Average wait = 17.0 ms
```

Try changing the arrays in `main` to test your own jobs and orders.

## Presentation

My slides are in [`slides/FCFS_Scheduling.pdf`](slides/FCFS_Scheduling.pdf).

## Resources
- AI conversation I used to learn the topic: https://claude.ai/share/a8fb115c-e893-4183-8fb8-e98723551cad
