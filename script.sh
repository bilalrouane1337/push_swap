#!/bin/bash

valgrind ./a.out ""
valgrind ./a.out "    "
valgrind ./a.out "    d"
valgrind ./a.out "d    "
valgrind ./a.out "h   d"
valgrind ./a.out "a"
valgrind ./a.out "uigui4uighu iu4hqgquogo"
valgrind ./a.out "1 2 3"
valgrind ./a.out "1 0 -1 5 -05"
valgrind ./a.out "1 0 -1 -5 -05"
