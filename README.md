# Cpp-python-link-testing

Testing with calling c++ in python. Using ctypes and pybind11.

# Ctypes. 
  To compile the c++ program and make the shared file (Already in repo.) You would run the command 
  
      g++ -shared -o sum_vectors.so sum_vectors.cpp
  
  To run the program just run the .py file

# pybind11.
  To compile the c++ program for pybind and make the shared file (Also already in the repo) you would run the command
  
      g++ -shared -fPIC `python3 -m pybind11 --includes` example.cpp -o example.so

  you can install pybind11 with conda using the command
      
      conda install -c conda-forge pybind11

  Or you can install it with pip
      
      pip install pybind11
      
