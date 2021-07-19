/*=============================================================================

  APPLIEDNEURALNETWORKS: from scratch neural networks

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#ifndef annMyFunctions_h
#define annMyFunctions_h

#include "annWin32ExportHeader.h"
#include "annException.h"
#include <vector>

/**
* \file annMyFunctions.h
* \brief Various Utilities.
* \ingroup utilities
*/
namespace ann
{

/**
* \brief My first function, adds two integers.
*/
APPLIEDNEURALNETWORKS_WINEXPORT int MyFirstAddFunction(int a, int b);

/**
* \brief Dot product for a vector and a matrix
*/
APPLIEDNEURALNETWORKS_WINEXPORT std::vector<float>  dot(std::vector<float> v, std::vector<std::vector<float>> mat);

/**
* \brief Dot product for two vectors
*/
APPLIEDNEURALNETWORKS_WINEXPORT float dot(std::vector<float> x, std::vector<float> y);
} // end namespace

#endif
