##Concurrent Access To Shared Memory: Race Problems
If a memory variable is shared by different processes and these processes modify it concurrently, 
then this might lead to a final incorrect result ! The goal in the following exercise is to show these 
possible errors.
    1. Using two tasks, create a shared variable ‘i’ and initialize  it 65; one task  should increment the variable and the other one should decrement it. Run  these tasks and display the final value of ‘i’ ; can you see an error ?
    2. Replace the previous tasks with the following instructions. Explain what needs to be done in order to achieve either error (64 or 65) at will.
    ```Reg = i
       sleep(for_some_time) // your choice
       Reg++ (or Reg--);// depending on the task
       i = Reg;
    ```
