/*=============================================================================

  APPLIEDNEURALNETWORKS: from scratch neural networks

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#ifndef annWin32ExportHeader_h
#define annWin32ExportHeader_h

/**
* \file annWin32ExportHeader.h
* \brief Header to sort Windows dllexport/dllimport.
*/

#if (defined(_WIN32) || defined(WIN32)) && !defined(APPLIEDNEURALNETWORKS_STATIC)
  #ifdef APPLIEDNEURALNETWORKS_WINDOWS_EXPORT
    #define APPLIEDNEURALNETWORKS_WINEXPORT __declspec(dllexport)
  #else
    #define APPLIEDNEURALNETWORKS_WINEXPORT __declspec(dllimport)
  #endif  /* APPLIEDNEURALNETWORKS_WINEXPORT */
#else
/* linux/mac needs nothing */
  #define APPLIEDNEURALNETWORKS_WINEXPORT
#endif

#endif
