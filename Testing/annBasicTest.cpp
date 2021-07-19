/*=============================================================================

  APPLIEDNEURALNETWORKS: from scratch neural networks

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "catch.hpp"
#include "annCatchMain.h"
#include "annMyFunctions.h"
#include "annBasicTypes.h"
#include <iostream>
#include <vector>

TEST_CASE( "My first test", "[some group identifier]" ) {
  int a = 5;
  REQUIRE( a < 6 );
}

TEST_CASE( "My second test", "[some group identifier]" ) {
  std::vector<int> a;
  REQUIRE( a.size() == 0 );
}

TEST_CASE( "Simple add", "[MyFirstAddFunction]") {
  REQUIRE( ann::MyFirstAddFunction(1, 2) == 3);
}

/**
* Unit tests for Dense Layer Object
**/
TEST_CASE("Dense Layer Constructor 1", "[DenseLayer::DenseLayer]"){
  int num_inputs = 2; int num_neurons = 3;
  ann::DenseLayer dl = ann::DenseLayer(num_inputs, num_neurons);

  REQUIRE(dl.getWeightsShape()[0] == 2);
  REQUIRE(dl.getWeightsShape()[1] == 3);
}
