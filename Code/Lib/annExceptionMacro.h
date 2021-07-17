/*=============================================================================

  APPLIEDNEURALNETWORKS: from scratch neural networks

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#ifndef annExceptionMacro_h
#define annExceptionMacro_h

#include "annException.h"

#define annExceptionThrow() throw ann::Exception(__FILE__,__LINE__)

#endif
