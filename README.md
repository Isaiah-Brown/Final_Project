# Final_Project
#*Note to follow these instructions cmake must be installed*


Build
To run the code navigate to the cplusplus folder and make a build directory:
	mkdir build

Inside the build directory run:
cmake ..
make

This creates two executables:
	./serial
	./threaded


Run
To run the serial version enter ./serial followed by the two sequences you would like to compare:
	$ ./serial <proteinseq1.txt> <proteinseq2.txt>
To run the threaded version enter ./threaded then two sequences then the number of threads:
$ ./threaded <proteinseq1.txt> <proteinseq2.txt> <number of threads>


Output
Outputs are written to serial_results.txt or threaded_results.txt
Example output to threaded_results.txt:

Sequence 1: QKHVE_DLLT_KLKEAKEQQASMEEKF_H
Sequence 2: ZPKVQIXAMTIPXDKAQZQHJ_JQZEFE_H
Execution time (milliseconds): 7
CUPMS: 33
Seq length: 303
Threads: 10

