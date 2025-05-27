6. Basic Monitors / Condition Variables
Write a function pingpong that creates two threads, ping (which prints "ping\n") and pong (which prints "pong\n"). Using only a mutex, condition variables, and counters, ensure that ping and pong together output:

  ping
  pong
  ping
  pong
  ...
Such that each "ping" is followed by a "pong" and each "pong" is followed by a "ping". This should stop after ten messages (five pings and five pongs). pingpong should not return until all pings and pongs have finished printing.