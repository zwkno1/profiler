all:
	g++ test.cpp -o test_volatile -pthread -O2 -DUSE_VOLATILE
	g++ test.cpp -o test_atomic -pthread -O2 -DUSE_ATOMIC
	g++ test.cpp -o test_null -pthread -O2
	
test:
	perf stat -e L1-dcache-load-misses ./test_atomic 1 true
	perf stat -e L1-dcache-load-misses ./test_atomic 1 false
	perf stat -e L1-dcache-load-misses ./test_atomic 2 true
	perf stat -e L1-dcache-load-misses ./test_atomic 2 false
	perf stat -e L1-dcache-load-misses ./test_atomic 4 true
	perf stat -e L1-dcache-load-misses ./test_atomic 4 false
	
	perf stat -e L1-dcache-load-misses ./test_volatile 1 true
	perf stat -e L1-dcache-load-misses ./test_volatile 1 false
	perf stat -e L1-dcache-load-misses ./test_volatile 2 true
	perf stat -e L1-dcache-load-misses ./test_volatile 2 false
	perf stat -e L1-dcache-load-misses ./test_volatile 4 true
	perf stat -e L1-dcache-load-misses ./test_volatile 4 false


