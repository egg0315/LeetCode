class Elevator {
public:
    Elevator():direction(0), curFloor(1) {};
    void moveUp() { curFloor++;}
    void moveDown() { curFloor--;}
    void stop() {}
    void openDoor() {}
    void closeDoor() {}

    void update() {
        int target = Request::getInstance().getNextFloor(curFloor, direction);
        if(taret == curFloor && direction == 0)
            return;
        if(target > curFloor) {
            direction = 1;
            moveUp();
        }
        else if(target < curFloor) {
            direction = -1;
            moveDown();
        }
        if(target == curFloor) {
            openDoor();
            closeDoor();
            direction = 0;
            stop();
            return;
        }
    }
private:
    int curFloor;
    int direction;

};

class Request {
public:
    static Request& getInstance() {
        static Request instance;
        return instance;
    }

    int getNextFloor(int curFloor, int direction) {
        if(requests.size() == 0)
            return curFloor;
        if(dir >= 0) {
            return *requests.rbegin();
        }
        return *requests.begin();
    }

    void addRequest(int floor) {
        requests.insert(floor);
    }

    void removeRequest(int floor) {
        requests.erase(floor);
    }

private:
    set<int> requests;
}

class ElevatorManager {
public:
    void addRequest(int floor) {
        Request::getInstance().addRequest(floor);
    }
}


