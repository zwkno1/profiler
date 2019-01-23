# gperftools

##profile

### start profile 
./profiler_test

### gen pdf file
pprof --pdf demo ./demo.prof > profie.pdf


## heap profile

### start heap profile
HEAPPROFILE=./heap ./heapprofiler_test

### gen pdf file
opprof --pdf ./heapprofiler_test heap.0001.heap > heapprofile.pdf

