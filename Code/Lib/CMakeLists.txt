#/*============================================================================
#
#  APPLIEDNEURALNETWORKS: from scratch neural networks
#
#  Copyright (c) University College London (UCL). All rights reserved.
#
#  This software is distributed WITHOUT ANY WARRANTY; without even
#  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
#  PURPOSE.
#
#  See LICENSE.txt in the top level directory for details.
#
#============================================================================*/

set(APPLIEDNEURALNETWORKS_LIBRARY_NAME appliedneuralnetworks)

set(APPLIEDNEURALNETWORKS_LIBRARY_SRCS
  annBasicTypes.cpp
  annMyFunctions.cpp
  annException.cpp
)

set(APPLIEDNEURALNETWORKS_LIBRARY_HDRS
  annExceptionMacro.h
)

add_library(${APPLIEDNEURALNETWORKS_LIBRARY_NAME} ${APPLIEDNEURALNETWORKS_LIBRARY_HDRS} ${APPLIEDNEURALNETWORKS_LIBRARY_SRCS})

if(BUILD_SHARED_LIBS)
  if(WIN32)
    add_definitions(-DAPPLIEDNEURALNETWORKS_WINDOWS_EXPORT)
  endif(WIN32)
endif(BUILD_SHARED_LIBS)

target_link_libraries(${APPLIEDNEURALNETWORKS_LIBRARY_NAME} PRIVATE ${ALL_THIRD_PARTY_LIBRARIES})

