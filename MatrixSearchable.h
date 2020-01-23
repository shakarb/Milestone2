//
// Created by shaked on 15/01/2020.
//

#ifndef MILESTONE2_MATRIXSEARCHABLE_H
#define MILESTONE2_MATRIXSEARCHABLE_H

#include "Searchable.h"
#include <string>
#include <vector>
#include <tgmath.h>
#include "Point.h"
#include "State.h"
#include <iostream>


class MatrixSearchable: public Searchable<Point*> {
  string data;
  // every number in the matrix will be a state of point
  vector<vector<State<Point*>*>> matrix;
  Point* init_point;
  Point* end_point;
  int num_rows;
  int num_cols;
  int solution_cost;

  /*
   * converting the matrix from string to vector of vectors of states.
   */
  void convertSearchable();

  /*
   * Set initPoint and endPoint of the matrix by pasrsing it from the problem
   * and change 'data' to be only the data of the matrix (without the start end points)
   */
  void parser();

 public:
  MatrixSearchable(string data);

  /*
   * Get the string of the matrix
   */
  string getStr();

  /*
   * return the matrix.
   */
  vector<vector<State<Point*>*>> getMatrix();

  /*
   * Get the initial state of the matrix
   */
  State<Point*>* getInitialState();

  /*
   * Check whether the given state is the goal state
   */
  bool isGoalState(State<Point*>* state);

  /*
   * Get all possibile movements from the given state
   */
  vector<State<Point*>*> getAllPossisbleStates(State<Point*>* state);

  /*
   * return a string witch instructs how to go from the initial state to the goal state.
   */

  string getDirection(vector<State<Point*>*> *trace);

  double disFromGoal(State<Point*>* state);

  int getSolutionCost();
};


#endif //MILESTONE2_MATRIXSEARCHABLE_H
