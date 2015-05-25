#!/bin/bash

diff $1.out <(./$1 < $1.in) 1>&2