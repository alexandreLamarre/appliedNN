/*=============================================================================

  APPLIEDNEURALNETWORKS: from scratch neural networks

  Copyright (c) University College London (UCL). All rights reserved.

  This software is distributed WITHOUT ANY WARRANTY; without even
  the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
  PURPOSE.

  See LICENSE.txt in the top level directory for details.

=============================================================================*/

#include "annBasicTypes.h"
#include "annException.h"

namespace ann {

/**
* Builds a Dense Layer of a neural network.
* Initializes weights to random floats between 0 and 0.01.
* @param num_input : the number of inputs to this layer
* @param num_neurons : the number of neurons in this layer
* @throws ann::InvalidInteger : nump_input > 0 and num_neuron > 0
**/
DenseLayer::DenseLayer(int num_input, int num_neurons){
  if(num_input <= 0) throw Exception("annBasicTypes.cpp : Invalid number of inputs for dense layer , expected > 0", 27);
  if(num_neurons <= 0) throw Exception("annBasicTypes.cpp : Invalid number of neurons for dense layer, expected > 0", 28);

  for(int i = 0; i < num_input; i++){
    std::vector<float> newWeightsRow = std::vector<float>{};
    for(int j = 0; j < num_neurons; j++){
      float r = static_cast <float> (std::rand()) / static_cast <float> (RAND_MAX);
      newWeightsRow.push_back(r * 0.01);
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
    throw Exception("annBasicTypes.cpp : Invalid neuron index", 67);
  }
  if(input >= weights[neuron].size()){
    throw Exception("annBasicTypes.cpp : Invalid input index", 70);
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
    throw Exception("annBasicTypes.cpp : Invalid neuron index", 83);
  }
  return biases[neuron];
}

/**
* Returns the current state of the output for this layer
* @returns vector of current output values for this layer
**/
std::vector<float> DenseLayer::getOutput(){
  return outputs;
}

/**
* Forward propagate the given input values through the layer
* @param 
**/
void DenseLayer::forward_propagation(std::vector<float> inputs){
  if(inputs.size() != weights.size()){
    throw Exception("annBasicTypes.cpp : Mismatched actual input size and expected layer input size", 103);
  }
  outputs = dot(inputs, weights);
  if(outputs.size() != biases.size()){
    throw Exception("annBasicTypes.cpp : Mismatched output layer size and biases size", 108);
  }
  for(int i = 0; i < outputs.size(); i++){
    outputs[i] += biases[i];
  }
}


} // end namespace
