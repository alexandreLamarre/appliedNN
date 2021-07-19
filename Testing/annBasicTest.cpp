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
* Unit tests for dot product functions
**/

/**
* Test dot product for two vectors
*/
TEST_CASE("dot product: two vectors", "[ann:dot(std::vector<float>, std::vector<float>)]") {
  std::vector<float> v1{1, 2, 3};
  std::vector<float> v2{4, 5, 6};
  REQUIRE(ann::dot(v1, v2) == 4 + 10 + 18);

  std::vector<float> v3{-1, 2, 3};
  std::vector<float> v4{-4, -5, 6};
  REQUIRE(ann::dot(v3, v4) == 4 - 10 + 18);
}

/**
* Unit tests for Dense Layer Object
**/

/**
* Test constructor and weights shape
**/
TEST_CASE("Dense Layer Constructor 1", "[DenseLayer::DenseLayer]"){
  int num_inputs = 2; int num_neurons = 3;
  ann::DenseLayer dl = ann::DenseLayer(num_inputs, num_neurons);

  REQUIRE(dl.getWeightsShape()[0] == 2);
  REQUIRE(dl.getWeightsShape()[1] == 3);

  num_inputs = 1541; num_neurons = 4987;
  dl = ann::DenseLayer(num_inputs, num_neurons);
  REQUIRE(dl.getWeightsShape()[0] == 1541);
  REQUIRE(dl.getWeightsShape()[1] == 4987);
}

/**
* Test constructor has initialized the weights randomly between 0 and 0.01
* Test constructor has intialized biases to 0.
**/
TEST_CASE("Dense Layer Constructor 2", "[DenseLayer::DenseLayer]"){
  int num_inputs = 2; int num_neurons = 3;
  ann::DenseLayer dl = ann::DenseLayer(num_inputs, num_neurons);

  for(int i = 0; i < num_inputs; i++){
    for(int j = 0; j < num_neurons; j++){
      REQUIRE(dl.getWeightAt(i,j) <= 0.01);
      REQUIRE(dl.getWeightAt(i,j) >= 0);
    }
  }

  for(int i = 0; i < num_neurons; i++){
    REQUIRE(dl.getBiasAt(i) == 0);
  }
}
