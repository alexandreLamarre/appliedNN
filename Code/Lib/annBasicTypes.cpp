/*=============================================================================

  APPLIEDNEURALNETWORKS: from scratch neural networks

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "annBasicTypes.h"

namespace ann {

DenseLayer::DenseLayer(int num_input, int num_neurons){
  for(int i = 0; i < num_input; i++){
    std::vector<float> newWeightsRow = std::vector<float>{};
    for(int j = 0; j < num_neurons; j++){
      float r = static_cast <float> (std::rand()) / static_cast <float> (RAND_MAX);
      newWeightsRow.push_back(r);
    }
    weights.push_back(newWeightsRow);
  }

  for(int i = 0; i < num_neurons; i++){
    biases.push_back(0.0f);
  }
}

/**
* Gets the dimension of the weights for this dense layer
* @returns : vector with the dense layer shape (n1, n2, ...)
**/
std::vector<int> DenseLayer::getWeightsShape(){
  std::vector<int> shape = std::vector<int>{};
  int dimX = weights.size();
  shape.push_back(dimX);
  if(dimX > 0){
    shape.push_back(weights[0].size());
  }
  return shape;
}

/**
* Gets the current weight for a specific neuron and input
* @param neuron: the index of the neuron of the weight we want
* @param input : the index of the input of the weight we want
* @throws ann:InvalidIndex : when the neuron or input indicies are invalid
* @returns the weight of the input for a given neuron
**/
float DenseLayer::getWeightAt(int neuron, int input){
  if(neuron >= weights.size()){
    //TODO: throw an exception
  }
  if(input >= weights[neuron].size()){
    //TODO: throw an exception
  }
  return weights[neuron][input];
}

/**
* Gets the current bias for a specific neuron
* @param neuron : the index of the neuron we want
* @throws ann::InvalidIndex : when the neuron index is invalid
* @returns the biases of the given neuron
**/
float DenseLayer::getBiasAt(int neuron){
  if(neuron >= biases.size()){
    //TODO: throw an exception
  }
  return biases[neuron];
}


} // end namespace
