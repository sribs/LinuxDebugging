#!/bin/sh
dd if=/dev/urandom of=file count=10000 bs=8192 oflag=direct
