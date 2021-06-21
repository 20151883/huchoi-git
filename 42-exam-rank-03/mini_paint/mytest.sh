#!/bin/bash
gcc huchoi.c && ./genetate && ./standard example_ > expected.txt && ./a.out > myoutput.txt && diff expected.txt myoutput.txt
