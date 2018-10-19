# hackerrank

It’s been a bit since I've seriously coded C++.  Decided to refresh my skills in order to get back into the industry.  Happened across hanckerrank.com and decided this is a vehicle to achieve that objective.  Originally, I started with LeetCode but I’ve found HackerRank provides a better learning experience especially the discussion area where you see other REALLY efficient solutions.  I learn a lot by seeing different solutions, the discussions surrounding them, their O(n), etc.

Note: most of my code written for hackerrank is terse and has limited or no error checking.  Its assumed that the input data is clean.  This is about efficiency over error checking.

A good resource for the various competitive hacking web sites is the wiki page
https://en.wikipedia.org/wiki/Competitive_programming

Prior to starting down the competitive road I did the complete C++ course at:
http://www.learncpp.com/ - GREAT refresher!

Quick random number generator to create test data:
https://www.random.org/integers/
For large dataset I put the data in a file and have the shell feed my program with the data.  As an example, I dump the data into file testcase.in then run my compiled program.
pnema@PaulieLappy:~/projects/c++/hackerrank$ ./a.out < testcase.in

To test the efficiency of different algorithms I surround the function call with the following:

struct timespec start, finish;
double elapsed;

clock_gettime(CLOCK_MONOTONIC, &start);

int result = funcToBeTimed();

clock_gettime(CLOCK_MONOTONIC, &finish);

elapsed = (finish.tv_sec - start.tv_sec);
elapsed += (finish.tv_nsec - start.tv_nsec) / 1000000000.0;

The above obtained from:
https://stackoverflow.com/questions/2962785/c-using-clock-to-measure-time-in-multi-threaded-programs/2962914#2962914

