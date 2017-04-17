# TestDome Path Problem
Solutions of Testdome.com Path Problem.

Write a function that provides change directory (cd) function for an abstract file system.

Notes:
* Root path is '/'. 
* Path separator is '/'.  
* Parent directory is addressable as "..".  
* Directory names consist only of English alphabet letters (A-Z and a-z). 
For example, Path("/a/b/c/d").cd("../x").getPath() should return "/a/b/c/x".  

Note: Do not use built-in path-related functions.

Link to the problem : https://www.testdome.com/for-developers/solve-question/6448
Passes all the test cases on the testdome website. 
Solutions of Testdome.com Path Problem.

The solution makes use of stack to keep track of the path.
