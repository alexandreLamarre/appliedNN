/*=============================================================================

  APPLIEDNEURALNETWORKS: from scratch neural networks

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "annMyFunctions.h"
#include <iostream>

namespace ann {

//-----------------------------------------------------------------------------
int MyFirstAddFunction(int a, int b)
{
  return a + b;
}

/**
* @param v: the "left" vector input to use for dot product
* @param mat : the "right" matrix input to use for dot product
* @throws ann::Exception : mismatched dimensions
*/
std::vector<float>  dot(std::vector<float> v, std::vector<std::vector<float>> mat){
  if(v.size() != mat.size()){
    throw Exception("annMyFunctions.cpp : mismatched input vector and matrix dimensions", 32);
  }
  std::vector<float> res = std::vector<float>{};
  int rowDim = mat[0].size();
  for(int k =0; k < rowDim; k ++){
    float nextValue = 0.0f;
    for(int i = 0; i < v.size(); i ++){
      for(int j = 0; j < v.size(); j ++){
        nextValue += v[i] * mat[j][k];
      }
    }
    res.push_back(nextValue);
  }
  return res;
}

/**
* @param x: the first input vector
* @param y: the second input vector
* @throws ann::Exception : mismatched vector dimensions
* @returns the dot product scalar value of vector X and vector Y
*/
float dot(std::vector<float> x, std::vector<float> y){
  if(x.size() != y.size()){
    throw Exception("annMyFuncions.cpp : mismatched input vector dimensions", 57);
  }
  float res = 0.0f;
  for(int i = 0; i < x.size(); i++){
    res += x[i] * y[i];
  }
  return res;
}

} // end namespace
