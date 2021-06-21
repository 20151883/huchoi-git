#!/bin/bash
./standard examples/0 > expected.txt && ./a.out examples/0 > myoutput.txt && diff expected.txt myoutput.txt
./standard examples/1 > expected.txt && ./a.out examples/1 > myoutput.txt && diff expected.txt myoutput.txt
./standard examples/2 > expected.txt && ./a.out examples/2 > myoutput.txt && diff expected.txt myoutput.txt
./standard examples/3 > expected.txt && ./a.out examples/3 > myoutput.txt && diff expected.txt myoutput.txt
./standard examples/4 > expected.txt && ./a.out examples/4 > myoutput.txt && diff expected.txt myoutput.txt
./standard examples/5 > expected.txt && ./a.out examples/5 > myoutput.txt && diff expected.txt myoutput.txt
./standard examples/6 > expected.txt && ./a.out examples/6 > myoutput.txt && diff expected.txt myoutput.txt
./standard examples/7 > expected.txt && ./a.out examples/7 > myoutput.txt && diff expected.txt myoutput.txt
./standard examples/8 > expected.txt && ./a.out examples/8 > myoutput.txt && diff expected.txt myoutput.txt
