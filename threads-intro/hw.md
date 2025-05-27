### 1.

Let’s examine a simple program, “loop.s”. First, just read and understand it. Then, run it with these arguments
```sh
(./x86.py -t 1 -p loop.s -i 100 -R dx)
``` 
This specifies a single thread, an interrupt every 100 instructions, and tracing of register %dx. What
will %dx be during the run? Use the -c flag to check your answers;
the answers, on the left, show the value of the register (or memory
value) after the instruction on the right has run.

###10. Now switch the inputs: ./x86.py -p wait-for-me.s -a
ax=0,ax=1 -R ax -M 2000 How do the threads behave? What
is thread 0 doing? How would changing the interrupt interval (e.g.,
-i 1000, or perhaps to use random intervals) change the trace outcome? Is the program efficiently using the CPU?

My Answer: The waiter now loops forever waiting for the signaller. Only when an interrupt hits and the signaller gets to run does the waiter finally get its message the next time it runs
This is inefficient for the CPU because the waiter takes up CPU time by constantly checking the condition variable 