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
    if(upRequest->location == Location::OUTSIDE) {
      upQueue.push(Request(upRequest->currentFloor, upRequest->currentFloor, Direction::_UP, Location::OUTSIDE));
      std::cout << "Append up request going to floor " <<  + upRequest->currentFloor <<  "." << std::endl;
    }
    upQueue.push(*upRequest);
    std::cout << "Append up request going to floor " << upRequest->desiredFloor << "." << std::endl;
  }

  void sendDownRequest(Request *downRequest) {
	if(downRequest->location == Location::OUTSIDE) {
	  downQueue.push(Request(downRequest->currentFloor, downRequest->currentFloor, Direction::_DOWN, Location::OUTSIDE));
	  std::cout << "Append down request going to floor " <<  + downRequest->currentFloor <<  "." << std::endl;
	}
	downQueue.push(*downRequest);
	std::cout << "Append down request going to floor " << downRequest->desiredFloor << "." << std::endl;
  }
  void run() {
    if(!this->upQueue.empty() || !this->downQueue.empty()) {
      processRequest();
    }
    std::cout << "finish all request." << std::endl;
    this->direction = Direction::_IDLE;
  }
  void processRequest() {
	if(this->direction == Direction::_UP || this->direction == Direction::_IDLE) {
	  processUpRequest();
	  processDownRequest();
	} else {
	  processDownRequest();
	  processUpRequest();
	}
  }
  void processUpRequest() {
	while(!this->upQueue.empty()) {
	  Request up = this->upQueue.top(); this->upQueue.pop();
	  this->currentFloor = up.desiredFloor;
	}
	if(!this->downQueue.empty()) {
		this->direction = Direction::_DOWN;
	} else {
	  this->direction = Direction::_IDLE;
	}
  }
  void processDownRequest() {
	while(!this->downQueue.empty()) {
	  Request down = this->downQueue.top(); this->downQueue.pop();
	  this->currentFloor = down.desiredFloor;
	}
	if(!this->upQueue.empty()) {
	  this->direction = Direction::_UP;
	} else {
	  this->direction = Direction::_IDLE;
	}
  }
};

int main() {
  Elevator *elevator = new Elevator(0);

  Request *upRequest1 = new Request(elevator->currentFloor, 5, Direction::_UP, Location::INSIDE);
  Request *upRequest2 = new Request(elevator->currentFloor, 3, Direction::_UP, Location::INSIDE);

  Request *downRequest1 = new Request(elevator->currentFloor, 1, Direction::_DOWN, Location::INSIDE);
  Request *downRequest2 = new Request(elevator->currentFloor, 2, Direction::_DOWN, Location::INSIDE);
  Request *downRequest3 = new Request(4, 0, Direction::_DOWN, Location::OUTSIDE);

  elevator->sendUpRequest(upRequest1);
  elevator->sendUpRequest(upRequest2);

  elevator->sendDownRequest(downRequest1);
  elevator->sendDownRequest(downRequest2);
  elevator->sendDownRequest(downRequest3);

  elevator->run();
  return 0;
}
