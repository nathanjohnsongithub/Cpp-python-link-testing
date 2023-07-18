#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <vector>
#include <iostream>

using namespace std;
namespace py = pybind11;

py::array_t<double> sum_vectors(py::array_t<double> input1, py::array_t<double> input2) {
    // Get the input arrays as C++ vectors
    py::buffer_info info1 = input1.request();
    py::buffer_info info2 = input2.request();
    vector<double> vec1(static_cast<double*>(info1.ptr), static_cast<double*>(info1.ptr) + info1.size);
    vector<double> vec2(static_cast<double*>(info2.ptr), static_cast<double*>(info2.ptr) + info2.size);

    // make row and cols variabes
    int row = vec1.size();
    int cols = vec2.size();
    // place holder vector so we can make a matrix full of 0's
    vector<int> v(row, 0);
    // create matrix
    vector<vector<int>> sum_matrix(row, v);

    // populate matrix
    for (int i = 0; i < row; ++i){
        for (int j = 0; j < cols; ++j){
            sum_matrix[i][j] = vec1[i] * vec2[j];
        }
    }

    // Create a new numpy array to hold the result
    py::array_t<double> result({row, cols});
    py::buffer_info result_info = result.request();
    double* result_data = static_cast<double*>(result_info.ptr);

    // copy sum_matrix into result_data
    for (const auto& rows : sum_matrix) {
        result_data = copy(rows.begin(), rows.end(), result_data);
    }

    return result;
}

PYBIND11_MODULE(example, m) {
    m.def("sum_vectors", &sum_vectors, "Compute the sum of two vectors");
}
