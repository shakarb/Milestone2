//
// Created by shaked on 15/01/2020.
//

#ifndef MILESTONE2_MATRIXSEARCHABLE_H
#define MILESTONE2_MATRIXSEARCHABLE_H

#include "Searchable.h"
#include <string>
#include <vector>
#include "Point.h"

template <typename T>
class MatrixSearchable: public Searchable<T> {

    string data;
    vector<string> matrix;
    T init_point;
    T end_point;
public:

    MatrixSearchable(string data) {
      this->data = data;
      this->parser();
    }

    /*
     * Get the string of the matrix
     */
    string getStr() {
        return this->data;
    }

    /*
     * Get the converted matrix by converting it from string to vector of strings.
     */
    vector<string> getConvertedSearchable() {

        string str;
        int j = 0;
        for(int i = 0; i < data.length(); i++) {
            while (data[i] != '\n') {
                str += data[i];
            }
            this->matrix[j] = str;
            str = "";
            j++;
        }

        return this->matrix;
    }

    /*
     * Set initPoint and endPoint of the matrix by pasrsing it from the problem
     */

    void parser() {
        int x, y, comma_pos;
        // get one line before the last line which represents the start point of the matrix
        string init_matrix = matrix[sizeof(matrix) - 2];
        comma_pos = init_matrix.find(',');
        x = stoi(init_matrix.substr(0, comma_pos));
        y = stoi(init_matrix.substr(comma_pos));
        this->initPoint = new T(x, y);
        // get the last line which represents the end point of the matrix
        string end_matrix = matrix[sizeof(matrix) - 1];
        comma_pos = init_matrix.find(',');
        x = stoi(init_matrix.substr(0, comma_pos));
        y = stoi(init_matrix.substr(comma_pos));
        this->endPoint = new T(x, y);
    }

    /*
     * Get the initial point of the matrix
     */
    T getInitialState() {
        return this->init_point;
    }

    /*
     * Check whether the given state is the goal state
     */
    bool isGoalState(T state) {
        return this->end_point == state;
    }

    /*
     * Get all possibile movements from the given state
     */
    list<T> getAllPossisbleStates(T state) {

    }

};


#endif //MILESTONE2_MATRIXSEARCHABLE_H
