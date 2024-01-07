# FreeRTOS 

FreeRTOS is a real-time operating system (RTOS) for microcontrollers 
and small microprocessors. Distributed freely under the MIT open source license.

FreeRTOS includes a kernel and a growing set of IoT libraries suitable for use 
across all industry sectors.


## Tasks 

A task can exist in one of the following **states**:

![Tast States](doc/tskstate.gif)

* Running: When a task is actually executing it is said to be in the Running state. It is currently 
    utilising the processor. If the processor on which the RTOS is running only has a single core 
    then there can only be one task in the Running state at any given time.

* Ready: Ready tasks are those that are able to execute (they are not in the Blocked or Suspended 
    state) but are not currently executing because a different task of equal or higher priority is 
    already in the Running state.

* Blocked: A task is said to be in the Blocked state if it is currently waiting for either a temporal 
    or external event. For example, if a task calls vTaskDelay() it will block (be placed into the 
    Blocked state) until the delay period has expired - a temporal event. Tasks can also block to wait 
    for queue, semaphore, event group, notification or semaphore event. Tasks in the Blocked state 
    normally have a 'timeout' period, after which the task will be timeout, and be unblocked, even if 
    the event the task was waiting for has not occurred.

    Tasks in the Blocked state do not use any processing time and cannot be selected to enter the 
    Running state.

* Suspended: Like tasks that are in the Blocked state, tasks in the Suspended state cannot be 
    selected to enter the Running state, but tasks in the Suspended state do not have a time out. 
    Instead, tasks only enter or exit the Suspended state when explicitly commanded to do so through 
    the vTaskSuspend() and xTaskResume() API calls respectively.

The **FreeRTOS scheduler** ensures that tasks in the Ready or Running state will always be given 
processor (CPU) time in preference to tasks of a lower priority that are also in the ready state. 
In other words, **the task placed into the Running state is always the highest priority task 
that is able to run**.


## Simply Explained YouTube Tutorials

* [What is FreeRTOS?](https://youtu.be/kP-pP6FEu8I)
    FreeRTOS can be used from within ESP IDF and Arduino.    

* [How to Multitask with FreeRTOS](https://youtu.be/WQGAs9MwXno)    
    * xTaskCreate()
    * vTaskDelay()

* [Manage FreeRTOS tasks - Suspend, Delay, Resume, Delete](https://youtu.be/jJaGRCgDo9s?si=1ZBI1Coe6A3cQmLx)
    * vTaskDelete()        
    * TaskHandle_t
    * vTaskSuspend()
    * vTaskSuspendAll()
    * vTaskResume()
    * xTaskResumeAll()


## Digi-Key Electronics YouTube Tutorials

* [Part 1: What is a Real-Time Operating System (RTOS)?](https://youtu.be/F321087yYy4)
    * Task: Set of Program instructions loaded in memory.
    * Thread: Unit of CPU utilization with its own program counter and stack.
    * Process: Instance of a computer program.

* [Part 2: Getting Started with FreeRTOS](https://youtu.be/JIr7Xm_riRs)

* [Part 3: Task Scheduling](https://youtu.be/95yUbClyf3E?si=051YN9SgNIgvrAyq)

* [Part 4: Memory Management](https://youtu.be/Qske3yZRW5I?si=TJ-p58wu5jiKC7lX)

* [Part 5: Queue](https://youtu.be/pHJ3lxOoWeI?si=2015sxZI8Nzx6rIS)

* [Part 6: Mutex](https://youtu.be/I55auRpbiTs?si=57p6FpE6H6TNtaoJ)

* [Part 7: Semaphore](https://youtu.be/5JcMtbA9QEE?si=0YdQtZjEYHXZQkBS)



## References
* [Homepage: FreeRTOS](https://www.freertos.org/)
* [GitHub: FreeRTOS](https://github.com/FreeRTOS)