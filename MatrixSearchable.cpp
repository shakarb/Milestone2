//
// Created by batel on 18/01/2020.
//
#include "MatrixSearchable.h"
MatrixSearchable::MatrixSearchable(string data) {
  this->data = data;
  this->parser();
  this->convertSearchable();
}

void MatrixSearchable::convertSearchable() {
  vector<State<Point*>*> v;
  int num_col = 0;
  int num_row = 0;
  for(int i= 0; i < data.length(); i++) {
    if (data[i] != '\n' && data[i] != ',') {
      // create a state of point:
      // remember : the point here is const.
      State<Point*>* state = new State<Point*>(new Point(num_row, num_col));
      string s(1, data[i]);
      state->setCost(stod(s));
      v.push_back(state);
      num_col++;
    }
    if (data[i] == '\n'){
      num_row ++;
      num_col = 0;
      this->matrix.push_back(v);
      v.clear();
    }
  }

  // update the number of rows and columns.
  this->num_cols = this->matrix.begin()->size();
  this->num_rows = num_row;
}

void MatrixSearchable::parser() {
  // make a vector of the matrix's strings
  vector<string> matrix_strings;
  string str;
  for(int i = 0; i < data.length(); i++) {
    if(data[i] != '\n') {
      str += data[i];
    } else {
      matrix_strings.push_back(str);
      str = "";
    }
  }

  int x, y, comma_pos;
  // get one line before the last line which represents the start point of the matrix
  string init_matrix = matrix_strings[matrix_strings.size() - 2];
  comma_pos = init_matrix.find(',');
  x = stoi(init_matrix.substr(0, comma_pos));
  y = stoi(init_matrix.substr(comma_pos + 1));
  this->init_point = new Point(x, y);
  // get the last line which represents the end point of the matrix
  string end_matrix = matrix_strings[matrix_strings.size() - 1];
  comma_pos = end_matrix.find(',');
  x = stoi(end_matrix.substr(0, comma_pos));
  y = stoi(end_matrix.substr(comma_pos + 1));
  this->end_point = new Point(x, y);

  // updating 'data' to be only the matrix. without the start and the end points.
  this->data = "";
  for(int i = 0; i < matrix_strings.size() - 2; i++) {
    this->data += matrix_strings[i] +"\n";
  }
}

bool MatrixSearchable::isGoalState(State<Point*>* state) {
  /*
  return this->end_point->getX() == state->getState()->getX() &&
  this->end_point->getY() == state->getState()->getY();*/
  return *state->getState() == *this->end_point;
}

vector<vector<State<Point*>*>> MatrixSearchable::getMatrix() {
  return this->matrix;
}

string MatrixSearchable::getStr() {
  return this->data;
}

State<Point*>* MatrixSearchable::getInitialState() {
  State<Point*>* init_state = new State<Point*>(init_point);
  return init_state;
}

vector<State<Point*>*> MatrixSearchable::getAllPossisbleStates(State<Point*>* state) {
  int is_done = 0;
  vector<State<Point*>*> states;
  int x_of_state = state->getState()->getX();
  int y_of_state = state->getState()->getY();
  //about the corners:
  if(x_of_state == 0 && y_of_state == 0) {
    if(num_rows >= 2) {
      states.push_back(matrix[1][0]);
    }
    if(num_cols >= 2) {
      states.push_back(matrix[0][1]);
    }
    is_done = 1;
  }
  if(x_of_state == 0 && y_of_state == num_cols - 1 && !is_done) {
    if(num_rows >= 2) {
      states.push_back(matrix[1][num_cols - 1]);
    }
    states.push_back(matrix[0][num_cols - 2]);
    is_done = 1;
  }
  if(x_of_state == num_rows - 1 && y_of_state == 0 && !is_done) {
    states.push_back(matrix[num_rows - 2][0]);
    if(num_cols >= 2) {
      states.push_back(matrix[num_rows - 1][1]);
    }
    is_done = 1;
  }
  if(x_of_state == num_rows - 1 && y_of_state == num_cols - 1 && !is_done) {
    states.push_back(matrix[num_rows - 2][num_cols -1]);
    states.push_back(matrix[num_rows - 1][num_cols -2]);
    is_done = 1;
  }
  // about the sides:
  // if the state is in the first row but not in the corners:
  if(x_of_state == 0 && !is_done) {
    states.push_back(matrix[0][y_of_state - 1]);
    states.push_back(matrix[0][y_of_state + 1]);
    if(num_rows >= 2) {
      states.push_back(matrix[1][y_of_state]);
    }
    is_done = 1;
  }
  // if the state is in the last row but not in the corners:
  if(x_of_state == num_rows - 1 && !is_done) {
    states.push_back(matrix[num_rows - 1][y_of_state - 1]);
    states.push_back(matrix[num_rows - 1][y_of_state + 1]);
    states.push_back(matrix[num_rows - 2][y_of_state]);
    is_done = 1;
  }
  // if the state is in the first column but not in the corners:
  if(y_of_state == 0 && !is_done) {
    states.push_back(matrix[x_of_state - 1][y_of_state]);
    states.push_back(matrix[x_of_state + 1][y_of_state]);
    if(num_cols >= 2) {
      states.push_back(matrix[x_of_state][y_of_state + 1]);
    }
    is_done = 1;
  }
  // if the state is in the last column but not in the corners:
  if(y_of_state == num_cols - 1 && !is_done) {
    states.push_back(matrix[x_of_state + 1][y_of_state]);
    states.push_back(matrix[x_of_state - 1][y_of_state]);
    states.push_back(matrix[x_of_state][y_of_state - 1]);
    is_done = 1;
  }
  // otherwise:
  if(!is_done) {
    states.push_back(matrix[x_of_state + 1][y_of_state]);
    states.push_back(matrix[x_of_state - 1][y_of_state]);
    states.push_back(matrix[x_of_state][y_of_state - 1]);
    states.push_back(matrix[x_of_state][y_of_state + 1]);
  }
  return states;
}

string MatrixSearchable::getDirection(vector<State<Point*>*> trace) {
  std::cout<<"kk"<<endl;
  string solution = "";
  for(int i = trace.size() - 1; i >= 0; i--) {
    solution.append(",");
    State<Point*>* father = trace[i];
    State<Point*>* son = trace [i - 1];
    int son_x = son->getState()->getX();
    int son_y = son->getState()->getY();
    int father_x = father->getState()->getX();
    int father_y = father->getState()->getY();
    if(son_x > father_x && son_y == father_y) {
      solution.append("Down");
    }
    if(son_x < father_x && son_y == father_y) {
      solution.append("Up");
    }
    if(son_x == father_x && son_y < father_y) {
      solution.append("Left");
    }
    if(son_x == father_x && son_y > father_y) {
      solution.append("Right");
    }
  }
  solution.erase(solution.begin());
  solution.append("\n");
  return solution;
}