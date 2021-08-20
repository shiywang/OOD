//
// Created by Shiyang Wang on 8/19/21.
//

#ifndef C____ELEVATOR_H_
#define C____ELEVATOR_H_
using namespace std;

class Elevator;
class ExternalRequest;
class InternalRequest;

enum Direction {
  _UP, _DOWN
};

enum Status {
  UP, DOWN, IDLE
};

class Request {
 private :
  int level;

 public :
  Request(int l = 0){
	level = l;
  }

  int getLevel(){
	return level;
  }
};


class ElevatorButton{
 private :
  int level;
  Elevator *elevator;

 public :
  ElevatorButton(int level, Elevator *e){
	this->level = level;
	this->elevator = e;
  }

  void pressButton();
};

class ExternalRequest: public Request{

 private :
  Direction direction;

 public :
  ExternalRequest(){

  }
  ExternalRequest(int l, Direction d):Request(l) {
	// TODO Auto-generated constructor stub
	this->direction = d;
  }

  Direction getDirection(){
	return direction;
  }
};

class InternalRequest:public Request{

 public :
  InternalRequest(int l = 0):Request(l) {
	// TODO Auto-generated constructor stub
  }
};

string writeVector(vector<bool>& vec){
  string temp = writeVector(vec);
  for(auto ch = temp.begin();ch != temp.end();ch++){
	if((*ch) == ','){
	  ch = temp.insert(++ch,' ');
	}
  }
  return temp;
}

class Elevator {
 private :
  vector<ElevatorButton> buttons;
  vector<bool> upStops;
  vector<bool> downStops;
  int currLevel;
  Status status;

 public :
  Elevator(int n) {
	status = IDLE;
	for (int i = 0; i < n; ++i) {
	  upStops.push_back(false);
	  downStops.push_back(false);
	}
  }

  void insertButton(ElevatorButton eb){
	buttons.push_back(eb);
  }

  void handleExternalRequest(ExternalRequest r){
	// Write your code here
  }

  void handleInternalRequest(InternalRequest r){
	// Write your code here
  }

  void openGate(){
	// Write your code here
  }

  void closeGate(){
	// Write your code here
  }

  bool noRequests(vector<bool>& stops)
  {
	for (int i = 0; i < stops.size(); i++)
	{
	  if (stops[i])
	  {
		return false;
	  }
	}
	return true;
  }

  string elevatorStatusDescription(){
	string status_;
	if(status == UP){
	  status_="UP";
	}
	else if(status == DOWN){
	  status_="DOWN";
	}
	else if(status == IDLE){
	  status_="IDLE";
	}
	string description = "Currently elevator status is : " + status_
		+ ".\nCurrent level is at: " + to_string(currLevel + 1)
		+ ".\nup stop list looks like: " + writeVector(upStops)
		+ ".\ndown stop list looks like:  " + writeVector(downStops)
		+ ".\n*****************************************\n";
	//cout<<description<<endl;
	return description;
  }
};

void ElevatorButton::pressButton(){
  InternalRequest request = InternalRequest(level);
  elevator->handleInternalRequest(request);
}
#endif //C____ELEVATOR_H_
