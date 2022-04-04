#!/bin/bash
gcc last.c && ./generate && ./standard example_ > expected.txt && ./a.out  example_> myoutput.txt && diff expected.txt myoutput.txt
