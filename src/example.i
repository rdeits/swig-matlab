%module swigexample

%include "eigen_matlab.i"

%{
#include "example.h"
%}

%eigen_typemaps(Eigen::VectorXd);
%eigen_typemaps(Eigen::MatrixXd);
%eigen_typemaps(Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>)

%include "example.h"
