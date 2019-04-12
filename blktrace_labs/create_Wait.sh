#!/bin/sh
dd if=./file of=./file1 count=100000000000 bs=512 oflag=direct

