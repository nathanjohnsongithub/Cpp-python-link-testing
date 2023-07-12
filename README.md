# Cpp-python-link-testing

Testing with calling c++ in python. Using ctypes and pybind11.

# Ctypes. 
  To compile the c++ program and make the shared file (Already in repo) you would run the command 
  
      g++ -shared -o sum_vectors.so sum_vectors.cpp
  
  To run the program just run the .py file

# pybind11.
  To compile the c++ program for pybind and make the shared file (Also already in the repo) you would run the command
  
      g++ -O3 -Wall -shared -std=c++11 -fPIC `python3 -m pybind11 --includes` example.cpp -o example`python3-config --extension-suffix` -I<python_include_dir> -L<python_lib_dir>            -lpython<python_version>

  
  for <python_include_dir> and <python_lib_dir> you most provide the corrent paths. To do this you can type.
  
      python3 -c "import sysconfig; print(sysconfig.get_paths()['include'])"    
  
  for <python_include_dir>  and
  
      python3-config --ldflags | awk -F '-L' '{print $2}''''
  
  for <python_lib_dir>.

  
  for <python_version> put in the version of python.
  
  ex. 3.10
      -lpython3.10
