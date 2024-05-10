#!/bin/bash
cd ../build
make
cp libleveldb.a ../practice/
cd ../practice
g++ -o demo demo.cc libleveldb.a libisal.a -lpthread
g++ -o read read.cc libleveldb.a libisal.a -lpthread