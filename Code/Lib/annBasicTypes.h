/*=============================================================================

  APPLIEDNEURALNETWORKS: from scratch neural networks

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#ifndef annBasicTypes_h
#define annBasicTypes_h

#include "annWin32ExportHeader.h"
#include <cstdlib>
#include <vector>

/**
* \defgroup internal internal
* \brief Internal stuff, not for end-users.
*/

/**
* \defgroup types types
* \brief Package-wide data types.
*/

/**
* \defgroup utilities utilities
* \brief Groups of c-style functions.
*/

/**
* \defgroup applications applications
* \brief Small, end-user applications, most likely command line.
*/

/**
* \file annBasicTypes.h
* \brief Defines types and typedefs used in this library.
* \ingroup types
*/

//! Single namespace for all code in this package
namespace ann
{

class DenseLayer{
  public:
    DenseLayer(int, int);
    void forward_propagation(std::vector<int>);
    std::vector<float> getOutput(std::vector<float>);
    std::vector<int> getWeightsShape();
    float getWeightAt(int neuron, int input);
    float getBiasAt(int neuron);
  private:
    std::vector<std::vector<float>> weights;
    std::vector<float> biases;
    std::vector<float> outputs;
};

} // end namespace

#endif
