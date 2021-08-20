#include <iostream>
#include <string>
#include <vector>
#include <queue>
//#include "Elevator.h"
//first version of code : https://tedweishiwang.github.io/journal/object-oriented-design-elevator.html

enum Direction {
  _UP, _DOWN, _IDLE
};

enum Location {
  INSIDE,
  OUTSIDE
};

class Request {
 public:
  int currentFloor;
  int desiredFloor;
  Direction direction;
  Location location;

  Request(int currentFloor, int desiredFloor, Direction direction, Location location) {
	this->currentFloor = currentFloor;
	this->desiredFloor = desiredFloor;
	this->direction = direction;
	this->location = location;
  }
};

class Elevator {
 public:
  int currentFloor;
  Direction direction;
  bool upCmp = [](Request a, Request b) {
	return a.desiredFloor > b.desiredFloor;
  };
  bool downCmp = [](Request a, Request b) {
	return a.desiredFloor < b.desiredFloor;
  };
  std::priority_queue<Request, std::vector<Request>, decltype(upCmp)> upQueue;
  std::priority_queue<Request, std::vector<Request>, decltype(downCmp)> downQueue;

  Elevator(int currentFloor) {
	this->currentFloor = currentFloor;
	this->direction = Direction::_IDLE;
  }

  void sendUpRequest(Request *upRequest) {
    
  }

  void sendDownRequest(Request *downRequest) {

  }
  void run() {

  }
  void processRequest() {

  }
  void processUpRequest() {

  }
  void processDownRequest() {

  }
};

int main() {
  Elevator *elevator = new Elevator(0);

  Request *upRequest1 = new Request(elevator->currentFloor, 5, Direction::_UP, Location::INSIDE);
  Request *upRequest2 = new Request(elevator->currentFloor, 3, Direction::_UP, Location::INSIDE);

  Request *downRequest1 = new Request(elevator->currentFloor, 1, Direction::_DOWN, Location::INSIDE);
  Request *downRequest2 = new Request(elevator->currentFloor, 2, Direction::_DOWN, Location::INSIDE);
  Request *downRequest3 = new Request(elevator->currentFloor, 0, Direction::_DOWN, Location::OUTSIDE);

  elevator->sendUpRequest(upRequest1);
  elevator->sendUpRequest(upRequest2);

  elevator->sendDownRequest(downRequest1);
  elevator->sendDownRequest(downRequest2);
  elevator->sendDownRequest(downRequest3);

  elevator->run();
  return 0;
}
