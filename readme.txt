Assignment - Multi-Threading - The Space Race

Assignment Background Information
  For this assignment, you will demonstrate the creation, execution, management of 
  multiple threads. To get started, review the Multi-threading lecture and read the 
  mutli-threaded introduction found on the solarian programmer website. 
  https://solarianprogrammer.com/2011/12/16/cpp-11-thread-tutorial/. In the first code snippet of this tutorial, it shows how to create 
  and launch a thread with the “hello world” code snippet. The important thing to 
  remember here is that the main function also creates a thread, which is joined with 
  the thread t1 (returns when the thread execution has completed). One of the other 
  code snippet passes in integers as parameters to 10 threads being created (actually 
  11 threads when we count the main thread). Notice how the threads run randomly and 
  they are not in any particular order. Preventing multiple threads from randomly 
  executing is called “Mutual exclusion”. The tool for implementing this in  C++ is 
  called a “Mutex”. A Mutex will allow you to lock and unlock the threads by 
  constructing an instance of std::mutex. The member functions ()lock and ()unlock 
  will allow you to block and then release each thread as it is executed.

Assignment Requirements:
  Clearly use true multithreading.
  Create the main space base and start launching 10 Rockets at the Rocket Pad remotely.
  There should be 3 seconds between each launch.
  Then transfer launch control from Main Base to the Rocket Pad Space Cadet after the first rocket launch.
  Use an abort button from Main Base to override the Space Cadet and stop him/her from launching any further Rockets.
  Demonstrate the override action using multithreading.
  Your code must be over commented.
  You must have a good UX and keep the user over-informed of what is happening.
